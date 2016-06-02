/*
 * Shell Registry Access
 *
 * Copyright 2000 Juergen Schmied
 *
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
 */

#include "precomp.h"

WINE_DEFAULT_DEBUG_CHANNEL(shell);

/*************************************************************************
 * SHRegOpenKeyA                [SHELL32.506]
 *
 */
EXTERN_C HRESULT WINAPI SHRegOpenKeyA(
    HKEY hKey,
    LPSTR lpSubKey,
    PHKEY phkResult)
{
    TRACE("(%p, %s, %p)\n", hKey, debugstr_a(lpSubKey), phkResult);
    return RegOpenKeyA(hKey, lpSubKey, phkResult);
}

/*************************************************************************
 * SHRegOpenKeyW                [SHELL32.507] NT 4.0
 *
 */
EXTERN_C HRESULT WINAPI SHRegOpenKeyW (
    HKEY hkey,
    LPCWSTR lpszSubKey,
    PHKEY retkey)
{
    WARN("%p %s %p\n",hkey,debugstr_w(lpszSubKey),retkey);
    return RegOpenKeyW( hkey, lpszSubKey, retkey );
}

/*************************************************************************
 * SHRegQueryValueA   [SHELL32.508]
 *
 */
EXTERN_C HRESULT WINAPI SHRegQueryValueA(HKEY hkey, LPSTR lpSubKey, LPSTR lpValue, LPDWORD lpcbValue)
{
    TRACE("(%p %s %p %p)\n", hkey, debugstr_a(lpSubKey), lpValue, lpcbValue);
    return RegQueryValueA(hkey, lpSubKey, lpValue, (LONG*)lpcbValue);
}

/*************************************************************************
 * SHRegQueryValueExA   [SHELL32.509]
 *
 */
EXTERN_C HRESULT WINAPI SHRegQueryValueExA(
    HKEY hkey,
    LPSTR lpValueName,
    LPDWORD lpReserved,
    LPDWORD lpType,
    LPBYTE lpData,
    LPDWORD lpcbData)
{
    TRACE("%p %s %p %p %p %p\n", hkey, lpValueName, lpReserved, lpType, lpData, lpcbData);
    return RegQueryValueExA (hkey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}

/*************************************************************************
 * SHRegQueryValueW                [SHELL32.510] NT4.0
 *
 */
EXTERN_C HRESULT WINAPI SHRegQueryValueW(
    HKEY hkey,
    LPWSTR lpszSubKey,
    LPWSTR lpszData,
    LPDWORD lpcbData )
{
    WARN("%p %s %p %p semi-stub\n",
        hkey, debugstr_w(lpszSubKey), lpszData, lpcbData);
    return RegQueryValueW( hkey, lpszSubKey, lpszData, (LONG*)lpcbData );
}

/*************************************************************************
 * SHRegQueryValueExW    [SHELL32.511] NT4.0
 *
 * FIXME
 *  if the datatype REG_EXPAND_SZ then expand the string and change
 *  *pdwType to REG_SZ.
 */
EXTERN_C HRESULT WINAPI SHRegQueryValueExW (
    HKEY hkey,
    LPWSTR pszValue,
    LPDWORD pdwReserved,
    LPDWORD pdwType,
    LPVOID pvData,
    LPDWORD pcbData)
{
    DWORD ret;
    WARN("%p %s %p %p %p %p semi-stub\n",
        hkey, debugstr_w(pszValue), pdwReserved, pdwType, pvData, pcbData);
    ret = RegQueryValueExW ( hkey, pszValue, pdwReserved, pdwType, (LPBYTE)pvData, pcbData);
    return ret;
}

/*************************************************************************
 * SHRegDeleteKeyA   [SHELL32.?]
 */
HRESULT WINAPI SHRegDeleteKeyA(
    HKEY hkey,
    LPCSTR pszSubKey)
{
    FIXME("hkey=%p, %s\n", hkey, debugstr_a(pszSubKey));
    return 0;
}

/*************************************************************************
 * SHRegDeleteKeyW   [SHELL32.512]
 */
EXTERN_C HRESULT WINAPI SHRegDeleteKeyW(
    HKEY hkey,
    LPCWSTR pszSubKey)
{
    FIXME("hkey=%p, %s\n", hkey, debugstr_w(pszSubKey));
    return 0;
}

/*************************************************************************
 * SHRegCloseKey            [SHELL32.505] NT 4.0
 */
EXTERN_C HRESULT WINAPI SHRegCloseKey (HKEY hkey)
{
    TRACE("%p\n",hkey);
    return RegCloseKey( hkey );
}

/*************************************************************************
 * SHCreateSessionKey            [SHELL32.723]
 */
EXTERN_C HRESULT
WINAPI
SHCreateSessionKey(REGSAM samDesired, PHKEY phKey)
{
    HRESULT hr = S_OK;
    static WCHAR wszSessionKey[256];
    LONG Error;

    if (!wszSessionKey[0]) // FIXME: Critical Section
    {
        HANDLE hToken;

        if (OpenProcessToken(GetCurrentProcess(), TOKEN_READ, &hToken))
        {
            TOKEN_STATISTICS Stats;
            DWORD ReturnLength;

            if (GetTokenInformation(hToken, TokenStatistics, &Stats, sizeof(Stats), &ReturnLength))
            {
                swprintf(wszSessionKey,
                         L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\SessionInfo\\%08x%08x",
                         Stats.AuthenticationId.HighPart, Stats.AuthenticationId.LowPart);
            }
            else
                hr = HRESULT_FROM_WIN32(GetLastError());

            CloseHandle(hToken);
        }
        else
            hr = HRESULT_FROM_WIN32(GetLastError());
    }

    if(SUCCEEDED(hr))
    {
        Error = RegCreateKeyExW(HKEY_LOCAL_MACHINE, wszSessionKey, 0, NULL,
                                REG_OPTION_VOLATILE, samDesired, NULL, phKey, NULL);
        if (Error != ERROR_SUCCESS)
            hr = HRESULT_FROM_WIN32(Error);
    }

    return hr;
}
