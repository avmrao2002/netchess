# Microsoft Developer Studio Generated NMAKE File, Based on NetChess.dsp
!IF "$(CFG)" == ""
CFG=NetChess - Win32 Debug
!MESSAGE No configuration specified. Defaulting to NetChess - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "NetChess - Win32 Release" && "$(CFG)" != "NetChess - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "NetChess - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\NetChess2.1.exe"


CLEAN :
	-@erase "$(INTDIR)\AcceptDlg.obj"
	-@erase "$(INTDIR)\ChessBoard.obj"
	-@erase "$(INTDIR)\ClientSocket.obj"
	-@erase "$(INTDIR)\CommentDlg.obj"
	-@erase "$(INTDIR)\ConvertDlg.obj"
	-@erase "$(INTDIR)\DemoIntervalDlg.obj"
	-@erase "$(INTDIR)\Engine.obj"
	-@erase "$(INTDIR)\EngineConfigDlg.obj"
	-@erase "$(INTDIR)\EngineLevelDlg.obj"
	-@erase "$(INTDIR)\EngineLogDlg.obj"
	-@erase "$(INTDIR)\EnterMoveDlg.obj"
	-@erase "$(INTDIR)\GameStateDlg.obj"
	-@erase "$(INTDIR)\GameStateInfoDlg.obj"
	-@erase "$(INTDIR)\GoToMoveHistoryDlg.obj"
	-@erase "$(INTDIR)\GoToPGNGameDlg.obj"
	-@erase "$(INTDIR)\History.obj"
	-@erase "$(INTDIR)\HistoryDlg.obj"
	-@erase "$(INTDIR)\HowToPlayDlg.obj"
	-@erase "$(INTDIR)\ICSClient.obj"
	-@erase "$(INTDIR)\ICSConfigureDlg.obj"
	-@erase "$(INTDIR)\ICSWindowDlg.obj"
	-@erase "$(INTDIR)\LostPieceDlg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MessageSend.obj"
	-@erase "$(INTDIR)\MyColorDialog.obj"
	-@erase "$(INTDIR)\MyColorEdit.obj"
	-@erase "$(INTDIR)\NetChess.obj"
	-@erase "$(INTDIR)\NetChess.pch"
	-@erase "$(INTDIR)\NetChess.res"
	-@erase "$(INTDIR)\NetChessDoc.obj"
	-@erase "$(INTDIR)\NetChessLogDlg.obj"
	-@erase "$(INTDIR)\NetChessView.obj"
	-@erase "$(INTDIR)\ObserversDlg.obj"
	-@erase "$(INTDIR)\Options.obj"
	-@erase "$(INTDIR)\PGNDlg.obj"
	-@erase "$(INTDIR)\PGNGameInfoDlg.obj"
	-@erase "$(INTDIR)\PickPieceDlg.obj"
	-@erase "$(INTDIR)\PropertiesDlg.obj"
	-@erase "$(INTDIR)\ServerInfoDlg.obj"
	-@erase "$(INTDIR)\ServerSocket.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\UCIEngineOptions.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\ViewImage.obj"
	-@erase "$(OUTDIR)\NetChess2.1.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\NetChess.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\NetChess.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\NetChess.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\NetChess2.1.pdb" /machine:I386 /out:"$(OUTDIR)\NetChess2.1.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AcceptDlg.obj" \
	"$(INTDIR)\ChessBoard.obj" \
	"$(INTDIR)\ClientSocket.obj" \
	"$(INTDIR)\CommentDlg.obj" \
	"$(INTDIR)\ConvertDlg.obj" \
	"$(INTDIR)\DemoIntervalDlg.obj" \
	"$(INTDIR)\Engine.obj" \
	"$(INTDIR)\EngineConfigDlg.obj" \
	"$(INTDIR)\EngineLevelDlg.obj" \
	"$(INTDIR)\EngineLogDlg.obj" \
	"$(INTDIR)\EnterMoveDlg.obj" \
	"$(INTDIR)\GameStateDlg.obj" \
	"$(INTDIR)\GameStateInfoDlg.obj" \
	"$(INTDIR)\GoToMoveHistoryDlg.obj" \
	"$(INTDIR)\GoToPGNGameDlg.obj" \
	"$(INTDIR)\History.obj" \
	"$(INTDIR)\HistoryDlg.obj" \
	"$(INTDIR)\HowToPlayDlg.obj" \
	"$(INTDIR)\ICSClient.obj" \
	"$(INTDIR)\ICSConfigureDlg.obj" \
	"$(INTDIR)\ICSWindowDlg.obj" \
	"$(INTDIR)\LostPieceDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MessageSend.obj" \
	"$(INTDIR)\MyColorDialog.obj" \
	"$(INTDIR)\MyColorEdit.obj" \
	"$(INTDIR)\NetChess.obj" \
	"$(INTDIR)\NetChessDoc.obj" \
	"$(INTDIR)\NetChessLogDlg.obj" \
	"$(INTDIR)\NetChessView.obj" \
	"$(INTDIR)\ObserversDlg.obj" \
	"$(INTDIR)\Options.obj" \
	"$(INTDIR)\PGNDlg.obj" \
	"$(INTDIR)\PGNGameInfoDlg.obj" \
	"$(INTDIR)\PickPieceDlg.obj" \
	"$(INTDIR)\PropertiesDlg.obj" \
	"$(INTDIR)\ServerInfoDlg.obj" \
	"$(INTDIR)\ServerSocket.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\UCIEngineOptions.obj" \
	"$(INTDIR)\ViewImage.obj" \
	"$(INTDIR)\NetChess.res"

