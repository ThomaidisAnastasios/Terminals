@echo off

setlocal ENABLEDELAYEDEXPANSION

set LIST=
for %%i in (*) do set LIST=!LIST! %%i
echo !LIST!

endlocal

pause