@echo off

rem Var
set drive=%CD:~0,3%
set currentDir=%CD%
set path=%drive%aspm
set autoRun=%drive%\ProgramData\Microsoft\Windows\"Start Menu"\Programs\StartUp\
set installed=0

rem Code
if exist %path%\ (set installed=1)else (echo Nothing to uninstall!)

if %installed% == 1 (goto uninstall)

:uninstall
cd %drive%
del aspm
echo Removed ASPM Directory

cd %autoRun%
del setup.bat
echo Removed ASPM aliasing

cd %currentDir%
echo Successfully uninstalled
