@echo off
cd \libsf\source\vjr\source\lib32\
REM copy for debugging
copy freeglut-32.dll ..\..\freeglut.dll
copy glew32-32.dll ..\..\glew32.dll
copy sdl-32.dll ..\..\sdl.dll
REM Copy for offline builds
copy freeglut-32.dll \libsf_offline\source\vjr\bin\32-bit\freeglut.dll
copy glew32-32.dll \libsf_offline\source\vjr\bin\32-bit\glew32.dll
copy sdl-32.dll \libsf_offline\source\vjr\bin\32-bit\sdl.dll