"$(OUTDIR)\NetChess2.1.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : ".\Debug\NetChess2.1.hlp" "$(OUTDIR)\NetChess2.1.exe" "$(OUTDIR)\NetChess.bsc"


CLEAN :
	-@erase "$(INTDIR)\AcceptDlg.obj"
	-@erase "$(INTDIR)\AcceptDlg.sbr"
	-@erase "$(INTDIR)\ChessBoard.obj"
	-@erase "$(INTDIR)\ChessBoard.sbr"
	-@erase "$(INTDIR)\ClientSocket.obj"
	-@erase "$(INTDIR)\ClientSocket.sbr"
	-@erase "$(INTDIR)\CommentDlg.obj"
	-@erase "$(INTDIR)\CommentDlg.sbr"
	-@erase "$(INTDIR)\ConvertDlg.obj"
	-@erase "$(INTDIR)\ConvertDlg.sbr"
	-@erase "$(INTDIR)\DemoIntervalDlg.obj"
	-@erase "$(INTDIR)\DemoIntervalDlg.sbr"
	-@erase "$(INTDIR)\Engine.obj"
	-@erase "$(INTDIR)\Engine.sbr"
	-@erase "$(INTDIR)\EngineConfigDlg.obj"
	-@erase "$(INTDIR)\EngineConfigDlg.sbr"
	-@erase "$(INTDIR)\EngineLevelDlg.obj"
	-@erase "$(INTDIR)\EngineLevelDlg.sbr"
	-@erase "$(INTDIR)\EngineLogDlg.obj"
	-@erase "$(INTDIR)\EngineLogDlg.sbr"
	-@erase "$(INTDIR)\EnterMoveDlg.obj"
	-@erase "$(INTDIR)\EnterMoveDlg.sbr"
	-@erase "$(INTDIR)\GameStateDlg.obj"
	-@erase "$(INTDIR)\GameStateDlg.sbr"
	-@erase "$(INTDIR)\GameStateInfoDlg.obj"
	-@erase "$(INTDIR)\GameStateInfoDlg.sbr"
	-@erase "$(INTDIR)\GoToMoveHistoryDlg.obj"
	-@erase "$(INTDIR)\GoToMoveHistoryDlg.sbr"
	-@erase "$(INTDIR)\GoToPGNGameDlg.obj"
	-@erase "$(INTDIR)\GoToPGNGameDlg.sbr"
	-@erase "$(INTDIR)\History.obj"
	-@erase "$(INTDIR)\History.sbr"
	-@erase "$(INTDIR)\HistoryDlg.obj"
	-@erase "$(INTDIR)\HistoryDlg.sbr"
	-@erase "$(INTDIR)\HowToPlayDlg.obj"
	-@erase "$(INTDIR)\HowToPlayDlg.sbr"
	-@erase "$(INTDIR)\ICSClient.obj"
	-@erase "$(INTDIR)\ICSClient.sbr"
	-@erase "$(INTDIR)\ICSConfigureDlg.obj"
	-@erase "$(INTDIR)\ICSConfigureDlg.sbr"
	-@erase "$(INTDIR)\ICSWindowDlg.obj"
	-@erase "$(INTDIR)\ICSWindowDlg.sbr"
	-@erase "$(INTDIR)\LostPieceDlg.obj"
	-@erase "$(INTDIR)\LostPieceDlg.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MessageSend.obj"
	-@erase "$(INTDIR)\MessageSend.sbr"
	-@erase "$(INTDIR)\MyColorDialog.obj"
	-@erase "$(INTDIR)\MyColorDialog.sbr"
	-@erase "$(INTDIR)\MyColorEdit.obj"
	-@erase "$(INTDIR)\MyColorEdit.sbr"
	-@erase "$(INTDIR)\NetChess.obj"
	-@erase "$(INTDIR)\NetChess.pch"
	-@erase "$(INTDIR)\NetChess.res"
	-@erase "$(INTDIR)\NetChess.sbr"
	-@erase "$(INTDIR)\NetChessDoc.obj"
	-@erase "$(INTDIR)\NetChessDoc.sbr"
	-@erase "$(INTDIR)\NetChessLogDlg.obj"
	-@erase "$(INTDIR)\NetChessLogDlg.sbr"
	-@erase "$(INTDIR)\NetChessView.obj"
	-@erase "$(INTDIR)\NetChessView.sbr"
	-@erase "$(INTDIR)\ObserversDlg.obj"
	-@erase "$(INTDIR)\ObserversDlg.sbr"
	-@erase "$(INTDIR)\Options.obj"
	-@erase "$(INTDIR)\Options.sbr"
	-@erase "$(INTDIR)\PGNDlg.obj"
	-@erase "$(INTDIR)\PGNDlg.sbr"
	-@erase "$(INTDIR)\PGNGameInfoDlg.obj"
	-@erase "$(INTDIR)\PGNGameInfoDlg.sbr"
	-@erase "$(INTDIR)\PickPieceDlg.obj"
	-@erase "$(INTDIR)\PickPieceDlg.sbr"
	-@erase "$(INTDIR)\PropertiesDlg.obj"
	-@erase "$(INTDIR)\PropertiesDlg.sbr"
	-@erase "$(INTDIR)\ServerInfoDlg.obj"
	-@erase "$(INTDIR)\ServerInfoDlg.sbr"
	-@erase "$(INTDIR)\ServerSocket.obj"
	-@erase "$(INTDIR)\ServerSocket.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\UCIEngineOptions.obj"
	-@erase "$(INTDIR)\UCIEngineOptions.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\ViewImage.obj"
	-@erase "$(INTDIR)\ViewImage.sbr"
	-@erase "$(OUTDIR)\NetChess.bsc"
	-@erase "$(OUTDIR)\NetChess2.1.exe"
	-@erase "$(OUTDIR)\NetChess2.1.ilk"
	-@erase "$(OUTDIR)\NetChess2.1.pdb"
	-@erase ".\Debug\NetChess2.1.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\NetChess.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\NetChess.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\NetChess.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AcceptDlg.sbr" \
	"$(INTDIR)\ChessBoard.sbr" \
	"$(INTDIR)\ClientSocket.sbr" \
	"$(INTDIR)\CommentDlg.sbr" \
	"$(INTDIR)\ConvertDlg.sbr" \
	"$(INTDIR)\DemoIntervalDlg.sbr" \
	"$(INTDIR)\Engine.sbr" \
	"$(INTDIR)\EngineConfigDlg.sbr" \
	"$(INTDIR)\EngineLevelDlg.sbr" \
	"$(INTDIR)\EngineLogDlg.sbr" \
	"$(INTDIR)\EnterMoveDlg.sbr" \
	"$(INTDIR)\GameStateDlg.sbr" \
	"$(INTDIR)\GameStateInfoDlg.sbr" \
	"$(INTDIR)\GoToMoveHistoryDlg.sbr" \
	"$(INTDIR)\GoToPGNGameDlg.sbr" \
	"$(INTDIR)\History.sbr" \
	"$(INTDIR)\HistoryDlg.sbr" \
	"$(INTDIR)\HowToPlayDlg.sbr" \
	"$(INTDIR)\ICSClient.sbr" \
	"$(INTDIR)\ICSConfigureDlg.sbr" \
	"$(INTDIR)\ICSWindowDlg.sbr" \
	"$(INTDIR)\LostPieceDlg.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MessageSend.sbr" \
	"$(INTDIR)\MyColorDialog.sbr" \
	"$(INTDIR)\MyColorEdit.sbr" \
	"$(INTDIR)\NetChess.sbr" \
	"$(INTDIR)\NetChessDoc.sbr" \
	"$(INTDIR)\NetChessLogDlg.sbr" \
	"$(INTDIR)\NetChessView.sbr" \
	"$(INTDIR)\ObserversDlg.sbr" \
	"$(INTDIR)\Options.sbr" \
	"$(INTDIR)\PGNDlg.sbr" \
	"$(INTDIR)\PGNGameInfoDlg.sbr" \
	"$(INTDIR)\PickPieceDlg.sbr" \
	"$(INTDIR)\PropertiesDlg.sbr" \
	"$(INTDIR)\ServerInfoDlg.sbr" \
	"$(INTDIR)\ServerSocket.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\UCIEngineOptions.sbr" \
	"$(INTDIR)\ViewImage.sbr"

