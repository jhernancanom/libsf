@echo off

REM move to starting directory
cd \libsf\source\vjr\

REM remove common files
del command.vjr
del screen.vjr
del system.log

REM remove vs 2003 files
del vjr_vs2003.exe
del vjr_vs2003.ilk
del vjr_vs2003.pdb

REM remove all the compiler subdirs
echo Removing compiler folders
for /d /r . %%d in (Debug Release .clang .codelite) do @if exist "%%d" echo "%%d" && rd /s/q "%%d"

REM remove all intellisense-like databases
echo Removing intellisense-like databases
del /s *.ncb
REM All done
