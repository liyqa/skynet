:: Debug x64
:: [General]   -> [Output Directory]  ..\..\
:: [Debugging] -> [Working Directory] $(OutDir)

:: @echo off
setlocal enabledelayedexpansion

del /Q /S *.user skynet.exe skynet.exp skynet.lib skynet.pdb lua.exe lua.pdb
del luaclib\*.exp luaclib\*.lib luaclib\*.pdb luaclib\*.so
del cservice\*.exp cservice\*.lib cservice\*.pdb cservice\*.so

@REM 设置你想删除的目录
set DIRS=x64;.vs

for /r . %%a in (!DIRS!) do (
  if exist %%a (
  echo "remove"%%a
  rd /s /q "%%a"
 )
)
