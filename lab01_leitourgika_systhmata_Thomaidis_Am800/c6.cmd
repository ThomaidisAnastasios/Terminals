@echo off

set msg1=Welcome
set msg2=Who  are you?

set /p yourname=What is your name?

set name=John

IF %name%==%yourname% ( echo %msg1% %yourname% 
) ELSE ( echo %msg2% )


pause
	