/*++

Copyright (c) 2017  Shorthorn Project

Module Name:

    synch.c

Abstract:

    This module implements all Win32 syncronization
    objects.

Author:

    Skulltrail 16-March-2017

Revision History:

--*/
 
#define NDEBUG

#include "main.h"

typedef CRITICAL_SECTION pthread_mutex_t;

typedef struct win32_cond_t {
    pthread_mutex_t mtx_broadcast;
    pthread_mutex_t mtx_waiter_count;
    volatile int waiter_count;
    HANDLE semaphore;
    HANDLE waiters_done;
    volatile int is_broadcast;
} win32_cond_t;

typedef struct _RW_LOCK {
    CRITICAL_SECTION countsLock;
    CRITICAL_SECTION writerLock;
    HANDLE noReaders;
    int readerCount;
    BOOL waitingWriter;
} RW_LOCK, *PRW_LOCK;

/* returns directory handle to \\BaseNamedObjects */
HANDLE get_BaseNamedObjects_handle(void)
{
    static HANDLE handle = NULL;
    static const WCHAR basenameW[] = {'\\','S','e','s','s','i','o','n','s','\\','%','u',
                                      '\\','B','a','s','e','N','a','m','e','d','O','b','j','e','c','t','s',0};
    WCHAR buffer[64];
    UNICODE_STRING str;
    OBJECT_ATTRIBUTES attr;

    if (!handle)
    {
        HANDLE dir;

        sprintfW( buffer, basenameW, NtCurrentTeb()->ProcessEnvironmentBlock->SessionId );
        RtlInitUnicodeString( &str, buffer );
        InitializeObjectAttributes(&attr, &str, 0, 0, NULL);
        NtOpenDirectoryObject(&dir, DIRECTORY_CREATE_OBJECT|DIRECTORY_TRAVERSE,
                              &attr);
        if (InterlockedCompareExchangePointer( &handle, dir, 0 ) != 0)
        {
            /* someone beat us here... */
            CloseHandle( dir );
        }
    }
    return handle;
}

/*
 * @implemented
 */
BOOL 
WINAPI 
InitializeCriticalSectionEx(
	OUT LPCRITICAL_SECTION lpCriticalSection,
    IN DWORD dwSpinCount,
    IN DWORD flags 
)
{
    NTSTATUS Status;

    /* FIXME: Flags ignored */

    /* Initialize the critical section */
    Status = RtlInitializeCriticalSectionAndSpinCount(
        (PRTL_CRITICAL_SECTION)lpCriticalSection,
        dwSpinCount);
    if (!NT_SUCCESS(Status))
    {
        /* Set failure code */
        SetLastError(Status);
        return FALSE;
    }

    /* Success */
    return TRUE;
} 

BOOL 
WINAPI 
SleepConditionVariableSRW(
	PRTL_CONDITION_VARIABLE ConditionVariable, 
	PRTL_SRWLOCK SRWLock, 
	DWORD dwMilliseconds, 
	ULONG Flags
)
{
	CRITICAL_SECTION crit;
	InitializeCriticalSection(&crit);
	return SleepConditionVariableCS(ConditionVariable, &crit, Flags);
	// NTSTATUS status;
    // LARGE_INTEGER time;

    // status = RtlSleepConditionVariableSRW( ConditionVariable, SRWLock, get_nt_timeout( &time, dwMilliseconds ), Flags );
    // if (status != STATUS_SUCCESS)
    // {
        // SetLastError( RtlNtStatusToDosError(status) );
        // return FALSE;
    // }
    // return TRUE;
}

void 
WINAPI 
InitializeConditionVariable(
	PCONDITION_VARIABLE cond
) 
{
    win32_cond_t *win32_cond = NULL;
    win32_cond = (win32_cond_t *)LocalAlloc(0x40,sizeof(win32_cond_t));
    if (!win32_cond)
        return;
    cond->Ptr = win32_cond;
    win32_cond->semaphore = CreateSemaphore(NULL, 0, 0x7fffffff, NULL);
    if (!win32_cond->semaphore)
        return;
    win32_cond->waiters_done = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (!win32_cond->waiters_done)
        return;
    InitializeCriticalSection(&win32_cond->mtx_waiter_count);
    InitializeCriticalSection(&win32_cond->mtx_broadcast);
    return;
}

void 
WINAPI 
WakeAllConditionVariable(
	PCONDITION_VARIABLE cond
) 
{
    win32_cond_t *win32_cond = (win32_cond_t *)cond->Ptr;
    int have_waiter;
    EnterCriticalSection(&win32_cond->mtx_broadcast);
    EnterCriticalSection(&win32_cond->mtx_waiter_count);
    have_waiter = 0;
    if (win32_cond->waiter_count) {
        win32_cond->is_broadcast = 1;
        have_waiter = 1;
    }
    if (have_waiter) {
        ReleaseSemaphore(win32_cond->semaphore, win32_cond->waiter_count, NULL);
        LeaveCriticalSection(&win32_cond->mtx_waiter_count);
        WaitForSingleObject(win32_cond->waiters_done, INFINITE);
        ResetEvent(win32_cond->waiters_done);
        win32_cond->is_broadcast = 0;
    } else
        LeaveCriticalSection(&win32_cond->mtx_waiter_count);
    LeaveCriticalSection(&win32_cond->mtx_broadcast);
}

