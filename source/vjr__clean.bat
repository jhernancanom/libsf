@echo off

REM move to starting directory
cd \libsf\source\vjr\

REM remove common files
del command.vjr
del screen.vjr
del system.log

REM remove all the compiler subdirs
echo Removing compiler folders
for /d /r . %%d in (Debug Release .clang .codelite) do @if exist "%%d" echo "%%d" && rd /s/q "%%d"

REM remove all intellisense-like databases
echo Removing intellisense-like databases
del /s *.ncb
REM All done
