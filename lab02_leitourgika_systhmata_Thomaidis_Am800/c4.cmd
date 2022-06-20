@echo off

set msg0=In the classroom are

set msg1=students and 1 is gonna leave.

set msg2=There are no students in the classrom.

set j=%1

if defined j(goto 1op) else(goto 2op)

:2op 

set /p j=Give the number of students.
for /L %%i in (%j%,-1,1) do echo %msg0% %%i %msg1%
echo %msg2%

goto end

:1op

for /L %%i in (%1,-1,1) do echo %msg0% %%i %msg1%
echo %msg2%)

goto end



:end

pause
 