void 
WINAPI 
WakeConditionVariable(
	PCONDITION_VARIABLE cond
) 
{
    win32_cond_t *win32_cond = (win32_cond_t *)cond->Ptr;
    int have_waiter;
    EnterCriticalSection(&win32_cond->mtx_broadcast);
    EnterCriticalSection(&win32_cond->mtx_waiter_count);
    have_waiter = win32_cond->waiter_count;
    LeaveCriticalSection(&win32_cond->mtx_waiter_count);
    if (have_waiter) {
        ReleaseSemaphore(win32_cond->semaphore, 1, NULL);
        WaitForSingleObject(win32_cond->waiters_done, INFINITE);
        ResetEvent(win32_cond->waiters_done);
    }
    LeaveCriticalSection(&win32_cond->mtx_broadcast);
}

int 
WINAPI 
SleepConditionVariableCS(
	PCONDITION_VARIABLE cond, 
    pthread_mutex_t *mutex, 
	int slp
)
{
    win32_cond_t *win32_cond = (win32_cond_t *)cond->Ptr;
    int last_waiter;
	int i; 
    EnterCriticalSection(&win32_cond->mtx_broadcast);
    EnterCriticalSection(&win32_cond->mtx_waiter_count);
    win32_cond->waiter_count++;
    LeaveCriticalSection(&win32_cond->mtx_waiter_count);
    LeaveCriticalSection(&win32_cond->mtx_broadcast);

    LeaveCriticalSection(mutex);
    
	i = WaitForSingleObject(win32_cond->semaphore, slp);
    if(i)
        SetLastError(i);
    EnterCriticalSection(&win32_cond->mtx_waiter_count);
    win32_cond->waiter_count--;
    last_waiter = !win32_cond->waiter_count || !win32_cond->is_broadcast;
    LeaveCriticalSection(&win32_cond->mtx_waiter_count);
    if (last_waiter)
        SetEvent(win32_cond->waiters_done);
    EnterCriticalSection(mutex);
    return (BOOL)(i==0);
}

/***********************************************************************
  *           InitOnceExecuteOnce    (KERNEL32.@)
  */
BOOL 
WINAPI 
InitOnceExecuteOnce( 
	INIT_ONCE *once, 
	PINIT_ONCE_FN func, 
	void *param, 
	void **context 
)
{
    return !RtlRunOnceExecuteOnce( once, (PRTL_RUN_ONCE_INIT_FN)func, param, context );
}

/***********************************************************************
 *           CreateEventExW    (KERNEL32.@)
 */
HANDLE 
WINAPI 
DECLSPEC_HOTPATCH 
CreateEventExW( 
	SECURITY_ATTRIBUTES *sa, 
	LPCWSTR name, 
	DWORD flags, 
	DWORD access 
)
{
    HANDLE ret = 0;
    UNICODE_STRING nameW;
    OBJECT_ATTRIBUTES attr;
    NTSTATUS status;

    /* one buggy program needs this
     * ("Van Dale Groot woordenboek der Nederlandse taal")
     */
    if (sa && IsBadReadPtr(sa,sizeof(SECURITY_ATTRIBUTES)))
    {
        SetLastError( ERROR_INVALID_PARAMETER);
        return 0;
    }

    attr.Length                   = sizeof(attr);
    attr.RootDirectory            = 0;
    attr.ObjectName               = NULL;
    attr.Attributes               = OBJ_OPENIF | ((sa && sa->bInheritHandle) ? OBJ_INHERIT : 0);
    attr.SecurityDescriptor       = sa ? sa->lpSecurityDescriptor : NULL;
    attr.SecurityQualityOfService = NULL;
    if (name)
    {
        RtlInitUnicodeString( &nameW, name );
        attr.ObjectName = &nameW;
        attr.RootDirectory = get_BaseNamedObjects_handle();
    }

    status = NtCreateEvent( &ret, access, &attr,
                            (flags & CREATE_EVENT_MANUAL_RESET) ? NotificationEvent : SynchronizationEvent,
                            (flags & CREATE_EVENT_INITIAL_SET) != 0 );
    if (status == STATUS_OBJECT_NAME_EXISTS)
        SetLastError( ERROR_ALREADY_EXISTS );
    else
        SetLastError( RtlNtStatusToDosError(status) );
    return ret;
}

/***********************************************************************
 *           CreateEventExA    (KERNEL32.@)
 */
HANDLE 
WINAPI 
DECLSPEC_HOTPATCH 
CreateEventExA( 
	SECURITY_ATTRIBUTES *sa, 
	LPCSTR name, 
	DWORD flags, 
	DWORD access 
)
{
    WCHAR buffer[MAX_PATH];

    if (!name) return CreateEventExW( sa, NULL, flags, access );

    if (!MultiByteToWideChar( CP_ACP, 0, name, -1, buffer, MAX_PATH ))
    {
        SetLastError( ERROR_FILENAME_EXCED_RANGE );
        return 0;
    }
    return CreateEventExW( sa, buffer, flags, access );
}

