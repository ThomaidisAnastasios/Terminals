@echo off

set s=0
set i=0

FOR /F "tokens=4" %%g IN ('dir C:\Windows /-C') do
(

set i=%%k
set /a s+=i
set /a i+=2

)

echo My loop s=%s%
set /a i+=2

For /F "skip=%i% tokens=3" %%k  IN ('dir C:\Windows /-C')

goto end

:end 
pause