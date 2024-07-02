@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by NETCHESS.HPJ. >"hlp\NetChess.hm"
echo. >>"hlp\NetChess.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\NetChess.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\NetChess.hm"
echo. >>"hlp\NetChess.hm"
echo // Prompts (IDP_*) >>"hlp\NetChess.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\NetChess.hm"
echo. >>"hlp\NetChess.hm"
echo // Resources (IDR_*) >>"hlp\NetChess.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\NetChess.hm"
echo. >>"hlp\NetChess.hm"
echo // Dialogs (IDD_*) >>"hlp\NetChess.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\NetChess.hm"
echo. >>"hlp\NetChess.hm"
echo // Frame Controls (IDW_*) >>"hlp\NetChess.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\NetChess.hm"
REM -- Make help for Project NETCHESS


REM -- echo Building Win32 Help files
REM --start /wait hcw /C /E /M "hlp\NetChess.hpj"
REM -- if errorlevel 1 goto :Error
REM -- if not exist "hlp\NetChess2.1.hlp" goto :Error
REM -- if not exist "hlp\NetChess2.1.cnt" goto :Error
REM -- echo.
REM -- if exist Debug\nul copy "hlp\NetChess2.1.hlp" Debug
REM -- if exist Debug\nul copy "hlp\NetChess.cnt" Debug
REM -- if exist Release\nul copy "hlp\NetChess2.1.hlp" Release
REM -- if exist Release\nul copy "hlp\NetChess.cnt" Release
REM -- echo.
REM -- goto :done

:Error
echo hlp\NetChess.hpj(1) : error: Problem encountered creating help file

:done
echo.
