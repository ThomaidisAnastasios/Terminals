@echo off

set msg0= Welcome
set msg1= Who  are you?

IF %1 == John (echo %msg0%) ELSE (echo %msg1%)

pause