"$(OUTDIR)\NetChess.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\NetChess2.1.pdb" /debug /machine:I386 /out:"$(OUTDIR)\NetChess2.1.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AcceptDlg.obj" \
	"$(INTDIR)\ChessBoard.obj" \
	"$(INTDIR)\ClientSocket.obj" \
	"$(INTDIR)\CommentDlg.obj" \
	"$(INTDIR)\ConvertDlg.obj" \
	"$(INTDIR)\DemoIntervalDlg.obj" \
	"$(INTDIR)\Engine.obj" \
	"$(INTDIR)\EngineConfigDlg.obj" \
	"$(INTDIR)\EngineLevelDlg.obj" \
	"$(INTDIR)\EngineLogDlg.obj" \
	"$(INTDIR)\EnterMoveDlg.obj" \
	"$(INTDIR)\GameStateDlg.obj" \
	"$(INTDIR)\GameStateInfoDlg.obj" \
	"$(INTDIR)\GoToMoveHistoryDlg.obj" \
	"$(INTDIR)\GoToPGNGameDlg.obj" \
	"$(INTDIR)\History.obj" \
	"$(INTDIR)\HistoryDlg.obj" \
	"$(INTDIR)\HowToPlayDlg.obj" \
	"$(INTDIR)\ICSClient.obj" \
	"$(INTDIR)\ICSConfigureDlg.obj" \
	"$(INTDIR)\ICSWindowDlg.obj" \
	"$(INTDIR)\LostPieceDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MessageSend.obj" \
	"$(INTDIR)\MyColorDialog.obj" \
	"$(INTDIR)\MyColorEdit.obj" \
	"$(INTDIR)\NetChess.obj" \
	"$(INTDIR)\NetChessDoc.obj" \
	"$(INTDIR)\NetChessLogDlg.obj" \
	"$(INTDIR)\NetChessView.obj" \
	"$(INTDIR)\ObserversDlg.obj" \
	"$(INTDIR)\Options.obj" \
	"$(INTDIR)\PGNDlg.obj" \
	"$(INTDIR)\PGNGameInfoDlg.obj" \
	"$(INTDIR)\PickPieceDlg.obj" \
	"$(INTDIR)\PropertiesDlg.obj" \
	"$(INTDIR)\ServerInfoDlg.obj" \
	"$(INTDIR)\ServerSocket.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\UCIEngineOptions.obj" \
	"$(INTDIR)\ViewImage.obj" \
	"$(INTDIR)\NetChess.res"

