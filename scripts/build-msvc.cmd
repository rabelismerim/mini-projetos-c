@echo off
setlocal
if not defined VSINSTALLDIR (
    if exist "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars64.bat" (
        call "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul
    ) else (
        echo Abra o Developer Command Prompt do Visual Studio e execute python scripts/build.py --cc cl
        exit /b 1
    )
)
python "%~dp0build.py" --cc cl
