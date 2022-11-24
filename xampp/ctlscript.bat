@echo off
rem START or STOP Services
rem ----------------------------------
rem Check if argument is STOP or START

if not ""%1"" == ""START"" goto stop

if exist D:\Codes\CGIBookLibrary\xampp\hypersonic\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\server\hsql-sample-database\scripts\ctl.bat START)
if exist D:\Codes\CGIBookLibrary\xampp\ingres\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\ingres\scripts\ctl.bat START)
if exist D:\Codes\CGIBookLibrary\xampp\mysql\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\mysql\scripts\ctl.bat START)
if exist D:\Codes\CGIBookLibrary\xampp\postgresql\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\postgresql\scripts\ctl.bat START)
if exist D:\Codes\CGIBookLibrary\xampp\apache\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\apache\scripts\ctl.bat START)
if exist D:\Codes\CGIBookLibrary\xampp\openoffice\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\openoffice\scripts\ctl.bat START)
if exist D:\Codes\CGIBookLibrary\xampp\apache-tomcat\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\apache-tomcat\scripts\ctl.bat START)
if exist D:\Codes\CGIBookLibrary\xampp\resin\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\resin\scripts\ctl.bat START)
if exist D:\Codes\CGIBookLibrary\xampp\jetty\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\jetty\scripts\ctl.bat START)
if exist D:\Codes\CGIBookLibrary\xampp\subversion\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\subversion\scripts\ctl.bat START)
rem RUBY_APPLICATION_START
if exist D:\Codes\CGIBookLibrary\xampp\lucene\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\lucene\scripts\ctl.bat START)
if exist D:\Codes\CGIBookLibrary\xampp\third_application\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\third_application\scripts\ctl.bat START)
goto end

:stop
echo "Stopping services ..."
if exist D:\Codes\CGIBookLibrary\xampp\third_application\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\third_application\scripts\ctl.bat STOP)
if exist D:\Codes\CGIBookLibrary\xampp\lucene\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\lucene\scripts\ctl.bat STOP)
rem RUBY_APPLICATION_STOP
if exist D:\Codes\CGIBookLibrary\xampp\subversion\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\subversion\scripts\ctl.bat STOP)
if exist D:\Codes\CGIBookLibrary\xampp\jetty\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\jetty\scripts\ctl.bat STOP)
if exist D:\Codes\CGIBookLibrary\xampp\hypersonic\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\server\hsql-sample-database\scripts\ctl.bat STOP)
if exist D:\Codes\CGIBookLibrary\xampp\resin\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\resin\scripts\ctl.bat STOP)
if exist D:\Codes\CGIBookLibrary\xampp\apache-tomcat\scripts\ctl.bat (start /MIN /B /WAIT D:\Codes\CGIBookLibrary\xampp\apache-tomcat\scripts\ctl.bat STOP)
if exist D:\Codes\CGIBookLibrary\xampp\openoffice\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\openoffice\scripts\ctl.bat STOP)
if exist D:\Codes\CGIBookLibrary\xampp\apache\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\apache\scripts\ctl.bat STOP)
if exist D:\Codes\CGIBookLibrary\xampp\ingres\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\ingres\scripts\ctl.bat STOP)
if exist D:\Codes\CGIBookLibrary\xampp\mysql\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\mysql\scripts\ctl.bat STOP)
if exist D:\Codes\CGIBookLibrary\xampp\postgresql\scripts\ctl.bat (start /MIN /B D:\Codes\CGIBookLibrary\xampp\postgresql\scripts\ctl.bat STOP)

:end