/***********************************************************************
 *           CreateSemaphoreExW   (KERNEL32.@)
 */
HANDLE 
WINAPI 
DECLSPEC_HOTPATCH 
CreateSemaphoreExW( 
	SECURITY_ATTRIBUTES *sa, 
	LONG initial, 
	LONG max,
    LPCWSTR name, 
	DWORD flags, 
	DWORD access 
)
{
    HANDLE ret = 0;
    UNICODE_STRING nameW;
    OBJECT_ATTRIBUTES attr;
    NTSTATUS status;

    attr.Length                   = sizeof(attr);
    attr.RootDirectory            = 0;
    attr.ObjectName               = NULL;
    attr.Attributes               = OBJ_OPENIF | ((sa && sa->bInheritHandle) ? OBJ_INHERIT : 0);
    attr.SecurityDescriptor       = sa ? sa->lpSecurityDescriptor : NULL;
    attr.SecurityQualityOfService = NULL;
    if (name)
    {
        RtlInitUnicodeString( &nameW, name );
        attr.ObjectName = &nameW;
        attr.RootDirectory = get_BaseNamedObjects_handle();
    }

    status = NtCreateSemaphore( &ret, access, &attr, initial, max );
    if (status == STATUS_OBJECT_NAME_EXISTS)
        SetLastError( ERROR_ALREADY_EXISTS );
    else
        SetLastError( RtlNtStatusToDosError(status) );
    return ret;
}

/***********************************************************************
 *           CreateSemaphoreExA   (KERNEL32.@)
 */
HANDLE 
WINAPI 
DECLSPEC_HOTPATCH 
CreateSemaphoreExA( 
	SECURITY_ATTRIBUTES *sa, 
	LONG initial, 
	LONG max,
    LPCSTR name, 
	DWORD flags, 
	DWORD access 
)
{
    WCHAR buffer[MAX_PATH];

    if (!name) return CreateSemaphoreExW( sa, initial, max, NULL, flags, access );

    if (!MultiByteToWideChar( CP_ACP, 0, name, -1, buffer, MAX_PATH ))
    {
        SetLastError( ERROR_FILENAME_EXCED_RANGE );
        return 0;
    }
    return CreateSemaphoreExW( sa, initial, max, buffer, flags, access );
}

void 
WINAPI
InitializeSRWLock(PSRWLOCK lock)
{
	RW_LOCK *rwlock = NULL;
    rwlock = (RW_LOCK *)LocalAlloc(0x40,sizeof(RW_LOCK));
    if (!rwlock)
        return;
	lock->Ptr = rwlock;
    InitializeCriticalSection(&rwlock->writerLock);
    InitializeCriticalSection(&rwlock->countsLock);

    /*
     * Could use a semaphore as well.  There can only be one waiter ever,
     * so I'm showing an auto-reset event here.
     */
    rwlock->noReaders = CreateEvent (NULL, FALSE, FALSE, NULL);
}

void 
WINAPI
AcquireSRWLockShared(PSRWLOCK lock)
{
    /*
     * We need to lock the writerLock too, otherwise a writer could
     * do the whole of rwlock_wrlock after the readerCount changed
     * from 0 to 1, but before the event was reset.
     */
	RW_LOCK *rwlock = (RW_LOCK *)lock->Ptr;
    EnterCriticalSection(&rwlock->writerLock);
    EnterCriticalSection(&rwlock->countsLock);
    ++rwlock->readerCount;
    LeaveCriticalSection(&rwlock->countsLock);
    LeaveCriticalSection(&rwlock->writerLock);
}

VOID 
WINAPI
AcquireSRWLockExclusive(PSRWLOCK lock)
{
	RW_LOCK *rwlock = (RW_LOCK *)lock->Ptr;
	EnterCriticalSection(&rwlock->writerLock);
	rwlock->waitingWriter = TRUE;
	while (rwlock->readerCount > 0) {
		LeaveCriticalSection(&rwlock->writerLock);
		WaitForSingleObject(rwlock->noReaders, INFINITE);
		EnterCriticalSection(&rwlock->writerLock);
	}
	rwlock->waitingWriter = FALSE;

    /* writerLock remains locked.  */
}

void 
WINAPI
ReleaseSRWLockShared(PSRWLOCK lock)
{
	RW_LOCK *rwlock = (RW_LOCK *)lock->Ptr;	
    EnterCriticalSection(&rwlock->countsLock);
    assert (rwlock->readerCount > 0);
    if (--rwlock->readerCount == 0) {
        if (rwlock->waitingWriter) {
            /*
             * Clear waitingWriter here to avoid taking countsLock
             * again in wrlock.
             */
            rwlock->waitingWriter = FALSE;
            SetEvent(rwlock->noReaders);
        }
    }
    LeaveCriticalSection(&rwlock->countsLock);
}

void 
WINAPI
ReleaseSRWLockExclusive(PSRWLOCK lock)
{
	RW_LOCK *rwlock = (RW_LOCK *)lock->Ptr;	
    LeaveCriticalSection(&rwlock->writerLock);
}