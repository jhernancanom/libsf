@echo off

REM remove common files
del /s command.vjr
del /s screen.vjr
del /s system.log

REM remove vs 2003 files
del vjr_vs2003.exe
del vjr_vs2003.ilk
del vjr_vs2003.pdb

REM remove vs 98 files
del vjr_vs98\vjr_vs98.plg
del vjr.ilk

REM remove the gcc and vs98 executable
del vjr.exe

REM remove all the compiler subdirs
echo Removing compiler folders
for /d /r . %%d in (Debug Release .clang .codelite) do @if exist "%%d" echo "%%d" && rd /s/q "%%d"

REM remove all intellisense-like databases
echo Removing intellisense-like databases
del /s *.ncb
REM All done
