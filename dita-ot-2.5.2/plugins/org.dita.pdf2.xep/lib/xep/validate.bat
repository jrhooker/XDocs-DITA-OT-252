@echo off
rem   This batch file encapsulates a standard XEP call. 

set CP=F:\tmp\2zips\zepinstall\lib\xep.jar;F:\tmp\2zips\zepinstall\lib\saxon6.5.5\saxon.jar;F:\tmp\2zips\zepinstall\lib\saxon6.5.5\saxon-xml-apis.jar;F:\tmp\2zips\zepinstall\lib\xt.jar

if x%OS%==xWindows_NT goto WINNT
"C:\Program Files\Java\jdk1.8.0_144\jre\bin\java" -classpath "%CP%" "-Dcom.renderx.xep.CONFIG=F:\tmp\2zips\zepinstall\xep.xml" com.renderx.xep.Validator %1 %2 %3 %4 %5 %6 %7 %8 %9
goto END

:WINNT
"C:\Program Files\Java\jdk1.8.0_144\jre\bin\java" -classpath "%CP%" "-Dcom.renderx.xep.CONFIG=F:\tmp\2zips\zepinstall\xep.xml" com.renderx.xep.Validator %*

:END

set CP=