"$(OUTDIR)\NetChess2.1.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("NetChess.dep")
!INCLUDE "NetChess.dep"
!ELSE 
!MESSAGE Warning: cannot find "NetChess.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "NetChess - Win32 Release" || "$(CFG)" == "NetChess - Win32 Debug"
SOURCE=.\AcceptDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\AcceptDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\AcceptDlg.obj"	"$(INTDIR)\AcceptDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\ChessBoard.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\ChessBoard.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\ChessBoard.obj"	"$(INTDIR)\ChessBoard.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\ClientSocket.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\ClientSocket.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\ClientSocket.obj"	"$(INTDIR)\ClientSocket.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\CommentDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\CommentDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\CommentDlg.obj"	"$(INTDIR)\CommentDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\ConvertDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\ConvertDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\ConvertDlg.obj"	"$(INTDIR)\ConvertDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\DemoIntervalDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\DemoIntervalDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\DemoIntervalDlg.obj"	"$(INTDIR)\DemoIntervalDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\Engine.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\Engine.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\Engine.obj"	"$(INTDIR)\Engine.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\EngineConfigDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\EngineConfigDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\EngineConfigDlg.obj"	"$(INTDIR)\EngineConfigDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\EngineLevelDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\EngineLevelDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\EngineLevelDlg.obj"	"$(INTDIR)\EngineLevelDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\EngineLogDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\EngineLogDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\EngineLogDlg.obj"	"$(INTDIR)\EngineLogDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\EnterMoveDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\EnterMoveDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\EnterMoveDlg.obj"	"$(INTDIR)\EnterMoveDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\GameStateDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\GameStateDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\GameStateDlg.obj"	"$(INTDIR)\GameStateDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\GameStateInfoDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\GameStateInfoDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\GameStateInfoDlg.obj"	"$(INTDIR)\GameStateInfoDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\GoToMoveHistoryDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\GoToMoveHistoryDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\GoToMoveHistoryDlg.obj"	"$(INTDIR)\GoToMoveHistoryDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\GoToPGNGameDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\GoToPGNGameDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\GoToPGNGameDlg.obj"	"$(INTDIR)\GoToPGNGameDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\History.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\History.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\History.obj"	"$(INTDIR)\History.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\HistoryDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\HistoryDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\HistoryDlg.obj"	"$(INTDIR)\HistoryDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\HowToPlayDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\HowToPlayDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\HowToPlayDlg.obj"	"$(INTDIR)\HowToPlayDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\ICSClient.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\ICSClient.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\ICSClient.obj"	"$(INTDIR)\ICSClient.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\ICSConfigureDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\ICSConfigureDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\ICSConfigureDlg.obj"	"$(INTDIR)\ICSConfigureDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\ICSWindowDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\ICSWindowDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\ICSWindowDlg.obj"	"$(INTDIR)\ICSWindowDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\LostPieceDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\LostPieceDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\LostPieceDlg.obj"	"$(INTDIR)\LostPieceDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\MessageSend.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\MessageSend.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\MessageSend.obj"	"$(INTDIR)\MessageSend.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\MyColorDialog.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\MyColorDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\MyColorDialog.obj"	"$(INTDIR)\MyColorDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\MyColorEdit.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\MyColorEdit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\MyColorEdit.obj"	"$(INTDIR)\MyColorEdit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\NetChess.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\NetChess.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\NetChess.obj"	"$(INTDIR)\NetChess.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\hlp\NetChess.hpj

