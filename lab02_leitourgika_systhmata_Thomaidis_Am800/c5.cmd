@echo off

setlocal ENABLEEXTENSIONS
set /A i=%random%
set /A j=1

echo %i%

:op0

set /p x=Give a number.

echo %x%

if %i% == %x% goto op1
if %x% LSS %i% goto op2
if %x% GTR %i% goto op3

:op1

echo Congrantulations you found it.

goto end

:op2

echo You gave a smaller number.

set /A j="%j%+1"

goto op0

:op3

echo You gave a bigger number.

set /A j="%j="%j%+1"

goto op0

:end
 
echo Yuou tried %j% times.
pause