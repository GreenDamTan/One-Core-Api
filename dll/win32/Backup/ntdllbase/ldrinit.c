 /*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 */
 
#define NDEBUG

#include <main.h>

HANDLE ImageExecOptionsKey;

HANDLE Wow64ExecOptionsKey;

UNICODE_STRING Wow64OptionsString = RTL_CONSTANT_STRING(L"");

UNICODE_STRING ImageExecOptionsString = RTL_CONSTANT_STRING(L"\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options");

NTSTATUS NTAPI LdrOpenImageFileOptionsKey 	( 	IN PUNICODE_STRING  	SubKey,
		IN BOOLEAN  	Wow64,
		OUT PHANDLE  	NewKeyHandle 
	) 		
{
    PHANDLE RootKeyLocation;
    HANDLE RootKey;
    UNICODE_STRING SubKeyString;
    OBJECT_ATTRIBUTES ObjectAttributes;
    NTSTATUS Status;
    PWCHAR p1;

    /* Check which root key to open */
    if (Wow64)
        RootKeyLocation = &Wow64ExecOptionsKey;
    else
        RootKeyLocation = &ImageExecOptionsKey;

    /* Get the current key */
    RootKey = *RootKeyLocation;

    /* Setup the object attributes */
    InitializeObjectAttributes(&ObjectAttributes,
                               Wow64 ?
                               &Wow64OptionsString : &ImageExecOptionsString,
                               OBJ_CASE_INSENSITIVE,
                               NULL,
                               NULL);

    /* Open the root key */
    Status = ZwOpenKey(&RootKey, KEY_ENUMERATE_SUB_KEYS, &ObjectAttributes);
    if (NT_SUCCESS(Status))
    {
        /* Write the key handle */
        if (_InterlockedCompareExchange((LONG*)RootKeyLocation, (LONG)RootKey, 0) != 0)
        {
            /* Someone already opened it, use it instead */
            NtClose(RootKey);
            RootKey = *RootKeyLocation;
        }

        /* Extract the name */
        SubKeyString = *SubKey;
        p1 = (PWCHAR)((ULONG_PTR)SubKeyString.Buffer + SubKeyString.Length);
        while (SubKeyString.Length)
        {
            if (p1[-1] == L'\\') break;
            p1--;
            SubKeyString.Length -= sizeof(*p1);
        }
        SubKeyString.Buffer = p1;
        SubKeyString.Length = SubKey->Length - SubKeyString.Length;

        /* Setup the object attributes */
        InitializeObjectAttributes(&ObjectAttributes,
                                   &SubKeyString,
                                   OBJ_CASE_INSENSITIVE,
                                   RootKey,
                                   NULL);

        /* Open the setting key */
        Status = ZwOpenKey((PHANDLE)NewKeyHandle, GENERIC_READ, &ObjectAttributes);
    }

    /* Return to caller */
    return Status;
}

