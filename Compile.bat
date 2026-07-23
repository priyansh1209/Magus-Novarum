@echo off
title Magus Novarum Build Tool
setlocal enabledelayedexpansion

:: Move to project root
cd /d "%~dp0"


echo ===================================================
echo Magus Novarum Compiler
echo ===================================================
echo.


echo [1/6] Finding Microsoft Visual C++ Compiler...


set "VS_PATH="

for /f "usebackq tokens=*" %%i in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
    set "VS_PATH=%%i"
)


if "!VS_PATH!"=="" (
    echo [ERROR] Visual Studio C++ tools not found.
    echo Install Desktop Development with C++.
    pause
    exit /b 1
)


set "DEV_CMD=!VS_PATH!\Common7\Tools\VsDevCmd.bat"


if not exist "!DEV_CMD!" (
    echo [ERROR] Visual Studio developer command missing.
    pause
    exit /b 1
)



echo [2/6] Loading Visual Studio environment...

call "!DEV_CMD!" -no_logo >nul



echo [3/6] Checking source files...


set FILES_OK=1


for %%f in (
    "src\Main.cpp"
    "src\Game\Game.cpp"
    "src\Dialogue\Dialogue.cpp"
    "src\Player\Player.cpp"
    "src\Save\SaveManager.cpp"
    "src\Locations\WizardGuild.cpp"
    "src\Locations\Dungeon.cpp"
    "src\Locations\Home.cpp"
    "src\Attributes\Type.cpp"
    "src\Attributes\Form.cpp"
    "src\Spells\BasicSpell.cpp"
) do (

    if not exist %%f (
        echo [ERROR] Missing file: %%f
        set FILES_OK=0
    )

)


if "!FILES_OK!"=="0" (
    echo.
    echo Build cancelled.
    pause
    exit /b 1
)



echo [4/6] Preparing build folder...


if not exist "build" mkdir build



echo [5/6] Compiling...


cl.exe ^
/Z7 ^
/EHsc ^
/nologo ^
/Fe:build\Game.exe ^
/Fo:build\ ^
/Fd:build\ ^
src\Main.cpp ^
src\Game\Game.cpp ^
src\Dialogue\Dialogue.cpp ^
src\Player\Player.cpp ^
src\Save\SaveManager.cpp ^
src\Locations\WizardGuild.cpp ^
src\Locations\Dungeon.cpp ^
src\Locations\Home.cpp ^
src\Attributes\Type.cpp ^
src\Attributes\Form.cpp ^
src\Spells\BasicSpell.cpp



if errorlevel 1 (

    echo.
    echo ===================================================
    echo BUILD FAILED
    echo ===================================================
    pause
    exit /b 1

)



echo [6/6] Copying assets...


if exist "assets" (

    xcopy /E /I /Y assets build\assets >nul

)
else (

    echo [WARNING] No assets folder found.

)



echo.
echo ===================================================
echo BUILD SUCCESSFUL
echo Output:
echo build\Game.exe
echo ===================================================
echo.


pause