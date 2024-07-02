# Microsoft Developer Studio Project File - Name="NetChess" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=NetChess - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "NetChess.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "NetChess.mak" CFG="NetChess - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "NetChess - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "NetChess - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "NetChess - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"Release/NetChess2.1.exe"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"Debug/NetChess2.1.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "NetChess - Win32 Release"
# Name "NetChess - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AcceptDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ChessBoard.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\CommentDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ConvertDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DemoIntervalDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine.cpp
# End Source File
# Begin Source File

SOURCE=.\EngineConfigDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EngineLevelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EngineLogDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EnterMoveDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GameStateDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GameStateInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GoToMoveHistoryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GoToPGNGameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GroupButton.cpp
# End Source File
# Begin Source File

SOURCE=.\History.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HowToPlayDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ICSClient.cpp
# End Source File
# Begin Source File

SOURCE=.\ICSConfigureDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ICSMessageChatDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ICSPlayersListDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ICSWindowDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LostPieceDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MailFromDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MailToDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Makehelp.bat
# End Source File
# Begin Source File

SOURCE=.\MessageSend.cpp
# End Source File
# Begin Source File

SOURCE=.\MyColorDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\MyColorEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\NetChess.cpp
# End Source File
# Begin Source File

SOURCE=.\hlp\NetChess.hpj

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build
OutDir=.\Debug
InputPath=.\hlp\NetChess.hpj
InputName=NetChess

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NetChess.rc
# End Source File
# Begin Source File

SOURCE=.\NetChessDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\NetChessLogDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NetChessView.cpp
# End Source File
# Begin Source File

SOURCE=.\ObserversDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Options.cpp
# End Source File
# Begin Source File

SOURCE=.\PGNDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PGNGameInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PickPieceDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Pop3.cpp
# End Source File
# Begin Source File

SOURCE=.\PropertiesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SeekListDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\Smtp.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TimeControlDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UCIEngineOptions.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewImage.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AcceptDlg.h
# End Source File
# Begin Source File

SOURCE=.\ChessBoard.h
# End Source File
# Begin Source File

SOURCE=.\ClientSocket.h
# End Source File
# Begin Source File

SOURCE=.\CommentDlg.h
# End Source File
# Begin Source File

SOURCE=.\ConvertDlg.h
# End Source File
# Begin Source File

SOURCE=.\DemoIntervalDlg.h
# End Source File
# Begin Source File

SOURCE=.\Engine.h
# End Source File
# Begin Source File

SOURCE=.\EngineConfigDlg.h
# End Source File
# Begin Source File

SOURCE=.\EngineLevelDlg.h
# End Source File
# Begin Source File

SOURCE=.\EngineLogDlg.h
# End Source File
# Begin Source File

SOURCE=.\EnterMoveDlg.h
# End Source File
# Begin Source File

SOURCE=.\GameStateDlg.h
# End Source File
# Begin Source File

SOURCE=.\GameStateInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\GoToMoveHistoryDlg.h
# End Source File
# Begin Source File

SOURCE=.\GoToPGNGameDlg.h
# End Source File
# Begin Source File

SOURCE=.\GroupButton.h
# End Source File
# Begin Source File

SOURCE=.\History.h
# End Source File
# Begin Source File

SOURCE=.\HistoryDlg.h
# End Source File
# Begin Source File

SOURCE=.\HowToPlayDlg.h
# End Source File
# Begin Source File

SOURCE=.\ICSClient.h
# End Source File
# Begin Source File

SOURCE=.\ICSConfigureDlg.h
# End Source File
# Begin Source File

SOURCE=.\ICSMessageChatDlg.h
# End Source File
# Begin Source File

SOURCE=.\ICSPlayersListDlg.h
# End Source File
# Begin Source File

SOURCE=.\ICSWindowDlg.h
# End Source File
# Begin Source File

SOURCE=.\LostPieceDlg.h
# End Source File
# Begin Source File

SOURCE=.\MailFromDlg.h
# End Source File
# Begin Source File

SOURCE=.\MailToDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MessageSend.h
# End Source File
# Begin Source File

SOURCE=.\MyColorDialog.h
# End Source File
# Begin Source File

SOURCE=.\MyColorEdit.h
# End Source File
# Begin Source File

SOURCE=.\NetChess.h
# End Source File
# Begin Source File

SOURCE=.\hlp\NetChess.hm
# End Source File
# Begin Source File

SOURCE=.\NetChessDoc.h
# End Source File
# Begin Source File

SOURCE=.\NetChessLogDlg.h
# End Source File
# Begin Source File

SOURCE=.\NetChessView.h
# End Source File
# Begin Source File

SOURCE=.\ObserversDlg.h
# End Source File
# Begin Source File

SOURCE=.\Options.h
# End Source File
# Begin Source File

SOURCE=.\PGNDlg.h
# End Source File
# Begin Source File

SOURCE=.\PGNGameInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\PickPieceDlg.h
# End Source File
# Begin Source File

SOURCE=.\Pop3.h
# End Source File
# Begin Source File

SOURCE=.\PropertiesDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SeekListDlg.h
# End Source File
# Begin Source File

SOURCE=.\ServerInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\ServerSocket.h
# End Source File
# Begin Source File

SOURCE=.\Smtp.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TimeControlDlg.h
# End Source File
# Begin Source File

SOURCE=.\UCIEngineOptions.h
# End Source File
# Begin Source File

SOURCE=.\ViewImage.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\base.bmp
# End Source File
# Begin Source File

SOURCE=.\res\base2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\base3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\base4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BISHOP.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BISHOPO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\KING.BMP
# End Source File
# Begin Source File

SOURCE=.\res\KINGO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\KNIGHT.BMP
# End Source File
# Begin Source File

SOURCE=.\res\KNIGHTO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\LDAPExplorer.ico
# End Source File
# Begin Source File

SOURCE=.\res\mainfram.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mainfram_extended.bmp
# End Source File
# Begin Source File

SOURCE=.\res\NetChess.ico
# End Source File
# Begin Source File

SOURCE=.\res\NetChess.rc2
# End Source File
# Begin Source File

SOURCE=.\res\NetChessDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\PAWN.BMP
# End Source File
# Begin Source File

SOURCE=.\res\PAWNO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\QUEEN.BMP
# End Source File
# Begin Source File

SOURCE=.\res\QUEENO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\ROOK.BMP
# End Source File
# Begin Source File

SOURCE=.\res\ROOKO.BMP
# End Source File
# End Group
# Begin Group "Help"

# PROP Default_Filter "rtf,bmp"
# Begin Source File

SOURCE=.\hlp\AfxCore.rtf

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\AfxPrint.rtf

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\AppExit.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\Bullet.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw2.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw4.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\CurHelp.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\EditCopy.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\EditCut.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\EditPast.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\EditUndo.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\FileNew.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\FileOpen.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\FilePrnt.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\FileSave.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\HlpSBar.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\HlpTBar.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\NetChess.ph

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\RecFirst.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\RecLast.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\RecNext.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\RecPrev.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\Scmax.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\ScMenu.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\Scmin.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

# PROP Ignore_Default_Tool 1

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\hlp\NetChess.cnt
# End Source File
# Begin Source File

SOURCE=C:\WINNT\NetChess.ini
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