!IF  "$(CFG)" == "NetChess - Win32 Release"

!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

OutDir=.\Debug
InputPath=.\hlp\NetChess.hpj
InputName=NetChess

"$(INTDIR)\NetChess2.1.hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
<< 
	

!ENDIF 

SOURCE=.\NetChess.rc

"$(INTDIR)\NetChess.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\NetChessDoc.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\NetChessDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\NetChessDoc.obj"	"$(INTDIR)\NetChessDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\NetChessLogDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\NetChessLogDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\NetChessLogDlg.obj"	"$(INTDIR)\NetChessLogDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\NetChessView.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\NetChessView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\NetChessView.obj"	"$(INTDIR)\NetChessView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\ObserversDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\ObserversDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\ObserversDlg.obj"	"$(INTDIR)\ObserversDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\Options.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\Options.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\Options.obj"	"$(INTDIR)\Options.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\PGNDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\PGNDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\PGNDlg.obj"	"$(INTDIR)\PGNDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\PGNGameInfoDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\PGNGameInfoDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\PGNGameInfoDlg.obj"	"$(INTDIR)\PGNGameInfoDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\PickPieceDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\PickPieceDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\PickPieceDlg.obj"	"$(INTDIR)\PickPieceDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\PropertiesDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\PropertiesDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\PropertiesDlg.obj"	"$(INTDIR)\PropertiesDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\ServerInfoDlg.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\ServerInfoDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\ServerInfoDlg.obj"	"$(INTDIR)\ServerInfoDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\ServerSocket.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\ServerSocket.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\ServerSocket.obj"	"$(INTDIR)\ServerSocket.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\NetChess.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\NetChess.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\NetChess.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\NetChess.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\UCIEngineOptions.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\UCIEngineOptions.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\UCIEngineOptions.obj"	"$(INTDIR)\UCIEngineOptions.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 

SOURCE=.\ViewImage.cpp

!IF  "$(CFG)" == "NetChess - Win32 Release"


"$(INTDIR)\ViewImage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ELSEIF  "$(CFG)" == "NetChess - Win32 Debug"


"$(INTDIR)\ViewImage.obj"	"$(INTDIR)\ViewImage.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\NetChess.pch"


!ENDIF 


!ENDIF 