NTSTATUS NTAPI LdrQueryImageFileKeyOption 	( 	IN HANDLE  	KeyHandle,
		IN PCWSTR  	ValueName,
		IN ULONG  	Type,
		OUT PVOID  	Buffer,
		IN ULONG  	BufferSize,
		OUT PULONG ReturnedLength  	OPTIONAL 
	) 		
{
    ULONG KeyInfo[256];
    UNICODE_STRING ValueNameString, IntegerString;
    ULONG KeyInfoSize, ResultSize;
    PKEY_VALUE_PARTIAL_INFORMATION KeyValueInformation = (PKEY_VALUE_PARTIAL_INFORMATION)&KeyInfo;
    BOOLEAN FreeHeap = FALSE;
    NTSTATUS Status;

    /* Build a string for the value name */
    Status = RtlInitUnicodeStringEx(&ValueNameString, ValueName);
    if (!NT_SUCCESS(Status)) return Status;

    /* Query the value */
    Status = ZwQueryValueKey(KeyHandle,
                             &ValueNameString,
                             KeyValuePartialInformation,
                             KeyValueInformation,
                             sizeof(KeyInfo),
                             &ResultSize);
    if (Status == STATUS_BUFFER_OVERFLOW)
    {
        /* Our local buffer wasn't enough, allocate one */
        KeyInfoSize = sizeof(KEY_VALUE_PARTIAL_INFORMATION) +
                      KeyValueInformation->DataLength;
        KeyValueInformation = RtlAllocateHeap(RtlGetProcessHeap(),
                                              0,
                                              KeyInfoSize);
        if (KeyValueInformation != NULL)
        {
            /* Try again */
            Status = ZwQueryValueKey(KeyHandle,
                                     &ValueNameString,
                                     KeyValuePartialInformation,
                                     KeyValueInformation,
                                     KeyInfoSize,
                                     &ResultSize);
            FreeHeap = TRUE;
        }
        else
        {
            /* Give up this time */
            Status = STATUS_NO_MEMORY;
        }
    }

    /* Check for success */
    if (NT_SUCCESS(Status))
    {
        /* Handle binary data */
        if (KeyValueInformation->Type == REG_BINARY)
        {
            /* Check validity */
            if ((Buffer) && (KeyValueInformation->DataLength <= BufferSize))
            {
                /* Copy into buffer */
                RtlMoveMemory(Buffer,
                              &KeyValueInformation->Data,
                              KeyValueInformation->DataLength);
            }
            else
            {
                Status = STATUS_BUFFER_OVERFLOW;
            }

            /* Copy the result length */
            if (ReturnedLength) *ReturnedLength = KeyValueInformation->DataLength;
        }
        else if (KeyValueInformation->Type == REG_DWORD)
        {
            /* Check for valid type */
            if (KeyValueInformation->Type != Type)
            {
                /* Error */
                Status = STATUS_OBJECT_TYPE_MISMATCH;
            }
            else
            {
                /* Check validity */
                if ((Buffer) &&
                    (BufferSize == sizeof(ULONG)) &&
                    (KeyValueInformation->DataLength <= BufferSize))
                {
                    /* Copy into buffer */
                    RtlMoveMemory(Buffer,
                                  &KeyValueInformation->Data,
                                  KeyValueInformation->DataLength);
                }
                else
                {
                    Status = STATUS_BUFFER_OVERFLOW;
                }

                /* Copy the result length */
                if (ReturnedLength) *ReturnedLength = KeyValueInformation->DataLength;
            }
        }
        else if (KeyValueInformation->Type != REG_SZ)
        {
            /* We got something weird */
            Status = STATUS_OBJECT_TYPE_MISMATCH;
        }
        else
        {
            /*  String, check what you requested */
            if (Type == REG_DWORD)
            {
                /* Validate */
                if (BufferSize != sizeof(ULONG))
                {
                    /* Invalid size */
                    BufferSize = 0;
                    Status = STATUS_INFO_LENGTH_MISMATCH;
                }
                else
                {
                    /* OK, we know what you want... */
                    IntegerString.Buffer = (PWSTR)KeyValueInformation->Data;
                    IntegerString.Length = (USHORT)KeyValueInformation->DataLength -
                                           sizeof(WCHAR);
                    IntegerString.MaximumLength = (USHORT)KeyValueInformation->DataLength;
                    Status = RtlUnicodeStringToInteger(&IntegerString, 0, (PULONG)Buffer);
                }
            }
            else
            {
                /* Validate */
                if (KeyValueInformation->DataLength > BufferSize)
                {
                    /* Invalid */
                    Status = STATUS_BUFFER_OVERFLOW;
                }
                else
                {
                    /* Set the size */
                    BufferSize = KeyValueInformation->DataLength;
                }

                /* Copy the string */
                RtlMoveMemory(Buffer, &KeyValueInformation->Data, BufferSize);
            }

            /* Copy the result length */
            if (ReturnedLength) *ReturnedLength = KeyValueInformation->DataLength;
        }
    }

    /* Check if buffer was in heap */
    if (FreeHeap) RtlFreeHeap(RtlGetProcessHeap(), 0, KeyValueInformation);

	DbgPrint("Function: LdrQueryImageFileKeyOption. Status: %08x\n",Status);	
	
    /* Return status */
    return Status;
}

/*
 * @implemented
 */
NTSTATUS
NTAPI
LdrQueryImageFileExecutionOptionsEx(IN PUNICODE_STRING SubKey,
                                    IN PCWSTR ValueName,
                                    IN ULONG Type,
                                    OUT PVOID Buffer,
                                    IN ULONG BufferSize,
                                    OUT PULONG ReturnedLength OPTIONAL,
                                    IN BOOLEAN Wow64)
{
    NTSTATUS Status;
    HANDLE KeyHandle;

    /* Open a handle to the key */
    Status = LdrOpenImageFileOptionsKey(SubKey, Wow64, &KeyHandle);

    /* Check for success */
    if (NT_SUCCESS(Status))
    {
        /* Query the data */
        Status = LdrQueryImageFileKeyOption(KeyHandle,
                                            ValueName,
                                            Type,
                                            Buffer,
                                            BufferSize,
                                            ReturnedLength);

        /* Close the key */
        NtClose(KeyHandle);
    }

	DbgPrint("Function: LdrQueryImageFileExecutionOptionsEx. Status: %08x\n",Status);
    /* Return to caller */
    return Status;
}