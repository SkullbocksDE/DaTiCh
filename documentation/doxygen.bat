@echo off
echo DoxyGen documentation generator
echo Saving current dir "%CD%" to CURRENT_DIR ..
set CURRENT_DIR=%CD%
echo Saving done!
IF NOT "%DOXYGEN_DIR%"=="" goto CHECKDOXY
echo System environment variable DOXYGEN_DIR is undefined!
GOTO SCANDOXY

:CHECKDOXY
IF NOT EXIST %DOXYGEN_DIR% echo System environment variable DOXYGEN_DIR defined, but link is dead: "%DOXYGEN_DIR%"
GOTO SCANDOXY

:SCANDOXY
echo Scanning for doxygen..
set DOXYGEN_DIR="C:\Program Files (x86)\doxygen\bin"
IF NOT EXIST %DOXYGEN_DIR% GOTO NODOXYDIR

:STARTDOXY
echo Doxygen dir found at: %DOXYGEN_DIR%
echo Switching to doxygen dir ..
pushd %DOXYGEN_DIR%
echo Switching done!

:ASKDOXY
echo Start doxygen documentation? [y/n]
set /p startDoxygen=">> "
If "%startDoxygen%" == "n" goto ENDDOXY
If "%startDoxygen%" == "N" goto ENDDOXY
If "%startDoxygen%" == "y" goto RUNDOXY
If "%startDoxygen%" == "Y" goto RUNDOXY
echo Wrong key, please insert a valid key!
goto ASKDOXY

:RUNDOXY
echo Starting doxygen..
%DOXYGEN_DIR%\doxygen.exe "%CURRENT_DIR%\DoxyGenfile"
echo Doxygen finished!

:ASKOPEN
echo Do you want to open the result? [y/n]
set /p startDoxygen=">> "
If "%startDoxygen%" == "n" goto ASKAGAIN
If "%startDoxygen%" == "N" goto ASKAGAIN
If "%startDoxygen%" == "y" goto OPENHTML
If "%startDoxygen%" == "Y" goto OPENHTML
echo Wrong key, please insert a valid key!
goto ASKOPEN

:OPENHTML
"%CURRENT_DIR%\html\index.html"

:ASKAGAIN
echo Do you want to rerun doxygen? [y/n]
set /p startDoxygen=">> "
If "%startDoxygen%" == "n" goto ENDDOXY
If "%startDoxygen%" == "N" goto ENDDOXY
If "%startDoxygen%" == "y" goto RUNDOXY
If "%startDoxygen%" == "Y" goto RUNDOXY
echo Wrong key, please insert a valid key!
goto ASKAGAIN

:ENDDOXY
echo Session terminated!
PAUSE
exit

:NODOXYDIR
echo No DoxyGen dir found at: %DOXYGEN_DIR%
set DOXYGEN_DIR="C:\Program Files\doxygen\bin"
IF NOT EXIST %DOXYGEN_DIR% GOTO NONODOXYDIR
GOTO STARTDOXY

:NONODOXYDIR
echo No DoxyGen dir found at: %DOXYGEN_DIR%
echo Giving up!
echo Please set a system environment variable called DOXYGEN_DIR to your doxygen binary dir.
echo OR run DoxyWizard with the DoxygenFile manually.
echo Leaving session!
PAUSE
exit
