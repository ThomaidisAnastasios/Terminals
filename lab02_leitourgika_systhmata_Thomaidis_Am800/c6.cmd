@echo off

setlocal ENABLEEXTENSIONS

set op=%1
set mp=%2

set msg0=Ok only 1.
set msg1=No parameter.
set msg2=Too many parameters.

If defined mp (echo %msg2%) ELSE (goto op1)

goto end

:op1 

If defined op (echo %msg0% ) ELSE (echo %msg1%)

:end

pause