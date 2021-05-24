@echo off


rem Var
set drive=%CD:~0,3%
set path=%drive%aspm
set installPath=%path%\aspm.exe

set currentDir=%CD%
set autoRun=%drive%\ProgramData\Microsoft\Windows\"Start Menu"\Programs\StartUp

if exist %installPath% (set installed=1)else (set installed=0)

if %installed% == 0 (goto installation)else (goto aliasing)


rem Code
:installation
mkdir %path%
echo Created Installing Directory

copy aspm.exe %installPath%
set installed = 1
echo Copied ASPM to the machine
goto success

:success
echo Successfully installed ASPM
goto aliasing

:aliasing
cd %drive%windows\system32
DOSKEY aspm = %installPath%
cd %currentDir%
copy %currentDir%\setup.bat %autoRun%\setup.bat
