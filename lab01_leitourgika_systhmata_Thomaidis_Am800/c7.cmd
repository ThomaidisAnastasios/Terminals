@echo off

set /p yourname=Give yourname! 

set /p n= Give a number.

for /L %%i in  (1,1, %n%) do echo  %yourname%


pause
	