call "c:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\VCVARSALL.BAT" amd64

cd .
nmake -f AFCS_MODEL1.mk  MODELLIB=AFCS_MODEL1lib.lib RELATIVE_PATH_TO_ANCHOR=.. MODELREF_TARGET_TYPE=NONE ISPROTECTINGMODEL=NOTPROTECTING
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
