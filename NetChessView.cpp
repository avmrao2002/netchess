// NetChessView.cpp : implementation of the CNetChessView class
//

#include "stdafx.h"
#include <afxinet.h>
#include "NetChess.h"
#include "Options.h"
#include "ChessBoard.h"
#include "ServerInfoDlg.h"
#include "ServerSocket.h"
#include "ClientSocket.h"
#include "MessageSend.h"
#include "History.h"
#include "HistoryDlg.h"
#include "PickPieceDlg.h"
#include "PropertiesDlg.h"
#include "MainFrm.h"
#include "LostPieceDlg.h"
#include "DemoIntervalDlg.h"
#include "NetChessDoc.h"
#include "NetChessView.h"
#include "HowToPlayDlg.h"
#include "PGNDlg.h"
#include "GoToMoveHistoryDlg.h"
#include "GoToPGNGameDlg.h"
#include "PGNGameInfoDlg.h"
#include "ObserversDlg.h"
#include "ConvertDlg.h"
#include "CommentDlg.h"
#include "ViewImage.h"
#include "EngineLogDlg.h"
#include "NetChessLogDlg.h"
#include "UCIEngineOptions.h"
#include "EngineLevelDlg.h"
#include "EnterMoveDlg.h"
#include "ICSConfigureDlg.h"
#include "ICSWindowDlg.h"
#include "ICSPlayersListDlg.h"
#include "MailFromDlg.h"
#include "MailToDlg.h"
#include "smtp.h"
#include "pop3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int Globalfirsttime = 0;		

CString tempString ; //going in unconventional way
/////////////////////////////////////////////////////////////////////////////
// CNetChessView
void writeMessage(char *str,...);
IMPLEMENT_DYNCREATE(CNetChessView, CView)

BEGIN_MESSAGE_MAP(CNetChessView, CView)
	//{{AFX_MSG_MAP(CNetChessView)
	ON_COMMAND(ID_EDIT_OPTIONS, OnEditOptions)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_TOOLS_CLIENT, OnToolsClient)
	ON_COMMAND(ID_TOOLS_SERVER, OnToolsServer)
	ON_COMMAND(ID_TOOLS_SENDMESSAGE, OnToolsSendmessage)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_VIEW_LETTER, OnViewLetter)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LETTER, OnUpdateViewLetter)
	ON_COMMAND(ID_VIEW_NUMBER, OnViewNumber)
	ON_UPDATE_COMMAND_UI(ID_VIEW_NUMBER, OnUpdateViewNumber)
	ON_COMMAND(ID_FILE_SAVEHISTORY, OnFileSavehistory)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_COMMAND(ID_EDIT_REDO, OnEditRedo)
	ON_WM_RBUTTONDOWN()
	ON_UPDATE_COMMAND_UI(ID_TOOLS_SERVER, OnUpdateToolsServer)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_CLIENT, OnUpdateToolsClient)
	ON_WM_TIMER()
	ON_COMMAND(ID_VIEW_HISTORY, OnViewHistory)
	ON_COMMAND(ID_TOOLS_WHITEONTOP, OnToolsWhiteontop)
	ON_COMMAND(ID_EDIT_MOVEFIRST, OnEditMovefirst)
	ON_COMMAND(ID_EDIT_MOVELAST, OnEditMovelast)
	ON_COMMAND(ID_HELP_HOWTOPLAY, OnHelpHowtoplay)
	ON_COMMAND(ID_TOOLS_DISCONNECT, OnToolsDisconnect)
	ON_COMMAND(D_EDIT_PROPERTIES, OnEditProperties)
	ON_COMMAND(ID_TOOLS_DRAW, OnToolsDraw)
	ON_COMMAND(ID_TOOLS_RESIGN, OnToolsResign)
	ON_COMMAND(ID_VIEW_LOSTPIECES, OnViewLostpieces)
	ON_COMMAND(ID_FILE_FEED, OnFileFeed)
	ON_COMMAND(ID_TOOLS_LEARN, OnToolsLearn)
	ON_COMMAND(ID_EDIT_SETBOARD, OnEditSetboard)
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_EDIT_CHECKMOVE, OnEditCheckmove)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CHECKMOVE, OnUpdateEditCheckmove)
	ON_COMMAND(ID_EDIT_MANUALEDIT_EMPTY, OnEditManualeditEmpty)
	ON_COMMAND(ID_EDIT_MANUALEDIT_END, OnEditManualeditEnd)
	ON_COMMAND(ID_EDIT_MANUALEDIT_PLAYERTURN, OnEditManualeditPlayerturn)
	ON_COMMAND(ID_EDIT_MANUALEDIT_START, OnEditManualeditStart)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MANUALEDIT_START, OnUpdateEditManualeditStart)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MANUALEDIT_EMPTY, OnUpdateEditManualeditEmpty)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MANUALEDIT_PLAYERTURN, OnUpdateEditManualeditPlayerturn)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MOVEFIRST, OnUpdateEditMovefirst)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MOVELAST, OnUpdateEditMovelast)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, OnUpdateEditRedo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DEMO, OnUpdateViewDemo)
	ON_COMMAND(ID_FILE_SUBMITPGNDATA, OnFileSubmitpgndata)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_VIEW_DEMO_PAUSE, OnViewDemoPause)
	ON_COMMAND(ID_VIEW_DEMO_START, OnViewDemoStart)
	ON_COMMAND(ID_VIEW_DEMO_STOP, OnViewDemoStop)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DEMO_PAUSE, OnUpdateViewDemoPause)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DEMO_START, OnUpdateViewDemoStart)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DEMO_STOP, OnUpdateViewDemoStop)
	ON_COMMAND(ID_VIEW_DEMO_GOTO, OnViewDemoGoto)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_GOTOPGNGAME, OnFileGotopgngame)
	ON_COMMAND(ID_FILE_LOADFIRSTGAME, OnFileLoadfirstgame)
	ON_COMMAND(ID_FILE_LOADNEXTGAME, OnFileLoadnextgame)
	ON_COMMAND(ID_FILE_OPENPGNFILE, OnFileOpenpgnfile)
	ON_COMMAND(ID_FILE_RELOADTHEPGNGAME, OnFileReloadthepgngame)
	ON_COMMAND(ID_FILE_LOADPREVPGNGAME, OnFileLoadprevpgngame)
	ON_COMMAND(ID_EDIT_GAMEINFO, OnEditGameinfo)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_VIEW_FLIPBOARD, OnViewFlipboard)
	ON_COMMAND(ID_EDIT_MANUALEDIT_PAUSECLOCK, OnEditManualeditPauseclock)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MANUALEDIT_PAUSECLOCK, OnUpdateEditManualeditPauseclock)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_UPDATE_COMMAND_UI(ID_FILE_GOTOPGNGAME, OnUpdateFileGotopgngame)
	ON_UPDATE_COMMAND_UI(ID_FILE_LOADFIRSTGAME, OnUpdateFileLoadfirstgame)
	ON_UPDATE_COMMAND_UI(ID_FILE_LOADNEXTGAME, OnUpdateFileLoadnextgame)
	ON_UPDATE_COMMAND_UI(ID_FILE_LOADPREVPGNGAME, OnUpdateFileLoadprevpgngame)
	ON_UPDATE_COMMAND_UI(ID_FILE_OPEN, OnUpdateFileOpen)
	ON_UPDATE_COMMAND_UI(ID_FILE_OPENPGNFILE, OnUpdateFileOpenpgnfile)
	ON_UPDATE_COMMAND_UI(ID_FILE_RELOADTHEPGNGAME, OnUpdateFileReloadthepgngame)
	ON_UPDATE_COMMAND_UI(ID_FILE_SUBMITPGNDATA, OnUpdateFileSubmitpgndata)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_DRAW, OnUpdateToolsDraw)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_RESIGN, OnUpdateToolsResign)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DEMO_GOTO, OnUpdateViewDemoGoto)
	ON_COMMAND(ID_FILE_SAVEBOARD, OnFileSaveboard)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVEBOARD, OnUpdateFileSaveboard)
	ON_COMMAND(ID_VIEW_OBSERVERSLIST, OnViewObserverslist)
	ON_UPDATE_COMMAND_UI(ID_VIEW_OBSERVERSLIST, OnUpdateViewObserverslist)
	ON_COMMAND(ID_FILE_CONVERT, OnFileConvert)
	ON_COMMAND(ID_EDIT_COMMENT, OnEditComment)
	ON_UPDATE_COMMAND_UI(ID_FILE_CONVERT, OnUpdateFileConvert)
	ON_COMMAND(ID_FILE_LOADLASTGAME, OnFileLoadlastgame)
	ON_UPDATE_COMMAND_UI(ID_FILE_LOADLASTGAME, OnUpdateFileLoadlastgame)
	ON_COMMAND(ID_EDIT_COPYEPD, OnEditCopyepd)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPYFEN, OnUpdateEditCopyfen)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPYEPD, OnUpdateEditCopyepd)
	ON_COMMAND(ID_EDIT_COPYFEN, OnEditCopyfen)
	ON_COMMAND(ID_VIEW_IMAGE, OnViewImage)
	ON_COMMAND(ID_EDIT_COPYEPDPOSITION, OnEditCopyepdposition)
	ON_COMMAND(ID_EDIT_COPYFENPOSITION, OnEditCopyfenposition)
	ON_COMMAND(ID_VIEW_LOG, OnViewLog)	
	ON_COMMAND(ID_FILE_NEWGAME, OnFileNewgame)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEWGAME, OnUpdateFileNewgame)
	ON_COMMAND(ID_TOOLS_BLACKENGINE_CLOSE, OnToolsBlackengineClose)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_BLACKENGINE_CLOSE, OnUpdateToolsBlackengineClose)
	ON_COMMAND(ID_TOOLS_BLACKENGINE_CONFIGURE, OnToolsBlackengineConfigure)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_BLACKENGINE_CONFIGURE, OnUpdateToolsBlackengineConfigure)
	ON_COMMAND(ID_TOOLS_BLACKENGINE_LOAD, OnToolsBlackengineLoad)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_BLACKENGINE_LOAD, OnUpdateToolsBlackengineLoad)
	ON_COMMAND(ID_TOOLS_BLACKENGINE_LOG, OnToolsBlackengineLog)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_BLACKENGINE_LOG, OnUpdateToolsBlackengineLog)
	ON_COMMAND(ID_TOOLS_BLACKENGINE_MOVENOW, OnToolsBlackengineMovenow)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_BLACKENGINE_MOVENOW, OnUpdateToolsBlackengineMovenow)
	ON_COMMAND(ID_TOOLS_BLACKENGINE_SETTINGS_BLACKASENGINE, OnToolsBlackengineSettingsBlackasengine)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_BLACKENGINE_SETTINGS_BLACKASENGINE, OnUpdateToolsBlackengineSettingsBlackasengine)
	ON_COMMAND(ID_TOOLS_BLACKENGINE_START, OnToolsBlackengineStart)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_BLACKENGINE_START, OnUpdateToolsBlackengineStart)
	ON_COMMAND(ID_TOOLS_BLACKENGINE_STOP, OnToolsBlackengineStop)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_BLACKENGINE_STOP, OnUpdateToolsBlackengineStop)
	ON_COMMAND(ID_TOOLS_WHITEENGINE_CLOSE, OnToolsWhiteengineClose)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_WHITEENGINE_CLOSE, OnUpdateToolsWhiteengineClose)
	ON_COMMAND(ID_TOOLS_WHITEENGINE_CONFIGURE, OnToolsWhiteengineConfigure)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_WHITEENGINE_CONFIGURE, OnUpdateToolsWhiteengineConfigure)
	ON_COMMAND(ID_TOOLS_WHITEENGINE_LOAD, OnToolsWhiteengineLoad)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_WHITEENGINE_LOAD, OnUpdateToolsWhiteengineLoad)
	ON_COMMAND(ID_TOOLS_WHITEENGINE_LOG, OnToolsWhiteengineLog)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_WHITEENGINE_LOG, OnUpdateToolsWhiteengineLog)
	ON_COMMAND(ID_TOOLS_WHITEENGINE_MOVENOW, OnToolsWhiteengineMovenow)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_WHITEENGINE_MOVENOW, OnUpdateToolsWhiteengineMovenow)
	ON_COMMAND(ID_TOOLS_WHITEENGINE_SETTINGS_WHITEASENGINE, OnToolsWhiteengineSettingsWhiteasengine)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_WHITEENGINE_SETTINGS_WHITEASENGINE, OnUpdateToolsWhiteengineSettingsWhiteasengine)
	ON_COMMAND(ID_TOOLS_WHITEENGINE_START, OnToolsWhiteengineStart)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_WHITEENGINE_START, OnUpdateToolsWhiteengineStart)
	ON_COMMAND(ID_TOOLS_WHITEENGINE_STOP, OnToolsWhiteengineStop)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_WHITEENGINE_STOP, OnUpdateToolsWhiteengineStop)
	ON_COMMAND(ID_WHITEENGINE_PONDER, OnWhiteenginePonder)
	ON_UPDATE_COMMAND_UI(ID_WHITEENGINE_PONDER, OnUpdateWhiteenginePonder)
	ON_COMMAND(ID_BLACKENGINE_PONDOR, OnBlackenginePondor)
	ON_UPDATE_COMMAND_UI(ID_BLACKENGINE_PONDOR, OnUpdateBlackenginePondor)
	ON_COMMAND(ID_EDIT_LEVELS, OnEditLevels)
	ON_UPDATE_COMMAND_UI(ID_EDIT_LEVELS, OnUpdateEditLevels)
	ON_COMMAND(ID_WHITEENGINE_ANALYZE, OnWhiteengineAnalyze)
	ON_UPDATE_COMMAND_UI(ID_WHITEENGINE_ANALYZE, OnUpdateWhiteengineAnalyze)
	ON_COMMAND(ID_BLACKENGINE_ANALYZE, OnBlackengineAnalyze)
	ON_UPDATE_COMMAND_UI(ID_BLACKENGINE_ANALYZE, OnUpdateBlackengineAnalyze)
	ON_COMMAND(ID_WHITEENGINE_DEFAULT, OnWhiteengineDefault)
	ON_UPDATE_COMMAND_UI(ID_WHITEENGINE_DEFAULT, OnUpdateWhiteengineDefault)
	ON_COMMAND(ID_BLACKENGINE_DEFAULT, OnBlackengineDefault)
	ON_UPDATE_COMMAND_UI(ID_BLACKENGINE_DEFAULT, OnUpdateBlackengineDefault)
	ON_COMMAND(ID_EDIT_GAMESTATE, OnEditGamestate)
	ON_COMMAND(ID_BLACKENGINE_RELOAD, OnBlackengineReload)
	ON_UPDATE_COMMAND_UI(ID_BLACKENGINE_RELOAD, OnUpdateBlackengineReload)
	ON_COMMAND(ID_WHITEENGINE_RELOAD, OnWhiteengineReload)
	ON_UPDATE_COMMAND_UI(ID_WHITEENGINE_RELOAD, OnUpdateWhiteengineReload)
	ON_COMMAND(ID_TOOLS_AREYOUOK, OnToolsAreyouok)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_AREYOUOK, OnUpdateToolsAreyouok)
	ON_COMMAND(ID_VIEW_LEARNING, OnViewLearning)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LEARNING, OnUpdateViewLearning)
	ON_COMMAND(ID_EDIT_ENTERMOVE, OnEditEntermove)
	ON_COMMAND(ID_ICS_CONFIGURE, OnIcsConfigure)
	ON_COMMAND(ID_ICS_WINDOW, OnIcsWindow)
	ON_COMMAND(ID_HELP_HTTPWWWGEOCITIESCOMRAOAVM, OnHelpHttpwwwgeocitiescomraoavm)
	ON_COMMAND(ID_WHITEENGINE_SETBOARD, OnWhiteengineSetboard)
	ON_COMMAND(ID_BLACKENGINE_SETBOARD, OnBlackengineSetboard)
	ON_UPDATE_COMMAND_UI(ID_WHITEENGINE_SETBOARD, OnUpdateWhiteengineSetboard)
	ON_UPDATE_COMMAND_UI(ID_BLACKENGINE_SETBOARD, OnUpdateBlackengineSetboard)
	ON_COMMAND(ID_WHITEENGINE_ONLYANALYZE, OnWhiteengineOnlyanalyze)
	ON_UPDATE_COMMAND_UI(ID_WHITEENGINE_ONLYANALYZE, OnUpdateWhiteengineOnlyanalyze)
	ON_COMMAND(ID_BLACKENGINE_ONLYANALYZE, OnBlackengineOnlyanalyze)
	ON_UPDATE_COMMAND_UI(ID_BLACKENGINE_ONLYANALYZE, OnUpdateBlackengineOnlyanalyze)
	ON_COMMAND(ID_ICS_SEEKLIST, OnIcsSeeklist)
	ON_COMMAND(ID_EDIT_TIMECONTROL, OnEditTimecontrol)
	ON_UPDATE_COMMAND_UI(ID_ICS_CONFIGURE, OnUpdateIcsConfigure)
	ON_WM_SHOWWINDOW()
	ON_COMMAND(ID_ICS_CHAT, OnIcsChat)
	ON_COMMAND(ID_EDIT_PROPERTIES, OnEditProperties)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	//ON_MESSAGE(ID_MY_MESSAGE_COLORDATA,OnMessageColorData)
	//ON_MESSAGE(WM_COMMAND,OnCommand)
	//ON_MESSAGE(ID_MY_MESSAGE_ENGINE,OnMyEngineMessage)

		ON_COMMAND(59, OnViewReplayAll)
		ON_UPDATE_COMMAND_UI(59, OnUpdateReplayAll)
		END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetChessView construction/destruction

CNetChessView::CNetChessView()
{
	// TODO: add construction code here
	m_mouseMoveFlag = false;
	m_moveRect =0;
	m_pClientSocket = NULL;
	m_pServerSocket = NULL;
	m_pClientICSSocket = NULL;
	m_iHistory = -1;
	m_LetterFlag = true;
	m_NumberFlag = true;
	m_white_on_top = false;
	m_player_turn = true;
	m_topHistory = -1;
	m_timerFlag = false;
	m_squareWidth = 40;
	m_pieceSide = WHITE;
	m_blackTime = m_whiteTime = m_engineLevelDlg.m_edit_time_control == 0? 5*60: m_engineLevelDlg.m_edit_time_control*60;
	m_elapsedTime =  0;
	m_startTime = (int)time(0);
	m_movedFromRect.left = -1;
	m_movedToRect.left = -1;
	m_blackKingMovedFlag = false;
	m_whiteKingMovedFlag = false;
	m_blackRookRank1MovedFlag = false;
	m_whiteRookRank1MovedFlag = false;
	m_blackRookRank7MovedFlag = false;
	m_whiteRookRank7MovedFlag = false;
//	m_SpecialAction = NOTHING;
	m_ChatDlg = NULL;
	m_pMailFromDlg = NULL;
	m_pMailToDlg = NULL;
	m_icsChatDlg = NULL;
	m_pickPieceDlg = NULL;
	m_checkmove = TRUE;
	m_manualEditingFlag = TRUE;
	m_demoFlag = FALSE;
	m_pauseFlag = FALSE;
	m_checkmove = TRUE;
	m_fileName = "";
	m_moveFlag = FALSE;
	m_pauseclockFlag = TRUE;
	m_observerFlag = FALSE;
	m_convertFlag = FALSE;
	m_learningFlag = FALSE;
	m_halfMoveCount = 0;
	m_ICSToBoardFlag = FALSE;
	m_BoardToICSFlag = FALSE;
	m_mailClientFlag = FALSE;
//	m_PGNEvent = m_PGNSite = m_PGNDate = m_PGNRound = m_PGNWhite = m_PGNBlack = m_PGNResult = m_FENString = "";
	//setup board
	int xstart = 30;
	int ystart = 30;
	int x,y=ystart;
	for ( int i = 0; i < 8; i++)
	{
		x = xstart;
		for( int j = 0; j < 8; j++)
		{
			CRect rect(x,y, x+ m_squareWidth, y+m_squareWidth);

			cb[i][j].SetRect(rect);
			cb[i][j].SetPieceType(BLANK);			 
			cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			 
			x += m_squareWidth;
		}
		y += m_squareWidth;
	}
	COLOR_TYPE typex = BLACK;
	 
	for(int i = 0; i< 8; i++)
	{
		if(typex == WHITE)
			typex = BLACK;
		else
			typex = WHITE;
		COLOR_TYPE type = typex;
		for(int j=0; j < 8; j++)
		{
			
			cb[i][j].SetColorType(type);
			if(type == WHITE)
				type = BLACK;
			else
				type = WHITE;
		}
	}	
	//set up Lost piece window
	xstart = 0;//375;//8*40+30+10(buffer)
	ystart = 60;//265;//6*40+30+10
	x=xstart,y=ystart;
	for (int i = 8; i < 12; i++)
	{
		x = xstart;
		for( int j = 8; j < 16; j++)
		{
			CRect rect(x,y, x+ m_squareWidth-13, y+m_squareWidth-13);

			cb[i][j].SetRect(rect);			
			//cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			cb[i][j].SetPieceData(ROOK_BLACK,BLACK,ROOK,PIECE_NOT_MOVING);
			 
			x += (m_squareWidth-13);
		}
		y += (m_squareWidth-13);
	}
	//read configuration parameters from NetChess.ini
	char defaultBuf[40]="default";
	char CurrentDir[255];
	GetWindowsDirectory(CurrentDir,MAX_PATH);
	strcat(CurrentDir,"\\NetChess.ini");	
	char data1[100];	
 	if(GetPrivateProfileString("NetChess","AutoSave",defaultBuf,data1,100,CurrentDir)>0)
	{
		if(strcmp(data1,"1") == 0)
			m_optDlg.m_check_auto_save = TRUE;
	}
	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","SaveWithComments",defaultBuf,data1,100,CurrentDir)>0)
	{
		if(strcmp(data1,"1") == 0)
			m_optDlg.m_check_save_with_history = TRUE;
	}

	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","Interval",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_edit_replay_interval = atoi(data1);
	}
	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","Log",defaultBuf,data1,100,CurrentDir)>0)
	{
		if(strcmp(data1,"1") == 0)
			m_optDlg.m_check_netchess_log = TRUE;
	}
	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","PGNMailFormat",defaultBuf,data1,100,CurrentDir)>0)
	{
		if(strcmp(data1,"1") == 0)
			m_optDlg.m_check_pgn_mail_format = TRUE;
	}
	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","ExtendedView",defaultBuf,data1,100,CurrentDir)>0)
	{
		if(strcmp(data1,"1") == 0)
		{
			m_optDlg.m_check_extended_view = TRUE;
//			((CMainFrame*)(AfxGetApp()->m_pMainWnd))->m_extendedViewFlag = TRUE;
		}
		else
		{
			m_optDlg.m_check_extended_view = FALSE;
		}
	}
	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","SaveGame",defaultBuf,data1,100,CurrentDir)>0)
	{
		if(strcmp(data1,"1") == 0)
		{
			m_optDlg.m_check_save_game = TRUE;
//			((CMainFrame*)(AfxGetApp()->m_pMainWnd))->m_extendedViewFlag = TRUE;
		}
	}

	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","BlackEngineAutoStart",defaultBuf,data1,100,CurrentDir)>0)
	{
		if(strcmp(data1,"1") == 0)
		{
			m_optDlg.m_check_black_engine_auto_start = TRUE;
		}
		else
		{
			m_optDlg.m_check_black_engine_auto_start = FALSE;
		}
	}		

	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","WhiteColor",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_crefWhiteColor = atoi(data1);
	}
	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","BlackColor",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_crefBlackColor = atoi(data1);			
	}		

	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","WhitePieceColor",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_crefWhitePieceColor = atoi(data1);
	}
	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","BlackPieceColor",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_crefBlackPieceColor = atoi(data1);			
	}		

	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","UCIMove",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_UCImove = atoi(data1);			
	}		

	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","DefaultWhiteEngine",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_edit_def_white_engine = data1;			
	}		

	
    memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","DefaultWhiteEngineProtocol",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_whiteEngineProtocol = (CHESS_PROTOCOL)atoi(data1);			
	}		

	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","DefaultBlackEngine",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_edit_def_black_engine = data1;			
	}

	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","DefaultBlackEngineProtocol",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_blackEngineProtocol = (CHESS_PROTOCOL)atoi(data1);			
	}		

	//load font details
    memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","Font",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_boardFont = atoi(data1);			
	}		

	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","FontSize",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_edit_font_size = atoi(data1);			
	}		

	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","FontFaceName",defaultBuf,data1,100,CurrentDir)>0)
	{		
		if(strcmp(data1,"default") != 0)
			m_optDlg.m_edit_font = data1;			
	}
	if(m_optDlg.m_boardFont == 2)
	{
		m_optDlg.m_font.CreatePointFont(
			m_optDlg.m_edit_font_size*10,
			m_optDlg.m_edit_font);
	}
	m_pICSWindowDlg = NULL;	
	m_pICSConfigureDlg = NULL;
	m_seekListDlg = NULL;
	m_icsFlag = FALSE;
	m_whiteEngineOnlyAnalyze = FALSE;
	m_blackEngineOnlyAnalyze = FALSE;
	m_whiteAsEngineFlag = m_blackAsEngineFlag = FALSE;
}

CNetChessView::~CNetChessView()
{
}

BOOL CNetChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView drawing

void CNetChessView::OnDraw(CDC* pDC)
{
	//CNetChessDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	DrawBoard();
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView printing

BOOL CNetChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNetChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNetChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView diagnostics

#ifdef _DEBUG
void CNetChessView::AssertValid() const
{
	CView::AssertValid();
}

void CNetChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNetChessDoc* CNetChessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNetChessDoc)));
	return (CNetChessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNetChessView message handlers

void CNetChessView::OnEditOptions() 
{
	m_optDlg.DoModal();	 
	DrawBoard();
}

void CNetChessView::DrawBoard()
{
	CClientDC dc(this);	 
	//select the standard bitmap, do all operations on that bitmap
	//and copy that bitmap to main bitmap
	CBitmap localbmp;
	localbmp.LoadBitmap(IDB_BITMAP_BASE);
	//BITMAP bp={0,1000,490,3000,1,24,0x00000000};
	//localbmp.CreateBitmapIndirect(&bp);

	CDC ldc;
	ldc.CreateCompatibleDC(&dc);
	ldc.SelectObject(&localbmp); 
	COLORREF bkcrRef(RGB(20,140,17));
	//this is background color
	COLORREF backgrndcolor(RGB(216,207,169));	 	 
	CBrush backgrndbrush(backgrndcolor);
	ldc.SelectObject(backgrndbrush);

	CRect crect;
	GetClientRect(&crect); 
	ldc.FillRect(&crect,&backgrndbrush);
	//If convertion is in progress do not show the board	
	if(m_convertFlag == TRUE)
	{	
		ShowConvertMessage(ldc);		
		return;
	}
	m_listctrl_movehistory.ShowWindow(SW_SHOW);
//	COLORREF bkcrRef;

	COLORREF redcr(RGB(205,177,207));
	CBrush redbrush;
	redbrush.CreateSolidBrush(redcr);
	
	COLORREF redbluecr(RGB(192,192,192));
	CBrush redbluebrush;
	redbluebrush.CreateSolidBrush(redbluecr);

	CBrush* pbrush = ldc.SelectObject(&redbluebrush);
	//this is the main window resolution for extended view , it is widh 211 and hight 31, not non-extended view, it is 
	if(((CMainFrame*)(AfxGetApp()->m_pMainWnd))->m_extendedViewFlag == TRUE)
	{
		ldc.Rectangle(crect.left + 4, crect.top + 4,
		crect.right - 215, crect.bottom - 35);
	}
	else
	{
		ldc.Rectangle(crect.left + 4, crect.top + 4,
			crect.right - 4, crect.bottom - 4);
	}

	 
	COLORREF bluecr(RGB(205,177,207));
	CBrush bluebrush;
	bluebrush.CreateSolidBrush(bluecr);

	COLORREF greencr(RGB(0,255,0));
	CBrush greenbrush;
	greenbrush.CreateSolidBrush(greencr);

	ldc.SelectObject(bluebrush);
	if(((CMainFrame*)(AfxGetApp()->m_pMainWnd))->m_extendedViewFlag == TRUE)
	{
		ldc.Rectangle(crect.left +21, crect.top +21,
			crect.right - 232, crect.bottom -55);
	}
	else
	{
		ldc.Rectangle(crect.left +21, crect.top +21,
			crect.right - 21, crect.bottom -21);
	}

	pbrush =  ldc.SelectObject(&redbluebrush);

	//Draw the board
	for(int i = 0; i < 8; i++)
	{
		for( int j = 0; j < 8; j++)
		{
			CRect rect = cb[i][j].GetRect();
			//draw for black squares  
			if(cb[i][j].GetColorType() == BLACK)
			{
				CPoint pt(m_moveRect.left+25,m_moveRect.top+25);
				if(rect.PtInRect(pt) == TRUE)
				{
					bkcrRef = m_optDlg.m_crefBlackColor;
				}
				FillBorder(ldc, rect, BLACK);
			}
			else if(cb[i][j].GetColorType() == WHITE)
			{
				CPoint pt(m_moveRect.left+25,m_moveRect.top+25);
				if(rect.PtInRect(pt) == TRUE)
				{
					bkcrRef = m_optDlg.m_crefWhiteColor ;
				}
				FillBorder(ldc, rect, WHITE);
			}
			//Draw board piece on each square
			if(DrawEachPiece(ldc, i, j) < 0)
				break;

			if(m_learningFlag == TRUE)
			{
				CRect rect2 = cb[i][j].GetRect();
				if(cb[i][j].GetLearningFlg() == TRUE)
				{
					CRect rect3(rect2.left+15,rect2.top+15,rect2.right-15,rect2.bottom-15);
					COLORREF cr(RGB(255,0,0));
					CBrush br(cr);
					ldc.FillRect(rect3,&br);
				}
			}
		}	
	}
	//draw coordinate system a to h and 1 to 8
	DrawCoordinateSystem(&ldc);	

	//draw moving piece
	//ldc.ExcludeClipRect(crect);
	DrawMovingPiece(&ldc, bkcrRef);	
	//ldc.ExcludeClipRect(crect);
	
	dc.BitBlt(0,0,377,400,&ldc,0,0,SRCCOPY);
	DrawInExtendedView(&dc);	
}

int CNetChessView::DrawEachPiece(CDC &ldc, int i, int j)
{
	CRect rect = cb[i][j].GetRect();

	if(cb[i][j].GetPieceType() != BLANK && cb[i][j].GetPieceState() != PIECE_MOVING)
	{
		int piece_id;
		COLOR_TYPE  piece_color;
		PIECE_TYPE  piece_type;
		STATE piece_state;
		cb[i][j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
		if(piece_id <= 0)
		{
			return -1;
		}
		//Draw board based on the font
		if(m_optDlg.m_boardFont == 1)
		{
			CBitmap bitmap;			
			bitmap.LoadBitmap(GetBitmapId(piece_id));			 
			CDC bmpdc;
			bmpdc.CreateCompatibleDC(&ldc);
			bmpdc.SelectObject(&bitmap); 

			BITMAP bmp;
			bitmap.GetBitmap(&bmp);
		
			ldc.StretchBlt(rect.left+7,rect.top+7,m_squareWidth -15,m_squareWidth-15,&bmpdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY); 
		}
		else
		{					
			CString piece;
			if(GetPieceString(piece_id,piece) == 0)
			{
				
				CFont *fnt = ldc.SelectObject(&m_optDlg.m_font);
				/*CRgn rgn;
				rgn.CreateRectRgn(rect.left,rect.top,rect.right,rect.bottom);
				
				ldc.SetPolyFillMode(WINDING);
				COLORREF white(RGB(255,255,255)), black(RGB(0,0,0));				
				CBrush brush(white);
				ldc.FillRgn(&rgn,&brush);*/
				//ldc.SetTextColor(piece_color == WHITE? white : black);
				ldc.SetBkMode(TRANSPARENT);
				ldc.SetTextColor(piece_color == WHITE ? m_optDlg.m_crefWhitePieceColor : m_optDlg.m_crefBlackPieceColor);
				
				ldc.DrawText(piece,rect,DT_CENTER | DT_VCENTER);
				//ldc.FillPath();
				ldc.SelectObject(fnt);
				//writeMessage("left %d top %d right %d bottom %d",rect.left,rect.top,rect.right,rect.bottom);
			}
		}				
	}
	return 0;
}

void CNetChessView::FillBorder(CDC& ldc, CRect rect, COLOR_TYPE ct)
{
	COLORREF cr;
	ct == WHITE ? cr = m_optDlg.m_crefWhiteColor : cr = m_optDlg.m_crefBlackColor;	
	CBrush brush(cr);

		if(m_movedFromRect == rect || m_movedToRect == rect)
		{
			COLORREF cr1(RGB(0,0,255));
			ldc.SetBkColor(cr1);
			CBrush brush1(cr1);					 
			ldc.SelectObject(brush1); 
			ldc.FillRect(&rect,&brush1);
			CRect rect1(rect.left+5, rect.top + 5, rect.right -5, rect.bottom -5);
	
			ldc.SetBkColor(cr);
			ldc.SelectObject(brush); 
			ldc.FillRect(&rect1,&brush);
			//m_movedFromRect.left = -1;

		}
		/*else if(m_movedToRect == rect)
		{
			COLORREF cr1(RGB(0,0,255));
			ldc.SetBkColor(cr1);
			CBrush brush1(cr1);					 
			ldc.SelectObject(brush1); 
			ldc.FillRect(&rect,&brush1);
			CRect rect1(rect.left+2, rect.top + 2, rect.right -2, rect.bottom -2);
			CBrush brush(m_optDlg.m_crefBlackColor);
			ldc.SetBkColor(m_optDlg.m_crefBlackColor);
			ldc.SelectObject(brush); 
			ldc.FillRect(&rect1,&brush);
		}*/
		else
		{
			
			ldc.SetBkColor(cr);
			ldc.SelectObject(brush); 
			ldc.FillRect(&rect,&brush);
		}
}

void CNetChessView::ShowConvertMessage(CDC &dc)
{
		m_listctrl_movehistory.ShowWindow(SW_HIDE);
		CDC ldc;
		CBitmap localbmp;
		localbmp.LoadBitmap(IDB_BITMAP_BASE);
		ldc.CreateCompatibleDC(&dc);
		ldc.SelectObject(&localbmp); 
		COLORREF backgrndcolor(RGB(255,255,255));	 	 
		CBrush backgrndbrush(backgrndcolor);
		ldc.SelectObject(backgrndbrush);
		CRect crect;
		GetClientRect(&crect); 
		ldc.FillRect(&crect,&backgrndbrush);		
		
		ldc.TextOut(10,150,"Chess format convertion is in progress. This will take several minutes, please wait!");
		CString str;
		int total = m_PGNFileData.GetSize();	
		str.Format("Converting %d/%d game",m_PGNFileIndex,total);
		ldc.TextOut(10,180,str);
		dc.BitBlt(0,0,600,600,&ldc,0,0,SRCCOPY);
}

void CNetChessView::DrawMovingPiece(CDC* ldc, COLORREF bkcrRef)
{
	if(m_mouseMoveFlag == true && cb[m_point.x][m_point.y].GetPieceId() > -1)
	{
		CRect rect = m_moveRect;
		int piece_id;
		ldc->SetBkColor(bkcrRef);
		//ldc->SetBkColor(OPAQUE);
		//Fill rectangle according to the color
		//Fill the color of the left top

		//Fill the color of the left bottom
		//Fill the color of the right top
		//Fill the color of the right bottom
		
		//ldc->DraText("N"		
		/*CPoint pt(m_moveRect.left,m_moveRect.top);
		COLOR_TYPE ct;
		CRect rect1;
		if(ChessPtInBoard(pt,ct, rect1) == TRUE)
		{
			CRect newrect(m_moveRect.left, m_moveRect.top,rect1.right,rect1.bottom);			
			FillBorder(*ldc,newrect,ct);
		}

		CPoint pt1(m_moveRect.right,m_moveRect.top);
		if(ChessPtInBoard(pt1,ct, rect1) == TRUE)
		{
			CRect newrect(rect1.left, m_moveRect.top,m_moveRect.right,rect1.bottom);			
			FillBorder(*ldc,newrect,ct);
		}				

		CPoint pt2(m_moveRect.left,m_moveRect.bottom);
		if(ChessPtInBoard(pt2,ct, rect1) == TRUE)
		{
			CRect newrect(m_moveRect.left, rect1.top,rect1.right,m_moveRect.bottom);			
			FillBorder(*ldc,newrect,ct);
		}				

		CPoint pt3(m_moveRect.right,m_moveRect.bottom);
		if(ChessPtInBoard(pt3,ct, rect1) == TRUE)
		{
			CRect newrect(rect1.left, rect1.top,m_moveRect.right,m_moveRect.bottom);			
			FillBorder(*ldc,newrect,ct);
		}*/			
		
		
		COLOR_TYPE  piece_color;
		PIECE_TYPE  piece_type;
		STATE piece_state;
		cb[m_point.x][m_point.y].GetPieceData(piece_id,piece_color,piece_type,piece_state);	
		//CBitmap bitmap;
		//bitmap.LoadBitmap(piece_id);
		int id = GetBitmapId(piece_id);
		if( id  > 0)
		{
				//Draw board based on the font
				
				if(m_optDlg.m_boardFont == 1)
				{
					CBitmap bitmap;			
					bitmap.LoadBitmap(GetBitmapId(piece_id));			 
					CDC bmpdc;
					bmpdc.CreateCompatibleDC(ldc);
					bmpdc.SelectObject(&bitmap); 

					BITMAP bmp;
					bitmap.GetBitmap(&bmp);
				
					ldc->StretchBlt(rect.left+7,rect.top+7,m_squareWidth -15,m_squareWidth-15,&bmpdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY); 
					
				}
				else
				{					
					CString piece;
					if(GetPieceString(piece_id,piece) == 0)
					{				
						//CRect rct(rect.left+10,rect.top+10,rect.right-10,rect.bottom-10);
						ldc->SetBkMode(TRANSPARENT);
						CFont *fnt = ldc->SelectObject(&m_optDlg.m_font);
						ldc->SetTextColor(piece_color == WHITE ? m_optDlg.m_crefWhitePieceColor : m_optDlg.m_crefBlackPieceColor);
						ldc->DrawText(piece,rect,0);//DT_CENTER | DT_VCENTER);
						//COLORREF white(RGB(255,255,255)), black(RGB(0,0,0));
						//ldc->SetBkColor(TRANSPARENT);
						//ldc->SetTextColor(piece_color == WHITE? white : black);
						//ldc->TextOut(rect.left+5,rect.top+5,piece);
						ldc->SelectObject(fnt);
					}
				}

			//bitmap.LoadBitmap(GetBitmapId(piece_id));
			//CDC bmpdc;
			//bmpdc.CreateCompatibleDC(&ldc);
			//bmpdc.SelectObject(&bitmap); 
			//bmpdc.SelectObject(&bkcrRef);

			//BITMAP bmp;
			//bitmap.GetBitmap(&bmp);		 
			//ldc.StretchBlt(rect.left+7,rect.top+7,m_squareWidth-15,m_squareWidth-15,&bmpdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY); 
			
		}
	}	
}
int CNetChessView::ChessPtInBoard(CPoint point, COLOR_TYPE &sqcolor, CRect &rect )
{
	for(int i = 0; i < 8; i++)
	{
		for( int j = 0; j < 8; j++)
		{
			CRgn rgn;
			rect = cb[i][j].GetRect();
			rgn.CreateRectRgn(rect.left, rect.top, rect.right, rect.bottom);
			if(rgn.PtInRegion(point))
			{
				sqcolor = cb[i][j].GetColorType();
				return TRUE;	 
			}
		}
	}
	return FALSE;
}

void CNetChessView::DrawInExtendedView(CDC *dc)
{
	if(((CMainFrame*)(AfxGetApp()->m_pMainWnd))->m_extendedViewFlag == TRUE)
	{
		//move history
		
		{
			CBitmap localbmp;
			localbmp.LoadBitmap(IDB_BITMAP_BASE3);	

			CDC ldc;
			ldc.CreateCompatibleDC(dc);
			ldc.SelectObject(&localbmp); 	
		
			COLORREF backgroundforlostpieces(RGB(192,192,192));
			CBrush backgroundbursh(backgroundforlostpieces);
			ldc.SelectObject(backgroundbursh);
			ldc.SetBkColor(backgroundforlostpieces);	
			
			/*CRect rect(378,1,450, 200);
			ldc.Rectangle(rect);
			ldc.FillRect(rect, &backgroundbursh);*/

			CString playerInfo;
			playerInfo.Format("White:--  %s",m_gameInfoDlg.m_edit_white);
			ldc.TextOut(1,2,playerInfo);
			playerInfo.Format("Black:--  %s",m_gameInfoDlg.m_edit_black);
			ldc.TextOut(1,20,playerInfo);
			playerInfo.Format("Result:--  %s", m_gameInfoDlg.m_edit_result);
			ldc.TextOut(1, 40, playerInfo);
			//move history window
			//m_listctrl_movehistory.Invalidate();
			ldc.TextOut(1,58,"Move history:--");	
			//if(Globalfirsttime == 1)
			{
				dc->BitBlt(378,1,450,75,&ldc,0,0,SRCCOPY);
				
				//Globalfirsttime = 0;
			}
			/*else
			{	
				CRect r(378,50,450,200);
				dc->ExcludeClipRect(r);
				dc->BitBlt(378,1,450,50,&ldc,0,0,SRCCOPY);
			}*/
		}
		
		
		m_white_group_button.EnableWindow();
		m_white_radio_button_computer.EnableWindow();
		m_white_radio_button_human.EnableWindow();
		m_black_group_button.EnableWindow();
		m_black_radio_button_computer.EnableWindow();
		m_black_radio_button_human.EnableWindow();


		
		/*//Computer/Human player window
		{
			CBitmap localbmp;
			localbmp.LoadBitmap(IDB_BITMAP_BASE3);	

			CDC ldc;
			ldc.CreateCompatibleDC(dc);
			ldc.SelectObject(&localbmp); 	
		
			COLORREF backgroundforlostpieces(RGB(192,192,192));
			CBrush backgroundbursh(backgroundforlostpieces);
			ldc.SelectObject(backgroundbursh);
			ldc.SetBkColor(backgroundforlostpieces);	
			
			CRect rect(378,50,450, 200);
			ldc.Rectangle(rect);
			ldc.FillRect(rect, &backgroundbursh);

			
			//move history window
			//m_listctrl_movehistory.Invalidate();
			//ldc.TextOut(1,150,"Move history:--");
			dc->BitBlt(378,50,450,200,&ldc,0,0,SRCCOPY);
			
		}*/

		//Lost pieces window		
		{
			CBitmap localbmp;
			localbmp.LoadBitmap(IDB_BITMAP_BASE2);	

			CDC ldc;
			ldc.CreateCompatibleDC(dc);
			ldc.SelectObject(&localbmp); 	
		
			COLORREF backgroundforlostpieces(RGB(192,192,192));
			CBrush backgroundbursh(backgroundforlostpieces);
			ldc.SelectObject(backgroundbursh);
			ldc.SetBkColor(backgroundforlostpieces);	
			
			CRect rect(378,256,400,400);
			ldc.Rectangle(rect);
			ldc.FillRect(rect,&backgroundbursh);
			//xstart = 375;//8*40+30+10(buffer)
			//ystart = 265;//6*40+30+10

			//ldc.TextOut(1,1,"Lost pieces:--");
			{		
				int bindex_i= -1,bindex_j=-1;
				int windex_i= -1,windex_j=-1;
				int to_pieceid = -1;
				for(int i=0;i<=m_iHistory;i++)
				{
					PIECE_SIDE piece_side;
					PIECE_TYPE from_piece_type;
					COLOR_TYPE from_color_type;
					int from_pieceid;
					int from_row_id;
					int from_col_id;
					PIECE_TYPE to_piece_type;
					COLOR_TYPE to_color_type;			
					int to_row_id;
					int to_col_id;
					m_History[i].GetHistory(
						piece_side,
						from_piece_type, from_color_type,from_pieceid,
						from_row_id,from_col_id, to_piece_type,
						to_color_type,to_pieceid,to_row_id,
						to_col_id);		
					if(to_pieceid > 0 || m_History[i].GetEnPassentFlag() == TRUE)
					{							
						if(m_History[i].GetEnPassentFlag() == TRUE)
						{			 
							to_pieceid = from_color_type == WHITE ? PAWN_BLACK: PAWN_WHITE;
							to_color_type = from_color_type == WHITE ? BLACK: WHITE;
						}
						if(to_color_type == WHITE)
						{
							if(m_white_on_top == false)
							{			
								if(windex_i == -1)
								{
									windex_i = 8;
									windex_j = 8;
								}
								else
								{
									windex_j++;
									if(windex_j > 15)
									{
										windex_i++;
										windex_j = 8;
									}
								}
							}
							else
							{
								if(windex_i == -1)
								{
									windex_i = 10;
									windex_j = 8;
								}
								else
								{
									windex_j++;
									if(windex_j > 15)
									{
										windex_i++;
										windex_j = 8;
									}
								}
							}
						}
						else if(to_color_type == BLACK)
						{
							if(m_white_on_top == false)
							{			
								if(bindex_i == -1)
								{
									bindex_i = 10;
									bindex_j = 8;
								}
								else
								{
									bindex_j++;
									if(bindex_j > 15)
									{
										bindex_i++;
										bindex_j = 8;
									}
								}
							}
							else
							{
								if(bindex_i == -1)
								{
									bindex_i = 8;
									bindex_j = 8;
								}
								else
								{
									bindex_j++;
									if(bindex_j > 15)
									{
										bindex_i++;
										bindex_j = 8;
									}
								}
							}			
						}
					}
					int index_i = -1, index_j = -1;
					if(to_color_type == BLACK)
					{
						index_i = bindex_i, index_j = bindex_j;
					}
					else
					{
						index_i = windex_i, index_j = windex_j;
					}
					if(to_pieceid > 0 && index_i > 0 && index_j > 0)
					{			
						CRect rect = cb[index_i][index_j].GetRect();
						/*CBitmap bitmap;			
						bitmap.LoadBitmap(GetBitmapId(to_pieceid));			 
						CDC bmpdc;
						bmpdc.CreateCompatibleDC(&ldc);
						bmpdc.SelectObject(&bitmap); 
						BITMAP bmp;
						bitmap.GetBitmap(&bmp);			 
						ldc.StretchBlt(rect.left+4,rect.top+4-49,m_squareWidth -15,m_squareWidth-15,&bmpdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);*/
							//Draw board based on the font
				
						if(m_optDlg.m_boardFont == 1)
						{
							CBitmap bitmap;			
							bitmap.LoadBitmap(GetBitmapId(to_pieceid));			 
							CDC bmpdc;
							bmpdc.CreateCompatibleDC(&ldc);
							bmpdc.SelectObject(&bitmap); 

							BITMAP bmp;
							bitmap.GetBitmap(&bmp);						
							ldc.StretchBlt(rect.left+4,rect.top+4-55,m_squareWidth -15,m_squareWidth-15,&bmpdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
						}
						else
						{
							
							CString piece;
							if(GetPieceString(to_pieceid,piece) == 0)
							{
								CRect rct(rect.left+4,rect.top+4-55,rect.left+4+m_squareWidth-15,rect.top+4-55+m_squareWidth-15);
								
								CFont fnt;
								fnt.CreatePointFont(200,m_optDlg.m_edit_font);
								CFont *f = ldc.SelectObject(&fnt);
								ldc.SetBkMode(TRANSPARENT);
								ldc.SetTextColor(to_color_type == WHITE ? m_optDlg.m_crefWhitePieceColor : m_optDlg.m_crefBlackPieceColor);
								ldc.DrawText(piece,rct,DT_CENTER | DT_VCENTER);
								ldc.SelectObject(f);
							}
						}

					}
				}
			}
			dc->BitBlt(378,300,400,500,&ldc,0,0,SRCCOPY);
		}
		//drawing on temporary board is over,now draw on original
		//comment window
		if(m_iHistory > -1)
		{
			m_edit_comment.SetWindowText(m_History[m_iHistory].GetComment());
		}
		else
		{		
			//m_edit_comment.SetWindowText("hello world");
		}	
	
	}
	
}

void CNetChessView::FlipBoard()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			int from_piece_id;
			COLOR_TYPE from_piece_color;
			PIECE_TYPE from_piece_type;
			STATE from_piece_state; 
			cb[i][7 -j].GetPieceData(from_piece_id,from_piece_color,from_piece_type,from_piece_state);
			int to_piece_id;
			COLOR_TYPE to_piece_color;
			PIECE_TYPE to_piece_type;
			STATE to_piece_state;
			cb[7-i][j].GetPieceData(to_piece_id,to_piece_color,to_piece_type,to_piece_state);
			cb[7-i][j].SetPieceData(from_piece_id,from_piece_color,from_piece_type,from_piece_state);
			cb[i][7 - j].SetPieceData(to_piece_id,to_piece_color,to_piece_type,to_piece_state);
		}
	}
}

void CNetChessView::DrawCoordinateSystem(CDC *ldc)
{
	CRect crect;
	GetClientRect(&crect);
	COLORREF redbluecr(RGB(192,192,192));
	COLORREF black(RGB(0,0,0));
	ldc->SetTextColor(black);
	//draw coordinate system
	if(((CMainFrame*)(AfxGetApp()->m_pMainWnd))->m_extendedViewFlag == TRUE)
	{
		for(int i=0;i<8;i++)
		{
			ldc->SetBkColor(redbluecr);
			if(m_LetterFlag == true)
			{
				if(m_white_on_top == false)
				{
					ldc->TextOut(m_squareWidth * (i+1),5,(CString)((char)('a'+i)));
					ldc->TextOut(m_squareWidth * (i+1),crect.bottom -50,(char)( 'a'+i));
				}
				else
				{
					ldc->TextOut(m_squareWidth * (i+1),5,(char)('h'-i));
					ldc->TextOut(m_squareWidth * (i+1),crect.bottom - 50, (char)('h'- i));
				}
			}
			if(m_NumberFlag == true)
			{
				if(m_white_on_top == false)
				{
					ldc->TextOut(10, m_squareWidth * (i+1), (char)('8' - i));
					ldc->TextOut(crect.right - 230, m_squareWidth * (i+1), (char)('8' - i));
				}
				else
				{
					ldc->TextOut(10, m_squareWidth * (i+1), (char)('1' + i));
					ldc->TextOut(crect.right - 230, m_squareWidth * (i+1), (char)('1' + i));
				}
			}	
		}	
	}
	else
	{
		for(int i=0;i<8;i++)
		{
			ldc->SetBkColor(redbluecr);
			if(m_LetterFlag == true)
			{
				if(m_white_on_top == false)
				{
					ldc->TextOut(m_squareWidth * (i+1),5,(char)('a'+i));
					ldc->TextOut(m_squareWidth * (i+1),crect.bottom - 21, (char)('a'+i));
				}
				else
				{
					ldc->TextOut(m_squareWidth * (i+1),5,(char)('h'-i));
					ldc->TextOut(m_squareWidth * (i+1),crect.bottom - 21, (char)('h'- i));
				}
			}
			if(m_NumberFlag == true)
			{
				if(m_white_on_top == false)
				{
					ldc->TextOut(10, m_squareWidth * (i+1), (char)('8' - i));
					ldc->TextOut(crect.right - 20, m_squareWidth * (i+1), (char)('8' - i));
				}
				else
				{
					ldc->TextOut(10, m_squareWidth * (i+1), (char)('1' + i));
					ldc->TextOut(crect.right - 20, m_squareWidth * (i+1), (char)('1' + i));
				}
			}
		}
	}
	
}
void CNetChessView::Initialize()
{
	m_mouseMoveFlag = false;
	m_moveRect =0;	 
	m_iHistory = -1;	 	 	 	 
	m_topHistory = -1;
	m_timerFlag = false;	
	m_blackTime = m_whiteTime =  m_engineLevelDlg.m_edit_time_control == 0? 5*60: m_engineLevelDlg.m_edit_time_control*60;
	m_elapsedTime = 0;
	m_startTime = (int)time(0);
	m_blackKingMovedFlag = false;
	m_whiteKingMovedFlag = false;
	m_blackRookRank1MovedFlag = false;
	m_whiteRookRank1MovedFlag = false;
	m_blackRookRank7MovedFlag = false;
	m_whiteRookRank7MovedFlag = false;
	m_checkFlag = m_castlingFlag = m_enpassentFlag = 
		m_promotionFlag = m_ambiguousMoveRankFlag = 
		m_ambiguousMoveFileFlag = FALSE;	
	m_listctrl_movehistory.ResetContent();
//	m_SpecialAction = NOTHING;
	CString str;
	str.Format("0:0:0");	 
	SetPaneText(WHITETIME,str);
	SetPaneText(BLACKTIME,str);
	if(m_pieceSide == BLACK)
	{
		m_player_turn = false;
	}
	else
	{
		m_player_turn = true;
	}
	m_fileReadFlag = FALSE;	
	m_demoTotal = 0;
	m_moveFlag = FALSE;
	m_movedFromRect.left = -1;
	m_movedToRect.left = -2;
//	m_PGNEvent = m_PGNSite = m_PGNDate = m_PGNRound = m_PGNWhite = m_PGNBlack = m_PGNResult = m_FENString = "";
	m_gameInfoDlg.ClearDialog();
	if(m_ChatDlg == NULL)
	{
		m_ChatDlg = new CMessageSend();
		m_ChatDlg->Create(IDD_DIALOG_MESSAGE,this);
	}
	if(m_icsChatDlg == NULL)
	{
		m_icsChatDlg = new CICSMessageChatDlg();
		m_icsChatDlg->Create(IDD_DIALOG_MESSAGE_ICS,this);
	}
	if(m_pickPieceDlg == NULL)
	{
		m_pickPieceDlg = new CPickPieceDlg();
		m_pickPieceDlg->Create(IDD_DIALOG_PICK_PIECE,this);
	}

	if(m_pMailFromDlg == NULL)
	{
		m_pMailFromDlg = new CMailFromDlg();
		m_pMailFromDlg->Create(IDD_DIALOG_MAIL_FROM,this);
	}

	if(m_pMailToDlg == NULL)
	{
		m_pMailToDlg = new CMailToDlg();
		m_pMailToDlg->Create(IDD_DIALOG_MAIL_TO,this);
	}

	if(m_pClientSocket == NULL)
		m_pieceSide = WHITE;
	//clean the board
	for ( int i = 0; i < 8; i++)
	{		
		for( int j = 0; j < 8; j++)
		{			
			cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);	
		}	
	}
	//setup up the board
	cb[0][0].SetPieceData(ROOK_BLACK,BLACK,ROOK,PIECE_NOT_MOVING);
	cb[0][1].SetPieceData(KNIGHT_BLACK,BLACK,KNIGHT,PIECE_NOT_MOVING);
	cb[0][2].SetPieceData(BISHOP_BLACK,BLACK,BISHOP,PIECE_NOT_MOVING);
	cb[0][3].SetPieceData(QUEEN_BLACK,BLACK,QUEEN,PIECE_NOT_MOVING);
	cb[0][4].SetPieceData(KING_BLACK,BLACK,KING,PIECE_NOT_MOVING);
	cb[0][5].SetPieceData(BISHOP_BLACK,BLACK,BISHOP,PIECE_NOT_MOVING);
	cb[0][6].SetPieceData(KNIGHT_BLACK,BLACK,KNIGHT,PIECE_NOT_MOVING);
	cb[0][7].SetPieceData(ROOK_BLACK,BLACK,ROOK,PIECE_NOT_MOVING);

	for(int i=0;i<8;i++)
	{
		cb[0][i].SetPieceState(PIECE_NOT_MOVING);
		cb[7][i].SetPieceState(PIECE_NOT_MOVING);
	}

	for(int i=0;i<8;i++)
	{
		cb[1][i].SetPieceData(PAWN_BLACK,BLACK,PAWN,PIECE_NOT_MOVING);
		cb[6][i].SetPieceData(PAWN_WHITE,WHITE,PAWN,PIECE_NOT_MOVING);
	}
	 
	cb[7][0].SetPieceData(ROOK_WHITE,WHITE,ROOK,PIECE_NOT_MOVING);
	cb[7][1].SetPieceData(KNIGHT_WHITE,WHITE,KNIGHT,PIECE_NOT_MOVING);
	cb[7][2].SetPieceData(BISHOP_WHITE,WHITE,BISHOP,PIECE_NOT_MOVING);
	cb[7][3].SetPieceData(QUEEN_WHITE,WHITE,QUEEN,PIECE_NOT_MOVING);
	cb[7][4].SetPieceData(KING_WHITE,WHITE,KING,PIECE_NOT_MOVING);
	cb[7][5].SetPieceData(BISHOP_WHITE,WHITE,BISHOP,PIECE_NOT_MOVING);
	cb[7][6].SetPieceData(KNIGHT_WHITE,WHITE,KNIGHT,PIECE_NOT_MOVING);
	cb[7][7].SetPieceData(ROOK_WHITE,WHITE,ROOK,PIECE_NOT_MOVING);

	SetTimer(PIECE_SIDE_TIMER_EVENT_ID,1000,NULL);
	SetTimer(ICS_TIMER,1000,NULL);
	SetTimer(SAVE_TIMER_EVENT_ID,1000,NULL);
	if(m_white_on_top == true)
		FlipBoard();
	//DrawBoard();

}

int CNetChessView::GetBitmapId(int piece_id)
{
	switch(m_optDlg.m_pieceType)
	{
		case 1:
			switch(piece_id)
			{
				case ROOK_WHITE:
					return IDB_BITMAP_ROOK_WHITE;
				case BISHOP_WHITE:
					return IDB_BITMAP_BISHOP_WHITE;				
				case KING_BLACK:
					return IDB_BITMAP_KING_BLACK;
				case KING_WHITE:
					return IDB_BITMAP_KING_WHITE;
				case KNIGHT_BLACK:
					return IDB_BITMAP_KNIGHT_BLACK;
				case KNIGHT_WHITE:
					return IDB_BITMAP_KNIGHT_WHITE;
				case PAWN_BLACK:
					return IDB_BITMAP_PAWN_BLACK;
				case PAWN_WHITE:
					return IDB_BITMAP_PAWN_WHITE;
				case QUEEN_BLACK:
					return IDB_BITMAP_QUEEN_BLACK;
				case QUEEN_WHITE:
					return IDB_BITMAP_QUEEN_WHITE;
				case ROOK_BLACK:
					return IDB_BITMAP_ROOK_BLACK;
				case BISHOP_BLACK: 
					return IDB_BITMAP_BISHOP_BLACK;
			}
			break;
		case 2:
			break;
		case 3:			 
			break;
	}
	return -1;
}
int CNetChessView::GetPieceString(int piece_id, CString &piece)
{
	switch(m_optDlg.m_pieceType)
	{
		case 1:
			switch(piece_id)
			{
				case ROOK_WHITE:
				//	piece = "r";
				//	return 0;

				case ROOK_BLACK:
					piece = "t";
					return 0;

				case BISHOP_WHITE:
				//	piece = "b";
				//	return 0;					

				
				case BISHOP_BLACK: 
					piece = "v";
					return 0;
				case KING_WHITE:
				//	piece = "k";
			//		return 0;
				case KING_BLACK:
					piece = "l";
					return 0;				
			
				case KNIGHT_WHITE:
				//	piece = "n";
				//	return 0;	
				case KNIGHT_BLACK:
					piece = "m";
					return 0;
				case PAWN_WHITE:
				//	piece = "p";
				//	return 0;
				case PAWN_BLACK:
					piece = "o";
					return 0;
					
				case QUEEN_WHITE:
				//	piece = "q";
				//	return 0;
				case QUEEN_BLACK:
					piece = "w";
					return 0;
				
			
			}
			break;
		case 2:
			break;
		case 3:			 
			break;
	}
	return -1;
}
void CNetChessView::OnInitialUpdate() 
{
	writeMessage("Welcome to AVM RAO's NetChess game!");
	CView::OnInitialUpdate();

	CRect editrect(0, 425,330 , 445);
	m_edit_comment.Create(WS_CHILD | WS_BORDER | WS_VISIBLE | WS_TABSTOP |
             ES_AUTOVSCROLL | WS_BORDER | ES_MULTILINE |WS_VSCROLL, editrect, this, ID_EXTRA_EDIT);

	
	CRect buttoncommentrect(331,425,377,445);
	m_button_comment.Create("Add",WS_CHILD | WS_BORDER | WS_VISIBLE |
		WS_BORDER |BS_PUSHBUTTON, buttoncommentrect,
		this, ID_EXTRA_BUTTON);
/*	//Create group box and radio button for player 1

	CRect whitegroupbuttonrect(378,60,595,110);
	m_white_group_button.Create("Player 1",WS_CHILD | WS_VISIBLE |
		BS_GROUPBOX,whitegroupbuttonrect,this,ID_EXTRA_WHITE_GROUPBOX);

	CRect whiteradiobuttoncomputer( 10,25,100,45);
	m_white_radio_button_computer.Create("Computer", 
		WS_CHILD | WS_VISIBLE | WS_BORDER |BS_AUTORADIOBUTTON  ,
		whiteradiobuttoncomputer, 
		&m_white_group_button,ID_EXTRA_WHITE_COMPUTER);
		//this,ID_EXTRA_WHITE_COMPUTER);


	CRect whiteradiobuttonhuman( 110,25,190,45);
	m_white_radio_button_human.Create("Human", 
		WS_CHILD | WS_VISIBLE |
		WS_BORDER |BS_AUTORADIOBUTTON  ,whiteradiobuttonhuman, 
		&m_white_group_button,ID_EXTRA_WHITE_HUMAN);


	//Create group box and radio button for player 2

	CRect blackgroupbuttonrect(378,120,595,170);
	m_black_group_button.Create("Player 2",WS_CHILD | WS_VISIBLE |
		BS_GROUPBOX,blackgroupbuttonrect,this,ID_EXTRA_BLACK_GROUPBOX);

	CRect blackradiobuttoncomputer( 10,25,100,45);
	m_black_radio_button_computer.Create("Computer", 
		WS_CHILD | WS_VISIBLE | WS_BORDER |BS_AUTORADIOBUTTON  ,
		blackradiobuttoncomputer, 
		&m_black_group_button,ID_EXTRA_BLACK_COMPUTER);


	CRect blackradiobuttonhuman( 110,25,190,45);
	m_black_radio_button_human.Create("Human", 
		WS_CHILD | WS_VISIBLE |
		WS_BORDER |BS_AUTORADIOBUTTON  ,blackradiobuttonhuman, 
		&m_black_group_button,ID_EXTRA_BLACK_HUMAN);*/

	//Create group box and radio button for player 1

	CRect whitegroupbuttonrect(0,385,185,424);
	m_white_group_button.Create("Player 1",WS_CHILD | WS_VISIBLE |
		BS_GROUPBOX,whitegroupbuttonrect,this,ID_EXTRA_WHITE_GROUPBOX);

	CRect whiteradiobuttoncomputer( 8,18,100,33);
	m_white_radio_button_computer.Create("Computer", 
		WS_CHILD | WS_VISIBLE | WS_BORDER |BS_AUTORADIOBUTTON  ,
		whiteradiobuttoncomputer, 
		&m_white_group_button,ID_EXTRA_WHITE_COMPUTER);
		//this,ID_EXTRA_WHITE_COMPUTER);


	CRect whiteradiobuttonhuman( 105,18,180,33);
	m_white_radio_button_human.Create("Human", 
		WS_CHILD | WS_VISIBLE |
		WS_BORDER |BS_AUTORADIOBUTTON  ,whiteradiobuttonhuman, 
		&m_white_group_button,ID_EXTRA_WHITE_HUMAN);


	//Create group box and radio button for player 2

	CRect blackgroupbuttonrect(190,385,375,424);
	m_black_group_button.Create("Player 2",WS_CHILD | WS_VISIBLE |
		BS_GROUPBOX,blackgroupbuttonrect,this,ID_EXTRA_BLACK_GROUPBOX);

	CRect blackradiobuttoncomputer( 8,18,100,33);
	m_black_radio_button_computer.Create("Computer", 
		WS_CHILD | WS_VISIBLE | WS_BORDER |BS_AUTORADIOBUTTON  ,
		blackradiobuttoncomputer, 
		&m_black_group_button,ID_EXTRA_BLACK_COMPUTER);


	CRect blackradiobuttonhuman( 105,18,180,33);
	m_black_radio_button_human.Create("Human", 
		WS_CHILD | WS_VISIBLE |
		WS_BORDER |BS_AUTORADIOBUTTON  ,blackradiobuttonhuman, 
		&m_black_group_button,ID_EXTRA_BLACK_HUMAN);


	//CRect listctrlrect(378,82,545,205);	
	CRect listctrlrect(378,75,598,300);	
	m_listctrl_movehistory.Create(WS_CHILD | WS_BORDER | WS_VISIBLE |
		ES_AUTOVSCROLL | WS_BORDER |LBS_NOTIFY|WS_VSCROLL | ES_NOHIDESEL, listctrlrect,
		this, ID_EXTRA_LISTBOX);
	
	Initialize();
	/*if(m_optDlg.m_check_save_game == TRUE)
	{
		char data1[2000];
		char defaultBuf[40]="default";
		char CurrentDir[255];
		GetWindowsDirectory(CurrentDir,MAX_PATH);
		strcat(CurrentDir,"\\NetChess.ini");
		memset(data1,'\0',2000);
		if(GetPrivateProfileString("NetChess","PGNFormat",defaultBuf,data1,100,CurrentDir)>0)
		{
			//AfxMessageBox(data1);

			OnFileOpen(data1);
			if(m_iHistory == -1)
				OnFileNewgame();
			
		}	
	}*/
	//Call count of usage
	/*CInternetSession isession;
	CHttpConnection *pconnection = isession.GetHttpConnection("www.geocities.com");
	CHttpFile *pFile = pconnection->OpenRequest(CHttpConnection::HTTP_VERB_GET,
				"/raoavm/netchesscount.html", NULL, 1, NULL, NULL, INTERNET_FLAG_EXISTING_CONNECT);
	pFile->AddRequestHeaders("Accept: text/*\r\nUser-Agent: ");
	pFile->SendRequest();
	DWORD dwRet;
	pFile->QueryInfoStatusCode(dwRet);

	CHttpConnection *pconnection1 = isession.GetHttpConnection("www.prasannatech.com");
	CHttpFile *pFile1 = pconnection1->OpenRequest(CHttpConnection::HTTP_VERB_GET,
				"/netchesscount.html", NULL, 1, NULL, NULL, INTERNET_FLAG_EXISTING_CONNECT);
	pFile1->AddRequestHeaders("Accept: text/*\r\nUser-Agent: ");
	pFile1->SendRequest();
	DWORD dwRet1;
	pFile1->QueryInfoStatusCode(dwRet1);*/
	
	
}

void CNetChessView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	OnLButtonDownAction(nFlags,point);	 
 	CView::OnLButtonDown(nFlags, point);
}

void CNetChessView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	OnLButtonUpAction(nFlags,point);	 
	CView::OnLButtonUp(nFlags, point);
}

void CNetChessView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	 
	OnMouseMoveAction(nFlags,point);
	CView::OnMouseMove(nFlags, point);
}

void CNetChessView::OnToolsClient() 
{
	// TODO: Add your command handler code here
	if(m_pServerSocket != NULL)
	{
		AfxMessageBox("Running as Server, cannot run as client");
		return;
	}
	if(m_pClientSocket != NULL)
	{
		AfxMessageBox("Already running as client");
		return;
	}
	if(m_iHistory > -1)
	{
		int ret=  AfxMessageBox("Do you want to save the playing game",MB_YESNOCANCEL);
		if(ret == IDYES)
		{
			OnFileSave();			 
		}
		else if(ret == IDCANCEL)
		{
			return;
		}
	}
	Initialize();
//	OnInitialUpdate();
	DrawBoard();
	CServerInfoDlg dlg(this,CLIENT);
	if(dlg.DoModal()==IDOK)
	{
		((CMessageSend*)m_ChatDlg)->m_edit_name = dlg.m_edit_name;		
		m_edit_name = dlg.m_edit_name;
		m_pClientSocket = new CClientSocket();
		CString str;
		((CClientSocket*)m_pClientSocket)->SetInfo(dlg.m_strIPAddress, dlg.m_port_nunber);
		m_pClientSocket->Create();
		m_pClientSocket->Connect(dlg.m_strIPAddress, dlg.m_port_nunber) !=0  || GetLastError();
		m_pieceSide = dlg.m_pieceSide; 
	}		
}
void CNetChessView::OnToolsServer() 
{
	// TODO: Add your command handler code here
	if(m_pServerSocket != NULL)
	{
		AfxMessageBox("Already running as server");
		return;
	}
	if(m_pClientSocket != NULL)
	{
		AfxMessageBox("Already running as client");
		return;
	}
	if(m_iHistory > -1)
	{
		int ret= AfxMessageBox("Do you want to save the playing game",MB_YESNOCANCEL);
		if(ret == IDYES)
		{
			OnFileSave();			 
		}
		else if(ret == IDCANCEL)
		{
			return;
		}		
		Initialize();
//		OnInitialUpdate();
		DrawBoard();
	}
	CServerInfoDlg dlg(this,SERVER);
	if(dlg.DoModal()==IDOK)
	{ 
		((CMessageSend*)m_ChatDlg)->m_edit_name = dlg.m_edit_name;
		m_edit_name = dlg.m_edit_name;		
		m_pServerSocket = new CServerSocket();
		((CServerSocket*)m_pServerSocket)->SetInfo(dlg.m_port_nunber);
		((CServerSocket*)m_pServerSocket)->CreateServer(dlg.m_port_nunber);		 
	}
}
void CNetChessView::SetClientSocket(CAsyncSocket* sock, int flag)
{
	if(m_iHistory > -1)
	{
		if(AfxMessageBox("Do you want to save the playing game",MB_YESNO) == IDYES)
		{
			OnFileSave();		 	 
		}
		Initialize();
//		OnInitialUpdate();
		DrawBoard();
	}
	if(flag == TRUE)
		m_pClientICSSocket = sock;
	else
		m_pClientSocket = sock;
}
void CNetChessView::SetObserverSocket(CAsyncSocket* sock)
{
	CString name;
	unsigned int port;
	CClientSocket *csock = (CClientSocket*)sock;
	csock->GetPeerName(name,port);
	csock->m_ipaddress = name;
	csock->m_port = port;
	csock->m_observerFlag = TRUE;
	CString msg;
	msg.Format(" requested as observer,Accept");
	msg = name + msg;
	CDialog dlg;
	if(AfxMessageBox(msg,MB_YESNO) ==IDYES)
	{	
		csock->m_clientId = (int)time(0);
		m_pObserverSocketList.AddTail(csock);
		unsigned char data[50];
		memset(data,'\0',50);
		data[0]=OBSERVER;
		memcpy(&data[1],&csock->m_clientId,4);
		strcpy((char*)&data[5],m_edit_name.GetBuffer(0));
		int length = m_edit_name.GetLength() + 6;
		char clength[5];	 
		memcpy(clength,&length,4);
		csock->Send(clength,4);	 
		csock->Send(data,length);		
	}
	else
	{		
		unsigned char data[50];
		memset(data,'\0',50);
		data[0]=CONNECT_REJECT;
		strcpy((char*)&data[1],m_edit_name.GetBuffer(0));
		int length = m_edit_name.GetLength() + 2;
		char clength[5];	 
		memcpy(clength,&length,4);
		csock->Send(clength,4);	 
		csock->Send(data,length);
	}
}

void CNetChessView::RemoveFromObserverList(CAsyncSocket* sock)
{
	POSITION pos = m_pObserverSocketList.Find(sock);
	if(pos != NULL)
	{
		m_pObserverSocketList.RemoveAt(pos);
	}	
}

CAsyncSocket* CNetChessView::GetClientSocket(int icsFlag)
{	 
	if(icsFlag == TRUE)
		return m_pClientICSSocket;
	else
		return m_pClientSocket;
}

void CNetChessView::SetShellIconData(char* data, int id)
{
	NOTIFYICONDATA nicondata;					
	nicondata.hWnd = AfxGetApp()->m_pMainWnd->GetSafeHwnd();
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(id,&nicondata);
}

void CNetChessView::HandleData(unsigned char* data,int length, int flag)
{
	if(flag == TRUE)
	{
		//AfxMessageBox((char*)data);
		HandleICSData(data);	
		
	}
	else
	{
	switch(data[0])
		{
			case MOVE:
				{
					memcpy(&m_whiteTime,&data[13],4);
				    memcpy(&m_blackTime,&data[17],4);
					m_moveFlag = TRUE;
					bool wotflag = data[1] == FALSE ?false:true;
					if(data[6] > 0)
					{
						m_pickPieceDlg->m_pickpiecetype  = 1;
						memcpy(&m_pickPieceDlg->m_piecked_piece,&data[7],4);
						m_pickPieceDlg->m_piece_color =(COLOR_TYPE)data[11];
						m_pickPieceDlg->m_piece_type = (PIECE_TYPE)data[12];
					}
					if(m_white_on_top == wotflag)
					{
						m_point.x = data[2];
						m_point.y = data[3];
						m_mouseMoveFlag = true;
						CRect rect=cb[data[4]][data[5]].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						if(data[6] == 2)
						{
							m_mouseMoveFlag = false;
							OnRButtonDownAction(0,pt);
						}
						else
							OnLButtonUpAction(0,pt);
					}
					else
					{
						m_point.x = 7-data[2];
						m_point.y = 7-data[3];
						m_mouseMoveFlag = true;
						CRect rect=cb[7-data[4]][7-data[5]].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						if(data[6] == 2)
						{
							m_mouseMoveFlag = false;
							OnRButtonDownAction(0,pt);
						}
						else
							OnLButtonUpAction(0,pt);
					}
					if(data[6] != 2)
						m_player_turn = true;
					if(m_pieceSide == WHITE )								
					{
						SetPaneText(PLAYERSIDE,"WHITE",0);
					}
					else if(m_pieceSide == BLACK)
					{
						SetPaneText(PLAYERSIDE,"BLACK",0);
					}
					//SendToEngine(data,length);					
					
				}
				break;
			case OBSERVER_TEXT:
				{	
					((CMessageSend*)m_ChatDlg)->SetReceiveData(&data[5]);	
					DrawBoard();
				}
				break;
			case TEXT:
				{	
					((CMessageSend*)m_ChatDlg)->SetReceiveData(&data[1]);	
					DrawBoard();
				}
				break;
		 
			case FILEDATA:
				{
					Initialize();
	//				OnInitialUpdate();
					if(m_white_on_top == true)
					{
						FlipBoard();
						m_white_on_top = false;
					}
					for(int i = 0; i< 8; i++)
					{
						for(int j=0;j<8;j++)
						{
							cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						}
					} 
					int count = 1, total = 0, totLines=0;				
					memcpy(&total, &data[1],4);
					count+=4;				
					while(totLines < total)
					{			
						int i,j;			
						PIECE_TYPE piece_type;
						COLOR_TYPE piece_color;
						int pieceid;
						i = data[count++];
						j = data[count++];
						piece_type = (PIECE_TYPE)data[count++];
						piece_color = (COLOR_TYPE)data[count++];
						memcpy(&pieceid,&data[count],4);
						count += 4;
						cb[i][j].SetPieceData(pieceid,piece_color,piece_type,PIECE_NOT_MOVING);
						totLines++;
					}				
					DrawBoard();
				}
				break;
			case PGNFILE:
				{				
					//if(m_fileReadFlag == TRUE)
					{
						Initialize();
						m_fileReadFlag = data[1];
	//					OnInitialUpdate();
					}				
				}
				break;
			case REFRESH:
				{
					m_demoTotal = data[1];
					DrawBoard();
				}
				break;
			case UNDO:
					{
						OnEditUndoAction(data[1]);
						DrawBoard();
					}
				break;
			case REDO:
					{					
						OnEditRedoAction(data[1]);					 
						DrawBoard();
					}
				break;
			case MOVEFIRST:
					{
						int total = m_iHistory;
						for(int i=0;i<=total;i++)
						{
							OnEditUndoAction(0); 		
						}					
						DrawBoard();
					}
				break;
			case MOVELAST:
					{					
						int total = m_topHistory;
						for(int i=0;i<=total;i++)
						{
							OnEditRedoAction(0); 		
						}					
						DrawBoard();
					}
				break;
			case GOTO:
				{
					int total = m_iHistory;
					int pos;
					memcpy(&pos,&data[1],4);				
					for(int i=0;i<=total;i++)
					{
						OnEditUndoAction(0); 			
					}	
					for(int i=1;i<=pos;i++)
					{
						OnEditRedoAction(0);				
					}
					m_demoTotal = pos;
					DrawBoard();
				}
				break;
			case NEWGAME:
					{
						DrawBoard();
						m_blackTime = m_whiteTime = m_engineLevelDlg.m_edit_time_control == 0? 5*60: m_engineLevelDlg.m_edit_time_control*60;
						m_startTime = (int)time(0);

						if(m_observerFlag == FALSE)
							AfxMessageBox("Your opponent has requested for new game");
						OnFileNewAction();
						SendToEngine(data,length);
					}
				break;	
			case CONNECT_REJECT:
					AfxMessageBox("server not accepted");
					break;
			case RESIGN_REQUEST:
					{
						CString str = (CString)&data[1] + (CString)" resigned from the game";
						AfxMessageBox(str);					 
						OnFileNewgame();
						SendToEngine(data,length);
					}
					break;
			case RESIGN_ACCEPT:
					break;
			case RESIGN_REJECT:
					break;
			case DRAW_REQUEST:
					{
						CString str = (CString)&data[1] + (CString)" requested for draw, Accept";
						if(AfxMessageBox(str,MB_YESNO) == IDYES)
						{						
							unsigned char data[50];
							data[0]=DRAW_ACCEPT;
							strcpy((char*)&data[1],m_edit_name.GetBuffer(0));
							SendSockData(data,m_edit_name.GetLength()+2);
						}
						else
						{					
							unsigned char data[50];
							data[0]=DRAW_REJECT;
							strcpy((char*)&data[1],m_edit_name.GetBuffer(0));
							SendSockData(data,m_edit_name.GetLength()+2);	
						}
					}
					break;
			case DRAW_ACCEPT:
					{
						CString str = (CString)&data[1] + (CString)" accepted for draw";
						AfxMessageBox(str);	
						OnFileNewgame();
						SendToEngine(data,length);
					}
					break;
			case DRAW_REJECT:
					{	
						CString str = (CString)&data[1] + (CString)" rejected for draw";
						AfxMessageBox(str);					 
					}
					break;
			case CONNECT_REQUEST:
				{
				}
				break;
			case CONNECT_INFO:
				{
					if(m_pieceSide == WHITE)
					{
						m_gameInfoDlg.m_edit_black = (CString)&data[1];
					}
					else
					{
						m_gameInfoDlg.m_edit_white = (CString)&data[1];
					}
				}
			break;
			case CONNECT_ACCEPT:
				{
					CString side;
					if(data[1] == WHITE)
					{
						side = "White";
						SetPaneText(PLAYERNAME,"BLACK");
						m_pieceSide = BLACK;
						m_white_on_top = true;
						FlipBoard();					
						m_player_turn = false;
						m_gameInfoDlg.m_edit_black = m_edit_name;
						m_gameInfoDlg.m_edit_white = (CString)&data[6];					
						memcpy(&m_clientId,&data[2],4);
						((CClientSocket*)m_pClientSocket)->m_clientId = m_clientId;

					}
					else if(data[1] == BLACK)
					{
						SetPaneText(PLAYERNAME,"WHITE");
						m_pieceSide = WHITE;
						side = "Black";
						m_white_on_top = false;					
						m_player_turn = true;
						m_gameInfoDlg.m_edit_white = m_edit_name;
						m_gameInfoDlg.m_edit_white = (CString)&data[6];
						memcpy(&m_clientId,&data[2],4);
						((CClientSocket*)m_pClientSocket)->m_clientId = m_clientId;
					}
					DrawBoard();
					unsigned char data1[50];
					memset(data1,'\0',50);
					data1[0] = CONNECT_INFO;
					memcpy(&data1[1],m_edit_name.GetBuffer(0),m_edit_name.GetLength());
					SendSockData(data1,m_edit_name.GetLength() + 2);
					m_blackTime = m_whiteTime = m_engineLevelDlg.m_edit_time_control == 0? 5*60: m_engineLevelDlg.m_edit_time_control*60;
					m_elapsedTime = 0;
					m_startTime = (int)time(0);
					m_manualEditingFlag = FALSE;
					m_demoFlag = FALSE;
					CString msg = (CString)&data[6] + (CString)" Accepted for playing chess with " + side + "Side";
					AfxMessageBox(msg);	
				}
				break;
			case CHECKLEGALMOVE:
				m_checkmove = data[1];
				//m_checkmove == TRUE ? AfxGetApp()->m_pMainWnd->GetMenu()->GetSubMenu(1)->CheckMenuItem(ID_EDIT_CHECKMOVE,0):AfxGetApp()->m_pMainWnd->GetMenu()->GetSubMenu(1)->CheckMenuItem(ID_EDIT_CHECKMOVE,1) ;
				if(m_checkmove == TRUE)
					AfxMessageBox("Enabled checking valid move");
				else
					AfxMessageBox("Disabled checking valid move");
				break;
			case MANUALEDITING_START:
				{
					CString str;
					str.Format("%s %s",&data[1]," Requested for Manual editing. Accept?");
					if(AfxMessageBox(str,MB_YESNO) == IDYES)
					{
						m_manualEditingFlag = TRUE;				
						AfxGetApp()->m_pMainWnd->GetMenu()->GetSubMenu(1)->CheckMenuItem(ID_EDIT_MANUALEDIT_START,1);
						char data[1];
						data[0] = MANUALEDITING_ACCEPT;
						SendSockData((unsigned char*)data,1);
					}
					else
					{
						m_manualEditingFlag = FALSE;
						AfxGetApp()->m_pMainWnd->GetMenu()->GetSubMenu(1)->CheckMenuItem(ID_EDIT_MANUALEDIT_START,0);
						char data[1];
						data[0] = MANUALEDITING_REJECT;
						SendSockData((unsigned char*)data,1);
					}
				}
				break;
			case MANUALEDITING_END:
				AfxMessageBox("Manual editing disabled!");
				m_manualEditingFlag = FALSE;
				AfxGetApp()->m_pMainWnd->GetMenu()->GetSubMenu(1)->CheckMenuItem(ID_EDIT_MANUALEDIT_START,0);
				break;
			case MANUALEDITING_EMPTY:
				if(m_manualEditingFlag == TRUE)
				{
					for ( int i = 0; i < 8; i++)
					{	
						for( int j = 0; j < 8; j++)
						{
							cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							 
						}	
					}

					m_iHistory = -1;
					DrawBoard();
				}
				break;
			case MANUALEDITING_ACCEPT:
				m_manualEditingFlag = TRUE;
				AfxGetApp()->m_pMainWnd->GetMenu()->GetSubMenu(1)->CheckMenuItem(ID_EDIT_MANUALEDIT_START,1);
				AfxMessageBox("Manual editing request accepted!");
				break;
			case MANUALEDITING_REJECT:
				m_manualEditingFlag = FALSE;
				AfxGetApp()->m_pMainWnd->GetMenu()->GetSubMenu(1)->CheckMenuItem(ID_EDIT_MANUALEDIT_START,0);
				AfxMessageBox("Manual editing request rejected!");
				break;
			case MANUALEDITING_PLAYER_TURN:
				m_player_turn = data[1]==0?false:true;
				AfxMessageBox("Player turn changed!");
				break;
			case DEMO_START:
				{
					CString str;
					str.Format("%s %s",&data[1]," Requested for Replay, Accept?");
					if(AfxMessageBox(str,MB_YESNO) == IDYES)
					{
						m_demoFlag = TRUE;				
						m_manualEditingFlag = FALSE;
						//AfxGetApp()->m_pMainWnd->GetMenu()->GetSubMenu(3)->CheckMenuItem(ID_VIEW_DEMO,1);
						char data[1];
						data[0] = DEMO_START_ACCEPT;
						SendSockData((unsigned char*)data,1);
					}
					else
					{
						m_demoFlag = FALSE;
						//AfxGetApp()->m_pMainWnd->GetMenu()->GetSubMenu(3)->CheckMenuItem(ID_VIEW_DEMO,0);
						char data[1];
						data[0] = DEMO_REJECT;
						SendSockData((unsigned char*)data,1);
					}
				}
				break;
			case DEMO_START_ACCEPT:
				{
					m_demoFlag = TRUE;
					m_manualEditingFlag = FALSE;
					OnEditMovefirst();
					m_demoTotal = 0;		
					SetTimer(DEMO_TIMER_EVENT_ID,m_demoInterval*1000,NULL);		
				}
				break;
			case DEMO_REJECT:
				m_demoFlag = FALSE;
				AfxMessageBox("Replay request rejected!");
				break;
			case DEMO_END:
				{
					CString result = "Demo stopped/over: Result-" + m_gameInfoDlg.m_edit_result;
					AfxMessageBox(result);				
					m_demoFlag = FALSE;
				}
				break;
			case GAMEINFO:
				{
					//m_PGNEvent = m_PGNSite = m_PGNDate = m_PGNRound = m_PGNWhite = m_PGNBlack = m_PGNResult = m_FENString = "";
					m_gameInfoDlg.ClearDialog();
					int length = data[1];
					int count = 2;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_edit_event += data[count++];
					}				
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{					
						m_gameInfoDlg.m_edit_site += data[count++];
					}				
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_edit_date += data[count++];					
					}				
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{					
						m_gameInfoDlg.m_edit_round += data[count++];					
					}				
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_edit_white += data[count++];
					}				
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_edit_black += data[count++];
					}				
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_edit_result += data[count++];
					}
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_edit_fenstring += data[count++];
					}
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_edit_eco += data[count++];
					}	
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_edit_playcount += data[count++];
					}	
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_edit_blackelo += data[count++];
					}	
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_edit_whiteelo += data[count++];
					}	
					length = data[count];
					count++;
					for(int i=0;i<length;i++)
					{
						m_gameInfoDlg.m_event_date += data[count++];
					}	
				}
				break;
			case CLOCK:
				{
					m_pauseclockFlag = data[1];
					if(m_pauseclockFlag == FALSE)
					{
						SetPaneText(MESSAGEPANE,"Game started!",1);
						if(m_whiteAsEngineFlag == TRUE && m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
							m_whiteEngine.WriteToEngine("resume");
						else if(m_blackAsEngineFlag == TRUE && m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
							m_blackEngine.WriteToEngine("resume");
					}
					else
					{
						SetPaneText(MESSAGEPANE,"Game paused!",1);
						if(m_iHistory > 0)
						{
							if(m_whiteAsEngineFlag == TRUE && m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
								m_whiteEngine.WriteToEngine("pause");
							else if(m_blackAsEngineFlag == TRUE && m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
								m_blackEngine.WriteToEngine("pause");
						}
					}
				}
				break;
			case OBSERVER:
				{
					memcpy(&m_clientId,&data[1],4);
					((CClientSocket*)m_pClientSocket)->m_clientId = m_clientId;
					CString msg = (CString)&data[5] + (CString)" Accepted you as observer";
					m_observerFlag = TRUE;
					m_manualEditingFlag = FALSE;
					AfxMessageBox(msg);
					unsigned char data1[50];
					memset(data1,'\0',50);
					data1[0] = SYNC_REQUEST;
					memcpy(&data1[1], &m_clientId,4);
					SendSockData(data1,5);
				}
				break;
			case SYNC_REQUEST:
				{
					//Send sync with server
					unsigned char data1[5000];
					CStringArray ar;
					CString str = GetHistoryString(ar,0);
					str += "*\r\n\r\n";
					memset(data1,'\0',5000);
					data1[0]=SYNC_SERVER;
					int clientid;
					memcpy(&clientid,&data[1],4);
					memcpy(&data1[1],&clientid,4);
					int length = str.GetLength() + 6;
					strcpy((char*)&data1[5],str.GetBuffer(0));
					SendObserverData(data1,length);			
				}
				break;
			case SYNC_SERVER:
				{
					int clientid;
					memcpy(&clientid,&data[1],4);
					if(clientid == ((CClientSocket*)m_pClientSocket)->m_clientId)
						doPGNRead(&data[5],'s');
				}
				break;
			case POSITION_DATA:
				{
					doFENPositionRead(&data[1],'F');
				}
				break;		
			case ARE_YOU_OK:
				{				
					unsigned char data1[5];				
					data1[0] = YES_IAM_FINE;
					memcpy(&data1[1],&data[1],4);
					SendSockData(data1,5);			
				}
				break;
			case YES_IAM_FINE:
				{
					int clientid;
					memcpy(&clientid,&data[1],4);
					if(clientid == ((CClientSocket*)m_pClientSocket)->m_clientId)
						AfxMessageBox("Yes. I am fine!");
				}			
				break;
			case ENGINE_DATA:
				{
					if(m_whiteAsEngineFlag == TRUE)
						m_whiteEngine.WriteToEngine(&data[1]);
					if(m_blackAsEngineFlag == TRUE)
						m_blackEngine.WriteToEngine(&data[1]);
				}
			default:
				break;
		}
	}
	SendObserverData(data,length);
	SetShellIconData("Received data",NIM_ADD);				 
	KillTimer(SHELL_ICON_TIMER_EVENT_ID);
	SetTimer(SHELL_ICON_TIMER_EVENT_ID,1000,NULL);
	m_timerFlag = true; 
}
void CNetChessView::HandleEngineData(COLOR_TYPE ct,CString data)
{
	//WB protocol
	int ret = data.Find("move ",0);	
	if(ret == 0)
	{
		//CString str = "Received message: " + data;
		//writeMessage(str.GetBuffer(0));
		int temp = m_iHistory;
		tempString = data.Right(data.GetLength() - (ret+4+1));
		writeMessage(tempString.GetBuffer(0));
		LPARAM l = CHECK_MOVE;				
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);
		/*if(m_iHistory != temp)
		{		
			return;
		}*/		
	}
	/*ret = data.Find("move ",0);	
	if(ret == 0)
	{

		/*int to_i,to_j;
		if(data.GetLength() >= (ret + 4+1+4))
		{
			if(m_white_on_top == false)
			{			
				m_point.y = (int)(data[ret + 4 + 1] -'a');
				m_point.x = (int)('8' - data[ret + 4 + 2]);
				to_j = (int)(data[ ret + 4 + 3] - 'a');
				to_i = (int)('8' - data[ ret + 4 + 4]);
			}
			else
			{
				m_point.y = 7-(int)(data[ret + 4 + 1] -'a');
				m_point.x = 7-(int)('8' - data[ret + 4 + 2]);
				to_j = 7-(int)(data[ ret + 4 + 3] - 'a');
				to_i = 7-(int)('8' - data[ ret + 4 + 4]);
			}
		}
		else
			return;
		if(data.GetLength() > (4+1+4))
		{
			if(data[4+1+4] != ' ')
			{	
				m_pickPieceDlg->m_pickpiecetype  = 1;
				char c = data[4+1+4];
				COLOR_TYPE ct;
				PIECE_TYPE pt;
				if(m_pieceSide == BLACK)
				{
					c = tolower(c);
					GetPieceInfo(c,ct,pt);
				}
				else
				{
					c = toupper(c);
					GetPieceInfo(c,ct,pt);
				}
				m_pickPieceDlg->m_piecked_piece = c;			
				m_pickPieceDlg->m_piece_color = ct;
				m_pickPieceDlg->m_piece_type = pt;		
			}
		}
		m_mouseMoveFlag = true;
		
		CRect rect=cb[to_i][to_j].GetRect();
		CPoint pt(rect.left+10,rect.top+10);
		//OnLButtonUpAction(0,pt);
		LPARAM l;
		char temp[4];
		memcpy(&temp[0],&pt.x,2);
		memcpy(&temp[2],&pt.y,2);
		memcpy(&l,temp,4);
		PostMessage(WM_LBUTTONUP,0,l);
		return;
	}*/
	//UCI protocol	
	ret = data.Find("bestmove ",0);
	if(ret == 0)
	{
		int temp = m_iHistory;
		tempString = data.Right(data.GetLength() - (ret+8+1));
		int ret = tempString.Find(' ');
		if(ret > 0)
			tempString = tempString.Left(ret);
		LPARAM l = CHECK_MOVE;				
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);
		if(m_iHistory != temp)
		{		
			return;
		}		
		/*int to_i,to_j;
		if(data.GetLength() >= (8+1+4))
		{

			if(m_white_on_top == false)
			{
				m_point.y = (int)(data[ret + 8 + 1] -'a');
				m_point.x = (int)('8' - data[ret + 8 + 2]);
				to_j = (int)(data[ ret + 8 + 3] - 'a');
				to_i = (int)('8' - data[ ret + 8 + 4]);
			}
			else
			{
				m_point.y = 7-(int)(data[ret + 8 + 1] -'a');
				m_point.x = 7-(int)('8' - data[ret + 8 + 2]);
				to_j = 7-(int)(data[ ret + 8 + 3] - 'a');
				to_i = 7-(int)('8' - data[ ret + 8 + 4]);
			}
		}
		else
			return;
		if(data.GetLength() > (8+1+4))
		{
			if(data[8+1+4] != ' ')
			{
				m_pickPieceDlg->m_pickpiecetype  = 1;
				char c = data[8+1+4];
				COLOR_TYPE ct;
				PIECE_TYPE pt;
				if(m_pieceSide == BLACK)
				{
					c = tolower(c);
					GetPieceInfo(c,ct,pt);
				}
				else
				{
					c = toupper(c);
					GetPieceInfo(c,ct,pt);
				}
				m_pickPieceDlg->m_piecked_piece = c;			
				m_pickPieceDlg->m_piece_color = ct;
				m_pickPieceDlg->m_piece_type = pt;		
			}
		}
		m_mouseMoveFlag = true;
		
		CRect rect=cb[to_i][to_j].GetRect();
		CPoint pt(rect.left+10,rect.top+10);
		//OnLButtonUpAction(0,pt);
		LPARAM l;
		char temp[4];
		memcpy(&temp[0],&pt.x,2);
		memcpy(&temp[2],&pt.y,2);
		memcpy(&l,temp,4);
		PostMessage(WM_LBUTTONUP,0,l);
		return;*/
	}
	//special move
	ret = data.Find(". ... ",0);	
	if(ret > 0)
	{
		int temp = m_iHistory;
		tempString = data.Right(data.GetLength() - (ret+5+1));
		LPARAM l = CHECK_MOVE;				
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);
		if(m_iHistory != temp)
		{		
			return;
		}		
		/*int to_i,to_j;
		if(data.GetLength() >= (5+1+4))
		{

			if(m_white_on_top == false)
			{
				m_point.y = (int)(data[ret + 5 + 1] -'a');
				m_point.x = (int)('8' - data[ret + 5 + 2]);
				to_j = (int)(data[ ret + 5 + 3] - 'a');
				to_i = (int)('8' - data[ ret + 5 + 4]);
			}
			else
			{
				m_point.y = 7-(int)(data[ret + 5 + 1] -'a');
				m_point.x = 7-(int)('8' - data[ret + 5 + 2]);
				to_j = 7-(int)(data[ ret + 5 + 3] - 'a');
				to_i = 7-(int)('8' - data[ ret + 5 + 4]);
			}
		}
		else
			return;
		if(data.GetLength() > (5+1+4))
		{
			if(data[5+1+4] != ' ')
			{	
				m_pickPieceDlg->m_pickpiecetype  = 1;
				char c = data[5+1+4];
				COLOR_TYPE ct;
				PIECE_TYPE pt;
				if(m_pieceSide == BLACK)
				{
					c = tolower(c);
					GetPieceInfo(c,ct,pt);
				}
				else
				{
					c = toupper(c);
					GetPieceInfo(c,ct,pt);
				}
				m_pickPieceDlg->m_piecked_piece = c;			
				m_pickPieceDlg->m_piece_color = ct;
				m_pickPieceDlg->m_piece_type = pt;		
			}
		}
		m_mouseMoveFlag = true;
		
		CRect rect=cb[to_i][to_j].GetRect();
		CPoint pt(rect.left+10,rect.top+10);
		//OnLButtonUpAction(0,pt);
		LPARAM l;
		char temp[4];
		memcpy(&temp[0],&pt.x,2);
		memcpy(&temp[2],&pt.y,2);
		memcpy(&l,temp,4);
		PostMessage(WM_LBUTTONUP,0,l);
		return;*/
	}
	//UCI protocol auther name and engine id
	ret = data.Find("id ",0);
	if(ret == 0)
	{
		ret = data.Find("name",0);
		if(ret > 0)
		{
			if(ct == BLACK)
			{				
				m_blackEngine.m_engineName = data.Right(data.GetLength() - (ret+4+1));
				m_gameInfoDlg.m_edit_black = m_blackEngine.m_engineName;
				return;
			}
			else
			{
				m_whiteEngine.m_engineName = data.Right(data.GetLength() - (ret - 5 -1));
				m_gameInfoDlg.m_edit_white = m_whiteEngine.m_engineName;
				return;
			}
		}
		ret = data.Find("author",0);
		if(ret > 0)
		{
			if(ct == BLACK)
			{
				m_blackEngine.m_engineAuthor =data.Right(data.GetLength() - (ret+6+1));
				return;
			}
			else
			{
				m_whiteEngine.m_engineAuthor = data.Right(data.GetLength() - (ret+6+1));
				return;
			}
		}
		return;
	}
	//UCI protocol,option parameters supported by the engine
	ret = data.Find("option",0);
	if(ret == 0)
	{
		data.Replace("\n","");
		data.Replace("\r","");
		if(ct == WHITE)
		{			
			m_whiteEngine.m_arrOptions.Add(data);
		}
		else
		{
			m_blackEngine.m_arrOptions.Add(data);
		}
		return;
	}
	//UCI all the options are sent
	ret = data.Find("uciok",0);
	if(ret == 0)
	{
		//show all option parameters
		
		if(ct == WHITE)
		{
			LPARAM l = WHITE_UCI_OPTIONS;			
			PostMessage(ID_MY_MESSAGE_ENGINE,0,l);
		}
		else if(ct == BLACK)
		{
			LPARAM l = BLACK_UCI_OPTIONS;			
			PostMessage(ID_MY_MESSAGE_ENGINE,0,l);
		}	
		return;
	}
	ret = data.Find("readyok",0);
	if(ret == 0)
	{
		//UCI engine is ready to play
		if(ct == WHITE)
		{
			LPARAM l = WHITE_ISREADYOK;			
			PostMessage(ID_MY_MESSAGE_ENGINE,0,l);
		}
		else if(ct == BLACK)
		{
			LPARAM l = BLACK_ISREADYOK;			
			PostMessage(ID_MY_MESSAGE_ENGINE,0,l);
		}	
		return;
	}
	//check mate
	ret = data.Find("checkmate",0);
	if(ret == 0)
	{
		LPARAM l = CHECKMATE;				
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);
		return;
	}
	//check for feature command
	ret = data.Find("feature",0);
	if(ret == 0)
	{
		data.Replace("\n","");
		data.Replace("\r","");
		if(ct == WHITE)
		{			
			m_whiteEngine.m_arrFeatures.Add(data);
			LPARAM l = WHITE_FEATURES;				
			PostMessage(ID_MY_MESSAGE_ENGINE,0,l);
		}
		else
		{
			m_blackEngine.m_arrFeatures.Add(data);
			LPARAM l = BLACK_FEATURES;				
			PostMessage(ID_MY_MESSAGE_ENGINE,0,l);
		}
		return;
	}
	ret = data.Find("1-0",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{		
			l = WHITE_WON_WHITE;
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = WHITE_WON_BLACK;
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}
	ret = data.Find("0-1",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{			
			l = BLACK_WON_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = BLACK_WON_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}
	ret = data.Find("1/2-1/2",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{		
			l = MATCH_DRAWN_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = MATCH_DRAWN_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}
	ret = data.Find("offer draw",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{		
			l = MATCH_DRAWN_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = MATCH_DRAWN_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}
	ret = data.Find("Illegal move",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{			
			l = ILLEGAL_MOVE_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = ILLEGAL_MOVE_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}
	ret = data.Find("illegal move",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{			
			l = ILLEGAL_MOVE_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = ILLEGAL_MOVE_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}
	ret = data.Find("illegal user move",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{			
			l = ILLEGAL_MOVE_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = ILLEGAL_MOVE_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}

	ret = data.Find("Error",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{			
			l = ERROR_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = ERROR_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}	
	ret = data.Find("resign",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{			
			l = RESIGN_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = RESIGN_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}
	ret = data.Find("tellopponent",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{			
			l = TELLOPPONENT_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = TELLOPPONENT_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}
	ret = data.Find("tellothers",0);
	if(ret == 0)
	{
		LPARAM l;
		if(ct == WHITE)
		{			
			l = TELLOTHERS_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = TELLOTHERS_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}	

	ret = data.Find("Hint:",0);
	if(ret == 0)
	{		
		LPARAM l;
		if(ct == WHITE)
		{			
			l = HINT_WHITE;				
			m_whiteEngine.m_tempString = data;
		}
		else
		{
			l = HINT_BLACK;				
			m_blackEngine.m_tempString = data;
		}
		PostMessage(ID_MY_MESSAGE_ENGINE,0,l);		
		return;
	}	
	//writeMessage(data.GetBuffer(0));
}
void CNetChessView::OnMyEngineMessage(WPARAM wParam,LPARAM lParam)
{
	switch(lParam)
	{
		case CHECKMATE:
			AfxMessageBox("Checkmate");
			break;
		case WHITE_UCI_OPTIONS:
			{
				if(m_whiteEngine.m_arrOptions.GetSize() > 0)
				{
					CUCIEngineOptions dlg;				
					for(int i= 0;i< m_whiteEngine.m_arrOptions.GetSize(); i++)
					{
						dlg.m_edit_read_options += m_whiteEngine.m_arrOptions.GetAt(i);
						dlg.m_edit_read_options += "\r\n";
					}					
					dlg.DoModal();
					for(int i = 0; i < dlg.m_arrSetOptions.GetSize(); i++)
					{
						CString str = dlg.m_arrSetOptions.GetAt(i);
						str += "\n";
						m_whiteEngine.WriteToEngine(str);
					}
					
					m_whiteEngine.WriteToEngine("isready");
					
				}			
			}
			break;
		case BLACK_UCI_OPTIONS:
			{
				if(m_blackEngine.m_arrOptions.GetSize() > 0)
				{
					CUCIEngineOptions dlg;				
					for(int i= 0;i< m_blackEngine.m_arrOptions.GetSize(); i++)
					{
						dlg.m_edit_read_options += m_blackEngine.m_arrOptions.GetAt(i) + "\r\n";
					}
					dlg.DoModal();
					for(int i = 0; i < dlg.m_arrSetOptions.GetSize(); i++)
					{
						CString str = dlg.m_arrSetOptions.GetAt(i);
						str += "\n";
						m_blackEngine.WriteToEngine(str);
					}
					
					m_blackEngine.WriteToEngine("isready");
					
				}			
			}
			break;
		case BLACK_ISREADYOK:
			{
				AfxMessageBox("Black UCI engine is ready to play the game");
			}
			break;
		case WHITE_ISREADYOK:
			{
				AfxMessageBox("White UCI engine is ready to play the game");
			}
			break;
		case BLACK_FEATURES:
			{
				CString str = "";
				for(int i=0;i<m_blackEngine.m_arrFeatures.GetSize();i++)
				{
					str += m_blackEngine.m_arrFeatures.GetAt(i) + "\r\n";
				}
				if(m_blackEngine.m_arrFeatures.GetSize() > 0 && str.Find("done=1",0) >= 0)
				{
					//xMessageBox(str);
					m_blackEngine.parseFeatures();
					if(m_blackEngine.m_name == 1)
						m_gameInfoDlg.m_edit_black = m_blackEngine.m_myname;
					DrawBoard();

				}
			}
			break;
		case WHITE_FEATURES:
			{
				CString str = "";
				for(int i=0;i<m_whiteEngine.m_arrFeatures.GetSize();i++)
				{
					str += m_whiteEngine.m_arrFeatures.GetAt(i) + "\r\n";
				}
				if(m_whiteEngine.m_arrFeatures.GetSize() > 0 && str.Find("done=1",0) >= 0)
				{
					//xMessageBox(str);
					m_whiteEngine.parseFeatures();
					if(m_whiteEngine.m_name == 1)
						m_gameInfoDlg.m_edit_white = m_whiteEngine.m_myname;
					DrawBoard();
				}
			}
			break;
		case BLACK_WON_WHITE:
			{
				
				CString str;
				str = "result " + m_whiteEngine.m_tempString;
				m_blackEngine.WriteToEngine(str);

				m_pauseclockFlag = TRUE;
				unsigned char data[2];
				data[0] = CLOCK;
				data[1] = m_pauseclockFlag;
				SendSockData(data,2);
				unsigned char data1[200];
				memset(data1,'\0',200);
				memcpy(&data1[1],str.GetBuffer(0),str.GetLength());
				data1[0] = ENGINE_DATA;
				SendSockData(data1,str.GetLength()+2);
				AfxMessageBox(m_whiteEngine.m_tempString);				
			}
			break;
		case BLACK_WON_BLACK:
			{
				CString str;
				str = "result " + m_blackEngine.m_tempString;
				m_whiteEngine.WriteToEngine(str);

				m_pauseclockFlag = TRUE;
				unsigned char data[2];
				data[0] = CLOCK;
				data[1] = m_pauseclockFlag;
				SendSockData(data,2);
				unsigned char data1[200];
				memset(data1,'\0',200);
				memcpy(&data1[1],str.GetBuffer(0),str.GetLength());
				data1[0] = ENGINE_DATA;
				SendSockData(data1,str.GetLength()+2);
				AfxMessageBox(m_blackEngine.m_tempString);
			}
			break;
		case WHITE_WON_WHITE:
			{
				CString str;				
				str = "result " + m_whiteEngine.m_tempString;
				m_blackEngine.WriteToEngine(str);

				m_pauseclockFlag = TRUE;
				unsigned char data[2];
				data[0] = CLOCK;
				data[1] = m_pauseclockFlag;
				SendSockData(data,2);
				unsigned char data1[200];
				memset(data1,'\0',200);
				memcpy(&data1[1],str.GetBuffer(0),str.GetLength());
				data1[0] = ENGINE_DATA;
				SendSockData(data1,str.GetLength()+2);
				AfxMessageBox(m_whiteEngine.m_tempString);
			}
			break;
		case WHITE_WON_BLACK:
			{
				CString str;
				str = "result " + m_blackEngine.m_tempString;
				m_whiteEngine.WriteToEngine(str);

				m_pauseclockFlag = TRUE;
				unsigned char data[2];
				data[0] = CLOCK;
				data[1] = m_pauseclockFlag;
				SendSockData(data,2);
				unsigned char data1[200];
				memset(data1,'\0',200);
				memcpy(&data1[1],str.GetBuffer(0),str.GetLength());
				data1[0] = ENGINE_DATA;
				SendSockData(data1,str.GetLength()+2);
				AfxMessageBox(m_blackEngine.m_tempString);
			}
			break;
		case MATCH_DRAWN_WHITE:
			{
				CString str;
				str = "result " + m_whiteEngine.m_tempString;
				m_blackEngine.WriteToEngine(str);

				m_pauseclockFlag = TRUE;
				unsigned char data[2];
				data[0] = CLOCK;
				data[1] = m_pauseclockFlag;
				SendSockData(data,2);
				unsigned char data1[200];
				memset(data1,'\0',200);
				memcpy(&data1[1],str.GetBuffer(0),str.GetLength());
				data1[0] = ENGINE_DATA;
				SendSockData(data1,str.GetLength()+2);
				AfxMessageBox(m_whiteEngine.m_tempString);
			}
			break;
		case MATCH_DRAWN_BLACK:
			{
				CString str;
				str = "result " + m_blackEngine.m_tempString;
				m_whiteEngine.WriteToEngine(str);
				m_pauseclockFlag = TRUE;
				unsigned char data[2];
				data[0] = CLOCK;
				data[1] = m_pauseclockFlag;
				SendSockData(data,2);
				unsigned char data1[200];
				memset(data1,'\0',200);
				memcpy(&data1[1],str.GetBuffer(0),str.GetLength());
				data1[0] = ENGINE_DATA;
				SendSockData(data1,str.GetLength()+2);
				AfxMessageBox(m_blackEngine.m_tempString);
			}
			break;		
		case ACCEPT_DRAW_WHITE:
			{
			m_pauseclockFlag = TRUE;
			CString str = "offer draw";
			m_blackEngine.WriteToEngine("offer draw");
			unsigned char data[2];
			data[0] = CLOCK;
			data[1] = m_pauseclockFlag;
			SendSockData(data,2);
			unsigned char data1[200];
			memset(data1,'\0',200);
			memcpy(&data1[1],str.GetBuffer(0),str.GetLength());
			data1[0] = ENGINE_DATA;
			SendSockData(data1,str.GetLength()+2);
			AfxMessageBox("Draw offer accepted");
			}
			break;
		case ACCEPT_DRAW_BLACK:
			{
			m_pauseclockFlag = TRUE;
			CString str = "offer draw";
			m_whiteEngine.WriteToEngine("offer draw");
			unsigned char data[2];
			data[0] = CLOCK;
			data[1] = m_pauseclockFlag;
			SendSockData(data,2);
			unsigned char data1[200];
			memset(data1,'\0',200);
			memcpy(&data1[1],str.GetBuffer(0),str.GetLength());
			data1[0] = ENGINE_DATA;
			SendSockData(data1,str.GetLength()+2);
			AfxMessageBox("Draw offer accepted");
			}
			break;
		case ILLEGAL_MOVE_WHITE:
			//AfxMessageBox(m_whiteEngine.m_tempString);
			break;
		case ILLEGAL_MOVE_BLACK:
			//AfxMessageBox(m_blackEngine.m_tempString);
			break;
		case ERROR_WHITE:
			AfxMessageBox(m_whiteEngine.m_tempString);
			break;
		case ERROR_BLACK:
			AfxMessageBox(m_blackEngine.m_tempString);
			break;
		case HINT_BLACK:
			//AfxMessageBox(m_blackEngine.m_tempString);
			SetPaneText(MESSAGEPANE,m_blackEngine.m_tempString);
			break;
		case HINT_WHITE:
			SetPaneText(MESSAGEPANE,m_whiteEngine.m_tempString);
			//AfxMessageBox(m_whiteEngine.m_tempString);
			break;
		case RESIGN_WHITE:
			{
			m_pauseclockFlag = TRUE;
			CString str = "resign";
			m_whiteEngine.WriteToEngine("resign");
			unsigned char data[2];
			data[0] = CLOCK;
			data[1] = m_pauseclockFlag;
			SendSockData(data,2);
			unsigned char data1[200];
			memset(data1,'\0',200);
			memcpy(&data1[1],str.GetBuffer(0),str.GetLength());
			data1[0] = ENGINE_DATA;
			SendSockData(data1,str.GetLength()+2);
			AfxMessageBox(m_whiteEngine.m_tempString);
			}
			break;
		case RESIGN_BLACK:
			{
			m_pauseclockFlag = TRUE;
			CString str = "resign";
			m_blackEngine.WriteToEngine("resign");
			unsigned char data[2];
			data[0] = CLOCK;
			data[1] = m_pauseclockFlag;
			SendSockData(data,2);
			unsigned char data1[200];
			memset(data1,'\0',200);
			memcpy(&data1[1],str.GetBuffer(0),str.GetLength());
			data1[0] = ENGINE_DATA;
			SendSockData(data1,str.GetLength()+2);
			AfxMessageBox(m_blackEngine.m_tempString);
			}
			break;
		case TELLOPPONENT_WHITE:
		case TELLOTHERS_WHITE:
			AfxMessageBox(m_whiteEngine.m_tempString);
			break;
		case TELLOPPONENT_BLACK:
		case TELLOTHERS_BLACK:
			AfxMessageBox(m_blackEngine.m_tempString);
			break;
		case CHECK_MOVE:			
			PGNMove(tempString.GetBuffer(0),m_pieceSide);
			tempString = "";
		
			break;
		default:
			break;
	}
}
void CNetChessView::SendSockData(unsigned char *data,int length)
{
	if(m_pClientICSSocket != NULL || m_pClientSocket != NULL)
	{
		//AfxMessageBox((char*)data);
		if(data[0] == MOVE)
		{
			if(m_ICSToBoardFlag == FALSE)
			{
				m_BoardToICSFlag = TRUE;
				CString str = GetSingleMoveString(m_iHistory) + "\r\n";
				//OnEditUndoAction(1);
				//AfxMessageBox(str);
				
				if(m_pClientICSSocket != NULL)
				m_pClientICSSocket->Send(str.GetBuffer(0),str.GetLength());	
				if(m_pICSWindowDlg != NULL)
				{
					m_pICSWindowDlg->m_edit_ics_log = m_pICSWindowDlg->m_edit_ics_log + str;		
					m_pICSWindowDlg->Update(IDC_EDIT_ICS_LOG);
				}			
				//SendObserverData(data,length);			
				//SendToEngine(data,length);				

			}
			if(m_moveFlag == FALSE && m_ICSToBoardFlag == TRUE)
			{
				SendToEngine((unsigned char*)data, length);
				m_moveFlag = FALSE;
			}						
			
			
			m_ICSToBoardFlag = FALSE;
		}		
	}
	if(data[0] == MOVE && m_mailClientFlag == TRUE)
	{
		SendMail((char*)data,length);	
	}
	char clength[5];	 
	memcpy(clength,&length,4);
	if(m_pClientSocket != NULL && m_moveFlag == FALSE)
	{	 
		if(m_observerFlag == TRUE && data[0] != OBSERVER_TEXT && data[0] != SYNC_REQUEST && data[0]!= ARE_YOU_OK)
		{
			return;
		}
		m_pClientSocket->Send(clength,4);	 
		m_pClientSocket->Send(data,length);	
	}
	SendObserverData(data,length);
	//if(m_pClientSocket == NULL )
	SendToEngine(data,length);
	
}
void CNetChessView::SendObserverData(unsigned char *data,int length)
{	
	switch(data[0])
	{
		case NEWGAME:
		case MOVE:
		case TEXT:
		case PGNFILE:
		case UNDO:
		case REDO:
		case MOVEFIRST:
		case MOVELAST:
		case REFRESH:
		case GOTO:
		case OBSERVER:
		case OBSERVER_TEXT:
		case GAMEINFO:	
		case SYNC_SERVER:
		case FILEDATA:
		case POSITION_DATA:
		case ARE_YOU_OK:
		{
			POSITION pos = m_pObserverSocketList.GetHeadPosition();
			for(int i=0;i < m_pObserverSocketList.GetCount();i++)
			{
				CClientSocket *csock = (CClientSocket*)m_pObserverSocketList.GetNext(pos);
				char clength[5];	 
				memcpy(clength,&length,4);
				int clientid = -1;
				if(data[0] == OBSERVER_TEXT || data[0] == SYNC_SERVER || data[0] == ARE_YOU_OK)
				{
					memcpy(&clientid,&data[1],4);
				}
				if(csock != NULL) 
				{	 
					if(csock->m_clientId != clientid || data[0] == SYNC_SERVER)
					{
						csock->Send(clength,4);	 
						csock->Send(data,length);	 	
					}
					else
					{						
						m_pClientSocket->Send(clength,4);
						m_pClientSocket->Send(data,length);
					}
				}
			}
		}
		break;
		default:
			break;
	}
}
void CNetChessView::SendToEngine(unsigned char *data,int length)
{	
	switch(data[0])
	{
		case MOVE:
			{				
				/****for UCI engine FEN side*/
				char side;
				if(m_pClientSocket != NULL)
				{
					if(m_whiteAsEngineFlag == TRUE)
						side = 'w';
					else if(m_blackAsEngineFlag == TRUE)
						side = 'b';
				}
				else
				{
					if(m_pieceSide == WHITE && m_whiteAsEngineFlag == TRUE)
						side = 'w';
					else if(m_pieceSide == BLACK && m_blackAsEngineFlag == TRUE)
						side= 'b';
				}
				/*****end FEN side*****/
				CString move = "";
				if(m_pClientSocket != NULL)
				{
					if(m_whiteAsEngineFlag == TRUE)
					{
						if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol ==  WB_I)
						{
							move = GetSingleMoveStringOldFormat(m_iHistory);
							 
						}
						else if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol ==  WB_II)
						{				
							move = GetSingleMoveStringOldFormat(m_iHistory);//GetSingleMoveString(m_iHistory);
						}
						else //UCI move
						{
							if(m_optDlg.m_UCImove == 1)//FENSTRING
							{
								int movecount = m_iHistory/2;								
								CString position = GetPositionString('F',movecount,side);
								position.Replace("\r\n","");
								CString str;
								str = "startpos FEN " + position + " moves ";
								for(int i=0;i<=m_iHistory;i++)
									str += GetSingleMoveStringOldFormat(i) + (CString)" ";
								move = str + "\ngo btime 300000 wtime 300000\n";								
							}
							else
							{
								CString str;
								str.Format("position startpos moves ");
								for(int i=0;i<=m_iHistory;i++)
								 str += GetSingleMoveStringOldFormat(i) + (CString)" ";
								move = str + "\ngo btime 300000 wtime 300000\n";
							}
						}
					}
					else if(m_blackAsEngineFlag == TRUE)
					{
						if(m_blackEngine.m_engineConfigDlg.m_chessProtocol ==  WB_I)
						{
							move = GetSingleMoveStringOldFormat(m_iHistory);
							 
						}
						else if(m_blackEngine.m_engineConfigDlg.m_chessProtocol ==  WB_II)
						{				
							move = GetSingleMoveStringOldFormat(m_iHistory);//GetSingleMoveString(m_iHistory);
						}
						else //UCI move
						{
							if(m_optDlg.m_UCImove == 1)//FENSTRING
							{
								int movecount = m_iHistory/2;								
								CString position = GetPositionString('F',movecount,side);
								position.Replace("\r\n","");
								CString str;
								str = "startpos FEN " + position + " moves ";
								for(int i=0;i<=m_iHistory;i++)
									str += GetSingleMoveStringOldFormat(i) + (CString)" ";
								move = str + "\ngo btime 300000 wtime 300000\n";								
							}
							else
							{
								CString str;
								str.Format("position startpos moves ");
								for(int i=0;i<=m_iHistory;i++)
								 str += GetSingleMoveStringOldFormat(i) + (CString)" ";
								move = str + "\ngo btime 300000 wtime 300000\n";
							}
						}
					}
				}
				else
				{
					if(m_pieceSide == WHITE && m_whiteAsEngineFlag == TRUE)
					{
						if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol ==  WB_I)
						{
							move = GetSingleMoveStringOldFormat(m_iHistory);
							 
						}
						else if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol ==  WB_II)
						{				
							move = GetSingleMoveStringOldFormat(m_iHistory);//GetSingleMoveString(m_iHistory);
						}
						else //UCI move
						{
							if(m_optDlg.m_UCImove == 1)//FENSTRING
							{
								int movecount = m_iHistory/2;								
								CString position = GetPositionString('F',movecount,side);
								position.Replace("\r\n","");
								CString str;
								str = "startpos FEN " + position + " moves ";
								for(int i=0;i<=m_iHistory;i++)
									str += GetSingleMoveStringOldFormat(i) + (CString)" ";
						
								move = str + "\ngo btime 300000 wtime 300000\n";								
							}
							else
							{
								CString str;
								str.Format("position startpos moves ");
								for(int i=0;i<=m_iHistory;i++)
								 str += GetSingleMoveStringOldFormat(i) + (CString)" ";
								move = str + "\ngo btime 300000 wtime 300000\n";
							}
						}
					}
					else if(m_pieceSide == BLACK  && m_blackAsEngineFlag == TRUE)
					{
						if(m_blackEngine.m_engineConfigDlg.m_chessProtocol ==  WB_I)
						{
							move = GetSingleMoveStringOldFormat(m_iHistory);
							 
						}
						else if(m_blackEngine.m_engineConfigDlg.m_chessProtocol ==  WB_II)
						{				
							move = GetSingleMoveStringOldFormat(m_iHistory);//GetSingleMoveString(m_iHistory);
						}
						else //UCI move
						{
							if(m_optDlg.m_UCImove == 1)//FENSTRING
							{
								int movecount = m_iHistory/2;								
								CString position = GetPositionString('F',movecount,side);
								position.Replace("\r\n","");
								CString str;
								str = "startpos FEN " + position + " moves ";
								for(int i=0;i<=m_iHistory;i++)
									str += GetSingleMoveStringOldFormat(i) + (CString)" ";
						
								move = str + "\ngo btime 300000 wtime 300000\n";								
							}
							else
							{
								CString str;
								str.Format("position startpos moves ");
								for(int i=0;i<=m_iHistory;i++)
								 str += GetSingleMoveStringOldFormat(i) + (CString)" ";
								move = str + "\ngo btime 300000 wtime 300000\n";
							}
						}

					}
				}
				/*if(m_pClientSocket != NULL || m_pClientICSSocket != NULL)
				{				
					if(m_whiteAsEngineFlag == TRUE && m_whiteEngineOnlyAnalyze == FALSE )
						m_whiteEngine.WriteToEngine(move);
					if(m_blackAsEngineFlag == TRUE && m_blackEngineOnlyAnalyze == FALSE)
						m_blackEngine.WriteToEngine(move);
				}
				else*/
				{
					if(m_pieceSide == WHITE && m_whiteAsEngineFlag == TRUE && m_whiteEngineOnlyAnalyze == FALSE)
						m_whiteEngine.WriteToEngine(move);
					if(m_pieceSide == BLACK && m_blackAsEngineFlag == TRUE && m_blackEngineOnlyAnalyze == FALSE)
						m_blackEngine.WriteToEngine(move);
				}
			}
			break;
		case NEWGAME:						
				if(m_whiteAsEngineFlag == TRUE)
				{
					if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_I ||
						m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
						m_whiteEngine.WriteToEngine("new");
					else
						m_whiteEngine.WriteToEngine("ucinewgame");
				}
				if(m_blackAsEngineFlag == TRUE)
				{
					if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_I ||
						m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
						m_blackEngine.WriteToEngine("new");
					else
						m_blackEngine.WriteToEngine("ucinewgame");					
				}
			break;
		case OBSERVER_TEXT:
			{	
				//what to here
			}
			break;
		case TEXT:
			{	
				//what to here
			}
			break;
	 
		case FILEDATA://obsolete
			{
				/*Initialize();
//				OnInitialUpdate();
				if(m_white_on_top == true)
				{
					FlipBoard();
					m_white_on_top = false;
				}
				for(int i = 0; i< 8; i++)
				{
					for(int j=0;j<8;j++)
					{
						cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					}
				} 
				int count = 1, total = 0, totLines=0;				
				memcpy(&total, &data[1],4);
				count+=4;				
				while(totLines < total)
				{			
					int i,j;			
					PIECE_TYPE piece_type;
					COLOR_TYPE piece_color;
					int pieceid;
					i = data[count++];
					j = data[count++];
					piece_type = (PIECE_TYPE)data[count++];
					piece_color = (COLOR_TYPE)data[count++];
					memcpy(&pieceid,&data[count],4);
					count += 4;
					cb[i][j].SetPieceData(pieceid,piece_color,piece_type,PIECE_NOT_MOVING);
					totLines++;
				}				
				DrawBoard();*/
			}
			break;
		case PGNFILE:
			{		
				//force the board setup
				//	Initialize();
				//	m_fileReadFlag = data[1];
				
			}
			break;
		case REFRESH://no equavlant is available 
			{
				//m_demoTotal = data[1];
				//DrawBoard();
			}
			break;
		case UNDO:
			{
				int movecount = m_iHistory/2;
				char side = m_pieceSide == WHITE ? 'w' : 'b';
				CString str = GetPositionString('F',movecount,side);
				if(m_whiteAsEngineFlag == TRUE)
					SetEnginePosition(m_whiteEngine, str);
				if(m_blackAsEngineFlag == TRUE)
					SetEnginePosition(m_blackEngine, str);				

				/*if(m_whiteAsEngineFlag == TRUE)
					m_whiteEngine.WriteToEngine("undo");
				if(m_blackAsEngineFlag == TRUE)
					m_blackEngine.WriteToEngine("undo");*/
			}
			break;
		case REDO:
			{			
				int movecount = m_iHistory/2;
				char side = m_pieceSide == WHITE ? 'w' : 'b';
				CString str = GetPositionString('F',movecount,side);
				if(m_whiteAsEngineFlag == TRUE)
					SetEnginePosition(m_whiteEngine, str);
				if(m_blackAsEngineFlag == TRUE)
					SetEnginePosition(m_blackEngine, str);				
				//stop the engine
				//Set the board position
				//set the player turn
				//DrawBoard();
			}
			break;
		case MOVEFIRST:
			{
				//stop the engine
				//Set the board positon
				//set the player
				int movecount = m_iHistory/2;
				char side = m_pieceSide == WHITE ? 'w' : 'b';
				CString str = GetPositionString('F',movecount,side);
				if(m_whiteAsEngineFlag == TRUE)
					SetEnginePosition(m_whiteEngine, str);
				if(m_blackAsEngineFlag == TRUE)
					SetEnginePosition(m_blackEngine, str);				
				/*int total = m_iHistory;
				for(int i=0;i<=total;i++)
				{
					if(m_whiteAsEngineFlag == TRUE)
						m_whiteEngine.WriteToEngine("undo");
					if(m_blackAsEngineFlag == TRUE)
						m_blackEngine.WriteToEngine("undo");
				}*/					
				//DrawBoard();
			}
			break;
		case MOVELAST:
			{
				//stop the engine
				//Set the board positon
				//set the player

				//int total = m_topHistory;
				//for(int i=0;i<=total;i++)
				//{
				//	OnEditRedoAction(0); 		
				//}					
				//DrawBoard();
				int movecount = m_iHistory/2;
				char side = m_pieceSide == WHITE ? 'w' : 'b';
				CString str = GetPositionString('F',movecount,side);
				if(m_whiteAsEngineFlag == TRUE)
					SetEnginePosition(m_whiteEngine, str);
				if(m_blackAsEngineFlag == TRUE)
					SetEnginePosition(m_blackEngine, str);				
			}
			break;
		case GOTO:
			{
				//stop the engine
				//Set the board positon
				//set the player

				/*int total = m_iHistory;
				int pos;
				memcpy(&pos,&data[1],4);				
				for(int i=0;i<=total;i++)
				{
					OnEditUndoAction(0); 			
				}	
				for(i=1;i<=pos;i++)
				{
					OnEditRedoAction(0);				
				}
				m_demoTotal = pos;
				DrawBoard();*/
				int movecount = m_iHistory/2;
				char side = m_pieceSide == WHITE ? 'w' : 'b';
				CString str = GetPositionString('F',movecount,side);
				if(m_whiteAsEngineFlag == TRUE)
					SetEnginePosition(m_whiteEngine, str);
				if(m_blackAsEngineFlag == TRUE)
					SetEnginePosition(m_blackEngine, str);				
			}
			break;		
		case CONNECT_REJECT:
				break;
		case RESIGN_REQUEST:
			{
				if(m_pieceSide == WHITE && m_whiteAsEngineFlag == TRUE)
					m_whiteEngine.WriteToEngine("resign");
				else if(m_pieceSide == BLACK && m_blackAsEngineFlag == TRUE)
					m_blackEngine.WriteToEngine("resign");
			
			}
			break;
		case RESIGN_ACCEPT:
			break;
		case RESIGN_REJECT:
			break;
		case DRAW_REQUEST:
			{
				if(m_pieceSide == WHITE && m_whiteAsEngineFlag == TRUE)
					m_whiteEngine.WriteToEngine("draw");
				else if(m_pieceSide == BLACK && m_blackAsEngineFlag == TRUE)
					m_blackEngine.WriteToEngine("draw");
			}
			break;
		case DRAW_ACCEPT:
			{
			}
			break;
		case DRAW_REJECT:
			{	
			}
			break;
		case CONNECT_REQUEST:
			{
			}
			break;
		case CONNECT_INFO:
			{
				
			}
		break;
		case CONNECT_ACCEPT:
			{
				
			}
			break;
		case CHECKLEGALMOVE:
			break;
		case MANUALEDITING_START:
			{
			
			}
			break;
		case MANUALEDITING_END:
			break;
		case MANUALEDITING_EMPTY:
			if(m_whiteAsEngineFlag == TRUE)
			{
				m_whiteEngine.WriteToEngine("edit");
				m_whiteEngine.WriteToEngine("#");
				m_whiteEngine.WriteToEngine(".");
			}
			if(m_blackAsEngineFlag == TRUE)
			{
				m_blackEngine.WriteToEngine("edit");			
				m_blackEngine.WriteToEngine("#");
				m_blackEngine.WriteToEngine(".");
			}
			break;
		case MANUALEDITING_ACCEPT:
			break;
		case MANUALEDITING_REJECT:
			break;
		case MANUALEDITING_PLAYER_TURN:
			if(m_whiteAsEngineFlag == TRUE)
			{
				if(m_pieceSide == WHITE)
					m_whiteEngine.WriteToEngine("black");
				else
					m_whiteEngine.WriteToEngine("white");
			}
			if(m_blackAsEngineFlag == TRUE)
			{
				if(m_pieceSide == WHITE)
					m_blackEngine.WriteToEngine("black");
				else
					m_blackEngine.WriteToEngine("white");				
			}
			break;
		case DEMO_START:
			{
				m_blackEngine.WriteToEngine("new");
				m_blackEngine.WriteToEngine("force");			
			}
			break;
		case DEMO_START_ACCEPT:
			{
			
			}
			break;
		case DEMO_REJECT:
			
			break;
		case DEMO_END:
			{
				int movecount = m_iHistory/2;
				char side = m_pieceSide == WHITE ? 'w' : 'b';
				CString str = GetPositionString('F',movecount,side);
				if(m_whiteAsEngineFlag == TRUE)
					SetEnginePosition(m_whiteEngine, str);
				if(m_blackAsEngineFlag == TRUE)
					SetEnginePosition(m_blackEngine, str);				
			}			
			break;
		case GAMEINFO:
			{
			
			}
			break;
		case CLOCK:
			{
			
			}
			break;
		case OBSERVER:
			{
			
			}
			break;
		case SYNC_REQUEST:
			{
			
			}
			break;
		case SYNC_SERVER:
			{
			
			}
			break;
		case POSITION_DATA:
			{
				int movecount = m_iHistory/2;
				char side = m_pieceSide == WHITE ? 'w' : 'b';
				CString str = GetPositionString('F',movecount,side);
				if(m_whiteAsEngineFlag == TRUE)
					SetEnginePosition(m_whiteEngine, str);
				if(m_blackAsEngineFlag == TRUE)
					SetEnginePosition(m_blackEngine, str);				
			}
			break;		
		default:
			break;
	}
}

void CNetChessView::OnToolsSendmessage() 
{
	if(m_pClientSocket != NULL)
	{	 
		m_ChatDlg->ShowWindow(SW_SHOW);	
	}
	else
	{
		AfxMessageBox("Not connected to network");
	}
}

void CNetChessView::OnFileOpen() 
{
	if(m_iHistory > -1)
	{
		int ret = AfxMessageBox("Do you want to save the playing game",MB_YESNOCANCEL);
		if(ret == IDYES)
		{
			OnFileSave();			 
		}
		else if(ret == IDCANCEL)
		{
			return;
		}
	}
	CFileDialog fdialog(TRUE);
	if(fdialog.DoModal() == IDOK)
	{
		BeginWaitCursor();
		Initialize();	
		
		CString file = fdialog.GetPathName(); 
		if(fdialog.GetFileExt() == "FEN" || fdialog.GetFileExt() == "fen")
		{
			doFENRead(file,'f');
		}
		else if(fdialog.GetFileExt() == "PGN" || fdialog.GetFileExt() == "pgn")
		{
			doPGNRead(file,'f');
		}
		else if(fdialog.GetFileExt() == "EPD" || fdialog.GetFileExt() == "epd")
		{
			doEPDRead(file,'f');
		}
		if(m_iHistory > -1)
		{
			EndWaitCursor();
			return;
		}
		doPGNRead(file,'f');
		if(m_iHistory > -1)
		{
			EndWaitCursor();
			return;
		}		
		/*FILE *fp = fopen(file,"r");		 
		int count = 1, total = 0, totLines=0;
		fscanf(fp,"%d",&total);
		char data[2054];		 
		data[0] = FILEDATA;
		memcpy(&data[count],&total,4);
		count+=4;				
		while(!feof(fp) && totLines < total)
		{			 
			char str[10];
			int i;char j;			
			PIECE_TYPE piece_type;
			COLOR_TYPE piece_color;
			int pieceid;
			fscanf(fp,"%s",str);
 			pieceid = str[0];
			j = str[1] - 'a';
			i = (int)(str[2] - '0');
			GetPieceInfo(pieceid,piece_color,piece_type);
			data[count++] = i;
			data[count++] = j;
			data[count++] = piece_type;
			data[count++] = piece_color;
			memcpy(&data[count],&pieceid,4);
			count += 4;
			if(i >=0 && j>=0)
				cb[i][j].SetPieceData(pieceid,piece_color,piece_type,PIECE_NOT_MOVING);	
			totLines++;
		}		
		fclose(fp);					
		if(m_iHistory > -1)
		{
			SendSockData((unsigned char*)data,count);
		}
		else*/
		{
			if(m_gameInfoDlg.m_edit_fenstring.IsEmpty())
			{
				Initialize();
				if(m_white_on_top == true)
				{
					FlipBoard();
					m_white_on_top = false;
				}
				for(int i = 0; i< 8; i++)
				{
					for(int j=0;j<8;j++)
					{
						cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					}
				} 
				FILE *fp = fopen(file,"r");
				if(fp == NULL)
				{
					CString str;
					str.Format("Could not open the file %s",file);
					AfxMessageBox(str);
					return;
				}

				if(!feof(fp))
				{
					CString str="";
					while(!feof(fp))
					{
						char c;
						fscanf(fp,"%c",&c);
						if(c == '\n')
							break;
						str += c;
					}
					
					doFENPositionRead(str,'F');
					unsigned char data[1024];
					memset(data,'\0',1024);
					data[0] = POSITION_DATA;
					int count = 1;
					for(int i=0;i<str.GetLength();i++)
					{
						data[count++] = str[i];
					}
					SendSockData(data,count);
				}
				fclose(fp);
			
			}
		}
	}
	DrawBoard();	
}

void CNetChessView::OnFileOpen(CString str) 
{
	if(m_iHistory > -1)
	{
		int ret = AfxMessageBox("Do you want to save the playing game",MB_YESNOCANCEL);
		if(ret == IDYES)
		{
			OnFileSave();			 
		}
		else if(ret == IDCANCEL)
		{
			return;
		}
	}	
	{
		BeginWaitCursor();
		Initialize();		
		
		doFENRead(str,'s');
		if(m_iHistory > -1)
		{
			EndWaitCursor();
			return;
		}

		doPGNRead(str,'s');
		if(m_iHistory > -1)
		{
			EndWaitCursor();
			return;
		}		
		
		/*FILE* fp = fopen(".\\temp.chs","w+");
		fprintf(fp,str.GetBuffer(0));		
		fclose(fp);				
		
		fp = fopen(".\\temp.chs","r");		 
		int count = 1, total = 0, totLines=0;
		fscanf(fp,"%d",&total);
		char data[2054];		 
		data[0] = FILEDATA;
		memcpy(&data[count],&total,4);
		count+=4;				
		while(!feof(fp) && totLines < total)
		{			 
			char str[10];
			int i;char j;			
			PIECE_TYPE piece_type;
			COLOR_TYPE piece_color;
			int pieceid;
			fscanf(fp,"%s",str);
 			pieceid = str[0];
			j = str[1] - 'a';
			i = (int)(str[2] - '0');
			GetPieceInfo(pieceid,piece_color,piece_type);
			data[count++] = i;
			data[count++] = j;
			data[count++] = piece_type;
			data[count++] = piece_color;
			memcpy(&data[count],&pieceid,4);
			count += 4;
			if(i >=0 && j>=0)
				cb[i][j].SetPieceData(pieceid,piece_color,piece_type,PIECE_NOT_MOVING);	
			totLines++;
		}
		fclose(fp);					
		DeleteFile(".\\temp.chs");
		if(m_iHistory > -1)
		{
			SendSockData((unsigned char*)data,count);
		}
		else{
		*/
		if(m_gameInfoDlg.m_edit_fenstring.IsEmpty())
		{
			Initialize();
			if(m_white_on_top == true)
			{
				FlipBoard();
				m_white_on_top = false;
			}
			for(int i = 0; i< 8; i++)
			{
				for(int j=0;j<8;j++)
				{
					cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
				}
			} 
			doFENPositionRead(str,'F');
			unsigned char data[1024];
			memset(data,'\0',1024);
			data[0] = POSITION_DATA;
			int count = 1;
			for(int i=0;i<str.GetLength();i++)
			{
				data[count++] = str[i];
			}
			SendSockData(data,count);
		}
		/*else
		{
			doFENPositionRead(m_FENString,'F');
			unsigned char data[1024];
			memset(data,'\0',1024);
			data[0] = POSITION_DATA;
			int count = 1;
			for(i=0;i<m_FENString.GetLength();i++)
			{
				data[count++] = m_FENString[i];
			}
			SendSockData(data,count);
		}*/
		EndWaitCursor();
	}
	DrawBoard();	
}


void CNetChessView::OnFileSave() 
{
	// TODO: Add your command handler code here
	CFileDialog fdialog(FALSE);	

	if(m_fileName.IsEmpty())
	{
		if(fdialog.DoModal() == IDCANCEL)
		{
			return;
		}		
		CString file = fdialog.GetPathName(); 
		m_fileName = file;		
	}	
	BeginWaitCursor();
	FILE *fp = fopen(m_fileName,"w");
	if(fp == NULL)
	{
		CString str;
		str.Format("Could not open the file %s",m_fileName);
		AfxMessageBox(str);
		return;
	}

	if(m_fileName.Right(3) == "FEN" || m_fileName.Right(3) == "fen")
	{
		CString str = GetPositionHistoryString('F');
		str.Replace("\r","");
		fprintf(fp,"%s",str);
	}
	else if(m_fileName.Right(3) == "EPD" || m_fileName.Right(3) == "epd")
	{
		CString str = GetPositionHistoryString('E');
		str.Replace("\r","");
		fprintf(fp,"%s",str);
	}
	else
	{
		CStringArray ar;
		CString str = GetHistoryString(ar,0);
		str.Replace("\r","");
		fprintf(fp,"%s",str);
	}	
	EndWaitCursor();
	/*else
	{
		int count=0;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{				 
				PIECE_TYPE piece_type;
				COLOR_TYPE piece_color;
				int pieceid;
				STATE piece_state;
				cb[i][j].GetPieceData(pieceid,piece_color,piece_type,piece_state);
				if(piece_type != BLANK)
				{
				  count++;
				}
			}
		}

		fprintf(fp,"%d %d %d %d %d %d %d\n",count,m_optDlg.m_check_white_on_top,m_white_on_top, m_pieceSide, m_player_turn,m_whiteTime,m_blackTime);

		for(i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{				 
				PIECE_TYPE piece_type;
				COLOR_TYPE piece_color;
				int pieceid;
				STATE piece_state;
				cb[i][j].GetPieceData(pieceid,piece_color,piece_type,piece_state);
				if(piece_type != BLANK)
				{
				 fprintf(fp,"C %d %d %d %d %d\n",
 					 i,j,piece_type,piece_color,pieceid);
				}
			}
		}
		fprintf(fp,"%d\n",m_iHistory+1);
		 
		PIECE_SIDE piece_side;		 
		PIECE_TYPE from_piece_type;
		COLOR_TYPE from_color_type;
		int from_pieceid;
		int from_row_id;
		int from_col_id;
		PIECE_TYPE to_piece_type;
		COLOR_TYPE to_color_type;
		int to_pieceid;
		int to_row_id;
		int to_col_id;
		for(i=0;i<=m_iHistory;i++)
		{		 
			m_History[i].GetHistory(			 
				piece_side,from_piece_type,
				from_color_type,from_pieceid,
				from_row_id,from_col_id, to_piece_type,
				to_color_type,to_pieceid,to_row_id,
				to_col_id);
			int SpecialAction = m_History[i].GetSpecialAction();
			unsigned int action = m_History[i].GetPieceMoveAction();
			fprintf(fp,"H %d %d %d %d %d %d %d %d %d %d %d %d %u\n",
				piece_side,from_piece_type,
				from_color_type,from_pieceid,
				from_row_id,from_col_id, to_piece_type,
				to_color_type,to_pieceid,to_row_id,
				to_col_id, SpecialAction,action);	 
		} 	
	}*/
	fclose(fp);
	DrawBoard();
}

CString CNetChessView::GetFileSaveString() 
{
	// TODO: Add your command handler code here
	CString str = "";
	char cstr[500];
		int count=0;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{				 
				PIECE_TYPE piece_type;
				COLOR_TYPE piece_color;
				int pieceid;
				STATE piece_state;
				cb[i][j].GetPieceData(pieceid,piece_color,piece_type,piece_state);
				if(piece_type != BLANK)
				{
				  count++;
				}
			}
		}

	sprintf(cstr,"%d %d %d %d %d %d %d\n",count,m_white_on_top,m_white_on_top, m_pieceSide, m_player_turn,m_whiteTime,m_blackTime);
	str += cstr;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{				 
			PIECE_TYPE piece_type;
			COLOR_TYPE piece_color;
			int pieceid;
			STATE piece_state;
			cb[i][j].GetPieceData(pieceid,piece_color,piece_type,piece_state);
			if(piece_type != BLANK)
			{
			 memset(cstr,'\0',500);
			 sprintf(cstr,"C %d %d %d %d %d\n",
 				 i,j,piece_type,piece_color,pieceid);
			 str += cstr;
			}
		}
	}
	memset(cstr,'\0',500);
	sprintf(cstr,"%d\n",m_iHistory+1);
	str += cstr;
	 
	PIECE_SIDE piece_side;		 
	PIECE_TYPE from_piece_type;
	COLOR_TYPE from_color_type;
	int from_pieceid;
	int from_row_id;
	int from_col_id;
	PIECE_TYPE to_piece_type;
	COLOR_TYPE to_color_type;
	int to_pieceid;
	int to_row_id;
	int to_col_id;
	for(int i=0;i<=m_iHistory;i++)
	{		 
		m_History[i].GetHistory(			 
			piece_side,from_piece_type,
			from_color_type,from_pieceid,
			from_row_id,from_col_id, to_piece_type,
			to_color_type,to_pieceid,to_row_id,
			to_col_id);
		int SpecialAction = m_History[i].GetSpecialAction();
		unsigned int action = m_History[i].GetPieceMoveAction();
		memset(cstr,'\0',500);
		sprintf(cstr,"H %d %d %d %d %d %d %d %d %d %d %d %d %u\n",
			piece_side,from_piece_type,
			from_color_type,from_pieceid,
			from_row_id,from_col_id, to_piece_type,
			to_color_type,to_pieceid,to_row_id,
			to_col_id, SpecialAction,action);	 
		str += cstr;
	} 	
	return str;
}

void CNetChessView::OnViewLetter() 
{
	// TODO: Add your command handler code here
	if(m_LetterFlag == false)
	{	 
		m_LetterFlag = true;
	}
	else
	{	 
		m_LetterFlag = false;
	}
	DrawBoard(); 
}

void CNetChessView::OnUpdateViewLetter(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_LetterFlag == false)
	{
		pCmdUI->SetCheck(0);	
	}
	else
	{
		pCmdUI->SetCheck(1);
	}
}

void CNetChessView::OnViewNumber() 
{
	// TODO: Add your command handler code here
	 if(m_NumberFlag == false)
	{	 
		m_NumberFlag = true;
	}
	else
	{	 
		m_NumberFlag = false;
	}
	DrawBoard();
}

void CNetChessView::OnUpdateViewNumber(CCmdUI* pCmdUI) 
{
	if(m_NumberFlag == false)
	{
		pCmdUI->SetCheck(0); 
	}
	else
	{
		pCmdUI->SetCheck(1);		 
	};
}
void CNetChessView::OnMessageColorData(WPARAM wParam,LPARAM lParam)
{	 
	DrawBoard();
}

void CNetChessView::OnFileSavehistory() 
{
	// TODO: Add your command handler code here
	if(m_iHistory < 0)
	{
		AfxMessageBox("Game not started");
		return;
	}
	CFileDialog fdialog(FALSE);
	if(fdialog.DoModal() == IDOK)
	{
		CString file = fdialog.GetPathName(); 
		FILE *fp = fopen(file,"w");
		if(fp == NULL)
		{
			CString str;
			str.Format("Could not open the file %s",file);
			AfxMessageBox(str);
			return;
		}
		CStringArray cr;
		CString m_edit_history = GetHistoryString(cr,0);		 
		fprintf(fp,"%s",m_edit_history.GetBuffer(0));
		m_edit_history.ReleaseBuffer(0);
		fclose(fp);
	}
	DrawBoard();
}
void CNetChessView::SetEnginePosition(CEngine& engine, CString position)
{	
	if(engine.m_engineConfigDlg.m_chessProtocol == WB_I )
	{
		int i=0;
		int j=0;
		char file[1024],side[2],castlingInfo[5],enpassentInfo[3];	
		char currentColor = 'w';
		memset(file,'\0',1024);

		sscanf(position.GetBuffer(0),"%s%s%s%s",file,side,castlingInfo,
			enpassentInfo);
		if(side[0] == 'b')
		{
			engine.WriteToEngine("new");		
			engine.WriteToEngine("force");
			engine.WriteToEngine("a2a3");
			engine.WriteToEngine("edit");
			engine.WriteToEngine("#");//clear the board
			m_pieceSide = BLACK;
			m_player_turn = true;
			currentColor = 'b';
		}
		else
		{
			engine.WriteToEngine("new");
			engine.WriteToEngine("force");
			engine.WriteToEngine("edit");
			engine.WriteToEngine("#");//clear the board
			m_pieceSide = WHITE;
			m_player_turn = true;
		}
		
		for(int k=0;k < (int)strlen(file) && file[k] != ' ';k++)
		{
			if(file[k] >= '1' && file[k] < '9')
			{
				int total = (int)(file[k] - '0');
				for(int count=0;count<total;count++,j++);			
			}
			else if(file[k] == '/')
			{
				j=0;
				i++;
			}
			else if(file[k] != ' ')
			{
				COLOR_TYPE ct;
				PIECE_TYPE pt;
				GetPieceInfo(file[k],ct,pt);
				CString str;			
				str.Format("%c%c%d",toupper(file[k]),'a' + j, 8 - i);			
				if(file[k] >='a' && file[k] <='z')
				{
					if(currentColor == 'b')
						engine.WriteToEngine(str);
					else
					{
						engine.WriteToEngine("c");
						engine.WriteToEngine(str);
						currentColor = 'b';
					}
				}
				else
				{
					if(currentColor == 'w')
						engine.WriteToEngine(str);
					else
					{
						engine.WriteToEngine("c");
						engine.WriteToEngine(str);
						currentColor = 'w';
					}
				}
				//cb[i][j].SetPieceData(file[k],ct,pt,PIECE_NOT_MOVING);
				j++;
			}
		}
		//set piece side	
		
		engine.WriteToEngine(".");//leave the setup
		//engine.WriteToEngine("force");//leave the setup
	}
	else if (engine.m_engineConfigDlg.m_chessProtocol == WB_II)
	{
		CString str;
		str = "setboard " + position;
		engine.WriteToEngine("new");
		engine.WriteToEngine(str);
	///	engine.WriteToEngine("go");
	}
	else if(engine.m_engineConfigDlg.m_chessProtocol == UCI_I ||
		engine.m_engineConfigDlg.m_chessProtocol == UCI_II)
	{
		engine.WriteToEngine("new");
		CString str;
		str = "startpos FEN " + position;
		engine.WriteToEngine(str);
		if(engine.m_pondorFlag == TRUE)
		{
			if(m_iHistory > 0 && (m_engineLevelDlg.m_edig_movestimecontrol - m_iHistory/2) > 0)
				str.Format("go ponder movestogo %d",m_engineLevelDlg.m_edig_movestimecontrol - m_iHistory/2);
			else
				engine.WriteToEngine(str);
		}
		else
		{
			engine.WriteToEngine("go");
		}
	}

	//set flags	
	//set enpassent availability, it will take some time	*/
}
CString CNetChessView::GetPositionString(int type, int& movecount, char &side)
{
	int flipflag = FALSE;
	if(m_white_on_top == true)
	{
		FlipBoard();
		flipflag = TRUE;
	}

	CString returnstr = "";
	for(int i=0;i<8;i++)
	{
		int spacecount = 0;
		for(int j=0;j<8;j++)
		{
			if(cb[i][j].GetPieceId() == -1)
				spacecount++;
			else
			{
				
				CString str;
				if(spacecount == 0)
					str.Format("%c",cb[i][j].GetPieceId());
				else
					str.Format("%d%c",spacecount,cb[i][j].GetPieceId());
				returnstr += str;
				spacecount = 0;
			}
		}
		if(spacecount != 0)
		{
			CString str;
			str.Format("%d",spacecount);
			returnstr += str;
		}
		if(i != 7)
			returnstr += '/';
	}			
	
	CString str;
	/*if(k == -1)
	{
		str.Format(" - KQkq - 0 0\r\n");
		returnstr += str;
	}
	else*/
	{
		CString castlinginfo;			
		if(m_whiteKingMovedFlag == false)
		{
			if(m_whiteRookRank7MovedFlag == false)
			{
				castlinginfo += "K";
			}
			if(m_whiteRookRank1MovedFlag == false)
			{
				castlinginfo += "Q";
			}
		}
		if(m_blackKingMovedFlag == false)
		{
			if(m_blackRookRank7MovedFlag == false)
			{
				castlinginfo += "k";
			}
			if(m_blackRookRank1MovedFlag == false)
			{
				castlinginfo += "q";
			}
		}
		if(movecount < 0)
		{
			castlinginfo = "KQkq";
		}
		if(castlinginfo.IsEmpty())
			castlinginfo = "-";
		// get enpassent data
		CString enpassentdata = "-";		
		if(m_iHistory -1 >= 0)
		{
			PIECE_SIDE piece_side;
			PIECE_TYPE from_piece_type;
			COLOR_TYPE from_color_type;
			int from_pieceid;
			int from_row_id;
			int from_col_id;
			PIECE_TYPE to_piece_type;
			COLOR_TYPE to_color_type;
			int to_pieceid;
			int to_row_id;
			int to_col_id;			
			m_History[m_iHistory-1].GetHistory(piece_side,from_piece_type,
					from_color_type,from_pieceid,
					from_row_id,from_col_id, to_piece_type,
					to_color_type,to_pieceid,to_row_id,
					to_col_id);
			if(from_pieceid == 'P' && from_row_id == 6 && to_row_id == 4)
			{
				enpassentdata.Format("%c3",'a' + from_col_id);
			}
			else if(from_pieceid == 'p' && from_row_id == 1 && to_row_id == 3)
			{
				enpassentdata.Format("%c6",'a' + from_col_id);
			}
		}
		CString movenumber="";
		if(side == 'b')
		{
			movecount++;
		}		
		if(type == 'F')
		{			
			if(m_iHistory > -1)
				movenumber.Format("%d %d",m_History[m_iHistory].GetHalfMoveCount(),movecount);
			else
				movenumber.Format("0 1");
		}
		CString commentstr="";
		if(type == 'E')
		{
			if(m_optDlg.m_check_save_with_history == TRUE)
			{
				if(m_iHistory >= 0)
					commentstr.Format( "c0 \"%s\";",m_History[m_iHistory].GetComment());
			}
		}
		
		if(side == 'b')
		{
			str.Format(" %c %s %s %s %s\r\n",side,castlinginfo,enpassentdata,movenumber,commentstr);
		}
		else
		{
			str.Format(" %c %s %s %s %s\r\n",side,castlinginfo,enpassentdata, movenumber, commentstr);
		}		
		//side = side == 'w' ? 'b' : 'w';
		returnstr += str;		
	}
	if(flipflag == TRUE)
	{
		FlipBoard();
		m_white_on_top = true;;
	}
	return returnstr;
}
CString CNetChessView::GetSingleMoveString(int i)
{
	CString str;
	PIECE_SIDE piece_side;
	PIECE_TYPE from_piece_type;
	COLOR_TYPE from_color_type;
	int from_pieceid;
	int from_row_id;
	int from_col_id;
	PIECE_TYPE to_piece_type;
	COLOR_TYPE to_color_type;
	int to_pieceid;
	int to_row_id;
	int to_col_id;
	m_History[i].GetHistory(piece_side,from_piece_type,
			from_color_type,from_pieceid,
			from_row_id,from_col_id, to_piece_type,
			to_color_type,to_pieceid,to_row_id,
			to_col_id);
		char from_type=' ';
		switch(from_piece_type)
		{
			case ROOK:
				from_type = 'R';
				break;
			case KNIGHT:
				from_type = 'N';
				break;
			case BISHOP:
				from_type = 'B';
				break;
			case QUEEN:
				from_type = 'Q';
				break;
			case KING:
				from_type = 'K';
				break;
			case PAWN:
				from_type = ' ';
				break;
			default:
				from_type = ' ';
				break;
		}
		char to_type=' ';
		switch(to_piece_type)
		{
			case ROOK:
				to_type = 'R';
				break;
			case KNIGHT:
				to_type = 'N';
				break;
			case BISHOP:
				to_type = 'B';
				break;
			case QUEEN:
				to_type = 'Q';
				break;
			case KING:
				to_type = 'K';
				break;
			case PAWN:
				to_type = ' ';
				break;
			default:
				to_type = ' ';
				break;
		}		
		if( m_History[i].GetCastlingFlag() == TRUE)			
		{
			if(from_col_id + 2 == to_col_id)
			{
				str.Format("O-O");
			}
			else
			{
				str.Format("O-O-O");
			}		 
		}
		else
		{			
			if(to_pieceid == -1)
			{
				if(from_type==' ')
				{						
					if(m_History[i].GetAmbiguousMoveRankFlag() == TRUE)							
					{
						str.Format("%c%d%c%d",
								from_col_id+'a',9-(from_row_id+1),
								to_col_id+'a',
								9-(to_row_id+1));							
					}
					else if(m_History[i].GetAmbiguousMoveFileFlag() == TRUE)							
					{
						str.Format("%c%d%c%d",
								from_col_id+'a',9-(from_row_id+1),
								to_col_id+'a',
								9-(to_row_id+1));
						
					}
					else if(m_History[i].GetEnPassentFlag() == TRUE)
					{
						str.Format("%cx%c%d",
								from_col_id+'a',
								to_col_id+'a',
								9-(to_row_id+1));
					}
					else
					{
						str.Format("%c%d",							
								to_col_id+'a',
								9-(to_row_id+1));							
					}
				}
				else
				{						
					if(m_History[i].GetAmbiguousMoveRankFlag() == TRUE)							
					{
						str.Format("%c%d%c%d",
								from_type,9-(from_row_id+1),
								to_col_id+'a',
								9-(to_row_id+1));							
					}
					else if(m_History[i].GetAmbiguousMoveFileFlag() == TRUE)							
					{
						str.Format("%c%c%c%d",
								from_type,from_col_id+'a',
								to_col_id+'a',
								9-(to_row_id+1));							
					}
					else
					{
						str.Format("%c%c%d",
							from_type,
							to_col_id+'a',
							9-(to_row_id+1));
					}
				}
			}
			else
			{
				if(from_type != ' ')
				{
					if(m_History[i].GetAmbiguousMoveRankFlag() == TRUE)							
					{
						str.Format("%c%dx%c%d",
							from_type,9-(from_row_id+1),
							to_col_id+'a',
							9-(to_row_id+1));
					}
					else if(m_History[i].GetAmbiguousMoveFileFlag() == TRUE)							
					{
						str.Format("%c%cx%c%d",
							from_type,from_col_id+'a',
							to_col_id+'a',
							9-(to_row_id+1));
					}
					else
					{
						str.Format("%cx%c%d",
							from_type,
							to_col_id+'a',
							9-(to_row_id+1));
					}
				}
				else
				{
					if(m_BoardToICSFlag == FALSE)
					{
						if(m_History[i].GetAmbiguousMoveRankFlag() == TRUE)
						{
							str.Format("%c%dx%c%d",
								from_col_id+'a',9-(from_row_id+1),
								to_col_id+'a',
								9-(to_row_id+1));
						}
						else if(m_History[i].GetAmbiguousMoveFileFlag() == TRUE)
						{
							str.Format("%c%dx%c%d",
								from_col_id+'a',9-(from_row_id+1),
								to_col_id+'a',
								9-(to_row_id+1));
						}
						else if(m_History[i].GetEnPassentFlag() == TRUE)
						{
							str.Format("%cx%c%d",
								from_col_id+'a',
								to_col_id+'a',
								9-(to_row_id+1));
						}
						else 
						{
							if(m_History[i].GetPromotionFlag() == TRUE)
							{
								str.Format("%c%d",									
									to_col_id+'a',
									9-(to_row_id+1));
							}
							else
							{
								str.Format("%cx%c%d",
									from_col_id+'a',
									to_col_id+'a',
									9-(to_row_id+1));
							}
						}
					}
					else
					{
						if(m_History[i].GetEnPassentFlag() == TRUE)
						{
							str.Format("%cx%c%d",
								from_col_id+'a',
								to_col_id+'a',
								9-(to_row_id+1));
						}
						else 
						{
							if(m_History[i].GetPromotionFlag() == TRUE)
							{
								str.Format("%c%d",									
									to_col_id+'a',
									9-(to_row_id+1));
							}
							else
							{
								str.Format("%cx%c%d",
									from_col_id+'a',
									to_col_id+'a',
									9-(to_row_id+1));
							}
						}
					}
				}
			}
		}
		if(m_History[i].GetPromotionFlag() == TRUE)
		{

			CString cstr;
			cstr.Format("=%c",to_type);
			str += cstr;
		}
		
		if( m_History[i].GetCheckFlag() == TRUE)			
		{
			str += "+";
		}
	return str;
}
CString CNetChessView::GetSingleMoveStringOldFormat(int i)
{
	int flipflag = FALSE;
	if(m_white_on_top == true)
	{
		FlipBoard();
		flipflag = TRUE;
	}

	CString str;
	PIECE_SIDE piece_side;
	PIECE_TYPE from_piece_type;
	COLOR_TYPE from_color_type;
	int from_pieceid;
	int from_row_id;
	int from_col_id;
	PIECE_TYPE to_piece_type;
	COLOR_TYPE to_color_type;
	int to_pieceid;
	int to_row_id;
	int to_col_id;
	m_History[i].GetHistory(piece_side,from_piece_type,
			from_color_type,from_pieceid,
			from_row_id,from_col_id, to_piece_type,
			to_color_type,to_pieceid,to_row_id,
			to_col_id);
	str.Format("%c%d%c%d",'a'+from_col_id,8-from_row_id,
						  'a'+to_col_id,8-to_row_id);
	if( m_History[i].GetCastlingFlag() == TRUE)			
	{		
	}
	
	if(m_History[i].GetPromotionFlag() == TRUE)
	{
				char to_type=' ';
		switch(to_piece_type)
		{
			case ROOK:
				to_type = 'r';
				break;
			case KNIGHT:
				to_type = 'n';
				break;
			case BISHOP:
				to_type = 'B';
				break;
			case QUEEN:
				to_type = 'q';
				break;
			case KING:
				to_type = 'k';
				break;
			case PAWN:
				to_type = ' ';
				break;
			default:
				to_type = ' ';
				break;
		}		
		CString cstr;
		cstr.Format("%c",to_type);
		str += cstr;
	}	
	if(flipflag == TRUE)
	{
		FlipBoard();
		m_white_on_top = true;;
	}

	return str;
}
CString CNetChessView::GetPositionHistoryString(int type)
{
	CString str;
	CString m_edit_history = "";	
	int flag = 0;
	int count=1;	
	int total = m_iHistory;
	
	int flipflag = FALSE;
	if(m_white_on_top == true)
	{
		FlipBoard();
		flipflag = TRUE;
	}

	//go back to first step
	for(int i=0;i<=total;i++)
	{
		OnEditUndoAction(0);
	}
	int k=-1;
	char side = 'w';
	int movecount = 0;
	do
	{		
		m_edit_history += GetPositionString(type,movecount,side);
		OnEditRedoAction(0);
		k++;
	}while (k <=total);
	
	
	if(flipflag == TRUE)
	{
		FlipBoard();
		flipflag = FALSE;
		m_white_on_top = true;
	}
	return m_edit_history;
}
CString CNetChessView::GetHistoryString(CStringArray& historystring,int type)
{
	CString str;
	CString m_edit_history = "";	
	int flag = 0;
	int count=1;
	int total = 0;
	if(type == 0)
	{
		total = m_iHistory;
		if(!m_gameInfoDlg.m_edit_event.IsEmpty())
			m_edit_history += (CString)"[Event \"" + m_gameInfoDlg.m_edit_event + "\"]\r\n";
		if(!m_gameInfoDlg.m_edit_site.IsEmpty())
			m_edit_history += (CString)"[Site \"" + m_gameInfoDlg.m_edit_site + "\"]\r\n";
		if(!m_gameInfoDlg.m_edit_date.IsEmpty())
			m_edit_history += (CString)"[Date \"" + m_gameInfoDlg.m_edit_date + "\"]\r\n";
		if(!m_gameInfoDlg.m_edit_round.IsEmpty())
			m_edit_history += (CString)"[Round \"" + m_gameInfoDlg.m_edit_round + "\"]\r\n";
		if(!m_gameInfoDlg.m_edit_white.IsEmpty())
			m_edit_history += (CString)"[White \"" + m_gameInfoDlg.m_edit_white + "\"]\r\n";
		if(!m_gameInfoDlg.m_edit_black.IsEmpty())
			m_edit_history += (CString)"[Black \"" + m_gameInfoDlg.m_edit_black + "\"]\r\n";		
		if(!m_gameInfoDlg.m_edit_result.IsEmpty())
			m_edit_history += (CString)"[Result \"" + m_gameInfoDlg.m_edit_result + "\"]\r\n";
		if(!m_gameInfoDlg.m_edit_eco.IsEmpty())
			m_edit_history += (CString)"[ECO \"" + m_gameInfoDlg.m_edit_eco + "\"]\r\n";
		if(!m_gameInfoDlg.m_edit_whiteelo.IsEmpty())
			m_edit_history += (CString)"[WhiteElo \"" + m_gameInfoDlg.m_edit_whiteelo + "\"]\r\n";
		if(!m_gameInfoDlg.m_edit_blackelo.IsEmpty())
			m_edit_history += (CString)"[BlackElo \"" + m_gameInfoDlg.m_edit_blackelo + "\"]\r\n";		
		if(!m_gameInfoDlg.m_edit_playcount.IsEmpty())
			m_edit_history += (CString)"[PlyCount \"" + m_gameInfoDlg.m_edit_playcount + "\"]\r\n";
		if(!m_gameInfoDlg.m_event_date.IsEmpty())
			m_edit_history += (CString)"[EventDate \"" + m_gameInfoDlg.m_event_date + "\"]\r\n";


		if(m_topHistory < 0)
		{
			int movecount = -1;
			char side = m_pieceSide == WHITE ? 'w' : 'b';
			str = GetPositionString('F',movecount,side);
			str = str.Left(str.GetLength() -2);
			m_edit_history += (CString)"[FEN \"" + str + "\"]\r\n";
			m_edit_history += "1...";
		}
	}
	else
	{
		total = m_topHistory;
	}
	for(int i=0;i<=total;i++)
	{		
		str = GetSingleMoveString(i);
		if( flag == 0)
		{
			CString str1;
			if(m_optDlg.m_check_pgn_mail_format == TRUE)
				str1.Format("%d.",count++);
			else
				str1.Format("%d. ",count++);
			m_edit_history += str1 + str;
			if(type == 1)
			{
				historystring.Add(m_edit_history);
				m_edit_history = "";
			}
			else
			{
				if(m_optDlg.m_check_save_with_history == TRUE)
				{
					if(m_History[i].GetComment().GetLength() > 0)
						m_edit_history += " {" + m_History[i].GetComment() + (CString)"} " + str1.Left(str1.GetLength() -1) + ".. ";
				}
			}
			flag = 1;
		}
		else
		{
			if(type == 1)
			{
				m_edit_history += (CString)"            " + str;
				historystring.Add(m_edit_history);
				m_edit_history = "";			
			}
			else
			{
				if(m_optDlg.m_check_save_with_history == TRUE)
				{
					if(m_History[i].GetComment().GetLength() > 0)
						m_edit_history += (CString)" " + str + (CString)" {" + m_History[i].GetComment() + " } ";
					else
						m_edit_history += (CString)" " + str + (CString)" ";

				}
				else
				{
					m_edit_history += (CString)" " + str + (CString)" ";
				}
			}
			flag = 0;
		}		 
		//UpdateData(FALSE);
	}	
	return m_edit_history;
}

bool CNetChessView::CheckValidMove(int x,int y)
{
	//if( m_checkmove== FALSE)
	//	return true;
	switch(cb[m_point.x][m_point.y].GetPieceType())
	{
	case PAWN:
		{
			if(cb[x][y].GetPieceType() == KING)
				return false;

			PIECE_SIDE piece_side;
			PIECE_TYPE from_piece_type;
			COLOR_TYPE from_color_type;
			int from_pieceid;
			int from_row_id;
			int from_col_id;
			PIECE_TYPE to_piece_type;
			COLOR_TYPE to_color_type;
			int to_pieceid;
			int to_row_id;
			int to_col_id;

			if(m_white_on_top == true)
			{
				if(cb[m_point.x][m_point.y].GetPieceColor() == BLACK)
				{
					if((m_point.y == y ) && (m_point.x-1 == x) && (cb[x][y].GetPieceId() <= 0)) 
					{						
						return true;
					}
					else if(m_point.y == y-1 && m_point.x-1 == x)
					{
						if(cb[x][y].GetPieceId() > 0)
						{
							return true;
						}
						else
						{
							if(m_iHistory < 0)
								return false;			
							m_History[m_iHistory].GetHistory(
								piece_side,
								from_piece_type, from_color_type,from_pieceid,
								from_row_id,from_col_id, to_piece_type,
								to_color_type,to_pieceid,to_row_id,
								to_col_id);
							//check enpassent							
							if(from_row_id == 1 && to_row_id == 3 && from_col_id == y && m_point.x == 3 && from_pieceid == 'P')
							{								
								m_enpassentFlag = TRUE;
								//m_SpecialAction = ENPASSENT;
								return true;
							}							 
						}
					}
					else if(m_point.y == y+1 && m_point.x-1 == x)
					{
						if(cb[x][y].GetPieceId() > 0)
						{
							return true;
						}
						else
						{
							if(m_iHistory < 0)
								return false;
							m_History[m_iHistory].GetHistory(
								piece_side,
								from_piece_type, from_color_type,from_pieceid,
								from_row_id,from_col_id, to_piece_type,
								to_color_type,to_pieceid,to_row_id,
								to_col_id);
							//check enpassent
							if(from_row_id == 1 && to_row_id == 3 && from_col_id == y && m_point.x == 3 && from_pieceid == 'P')
							{								
								m_enpassentFlag = TRUE;							
								return true;
							}
						}
					}
					else if(m_point.y == y && m_point.x == 6 && m_point.x-2 == x && cb[x][y].GetPieceId() <= 0 && cb[5][y].GetPieceId() <= 0)
					{
						return true;
					}
					 
					return false;
				}
				else
				{
					if((m_point.y == y ) && (m_point.x+1 == x) && (cb[x][y].GetPieceId() <= 0)) 
					{
						return true;
					}
					else if(m_point.y == y-1 && m_point.x+1 == x)
					{
						if(cb[x][y].GetPieceId() > 0)
						{
							return true;
						}
						else
						{
							if(m_iHistory < 0)
								return false;
			
							m_History[m_iHistory].GetHistory(
								piece_side,
								from_piece_type, from_color_type,from_pieceid,
								from_row_id,from_col_id, to_piece_type,
								to_color_type,to_pieceid,to_row_id,
								to_col_id);
							//check enpassent
							if(from_row_id == 6 && to_row_id == 4 && from_col_id == y && m_point.x == 3 && from_pieceid == 'p')
							{
								m_enpassentFlag = TRUE;
								return true;
							}							
						}
					}
					else if(m_point.y == y+1 && m_point.x+1 == x )
					{
						if(cb[x][y].GetPieceId() > 0)
						{
							return true;
						}
						else
						{
							if(m_iHistory < 0)
								return false;
			
							m_History[m_iHistory].GetHistory(
								piece_side,
								from_piece_type, from_color_type,from_pieceid,
								from_row_id,from_col_id, to_piece_type,
								to_color_type,to_pieceid,to_row_id,
								to_col_id);
							//check enpassent
							if(from_row_id == 6 && to_row_id == 4 && from_col_id == y && m_point.x == 4 && from_pieceid == 'p')
							{
								m_enpassentFlag = TRUE;
								return true;
							}
						}
					}	
					else if(m_point.y == y && m_point.x == 1 && m_point.x+2 == x && cb[x][y].GetPieceId() <= 0 &&cb[2][y].GetPieceId() <= 0)
					{
						return true;
					}	
				}
			}
			else
			{		
				if(cb[m_point.x][m_point.y].GetPieceColor() == BLACK)
				{
					if((m_point.y == y ) && (m_point.x+1 == x) && (cb[x][y].GetPieceId() <= 0)) 
					{
						return true;
					}
					else if(m_point.y == y-1 && m_point.x+1 == x)
					{
						if(cb[x][y].GetPieceId() > 0)
						{
							return true;
						}
						else
						{
							if(m_iHistory < 0)
								return false;
			
							m_History[m_iHistory].GetHistory(
								piece_side,
								from_piece_type, from_color_type,from_pieceid,
								from_row_id,from_col_id, to_piece_type,
								to_color_type,to_pieceid,to_row_id,
								to_col_id);
							//check enpassent
							if(from_row_id == 6 && to_row_id == 4 && from_col_id == y && m_point.x == 4 && from_pieceid == 'P')
							{
								m_enpassentFlag = TRUE;
								return true;
							}						
						}
							 
					}
					else if(m_point.y == y+1 && m_point.x+1 == x )
					{
						if(cb[x][y].GetPieceId() > 0)
						{
							return true;
						}
						else
						{
							if(m_iHistory < 0)
								return false;
			
							m_History[m_iHistory].GetHistory(
								piece_side,
								from_piece_type, from_color_type,from_pieceid,
								from_row_id,from_col_id, to_piece_type,
								to_color_type,to_pieceid,to_row_id,
								to_col_id);
							//check enpassent
							if(from_row_id == 6 && to_row_id == 4 && from_col_id == y && m_point.x == 4 && from_pieceid == 'P')
							{
								m_enpassentFlag = TRUE;
								return true;
							}							
						}
					}
					else if(m_point.y == y && m_point.x == 1 && m_point.x+2 == x && cb[x][y].GetPieceId() <= 0 && cb[2][y].GetPieceId() <= 0)
					{
						return true;
					}	
					return false;				 
				}
				else
				{
					if((m_point.y == y ) && (m_point.x-1 == x) && (cb[x][y].GetPieceId() <= 0)) 
					{
						return true;
					}
					else if(m_point.y == y-1 && m_point.x-1 == x)
						 
					{
						if(cb[x][y].GetPieceId() > 0)
						{
							return true;
						}
						else
						{
							if(m_iHistory < 0)
								return false;
			
							m_History[m_iHistory].GetHistory(
								piece_side,
								from_piece_type, from_color_type,from_pieceid,
								from_row_id,from_col_id, to_piece_type,
								to_color_type,to_pieceid,to_row_id,
								to_col_id);
							//check enpassent
							if(from_row_id == 1 && to_row_id == 3 && from_col_id == y && m_point.x == 3 && from_pieceid == 'p')
							{
								m_enpassentFlag = TRUE;
								return true;
							}						
						}
					}
					else if(m_point.y == y+1 && m_point.x-1 == x)						 
					{
						if(cb[x][y].GetPieceId() > 0)
						{
							return true;
						}
						else
						{
							if(m_iHistory < 0)
								return false;
			
							m_History[m_iHistory].GetHistory(
								piece_side,
								from_piece_type, from_color_type,from_pieceid,
								from_row_id,from_col_id, to_piece_type,
								to_color_type,to_pieceid,to_row_id,
								to_col_id);
							//check enpassent
							if(from_row_id == 1 && to_row_id == 3 && from_col_id == y && m_point.x == 3 && from_pieceid == 'p')
							{
								m_enpassentFlag = TRUE;
								return true;
							}							
						}
					}	
					else if(m_point.y == y && m_point.x == 6 && m_point.x-2 == x && cb[x][y].GetPieceId() <= 0 && cb[5][y].GetPieceId() <= 0)
					{
						return true;
					}	
					return false;
				}
			}
		}
		break;
		case ROOK:
			if(cb[x][y].GetPieceType() == KING)
				return false;
			if(m_point.x == x)
				{
					if(m_point.y > y)
					{
						for(int i=y+1; i< m_point.y;i++)
						{
							if(cb[x][i].GetPieceId() >0)
							{
								return false;
							}
						}
					}
					else
					{
						for(int i=m_point.y+1; i< y;i++)
						{
							if(cb[x][i].GetPieceId() >0)
							{
								return false;
							}
						}
					}
				}
				else if(m_point.y == y)
				{
					if(m_point.x > x)
					{
						for(int i=x+1; i< m_point.x;i++)
						{
							if(cb[i][y].GetPieceId() >0)
							{
								return false;
							}
						}
					}
					else
					{
						for(int i=m_point.x+1; i< x;i++)
						{
							if(cb[i][y].GetPieceId() >0)
							{
								return false;
							}
						}
					}
				}
				else
					return false;
				if(m_white_on_top == true)
				{				
					if(m_point.y == 0 && m_point.x == 0)
					{
						cb[m_point.x][m_point.y].GetPieceColor() == BLACK?m_blackRookRank7MovedFlag = true :	m_whiteRookRank7MovedFlag = true;					 
					}
					else if(m_point.y == 7 && m_point.x == 0)
					{
						cb[m_point.x][m_point.y].GetPieceColor() == BLACK?m_blackRookRank1MovedFlag = true :	m_whiteRookRank1MovedFlag = true;					 
					}
				}
				else
				{
					if(m_point.y == 0 && m_point.x == 7)
					{
						cb[m_point.x][m_point.y].GetPieceColor() == BLACK?m_blackRookRank1MovedFlag = true :	m_whiteRookRank1MovedFlag = true;					 
					}
					else if(m_point.y == 7 && m_point.x == 7)
					{
 						cb[m_point.x][m_point.y].GetPieceColor() == BLACK?m_blackRookRank7MovedFlag = true :	m_whiteRookRank7MovedFlag = true;					 
					}
				}
				return true;							 
			break;
		case KNIGHT:
			if(cb[x][y].GetPieceType() == KING)
				return false;
			if(
				(m_point.x -2 == x && m_point.y +1 == y) ||							 
				(m_point.x -1 == x && m_point.y+2 == y) ||
				(m_point.x +1 == x && m_point.y+2 == y) ||
				(m_point.x +2 == x && m_point.y+1 == y) ||
				 
				(m_point.x +2 == x && m_point.y-1 == y) ||
				(m_point.x +1 == x && m_point.y-2 == y) ||
				(m_point.x -1 == x && m_point.y-2 == y) ||
				(m_point.x -2 == x && m_point.y-1 == y) )
			{
				return true;
			}
			else return false;						 
			break;
		case BISHOP:
				if(cb[x][y].GetPieceType() == KING)
					return false;
				if(m_point.x > x)
				{	int i=0,j=0;
					if(m_point.y > y)
					{
						for(j=y+1,i=x+1; j< m_point.y && i < m_point.x;i++,j++)
						{
							if(cb[i][j].GetPieceId() >0)
							{
								return false;
							}
						}
						if(j == m_point.y && i == m_point.x)
							return true;
						else
							return false;

					}
					else if(m_point.y < y)
					{
						for(j=y-1,i=x+1; j> m_point.y && i < m_point.x;i++,j--)
						{
							if(cb[i][j].GetPieceId() >0)
							{
								return false;
							}
						}
						if(j == m_point.y && i == m_point.x)
							return true;
						else
							return false;
					}
					else 
						return false;
				}
				else if(m_point.x < x)
				{
					int i=0,j=0;
					if(m_point.y > y)
					{
						for(j=m_point.y-1,i=m_point.x+1; j> y && i < x;i++,j--)
						{
							if(cb[i][j].GetPieceId() >0)
							{
								return false;
							}
						}
						if(j == y && i == x)
							return true;
						else
							return false;
					}
					else if(m_point.y < y)
					{
						for(j=m_point.y+1,i=m_point.x+1; j< y && i < x;i++,j++)
						{
							if(cb[i][j].GetPieceId() >0)
							{
								return false;
							}
						}
						if(j == y && i == x)
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else 
					return false;
		break;
		case QUEEN:
			if(cb[x][y].GetPieceType() == KING)
				return false;
			if(m_point.x == x)
				{
					if(m_point.y > y)
					{
						for(int i=y+1; i< m_point.y;i++)
						{
							if(cb[x][i].GetPieceId() >0)
							{
								return false;
							}
						}
					}
					else
					{
						for(int i=m_point.y+1; i< y;i++)
						{
							if(cb[x][i].GetPieceId() >0)
							{
								return false;
							}
						}
					}
				}
				else if(m_point.y == y)
				{
					if(m_point.x > x)
					{
						for(int i=x+1; i< m_point.x;i++)
						{
							if(cb[i][y].GetPieceId() >0)
							{
								return false;
							}
						}
					}
					else
					{
						for(int i=m_point.x+1; i< x;i++)
						{
							if(cb[i][y].GetPieceId() >0)
							{
								return false;
							}
						}
					}
				}
				else if(m_point.x > x)
				{	int i=0,j=0;
					if(m_point.y > y)
					{
						for(j=y+1,i=x+1; j< m_point.y && i < m_point.x;i++,j++)
						{
							if(cb[i][j].GetPieceId() >0)
							{
								return false;
							}
						}
						if(j == m_point.y && i == m_point.x)
							return true;
						else
							return false;

					}
					else if(m_point.y < y)
					{
						for(j=y-1,i=x+1; j> m_point.y && i < m_point.x;i++,j--)
						{
							if(cb[i][j].GetPieceId() >0)
							{
								return false;
							}
						}
						if(j == m_point.y && i == m_point.x)
							return true;
						else
							return false;
					}
					else 
						return false;
				}
				else if(m_point.x < x)
				{
					int i=0,j=0;
					if(m_point.y > y)
					{
						for(j=m_point.y-1,i=m_point.x+1; j> y && i < x;i++,j--)
						{
							if(cb[i][j].GetPieceId() >0)
							{
								return false;
							}
						}
						if(j == y && i == x)
							return true;
						else
							return false;
					}
					else if(m_point.y < y)
					{
						for(j=m_point.y+1,i=m_point.x+1; j< y && i < x;i++,j++)
						{
							if(cb[i][j].GetPieceId() >0)
							{
								return false;
							}
						}
						if(j == y && i == x)
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else 
					return false;
			break;
		case KING:
			if(cb[x][y].GetPieceType() == KING)
			{
				return false;
			}
			if((m_point.x == x && m_point.y+1 == y) ||
				  (m_point.x+1 == x && m_point.y+1 == y) ||
				  (m_point.x +1== x && m_point.y == y) ||
				  (m_point.x+1 == x && m_point.y-1 == y) ||
				  (m_point.x == x && m_point.y-1 == y) ||
				  (m_point.x-1 == x && m_point.y -1 == y) ||
				  (m_point.x-1 == x && m_point.y == y) ||
				  (m_point.x -1 == x && m_point.y+1 == y))
			{				 
				//check for bishop check
				//check for king check
				//check for queen check
				//check for rook check
				//check for knight check
				//check for pawn check
				if(cb[m_point.x][m_point.y].GetPieceId() == KING_BLACK)
				{
					if(x-1>=0 && y-1>=0&&x+1< 8 && y+1 < 8)
					if((cb[x-1][y-1].GetPieceId() == KING_WHITE || 
						cb[x-1][y+1].GetPieceId() == KING_WHITE ||
						cb[x+1][y-1].GetPieceId() == KING_WHITE || 
						cb[x+1][y+1].GetPieceId() == KING_WHITE ||
						cb[x-1][y].GetPieceId() == KING_WHITE || 
						cb[x+1][y].GetPieceId() == KING_WHITE ||
						cb[x][y-1].GetPieceId() == KING_WHITE || 
						cb[x][y+1].GetPieceId() == KING_WHITE)) 
					{						
						return false;
					}					 
				}
				else if(cb[m_point.x][m_point.y].GetPieceId() == KING_WHITE)
				{
					if(x-1>=0 && y-1>=0&&x+1< 8 && y+1 < 8)
					if(cb[x-1][y-1].GetPieceId() == KING_BLACK ||
						cb[x-1][y+1].GetPieceId() == KING_BLACK ||
						cb[x+1][y-1].GetPieceId() == KING_BLACK || 
						cb[x+1][y+1].GetPieceId() == KING_BLACK ||
						cb[x-1][y].GetPieceId() == KING_BLACK || 
						cb[x+1][y].GetPieceId() == KING_BLACK ||
						cb[x][y-1].GetPieceId() == KING_BLACK ||
						cb[x][y+1].GetPieceId() == KING_BLACK)
					{						
						return false;
					}					 
				}
			
				cb[m_point.x][m_point.y].GetPieceColor() == BLACK?m_blackKingMovedFlag = true :	m_whiteKingMovedFlag = true;
				return true;
			}
			else if(m_white_on_top == false)
			{	
				COLOR_TYPE piececolor = cb[m_point.x][m_point.y].GetPieceColor();
				if(m_point.x == x && (m_point.x == 7  || m_point.x == 0 ) && m_point.y+2 == y  && ((cb[m_point.x][m_point.y].GetPieceColor() == WHITE ? m_whiteRookRank7MovedFlag:m_blackRookRank7MovedFlag) == false) && cb[m_point.x][m_point.y+1].GetPieceId() < 0 && cb[m_point.x][m_point.y+2].GetPieceId() < 0 && cb[m_point.x][m_point.y+3].GetPieceType() == ROOK && (cb[m_point.x][m_point.y].GetPieceColor() == WHITE ? m_whiteKingMovedFlag:m_blackKingMovedFlag) == false )
				{					 
					cb[m_point.x][m_point.y+1].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
					cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					if(CheckKingMove(m_point.x,m_point.y+1,m_point.x,m_point.y+1) == false)
					{
						cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y+1].GetPieceId(),cb[m_point.x][m_point.y+1].GetPieceColor(),cb[m_point.x][m_point.y+1].GetPieceType(),cb[m_point.x][m_point.y+1].GetPieceState());
						cb[m_point.x][m_point.y+1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						return false;
					}
					cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y+1].GetPieceId(),cb[m_point.x][m_point.y+1].GetPieceColor(),cb[m_point.x][m_point.y+1].GetPieceType(),cb[m_point.x][m_point.y+1].GetPieceState());
					cb[m_point.x][m_point.y+1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);

					cb[m_point.x][m_point.y+2].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
					cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					if(CheckKingMove(m_point.x,m_point.y+2,m_point.x,m_point.y+2) == false)
					{
						cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y+2].GetPieceId(),cb[m_point.x][m_point.y+2].GetPieceColor(),cb[m_point.x][m_point.y+2].GetPieceType(),cb[m_point.x][m_point.y+2].GetPieceState());
						cb[m_point.x][m_point.y+2].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						return false;
					}
					
					cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y+2].GetPieceId(),cb[m_point.x][m_point.y+2].GetPieceColor(),cb[m_point.x][m_point.y+2].GetPieceType(),cb[m_point.x][m_point.y+2].GetPieceState());
					cb[m_point.x][m_point.y+2].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					//cb[m_point.x][m_point.y].GetPieceColor() == BLACK?m_blackRookRank7MovedFlag = true :	m_whiteRookRank7MovedFlag = true;					 
					piececolor == BLACK?m_blackKingMovedFlag = true :	m_whiteKingMovedFlag = true;
					//m_SpecialAction = CASTLING;
					m_castlingFlag = TRUE;
					return true;
				}
				else if(m_point.x == x && (m_point.x == 7 || m_point.x == 0 ) && m_point.y-2 == y && ((cb[m_point.x][m_point.y].GetPieceColor() == WHITE ? m_whiteRookRank1MovedFlag:m_blackRookRank1MovedFlag) == false) && cb[m_point.x][m_point.y-1].GetPieceId() < 0 && cb[m_point.x][m_point.y-2].GetPieceId() < 0 && cb[m_point.x][m_point.y-3].GetPieceId() < 0 && cb[m_point.x][m_point.y-4].GetPieceType() == ROOK && (cb[m_point.x][m_point.y].GetPieceColor() == WHITE ? m_whiteKingMovedFlag:m_blackKingMovedFlag) == false)
				{
					/*(cb[m_point.x][m_point.y].GetPieceColor() == WHITE ? m_whiteRookRank7MovedFlag:m_blackRookRank7MovedFlag) == false */
					cb[m_point.x][m_point.y-1].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
					cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					if(CheckKingMove(m_point.x,m_point.y-1,m_point.x,m_point.y-1) == false)
					{
						cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y-1].GetPieceId(),cb[m_point.x][m_point.y-1].GetPieceColor(),cb[m_point.x][m_point.y-1].GetPieceType(),cb[m_point.x][m_point.y-1].GetPieceState());
						cb[m_point.x][m_point.y-1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						return false;
					}
					cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y-1].GetPieceId(),cb[m_point.x][m_point.y-1].GetPieceColor(),cb[m_point.x][m_point.y-1].GetPieceType(),cb[m_point.x][m_point.y-1].GetPieceState());
					cb[m_point.x][m_point.y-1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);

					cb[m_point.x][m_point.y-2].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
					cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					if(CheckKingMove(m_point.x,m_point.y-2,m_point.x,m_point.y-2) == false)
					{
						cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y-2].GetPieceId(),cb[m_point.x][m_point.y-2].GetPieceColor(),cb[m_point.x][m_point.y-2].GetPieceType(),cb[m_point.x][m_point.y-2].GetPieceState());
						cb[m_point.x][m_point.y-2].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						return false;
					}
					cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y-2].GetPieceId(),cb[m_point.x][m_point.y-2].GetPieceColor(),cb[m_point.x][m_point.y-2].GetPieceType(),cb[m_point.x][m_point.y-2].GetPieceState());
					cb[m_point.x][m_point.y-2].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					/*********Need to check the rule***********/
					/*cb[m_point.x][m_point.y-3].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
					cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
 					if(CheckKingMove(m_point.x,m_point.y-3,m_point.x,m_point.y-3) == false)
					{
						cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y-3].GetPieceId(),cb[m_point.x][m_point.y-3].GetPieceColor(),cb[m_point.x][m_point.y-3].GetPieceType(),cb[m_point.x][m_point.y-3].GetPieceState());
						cb[m_point.x][m_point.y-3].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						return false;
					}
				
					cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y-3].GetPieceId(),cb[m_point.x][m_point.y-3].GetPieceColor(),cb[m_point.x][m_point.y-3].GetPieceType(),cb[m_point.x][m_point.y-3].GetPieceState());
					cb[m_point.x][m_point.y-3].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);*/

					piececolor == BLACK?m_blackKingMovedFlag = true :	m_whiteKingMovedFlag = true;
					//cb[m_point.x][m_point.y].GetPieceColor() == BLACK?m_blackRookRank1MovedFlag = true :	m_whiteRookRank1MovedFlag = true;					 
					//m_SpecialAction = CASTLING;
					m_castlingFlag = TRUE;
					return true;
				}
			}
			else if(m_white_on_top == true)
			{			 
				COLOR_TYPE piececolor = cb[m_point.x][m_point.y].GetPieceColor();
				if(m_point.x == x && (m_point.x == 7 || m_point.x == 0 ) && m_point.y-2 == y && ((cb[m_point.x][m_point.y].GetPieceColor() == WHITE ? m_whiteRookRank7MovedFlag:m_blackRookRank7MovedFlag) == false)&& cb[m_point.x][m_point.y-1].GetPieceId() < 0 && cb[m_point.x][m_point.y-2].GetPieceId() < 0 && cb[m_point.x][m_point.y-3].GetPieceType() == ROOK && (cb[m_point.x][m_point.y].GetPieceColor() == WHITE ? m_whiteKingMovedFlag:m_blackKingMovedFlag) == false)
				{
					
					cb[m_point.x][m_point.y-1].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
					cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					if(CheckKingMove(m_point.x,m_point.y-1,m_point.x,m_point.y-1) == false)
					{
						cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y-1].GetPieceId(),cb[m_point.x][m_point.y-1].GetPieceColor(),cb[m_point.x][m_point.y-1].GetPieceType(),cb[m_point.x][m_point.y-1].GetPieceState());
						cb[m_point.x][m_point.y-1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						return false;
					}
					cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y-1].GetPieceId(),cb[m_point.x][m_point.y-1].GetPieceColor(),cb[m_point.x][m_point.y-1].GetPieceType(),cb[m_point.x][m_point.y-1].GetPieceState());
					cb[m_point.x][m_point.y-1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);

					cb[m_point.x][m_point.y-2].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
					cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					if(CheckKingMove(m_point.x,m_point.y-2,m_point.x,m_point.y-2) == false)
					{
						cb[m_point.x][m_point.y-2].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
						cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						return false;
					}
					cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y-2].GetPieceId(),cb[m_point.x][m_point.y-2].GetPieceColor(),cb[m_point.x][m_point.y-2].GetPieceType(),cb[m_point.x][m_point.y-2].GetPieceState());		 
					cb[m_point.x][m_point.y-2].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);

					piececolor == BLACK?m_blackKingMovedFlag = true :	m_whiteKingMovedFlag = true;
				 	//cb[m_point.x][m_point.y].GetPieceColor() == BLACK?m_blackRookRank7MovedFlag = true :	m_whiteRookRank7MovedFlag = true;
				 
					//m_SpecialAction = CASTLING;
					m_castlingFlag = TRUE;
					return true;
				}
				else if(m_point.x == x && (m_point.x == 7 || m_point.x == 0 ) && m_point.y+2 == y && ((cb[m_point.x][m_point.y].GetPieceColor() == WHITE ? m_whiteRookRank1MovedFlag:m_blackRookRank1MovedFlag) == false)&& cb[m_point.x][m_point.y+1].GetPieceId() < 0 && cb[m_point.x][m_point.y+2].GetPieceId() < 0 && cb[m_point.x][m_point.y+3].GetPieceId() < 0 && cb[m_point.x][m_point.y+4].GetPieceType() == ROOK && (cb[m_point.x][m_point.y].GetPieceColor() == WHITE ? m_whiteKingMovedFlag:m_blackKingMovedFlag) == false)
				{
					cb[m_point.x][m_point.y+1].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
					cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					if(CheckKingMove(m_point.x,m_point.y+1,m_point.x,m_point.y+1) == false)
					{
						cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y+1].GetPieceId(),cb[m_point.x][m_point.y+1].GetPieceColor(),cb[m_point.x][m_point.y+1].GetPieceType(),cb[m_point.x][m_point.y+1].GetPieceState());
						cb[m_point.x][m_point.y+1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						return false;
					}
					cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y+1].GetPieceId(),cb[m_point.x][m_point.y+1].GetPieceColor(),cb[m_point.x][m_point.y+1].GetPieceType(),cb[m_point.x][m_point.y+1].GetPieceState());
					cb[m_point.x][m_point.y+1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);

					cb[m_point.x][m_point.y+2].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
					cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					if(CheckKingMove(m_point.x,m_point.y+2,m_point.x,m_point.y+2) == false)
					{
						cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y+2].GetPieceId(),cb[m_point.x][m_point.y+2].GetPieceColor(),cb[m_point.x][m_point.y+2].GetPieceType(),cb[m_point.x][m_point.y+2].GetPieceState());
						cb[m_point.x][m_point.y+2].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						return false;
					}
					cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y+2].GetPieceId(),cb[m_point.x][m_point.y+2].GetPieceColor(),cb[m_point.x][m_point.y+2].GetPieceType(),cb[m_point.x][m_point.y+2].GetPieceState());
					cb[m_point.x][m_point.y+2].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);

					/*cb[m_point.x][m_point.y+3].SetPieceData(cb[m_point.x][m_point.y].GetPieceId(),cb[m_point.x][m_point.y].GetPieceColor(),cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceState());
					cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					if(CheckKingMove(m_point.x,m_point.y+3,m_point.x,m_point.y+3) == false)
					{
						cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y+3].GetPieceId(),cb[m_point.x][m_point.y+3].GetPieceColor(),cb[m_point.x][m_point.y+3].GetPieceType(),cb[m_point.x][m_point.y+3].GetPieceState());
						cb[m_point.x][m_point.y+3].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						return false;
					}
					cb[m_point.x][m_point.y].SetPieceData(cb[m_point.x][m_point.y+3].GetPieceId(),cb[m_point.x][m_point.y+3].GetPieceColor(),cb[m_point.x][m_point.y+3].GetPieceType(),cb[m_point.x][m_point.y+3].GetPieceState());
					cb[m_point.x][m_point.y+3].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);*/

					piececolor == BLACK?m_blackKingMovedFlag = true :	m_whiteKingMovedFlag = true;
					//cb[m_point.x][m_point.y].GetPieceColor() == BLACK?m_blackRookRank1MovedFlag = true :	m_whiteRookRank1MovedFlag = true;
					//m_SpecialAction = CASTLING;
					m_castlingFlag = TRUE;
					return true;
				}
			}
			return false;
			break;
		default:
			break;
		}	 
	return true;
}
 
void CNetChessView::OnLButtonDownAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(m_pauseclockFlag == TRUE)
	{
		AfxMessageBox("Enable Clock(Ctrl+K) to (re)start the game");
		return;
	}
	SetShellIconData("NetChess by A.V.M.Rao",NIM_DELETE);				 	 
	KillTimer(SHELL_ICON_TIMER_EVENT_ID);
	m_timerFlag = false;
	if(m_player_turn == false)
	{
		SetPaneText(MESSAGEPANE,"Your opponnent's turn to move");
		return;	
	}
	else
	{
		SetPaneText(MESSAGEPANE,"It is your turn to move");
	}
	if(m_demoFlag == TRUE)
	{		
		SetPaneText(MESSAGEPANE,"Replay is in progress",1);
		return;
	}

	if(	((m_whiteAsEngineFlag ==TRUE && m_pieceSide == WHITE && m_whiteEngineOnlyAnalyze == FALSE) || 
		(m_blackAsEngineFlag == TRUE && m_pieceSide ==BLACK && m_blackEngineOnlyAnalyze == FALSE)) )
	{
		SetPaneText(MESSAGEPANE,"Engine is playing",0);
		return;
	}

	for(int i = 0; i < 8; i++)
	{
		for( int j = 0; j < 8; j++)
		{
			CRgn rgn;
			CRect rect = cb[i][j].GetRect();
			rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);
			if(rgn.PtInRegion(point))
			{
				if(m_pieceSide == cb[i][j].GetPieceColor())
				{		 				 
					m_point.x = i; m_point.y = j;
					cb[i][j].SetPieceState(PIECE_MOVING);
					SetLearning(TRUE);
			 		m_mouseMoveFlag = true;					 
					return;	 
				}
			}
		}
	}
	 
 	CView::OnLButtonDown(nFlags, point);
}

int CNetChessView::OnLButtonUpAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	
	int validmoveflag = FALSE;
	if(m_mouseMoveFlag == false)
	{	 
		return -1;
	}	
	m_mouseMoveFlag = false;
	m_moveRect =0;
	//be careful for boundary values
	if(m_point.x < 0 || m_point.y < 0)
	{
		return -1;
	}
	cb[m_point.x][m_point.y].SetPieceState(PIECE_NOT_MOVING);	
    for(int i = 0; i < 8; i++)
	{
		for( int j = 0; j < 8; j++)
		{			 
			//if(cb[i][j].GetPieceType() == BLANK)
			{
				CRgn rgn;
				CRect rect = cb[i][j].GetRect();
				rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);	
				if(rgn.PtInRegion(point)&&rect != cb[m_point.x][m_point.y].GetRect())
				{						
					int flipflag = FALSE;
					if(m_white_on_top == true)
					{
						m_white_on_top = false;
						m_point.x = 7 - m_point.x;
						m_point.y = 7 - m_point.y;
						i = 7 - i;
						j = 7 - j;						
						FlipBoard();
						flipflag = TRUE;						
					}
				
					int piece_id;
					COLOR_TYPE  piece_color;
					PIECE_TYPE  piece_type;
					STATE piece_state;
					int to_piece_id;
					COLOR_TYPE  to_piece_color;
					PIECE_TYPE  to_piece_type;
					STATE to_piece_state;
					cb[m_point.x][m_point.y].GetPieceData(piece_id,piece_color,piece_type,piece_state);
					cb[i][j].GetPieceData(to_piece_id,to_piece_color,to_piece_type,to_piece_state);					 
					cb[m_point.x][m_point.y].SetPieceState(PIECE_NOT_MOVING);

					PIECE_SIDE piece_side;
					PIECE_TYPE from_piece_type;
					COLOR_TYPE from_color_type;
					int from_pieceid;
					int from_row_id;
					int from_col_id;
					PIECE_TYPE to_piecetype;
					COLOR_TYPE to_colortype;
					int to_pieceid;
					int to_row_id;
					int to_col_id;
					//check for valid move

					if(piece_color == to_piece_color)
					{						
					
						if(m_white_on_top == false && flipflag == TRUE)
						{							
							FlipBoard();
							flipflag = FALSE;
							m_white_on_top = true;
						}
						SetPaneText(MESSAGEPANE, "Invalid move! From piece color is same as to piece_color",1);
						//if(m_demoFlag == FALSE)
						//	AfxMessageBox("Invalid move! From piece color is same as to piece_color");
						m_point.x = m_point.y = -1;
						SetLearning(FALSE);
						DrawBoard();						
						return -1;
					}
					if(CheckValidMove(i,j) == true || m_checkmove == FALSE)
					{
						CheckAmbiguousMove(i,j);
						if(m_pClientSocket != NULL)
						{
							m_player_turn = false;
							if(m_pieceSide == WHITE )								
							{
								SetPaneText(PLAYERSIDE,"BLACK",0);
							}
							else if(m_pieceSide == BLACK)
							{
								SetPaneText(PLAYERSIDE,"WHITE",0);
							}
						}
						else
						{
							m_player_turn = true;
							m_pieceSide = m_pieceSide == WHITE ? BLACK: WHITE;							
							SetPaneText(PLAYERSIDE,m_pieceSide == WHITE ? "WHITE" : "BLACK",0);
						}
						if(nFlags != 255)
						{
							bool checkstate = CheckCheckState(cb[m_point.x][m_point.y].GetPieceType(),cb[m_point.x][m_point.y].GetPieceColor(),i,j);
							if(m_white_on_top == false)
							{
								//if(m_SpecialAction == ENPASSENT)
								if(m_enpassentFlag == TRUE)
								{
									m_History[m_iHistory].GetHistory(
										piece_side,
										from_piece_type, from_color_type,from_pieceid,
										from_row_id,from_col_id, to_piecetype,
										to_colortype,to_pieceid,to_row_id,
										to_col_id);
									m_History[++m_iHistory].SetHistory(BOTTOM,
										piece_type,piece_color,piece_id,m_point.x,m_point.y,
										to_piece_type,to_piece_color,to_piece_id,i,j); 									
									if(checkstate == true)
									{
										m_checkFlag = TRUE;
									}
								}
								else if(m_castlingFlag == TRUE)
								{
									  
									m_History[++m_iHistory].SetHistory(BOTTOM,
										piece_type,piece_color,piece_id,m_point.x,m_point.y,
										to_piece_type,to_piece_color,to_piece_id,i,j); 
	
								}
								else
								{
									m_History[++m_iHistory].SetHistory(BOTTOM,
										piece_type,piece_color,piece_id,m_point.x,m_point.y,
										to_piece_type,to_piece_color,to_piece_id,i,j);

									if(checkstate == true)
									{
										m_checkFlag = TRUE;
									}
								}
							}
							else
							{
								if(m_enpassentFlag == TRUE)
								{
									m_History[m_iHistory].GetHistory(
										piece_side,
										from_piece_type, from_color_type,from_pieceid,
										from_row_id,from_col_id, to_piecetype,
										to_colortype,to_pieceid,to_row_id,
										to_col_id);
									m_History[++m_iHistory].SetHistory(BOTTOM,
										piece_type,piece_color,piece_id,7-m_point.x,7-m_point.y,
										to_piece_type,to_piece_color,to_piece_id,7-i,7-j);

									if(checkstate == true)
									{
										m_checkFlag = TRUE;
									}
								}
								else if(m_castlingFlag == TRUE)
								{
									m_History[++m_iHistory].SetHistory(BOTTOM,
										piece_type,piece_color,piece_id,7-m_point.x,7-m_point.y,
										to_piece_type,to_piece_color,to_piece_id,7-i,7-j);
								}
								else
								{
									m_History[++m_iHistory].SetHistory(BOTTOM,piece_type,piece_color,piece_id,7-m_point.x,7-m_point.y,
										to_piece_type,to_piece_color,to_piece_id,7-i,7-j);
								
									if(checkstate == true)
									{
										m_checkFlag = TRUE;
									}
								}
							}
							m_topHistory = m_iHistory;
						}						 
						 
						if(m_enpassentFlag == TRUE)
						{
							cb[i][j].SetPieceData(piece_id,piece_color,piece_type,PIECE_NOT_MOVING);
							cb[to_row_id][to_col_id].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						}
						else if(m_castlingFlag == TRUE)
						{						
							cb[i][j].SetPieceData(piece_id,piece_color,piece_type,PIECE_NOT_MOVING);							 
							if(m_point.y+2 == j)
							{
								cb[i][j-1].SetPieceData(cb[i][7].GetPieceId(),cb[i][7].GetPieceColor(),cb[i][7].GetPieceType(),PIECE_NOT_MOVING);
								cb[i][7].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
								if(CheckCheckState(cb[i][j-1].GetPieceType(),cb[i][j-1].GetPieceColor() ,i,j-1) == true)
								{
									m_checkFlag = TRUE;
								}
							}
							else if(m_point.y -2 == j)
							{
								cb[i][j+1].SetPieceData(cb[i][0].GetPieceId(),cb[i][0].GetPieceColor(),cb[i][0].GetPieceType(),PIECE_NOT_MOVING);
								cb[i][0].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
								if(CheckCheckState(cb[i][j+1].GetPieceType(),cb[i][j+1].GetPieceColor() ,i,j+1 ) == true)
								{
									m_checkFlag = TRUE;
								}
							}
						}
						else
						{
							cb[i][j].SetPieceData(piece_id,piece_color,piece_type,PIECE_NOT_MOVING);
						}
						
						cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						
						if(CheckKingMove(i,j,i,j) == false)
						{
							
							//writeMessage("CheckKingMove invalid move %d %d %c",m_point.x,m_point.y,cb[m_point.x][m_point.y].GetPieceId());
							OnEditUndoAction(0);							
							nFlags = 255;
							if(m_white_on_top == false && flipflag == TRUE)
							{
								m_point.x = 7 - m_point.x;
								m_point.y = 7 - m_point.y;
								i = 7 - i;
								j = 7 - j;
								FlipBoard();
								m_movedFromRect = m_movedToRect = 0;								
								flipflag = FALSE;
								m_white_on_top = true;
							}
							SetPaneText(MESSAGEPANE,"Invalid move! King is on check after this move",1);
							//if(m_demoFlag == FALSE)
							//	AfxMessageBox("Invalid move! King is on check after this move");
							m_point.x = m_point.y = -1;
							SetLearning(FALSE);
							DrawBoard();
							return -1;
						}						
						/************/
						CPickPieceDlg dlg;
						int foundflag = 0;
						if((i ==0 || i == 7) && cb[i][j].GetPieceType()== PAWN)
						{
							if(m_pickPieceDlg->m_pickpiecetype  == 1 && m_pickPieceDlg->m_piecked_piece != -2)
							{
								foundflag = 1;
							}
							else if(dlg.DoModal()==IDOK)
							{ 
								if( dlg.m_piecked_piece != -2)
									foundflag = 1;
							}					
								
							if(foundflag == 1)
							{								
								int to_piece_id;
								COLOR_TYPE  to_piece_color;
								PIECE_TYPE  to_piece_type;
								STATE to_piece_state=PIECE_NOT_MOVING;

								m_History[m_iHistory].GetHistory(
										piece_side,
										from_piece_type, from_color_type,from_pieceid,
										from_row_id,from_col_id, to_piecetype,
										to_colortype,to_pieceid,to_row_id,
										to_col_id);

								if(m_pickPieceDlg->m_pickpiecetype  == 1)
								{
									to_piece_id = m_pickPieceDlg->m_piecked_piece;
									to_piece_color = m_pickPieceDlg->m_piece_color;
									to_piece_type = m_pickPieceDlg->m_piece_type;									
								}
								else
								{
									to_piece_id = dlg.m_piecked_piece;
									to_piece_color = dlg.m_piece_color;
									to_piece_type = dlg.m_piece_type;						 						 
								}								
								cb[i][j].SetPieceState(PIECE_NOT_MOVING);
							//	m_player_turn = m_player_turn == WHITE ? BLACK: WHITE;								
								m_iHistory--;
								if(m_white_on_top == false)
								{
									
									m_History[++m_iHistory].SetHistory(BOTTOM,
										from_piece_type, from_color_type,from_pieceid,
										from_row_id,from_col_id,
										to_piece_type,to_piece_color,to_piece_id,i,j);
									m_promotionFlag = TRUE;
								}
								else
								{
									m_History[++m_iHistory].SetHistory(BOTTOM,
										from_piece_type, from_color_type,from_pieceid,
										7-from_row_id,7-from_col_id,
										to_piece_type,to_piece_color,to_piece_id,7-i,7-j);
									m_promotionFlag = TRUE;
								}							
								SetMoveHistory();
								m_topHistory = m_iHistory;
								cb[i][j].SetPieceData(to_piece_id,to_piece_color,to_piece_type,PIECE_NOT_MOVING);

								char data[30];
								memset(data,-1,30);
								data[0] = MOVE;
								data[1] = m_white_on_top == false?FALSE:TRUE;
								data[2] = (char)m_point.x;
								data[3] = (char)m_point.y;
	   							data[4] = i;
								data[5] = j;
								data[6] = 1;
								memcpy(&data[7],&to_piece_id,4);
								data[11] = to_piece_color;
								data[12] = to_piece_type;
								memcpy(&data[13],&m_whiteTime,4);
								memcpy(&data[17],&m_blackTime,4);
								//if(m_moveFlag == FALSE)
								{
									SendSockData((unsigned char*)data,21);
								}								
								/*else
									SendToEngine((unsigned char*)data,13);*/
								//m_moveFlag = FALSE;//move is done, so make it false							
								m_movedFromRect = cb[m_point.x][m_point.y].GetRect();
								m_movedToRect = cb[i][j].GetRect();
							}
						}
						/************/
						else if(nFlags != 255)//king move is not valid
						{
							SetMoveHistory();
							char data[30];
							memset(data,-1,25);
							data[0] = MOVE;
							data[1] = m_white_on_top == false?FALSE:TRUE;
							data[2] = (char)m_point.x;
							data[3] = (char)m_point.y;
	   						data[4] = i;
							data[5] = j;						
							data[6] = 0;
							//if(m_moveFlag == FALSE)
							{							
								SendSockData((unsigned char*)data,7);
							}
							//else
							//	SendToEngine((unsigned char*)data,7);
							m_moveFlag = FALSE;
							m_movedFromRect = cb[m_point.x][m_point.y].GetRect();
							m_movedToRect = cb[i][j].GetRect();
						}						
					}
					else
					{
						
						//writeMessage("%d %d %c is an invalid move to %d %d %c",
						//	m_point.x,m_point.y,cb[m_point.x][m_point.y].GetPieceId(),i,j,cb[i][j].GetPieceId());
						m_movedFromRect = m_movedToRect = 0;
						if(flipflag == TRUE)
						{
							m_point.x = 7 - m_point.x;
							//m_point.y = 7 - m_point.y;
							i = 7 - i;
							//j = 7 - j;
							CString str;
							str.Format("Invalid move! %c%d %c is an invalid move to %c%d %c",
								'a'+ m_point.y,m_point.x+1,cb[m_point.x][m_point.y].GetPieceId(),
								'a'+ j,i+1,cb[i][j].GetPieceId());
							SetPaneText(MESSAGEPANE,str,1);
							//if (m_demoFlag == FALSE)
								//AfxMessageBox(str);
							FlipBoard();
							m_movedFromRect = m_movedToRect = 0;								
							flipflag = FALSE;
							m_white_on_top = true;
						}
						else
						{
							m_point.x = 7 - m_point.x;
							//m_point.y = 7 - m_point.y;
							i = 7 - i;
							//j = 7 - j;*/
							CString str;
							str.Format("Invalid move! %c%d %c is an invalid move to %c%d %c",
								'a'+ m_point.y,m_point.x+1,cb[m_point.x][m_point.y].GetPieceId(),
								'a'+ j,i+1,cb[i][j].GetPieceId());
							SetPaneText(MESSAGEPANE,str,1);
							//if (m_demoFlag == FALSE)
								//AfxMessageBox(str);
						}
						m_point.x = m_point.y = -1;
						SetLearning(FALSE);
						DrawBoard();	 
						return -1;
					}
					CString lastMoveInfo = "";
					if(m_checkFlag == TRUE)
					{
						lastMoveInfo = " Check! ";
					}
					else if(m_castlingFlag == TRUE)
					{
						lastMoveInfo = " Castling! " + lastMoveInfo;
					}
					else if(m_enpassentFlag == TRUE)
					{					
						lastMoveInfo = " En passent! " + lastMoveInfo;
					}
					lastMoveInfo = "MOVE: " + GetSingleMoveString(m_iHistory) + lastMoveInfo;
					SetPaneText(MESSAGEPANE,lastMoveInfo,1);
					m_History[m_iHistory].SetMoveInfo(lastMoveInfo);
					CStringArray sa;
					GetHistoryString(sa,1);					
					if(sa.GetSize() > 0)
					{
						if(sa.GetSize() -1 == m_listctrl_movehistory.GetCount())
						{
							m_listctrl_movehistory.InsertString(-1,sa.GetAt(m_iHistory));
							m_listctrl_movehistory.SetCurSel(m_iHistory);
						}
						else
						{							
							m_listctrl_movehistory.ResetContent();
							for(int i=0;i<=m_iHistory;i++)
							{
								m_listctrl_movehistory.InsertString(-1,sa.GetAt(i));
							}
							m_listctrl_movehistory.SetCurSel(m_iHistory);							
						}
					}
					if(piece_id == 'P' || piece_id == 'p' || to_piece_id != -1)
					{
						m_halfMoveCount = 1;
					}
					else
					{
						if(m_halfMoveCount >= 1)
							m_halfMoveCount++;
					}
					m_History[m_iHistory].SetHalfMoveCount(m_halfMoveCount);
					m_checkFlag = m_castlingFlag = m_enpassentFlag = m_promotionFlag =
						m_ambiguousMoveRankFlag = m_ambiguousMoveFileFlag = FALSE;
					if(m_white_on_top == false && flipflag == TRUE)
					{
						m_point.x = 7 - m_point.x;
						m_point.y = 7 - m_point.y;
						i = 7 - i;
						j = 7 - j;
						FlipBoard();
						if(m_movedFromRect != 0)
						{
							m_movedFromRect = cb[m_point.x][m_point.y].GetRect();
							m_movedToRect = cb[i][j].GetRect();
						}
						flipflag = FALSE;
						m_white_on_top = true;
					}
					m_point.x = m_point.y = -1;
					SetLearning(FALSE);
					DrawBoard();
					/*//IF white is the first move and not in network and ICS not connected
					if(m_iHistory == 0 && m_blackAsEngineFlag == FALSE && m_pClientSocket == NULL && m_icsFlag == FALSE && m_optDlg.m_check_black_engine_auto_start == TRUE)
					{
						OnButtonBlackRadioButtonComputer();
					}*/
					return 0;
				}
			}
		}
	}
	m_movedFromRect = m_movedToRect = 0;
	m_point.x = m_point.y = -1;
	SetLearning(FALSE);
	DrawBoard();
	return -1;
}

void CNetChessView::OnMouseMoveAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_mouseMoveFlag == false)
		return;	 
	if(((m_whiteAsEngineFlag ==TRUE && m_pieceSide == WHITE && m_whiteEngineOnlyAnalyze == FALSE) || 
		(m_blackAsEngineFlag == TRUE && m_pieceSide ==BLACK && m_blackEngineOnlyAnalyze == FALSE)) )
	{
		//SetPaneText(MESSAGEPANE,"Connected to network and Engine is playing",0);
		return;
	}
	 
	CRect rect( point.x -25, point.y - 25, point.x + 25, point.y + 25);				  
	m_moveRect = rect;	 
	DrawBoard();	 
}

void CNetChessView::OnEditUndo() 
{
	// TODO: Add your command handler code here	
	OnEditUndoAction(1);
 	unsigned char msg[2];
	msg[0]= UNDO;
	msg[1]=1;
	SendSockData((unsigned char*)msg,2);

}
void CNetChessView::OnEditUndoAction(int redraw)
{
	if(m_iHistory < 0)
	{
		return;
	}
	PIECE_SIDE piece_side;
	PIECE_TYPE from_piece_type;
	COLOR_TYPE from_color_type;
	int from_pieceid;
	int from_row_id;
	int from_col_id;
	PIECE_TYPE to_piece_type;
	COLOR_TYPE to_color_type;
	int to_pieceid;
	int to_row_id;
	int to_col_id;
	if(m_pClientSocket == NULL)
	{
		m_player_turn = true;
		m_pieceSide = m_pieceSide == WHITE ? BLACK: WHITE;
	}
	else
	{
		if(m_player_turn == true)
		{
			m_player_turn =false;
		}
		else
		{
			m_player_turn = true;
		}
	}
	m_History[m_iHistory].GetHistory(
		piece_side,
		from_piece_type, from_color_type,from_pieceid,
		from_row_id,from_col_id, to_piece_type,
		to_color_type,to_pieceid,to_row_id,
		to_col_id);	

	if(m_white_on_top == false) 		 
	{
		cb[from_row_id][from_col_id].SetPieceData(
			from_pieceid,from_color_type,from_piece_type,
			PIECE_NOT_MOVING);

		cb[to_row_id][to_col_id].SetPieceData(
				to_pieceid,to_color_type,to_piece_type,
				PIECE_NOT_MOVING);	 	 
		if(m_History[m_iHistory].GetEnPassentFlag() == TRUE)			
		{
			PIECE_SIDE piece_side;
			PIECE_TYPE from_piece_type;
			COLOR_TYPE from_color_type;
			int from_pieceid;
			int from_row_id;
			int from_col_id;
			PIECE_TYPE to_piece_type;
			COLOR_TYPE to_color_type;
			int to_pieceid;
			int to_row_id;
			int to_col_id;
			m_History[m_iHistory-1].GetHistory(
				piece_side,
				from_piece_type, from_color_type,from_pieceid,
				from_row_id,from_col_id, to_piece_type,
				to_color_type,to_pieceid,to_row_id,
				to_col_id);
			cb[to_row_id][to_col_id].SetPieceData(
				from_pieceid,from_color_type,from_piece_type,
				PIECE_NOT_MOVING);			
		}
		else if(m_History[m_iHistory].GetCastlingFlag() == TRUE)			
		{
			if(cb[from_row_id][from_col_id+1].GetPieceType() == ROOK)
			{
				cb[from_row_id][7].SetPieceData(cb[from_row_id][from_col_id+1].GetPieceId(),
					cb[from_row_id][from_col_id+1].GetPieceColor(),
					cb[from_row_id][from_col_id+1].GetPieceType(),
					PIECE_NOT_MOVING);
				cb[from_row_id][from_col_id+1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			}
			else if(cb[from_row_id][from_col_id-1].GetPieceType() == ROOK)
			{
				cb[from_row_id][0].SetPieceData(cb[from_row_id][from_col_id-1].GetPieceId(),
					cb[from_row_id][from_col_id-1].GetPieceColor(),
					cb[from_row_id][from_col_id-1].GetPieceType(),
					PIECE_NOT_MOVING);
				cb[from_row_id][from_col_id-1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			}
		}
		else if(m_History[m_iHistory].GetPromotionFlag() == TRUE)
		{
			cb[to_row_id][to_col_id].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
		}
	}	
	else
	{
		cb[7-from_row_id][7-from_col_id].SetPieceData(
			from_pieceid,from_color_type,from_piece_type,
			PIECE_NOT_MOVING);

		cb[7-to_row_id][7-to_col_id].SetPieceData(
				to_pieceid,to_color_type,to_piece_type,
				PIECE_NOT_MOVING);	 	 
		if(m_History[m_iHistory].GetEnPassentFlag() == TRUE)
		{
			PIECE_SIDE piece_side;
			PIECE_TYPE from_piece_type;
			COLOR_TYPE from_color_type;
			int from_pieceid;
			int from_row_id;
			int from_col_id;
			PIECE_TYPE to_piece_type;
			COLOR_TYPE to_color_type;
			int to_pieceid;
			int to_row_id;
			int to_col_id;
			m_History[m_iHistory-1].GetHistory(
				piece_side,
				from_piece_type, from_color_type,from_pieceid,
				from_row_id,from_col_id, to_piece_type,
				to_color_type,to_pieceid,to_row_id,
				to_col_id);
			cb[7-to_row_id][7-to_col_id].SetPieceData(
				from_pieceid,from_color_type,from_piece_type,
				PIECE_NOT_MOVING);
		}
		else if(m_History[m_iHistory].GetCastlingFlag() == TRUE)
		{
			if(cb[7-from_row_id][7-from_col_id+1].GetPieceType() == ROOK)
			{
				cb[7-from_row_id][7].SetPieceData(cb[7-from_row_id][7-from_col_id+1].GetPieceId(),
					cb[7-from_row_id][7-from_col_id+1].GetPieceColor(),
					cb[7-from_row_id][7-from_col_id+1].GetPieceType(),
					PIECE_NOT_MOVING);
				cb[7-from_row_id][7-from_col_id+1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			}
			else if(cb[7-from_row_id][7-from_col_id-1].GetPieceType() == ROOK)
			{
				cb[7-from_row_id][0].SetPieceData(cb[7-from_row_id][7-from_col_id-1].GetPieceId(),
					cb[7-from_row_id][7-from_col_id-1].GetPieceColor(),
					cb[7-from_row_id][7-from_col_id-1].GetPieceType(),
					PIECE_NOT_MOVING);
				cb[7-from_row_id][7-from_col_id-1].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			}
		}
		else if(m_History[m_iHistory].GetPromotionFlag() == TRUE)
		{
			cb[7-to_row_id][7-to_col_id].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
		}
	}
	
	m_iHistory--;
	GetMoveHistory();
	if(redraw == 1)
		DrawBoard();
	int movecount = m_iHistory/2;
	char side = m_pieceSide == WHITE ? 'w' : 'b';
	CString str = GetPositionString('F',movecount,side);
	if(m_whiteAsEngineFlag == TRUE)
		SetEnginePosition(m_whiteEngine, str);
	if(m_blackAsEngineFlag == TRUE)
		SetEnginePosition(m_blackEngine, str);				
	
}

void CNetChessView::OnEditRedo() 
{
	// TODO: Add your command handler code here	
	OnEditRedoAction(1);
 	unsigned char msg[2];
	msg[0] = REDO;
	msg[1] = 1;
	SendSockData((unsigned char*)msg,2); 
}

void CNetChessView::OnEditRedoAction(int redraw)
{
	m_iHistory++;
	if(m_iHistory > m_topHistory)
	{
		m_iHistory--;
		return;
	}
	if(m_pClientSocket == NULL)
	{
		m_player_turn = true;
		m_pieceSide = m_pieceSide == WHITE ? BLACK: WHITE;
	}
	else
	{
		if(m_player_turn == true)
		{
			m_player_turn =false;
		}
		else
		{
			m_player_turn = true;
		}
	}
	GetMoveHistory();
	PIECE_SIDE piece_side;
	PIECE_TYPE from_piece_type;
	COLOR_TYPE from_color_type;
	int from_pieceid;
	int from_row_id;
	int from_col_id;
	PIECE_TYPE to_piece_type;
	COLOR_TYPE to_color_type;
	int to_pieceid;
	int to_row_id;
	int to_col_id;

	m_History[m_iHistory].GetHistory(
		piece_side,
		from_piece_type, from_color_type,from_pieceid,
		from_row_id,from_col_id, to_piece_type,
		to_color_type,to_pieceid,to_row_id,
		to_col_id);
	int SpecialAction  = m_History[m_iHistory].GetSpecialAction();
	if(m_white_on_top == false)		 
	{
		cb[from_row_id][from_col_id].SetPieceData(
				-1,NONE,BLANK,
				//to_pieceid,to_color_type,to_piece_type,
				PIECE_NOT_MOVING);	 	 
		cb[to_row_id][to_col_id].SetPieceData(
			from_pieceid,from_color_type,from_piece_type,
			PIECE_NOT_MOVING);
		m_movedFromRect = cb[from_row_id][from_col_id].GetRect();
		m_movedToRect = cb[to_row_id][to_col_id].GetRect();
		if(m_History[m_iHistory].GetEnPassentFlag() == TRUE)
		{
			PIECE_SIDE piece_side;
			PIECE_TYPE from_piece_type;
			COLOR_TYPE from_color_type;
			int from_pieceid;
			int from_row_id;
			int from_col_id;
			PIECE_TYPE to_piece_type;
			COLOR_TYPE to_color_type;
			int to_pieceid;
			int to_row_id;
			int to_col_id;
			m_History[m_iHistory-1].GetHistory(
				piece_side,
				from_piece_type, from_color_type,from_pieceid,
				from_row_id,from_col_id, to_piece_type,
				to_color_type,to_pieceid,to_row_id,
				to_col_id);
				cb[to_row_id][to_col_id].SetPieceData(
					-1,NONE,BLANK,				 
					PIECE_NOT_MOVING);	 	 
		}
		else if(m_History[m_iHistory].GetCastlingFlag() == TRUE)
		{
			if(from_col_id < to_col_id)
			{
				cb[from_row_id][5].SetPieceData(cb[from_row_id][7].GetPieceId(),
					cb[from_row_id][7].GetPieceColor(),
					cb[from_row_id][7].GetPieceType(),
					PIECE_NOT_MOVING);
				cb[from_row_id][7].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			}
			else //if(cb[to_row_id][to_col_id].GetPieceType() == KING)
			{
				cb[from_row_id][3].SetPieceData(cb[from_row_id][0].GetPieceId(),
					cb[from_row_id][0].GetPieceColor(),
					cb[from_row_id][0].GetPieceType(),
					PIECE_NOT_MOVING);
				cb[from_row_id][0].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			}
		}
		else if(m_History[m_iHistory].GetPromotionFlag() == TRUE)
		{
			cb[to_row_id][to_col_id].SetPieceData(
			to_pieceid,to_color_type,to_piece_type,
			PIECE_NOT_MOVING);
		}
		 
	}	
	else
	{
		cb[7-from_row_id][7-from_col_id].SetPieceData(
				-1,NONE,BLANK,
				//to_pieceid,to_color_type,to_piece_type,
				PIECE_NOT_MOVING);
		cb[7-to_row_id][7-to_col_id].SetPieceData(
			from_pieceid,from_color_type,from_piece_type,
			PIECE_NOT_MOVING);		 
		m_movedFromRect = cb[7-from_row_id][7-from_col_id].GetRect();
				m_movedToRect = cb[7-to_row_id][7-to_col_id].GetRect();
		if(m_History[m_iHistory].GetEnPassentFlag() == TRUE)
		{
			PIECE_SIDE piece_side;
			PIECE_TYPE from_piece_type;
			COLOR_TYPE from_color_type;
			int from_pieceid;
			int from_row_id;
			int from_col_id;
			PIECE_TYPE to_piece_type;
			COLOR_TYPE to_color_type;
			int to_pieceid;
			int to_row_id;
			int to_col_id;
			m_History[m_iHistory-1].GetHistory(
				piece_side,
				from_piece_type, from_color_type,from_pieceid,
				from_row_id,from_col_id, to_piece_type,
				to_color_type,to_pieceid,to_row_id,
				to_col_id);
			cb[7-to_row_id][7-to_col_id].SetPieceData(
					-1,NONE,BLANK,				 
					PIECE_NOT_MOVING);		
		}
		else if(m_History[m_iHistory].GetCastlingFlag() == TRUE)
		{
			if(7-from_col_id < 7-to_col_id)
			{
				cb[7-from_row_id][4].SetPieceData(cb[7-from_row_id][7].GetPieceId(),
					cb[7-from_row_id][7].GetPieceColor(),
					cb[7-from_row_id][7].GetPieceType(),
					PIECE_NOT_MOVING);
				cb[7-from_row_id][7].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			}
			else //if(cb[to_row_id][to_col_id].GetPieceType() == KING)
			{
				cb[7-from_row_id][2].SetPieceData(cb[7-from_row_id][0].GetPieceId(),
					cb[7-from_row_id][0].GetPieceColor(),
					cb[7-from_row_id][0].GetPieceType(),
					PIECE_NOT_MOVING);
				cb[7-from_row_id][0].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			}
		}
		else if(m_History[m_iHistory].GetPromotionFlag() == TRUE)
		{
			cb[7-to_row_id][7-to_col_id].SetPieceData(
			to_pieceid,to_color_type,to_piece_type,
			PIECE_NOT_MOVING);
		}
	}
	
	if(redraw == 1)
		DrawBoard();

	int movecount = m_iHistory/2;
	char side = m_pieceSide == WHITE ? 'w' : 'b';
	CString str = GetPositionString('F',movecount,side);
	if(m_whiteAsEngineFlag == TRUE)
		SetEnginePosition(m_whiteEngine, str);
	if(m_blackAsEngineFlag == TRUE)
		SetEnginePosition(m_blackEngine, str);				
}
void CNetChessView::OnRButtonDownAction(UINT nFlags, CPoint point) 
{
	CPickPieceDlg dlg;	 
	for(int i = 0; i < 8; i++)
	{
		for( int j = 0; j < 8; j++)
		{
			CRgn rgn;
			CRect rect = cb[i][j].GetRect();
			rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);
			if(rgn.PtInRegion(point))// && m_player_turn == cb[i][j].GetPieceColor())
			{	
				int foundflag = 0;
				if(m_pickPieceDlg->m_pickpiecetype  == 1 && m_pickPieceDlg->m_piecked_piece != -2)
				{
					foundflag = 1;
				}					 
				else
				{
					if(nFlags == 0)
					{
						if(dlg.DoModal()==IDOK)
						{ 
							if( dlg.m_piecked_piece != -2)
								foundflag = 1;
						}
					}					
				}
				if(foundflag == 1)
				{					
					int piece_id;
					COLOR_TYPE  piece_color;
					PIECE_TYPE  piece_type;
					STATE piece_state = PIECE_NOT_MOVING;
					int to_piece_id;
					COLOR_TYPE  to_piece_color;
					PIECE_TYPE  to_piece_type;
					STATE to_piece_state=PIECE_NOT_MOVING;
					if(m_pickPieceDlg->m_pickpiecetype  == 1)
					{
						piece_id = m_pickPieceDlg->m_piecked_piece;
						piece_color = m_pickPieceDlg->m_piece_color;
						piece_type = m_pickPieceDlg->m_piece_type;						 						 
						m_pickPieceDlg->m_pickpiecetype  = 0;
					}
					else
					{
						piece_id = dlg.m_piecked_piece;
						piece_color = dlg.m_piece_color;
						piece_type = dlg.m_piece_type;						 						 
					}
					cb[i][j].GetPieceData(to_piece_id,to_piece_color,to_piece_type,to_piece_state);	
					cb[i][j].SetPieceState(PIECE_NOT_MOVING);
					if(m_white_on_top == false)
					{
						m_History[++m_iHistory].SetHistory(BOTTOM,
								piece_type,piece_color,piece_id,i,j,
							to_piece_type,to_piece_color,to_piece_id,i,j);
					}
					else
					{
						m_History[++m_iHistory].SetHistory(BOTTOM,
							piece_type,piece_color,piece_id,7-i,7-j,
							to_piece_type,to_piece_color,to_piece_id,7-i,7-j);
					}
					m_topHistory = m_iHistory;
					cb[i][j].SetPieceData(piece_id,piece_color,piece_type,PIECE_NOT_MOVING);
					
					char data[30];
					memset(data,-1,30);					 
					data[0] = MOVE;
					data[1] = m_white_on_top == false?FALSE:TRUE;
					data[2] = (char)i;
					data[3] = (char)j;
   					data[4] = i;
					data[5] = j;						
					data[6] = 2;
					memcpy(&data[7],&piece_id,4);
					data[11] = piece_color;
					data[12] = piece_type;
					memcpy(&data[13],&m_whiteTime,4);
					memcpy(&data[17],&m_blackTime,4);
					//if(m_moveFlag == FALSE)
					//{					
						SendSockData((unsigned char*)data,21);
					//}
					//else
					//	SendToEngine((unsigned char*)data,13);
//					m_moveFlag = FALSE;
					SetMoveHistory();
					DrawBoard();
					return;	 
					}
			}
		}
	} 
}
void CNetChessView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_manualEditingFlag == FALSE)
	{
		SetPaneText(MESSAGEPANE,"Editing disabled",1);
		return;
	}
	if(m_pClientSocket != NULL && 
		((m_whiteAsEngineFlag ==TRUE && m_pieceSide == WHITE) || 
		(m_blackAsEngineFlag == TRUE && m_pieceSide ==BLACK)) )
	{
		SetPaneText(MESSAGEPANE,"Connected to network and Engine is playing",0);
		return;
	}
	OnRButtonDownAction(0,point);
	//valid only for manual editing	
	CView::OnRButtonDown(nFlags, point);
}

void CNetChessView::OnUpdateToolsServer(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_pServerSocket == NULL)
	{
		pCmdUI->SetCheck(0);	
	}
	else
	{
		pCmdUI->SetCheck(1);
	}
	
}

void CNetChessView::OnUpdateToolsClient(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_pClientSocket == NULL)
	{
		pCmdUI->SetCheck(0);	
	}
	else
	{
		pCmdUI->SetCheck(1);
	}	
}

void CNetChessView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class	

	 CBitmap localbmp;
	 localbmp.LoadBitmap(IDB_BITMAP_BASE);
	 
	 pDC->SelectObject(&localbmp); 
	 
	 COLORREF cr(RGB(216,207,169));    
	 CBrush brush(cr);
	 pDC->SelectObject(brush);
	 CRect crect = pInfo->m_rectDraw;
	 
	 COLORREF bkcrRef;    
	 COLORREF redcr(RGB(205,177,207));
 
	 CBrush redbrush;
	 redbrush.CreateSolidBrush(redcr);
 
	 COLORREF redbluecr(RGB(192,192,192));
	 CBrush redbluebrush;
	 redbluebrush.CreateSolidBrush(redbluecr);
 
	 CBrush* pbrush = pDC->SelectObject(&redbluebrush);
 
	 pDC->Rectangle(crect.left, crect.top,
	  crect.right, crect.right);
 
  
	 COLORREF bluecr(RGB(205,177,207));//ball color
	 CBrush bluebrush;
	 bluebrush.CreateSolidBrush(bluecr);
 
	 COLORREF greencr(RGB(0,255,0));
	 CBrush greenbrush;
	 greenbrush.CreateSolidBrush(greencr);
 
	 pDC->SelectObject(bluebrush);
 
	 int m_width = crect.Width() / 10;
	 pDC->Rectangle(crect.left + ((m_width * 3) /4), crect.top +((m_width * 3) /4),
	  crect.right - ((m_width * 3) /4), crect.right -((m_width * 3) /4));
 
	 pbrush =  pDC->SelectObject(&redbluebrush);
 
	  int xstart = m_width, ystart = m_width;
 
	 for(int i = 0; i < 8; i++)
	 {
	  xstart = m_width;
	  for( int j = 0; j < 8; j++)
	  {
	   CRect rect(xstart,ystart,xstart+m_width,ystart+m_width);
     
	   if(cb[i][j].GetColorType() == BLACK)
	   {
		CPoint pt(m_moveRect.left+25,m_moveRect.top+25);
		if(rect.PtInRect(pt) == TRUE)
		{
		 bkcrRef = m_optDlg.m_crefBlackColor;
		}           
		if(m_movedFromRect == rect)
		{
		 COLORREF cr1(RGB(0,0,255));
		 pDC->SetBkColor(cr1);
		 CBrush brush1(cr1);      
		 pDC->SelectObject(brush1); 
		 pDC->FillRect(&rect,&brush1);
		 CRect rect1(rect.left+4, rect.top + 4, rect.right -4, rect.bottom -4);
		 CBrush brush(m_optDlg.m_crefBlackColor);
		 pDC->SetBkColor(m_optDlg.m_crefBlackColor);
		 pDC->SelectObject(brush); 
		 pDC->FillRect(&rect1,&brush);
 
		}
		else if(m_movedToRect == rect)
		{
		 COLORREF cr1(RGB(0,0,255));
		 pDC->SetBkColor(cr1);
		 CBrush brush1(cr1);      
		 pDC->SelectObject(brush1); 
		 pDC->FillRect(&rect,&brush1);
		 CRect rect1(rect.left+4, rect.top + 4, rect.right -4, rect.bottom -4);
		 CBrush brush(m_optDlg.m_crefBlackColor);
		 pDC->SetBkColor(m_optDlg.m_crefBlackColor);
		 pDC->SelectObject(brush); 
		 pDC->FillRect(&rect1,&brush);
		}
		else
		{
		 CBrush brush(m_optDlg.m_crefBlackColor);
		 pDC->SetBkColor(m_optDlg.m_crefBlackColor);
		 pDC->SelectObject(brush); 
		 pDC->FillRect(&rect,&brush);
		}
	   }
	   else if(cb[i][j].GetColorType() == WHITE)
	   {
		CPoint pt(m_moveRect.left+25,m_moveRect.top+25);
		if(rect.PtInRect(pt) == TRUE)
		{
		 bkcrRef = m_optDlg.m_crefWhiteColor ;
		}
		if(m_movedFromRect == rect)
		{
		 COLORREF cr1(RGB(0,0,255));
		 pDC->SetBkColor(cr1);
		 CBrush brush1(cr1);      
		 pDC->SelectObject(brush1); 
		 pDC->FillRect(&rect,&brush1);
		 CRect rect1(rect.left +4, rect.top + 4, rect.right -4, rect.bottom -4);
		 CBrush brush(m_optDlg.m_crefWhiteColor);
		 pDC->SetBkColor(m_optDlg.m_crefWhiteColor);
		 pDC->SelectObject(brush); 
		 pDC->FillRect(&rect1,&brush);
 
		}
		else if(m_movedToRect == rect)
		{
		 COLORREF cr1(RGB(0,0,255));
		 pDC->SetBkColor(cr1);
		 CBrush brush1(cr1);      
		 pDC->SelectObject(brush1); 
		 pDC->FillRect(&rect,&brush1);
		 CRect rect1(rect.left +4, rect.top + 4, rect.right -4, rect.bottom -4);
		 CBrush brush(m_optDlg.m_crefWhiteColor);
		 pDC->SetBkColor(m_optDlg.m_crefWhiteColor);
		 pDC->SelectObject(brush); 
		 pDC->FillRect(&rect1,&brush);
 
		}    
		else
		{
		 CBrush brush(m_optDlg.m_crefWhiteColor);
		 pDC->SetBkColor(m_optDlg.m_crefWhiteColor);
		 pDC->SelectObject(brush); 
		 pDC->FillRect(&rect,&brush);
		}
	   }
	   if(cb[i][j].GetPieceType() != BLANK && cb[i][j].GetPieceState() != PIECE_MOVING)
	   {
		int piece_id;
		COLOR_TYPE  piece_color;
		PIECE_TYPE  piece_type;
		STATE piece_state;
		cb[i][j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
		if(piece_id <= 0)
		{
		 break;
		}
		/*if(m_optDlg.m_boardFont == 1)
		{
				CBitmap bitmap;			
				bitmap.LoadBitmap(GetBitmapId(piece_id));			 
				CDC bmpdc;
				bmpdc.CreateCompatibleDC(pDC);
				bmpdc.SelectObject(&bitmap); 
				BITMAP bmp;
				bitmap.GetBitmap(&bmp);
			
				pDC->StretchBlt(rect.left+7,rect.top+7,m_squareWidth -15,m_squareWidth-15,&bmpdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY); 
		}
		else
		{					
				CString piece;
				if(GetPieceString(piece_id,piece) == 0)
				{				
					//CRect rct(rect.left+10,rect.top+10,rect.right-10,rect.bottom-10);
					CFont *fnt = pDC->SelectObject(&m_optDlg.m_font);
					pDC->DrawText(piece,rect,0);//DT_CENTER | DT_VCENTER);
					//COLORREF white(RGB(255,255,255)), black(RGB(0,0,0));
					//ldc->SetBkColor(TRANSPARENT);
					//ldc->SetTextColor(piece_color == WHITE? white : black);
					//ldc->TextOut(rect.left+5,rect.top+5,piece);
					pDC->SelectObject(fnt);
				}
		}*/

		CBitmap bitmap;
		
		bitmap.LoadBitmap(GetBitmapId(piece_id));    
		CDC bmpdc;
		bmpdc.CreateCompatibleDC(pDC);
		bmpdc.SelectObject(&bitmap); 
 
		BITMAP bmp;
		bitmap.GetBitmap(&bmp);
		
     
		pDC->StretchBlt(rect.left+(m_width /6),(rect.top + m_width/6),(int)(m_width/1.5),(int)(m_width/1.5),&bmpdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY); 
	   }
	   
	   xstart += m_width;
	  }  
	  ystart += m_width;
	 }
 
	 pDC->SetBkColor(redbluecr);
	 for(int i=0;i<8;i++)
	 {  
	  if(m_LetterFlag == true)
	  {
	   if(m_white_on_top == false)
	   {
		pDC->TextOut(m_width * (i+1)+10,(m_width * 1)/ 3,(CString)((char)('a'+i)));
		pDC->TextOut(m_width * (i+1)+10,crect.right - ((m_width * 2)/ 3), (char)('a'+i));
	   }
	   else
	   {
		pDC->TextOut(m_width * (i+1),(m_width * 2)/ 3,(CString)((char)('h'-i)));
		pDC->TextOut(m_width * (i+1),crect.right - ((m_width * 2)/ 3), (char)('h'- i));
	   }
	  }
	  if(m_NumberFlag == true)
	  {
	   if(m_white_on_top == false)
	   {
		pDC->TextOut((m_width * 1)/ 3, m_width * (i+1), (CString)((char)('8' - i)));
		pDC->TextOut(crect.right - ((m_width * 2)/ 3), m_width * (i+1), (char)('8' - i));
	   }
	   else
	   {
		pDC->TextOut((m_width * 1)/ 3, m_width * (i+1), (CString)((char)('1' + i)));
		pDC->TextOut(crect.right - ((m_width * 2)/ 3), m_width * (i+1), (char)('1' + i));
	   }
	  }
	 }
CView::OnPrint(pDC, pInfo);
}

void CNetChessView::OnTimer(UINT nIDEvent) 
{
	
	static int count = 0;
	static int state=1;	 
	switch(nIDEvent)
	{
		case SHELL_ICON_TIMER_EVENT_ID:
			{
				NOTIFYICONDATA nicondata;
				char data[64] = "NetChess by A.V.M.Rao";
				 
				nicondata.hWnd = AfxGetApp()->m_pMainWnd->GetSafeHwnd();
				nicondata.uID = 10;
				nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
				nicondata.cbSize = sizeof(nicondata);
				nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
				nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
				strcpy(nicondata.szTip,data);				
				if(state == 1)
				{
					nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
					Shell_NotifyIcon(NIM_MODIFY,&nicondata);
					state = 0;
				}
				else
				{
					nicondata.hIcon = AfxGetApp()->LoadIcon(IDI_ICON_MAINFRAME_OPPOSITE);
					state = 1;
					Shell_NotifyIcon(NIM_MODIFY,&nicondata);
				}
			}
			break;
		case PIECE_SIDE_TIMER_EVENT_ID:
			{
				//if ICS Timer is sarted or clock type is 
				//CONVENTIONAL, ICS TYPE, MOVETIME use ICS Timer
				if(m_icsFlag == TRUE)
					/*||
				   m_timeControlDlg.m_radio_clock_type == CONVENTIONAL ||
				   m_timeControlDlg.m_radio_clock_type == ICSTYPE ||
				   m_timeControlDlg.m_radio_clock_type == MOVETIME) //for ICS games it should be decremented*/
					return;
				//Update the Status bar with last move info 
				//for every two seconds
				if(count == 2)
				{
					count = 0;
					if(m_iHistory > -1)
					{
						CString str = m_History[m_iHistory].GetMoveInfo();
						if(!str.IsEmpty())
							SetPaneText(MESSAGEPANE,str);
					}
				}
				count++;
				if(m_pauseclockFlag == TRUE)
				{
					m_elapsedTime++;
					break;
				}
				//m_pClientSocket is NULL means the timer is only for 
				//for the board
				if(m_pClientSocket == NULL)
				{
					//my piece side is black and player turn is true
					if(m_pieceSide == BLACK && m_player_turn == true)
					{	

						m_blackTime--;
						if(m_blackTime >= 0)
						{					
							//set black time
							CTime tb( m_blackTime);
							CTime st(0);						
							CTimeSpan ts = tb - st; 
							CString str;
							str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
							SetPaneText(BLACKTIME,str);
							if(m_blackTime == 0)
							{
								CString str;
								str.Format("Black side timeout");					 
								AfxMessageBox(str);
							}
						}
						/*CTime tb(time(0)  -  m_blackTime);						
						CTime st(m_startTime+m_elapsedTime);
						CTimeSpan ts = tb - st; 
						m_blackTime++;
						CString str;
						str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
						//str.Format("%d:%d:%d",t->tm_hour,t->tm_min,t->tm_sec);

						SetPaneText(BLACKTIME,str);*/
					}
					else if(m_pieceSide == WHITE && m_player_turn == true)
					{					 
						m_whiteTime--;
						if(m_whiteTime >=0)
						{
							//set white
							CTime tb(m_whiteTime);
							CTime st(0);
							CTimeSpan ts = tb - st; 
							CString str;
							str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
							//str.Format("%d:%d:%d",t->tm_hour,t->tm_min,t->tm_sec);
							SetPaneText(WHITETIME,str);
							if(m_whiteTime == 0)
							{
								CString str;
								str.Format("White side timeout");					 
								//SetPaneText(MESSAGEPANE,str);
								AfxMessageBox("White side timeout");
							}
						}
						/*CTime tb( time(0)- m_whiteTime);
						CTime st(m_startTime+ m_elapsedTime);						
						CTimeSpan ts = tb - st; 												
						m_whiteTime++;
						CString str;
						str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
						SetPaneText(WHITETIME,str);*/
					}
				}
				else //timer is client server
				{
					if(m_pieceSide == BLACK && m_player_turn == true || (m_pieceSide == WHITE && m_player_turn == false))
					{	
						m_blackTime--;
						if(m_blackTime >= 0)
						{					
							//set black time
							CTime tb( m_blackTime);
							CTime st(0);						
							CTimeSpan ts = tb - st; 
							CString str;
							str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
							SetPaneText(BLACKTIME,str);
						}
						/*CTime tb(time(0)  -  m_blackTime);
						CTime st(m_startTime+m_elapsedTime);
						CTimeSpan ts = tb - st; 
						m_blackTime++;
						CString str;
						str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
						//str.Format("%d:%d:%d",t->tm_hour,t->tm_min,t->tm_sec);

						SetPaneText(BLACKTIME,str);*/
					}
					else if(m_pieceSide == WHITE && m_player_turn == true || (m_pieceSide == BLACK && m_player_turn == false))
					{	
						m_whiteTime--;
						if(m_whiteTime >=0)
						{
							//set white
							CTime tb(m_whiteTime);
							CTime st(0);
							CTimeSpan ts = tb - st; 
							CString str;
							str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
							//str.Format("%d:%d:%d",t->tm_hour,t->tm_min,t->tm_sec);
							SetPaneText(WHITETIME,str);
						}
						/*CTime tb( time(0)- m_whiteTime);						
						CTime st(m_startTime+m_elapsedTime);
						CTimeSpan ts = tb - st; 
						m_whiteTime++;
						CString str;
						str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
						SetPaneText(WHITETIME,str);*/
					}
				}
			}
			break;
		case DEMO_TIMER_EVENT_ID:
			{
				if(m_demoTotal <= m_topHistory && m_demoFlag == TRUE && m_pauseFlag == FALSE)
				{				
					m_demoTotal++;
					OnEditRedoAction(1);
 					unsigned char msg[2];
					msg[0] = REDO;
					msg[1] = 1;
					SendSockData((unsigned char*)msg,2); 					
				}
				else if(m_pauseFlag != TRUE)
				{
					m_demoTotal = 0;
					KillTimer(DEMO_TIMER_EVENT_ID);
					m_demoFlag = FALSE;
					unsigned char msg[1];
					msg[0] = DEMO_END;
					SendSockData(msg,1);
					//CString result = "Demo over: Result-" + m_gameInfoDlg.m_edit_result;
					//AfxMessageBox(result);
					Sleep(5000);
					OnFileLoadnextgame();
					m_demoFlag = TRUE;
					m_manualEditingFlag = FALSE;
					OnEditMovefirst();
					m_demoTotal = 0;

					SetTimer(DEMO_TIMER_EVENT_ID_ALL, m_demoInterval * 1000, NULL);
					
				}	
			}
			break;
		case DEMO_TIMER_EVENT_ID_ALL:
		{
			if (m_demoTotal <= m_topHistory && m_demoFlag == TRUE && m_pauseFlag == FALSE)
			{
				m_demoTotal++;
				OnEditRedoAction(1);
				unsigned char msg[2];
				msg[0] = REDO;
				msg[1] = 1;
				SendSockData((unsigned char*)msg, 2);
			}
			else if (m_pauseFlag != TRUE)
			{
				m_demoTotal = 0;
				KillTimer(DEMO_TIMER_EVENT_ID_ALL);
				m_demoFlag = FALSE;
				unsigned char msg[1];
				msg[0] = DEMO_END;
				SendSockData(msg, 1);
				//CString result = "Demo over: Result-" + m_gameInfoDlg.m_edit_result;
				//AfxMessageBox(result);
				Sleep(5000);
				OnFileLoadnextgame();
				m_demoFlag = TRUE;
				m_manualEditingFlag = FALSE;
				OnEditMovefirst();
				m_demoTotal = 0;
				
				SetTimer(DEMO_TIMER_EVENT_ID_ALL, m_demoInterval * 1000, NULL);

			}
		}
		break;
		case SAVE_TIMER_EVENT_ID:
			{
				if(!m_fileName.IsEmpty())
					OnFileSave();				
				/*char defaultBuf[40]="default";
				char CurrentDir[255];
				GetWindowsDirectory(CurrentDir,MAX_PATH);
				strcat(CurrentDir,"\\NetChess.ini");
				CStringArray ar;
				CString str = GetHistoryString(ar,0);
				str.Replace("\r","");	
				str = str + "\n";
				WritePrivateProfileString("NetChess","PGNFormat",str,CurrentDir);*/
			}
			break;
		case ICS_TIMER:
			{				 
				if(m_icsFlag == TRUE ||
				   m_timeControlDlg.m_radio_clock_type == CONVENTIONAL ||
				   m_timeControlDlg.m_radio_clock_type == ICSTYPE ||
				   m_timeControlDlg.m_radio_clock_type == MOVETIME)

				{
					
					
					if(m_pieceSide == WHITE && m_player_turn == true || (m_pieceSide == BLACK && m_player_turn == false))
					{
						m_whiteTime--;
						if(m_whiteTime >=0)
						{
							//set white
							CTime tb(m_whiteTime);
							CTime st(0);
							CTimeSpan ts = tb - st; 
							CString str;
							str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
							//str.Format("%d:%d:%d",t->tm_hour,t->tm_min,t->tm_sec);
							SetPaneText(WHITETIME,str);
						}
					}
					else if(m_pieceSide == BLACK && m_player_turn == true || (m_pieceSide == WHITE && m_player_turn == false))
					{
						m_blackTime--;
						if(m_blackTime >= 0)
						{					
							//set black time
							CTime tb( m_blackTime);
							CTime st(0);						
							CTimeSpan ts = tb - st; 
							CString str;
							str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());					 
							SetPaneText(BLACKTIME,str);
						}
					}

				}

				break;
			}
		default:
			break;
		 
	}
	CView::OnTimer(nIDEvent);
}
void CNetChessView::KillTimerEvent()
{
	 
	KillTimer(SHELL_ICON_TIMER_EVENT_ID);
	m_timerFlag = false;
}

int CNetChessView::OnFileNewAction()
{
	if(m_iHistory > -1)
	{		 
		int ret = AfxMessageBox("Do you want to save the playing game",MB_YESNOCANCEL);
		if(ret == IDYES)
		{
			OnFileSave();			 
		}
		else if(ret == IDCANCEL)
		{
			return -1;
		}
	}
	Initialize();
//	OnInitialUpdate();
	if(m_pieceSide == BLACK)
	{
		m_player_turn = false;
	}
	else
	{
		m_player_turn = true;
	}
	DrawBoard();	
	return 0;
}

void CNetChessView::OnViewHistory() 
{
	 /*if(m_iHistory < 0)
	 {
		 AfxMessageBox("History not found");
		 return;
	 }*/
	  CHistoryDlg dlg(this,m_History,m_iHistory);
	  dlg.DoModal();
}

void CNetChessView::OnToolsWhiteontop() 
{	
}

void CNetChessView::OnEditMovefirst() 
{
	// TODO: Add your command handler code here	
	int total = m_iHistory;
	for(int i=0;i<=total;i++)
	{
		OnEditUndoAction(0); 		
	}
	unsigned char msg[2];
	msg[0] = MOVEFIRST;
	msg[1] = 0;
	SendSockData((unsigned char*)msg,2);
	DrawBoard();
}

void CNetChessView::OnEditMovelast() 
{
	// TODO: Add your command handler code here	
	int total = m_topHistory;
	for(int i=0;i<=total;i++)
	{
		OnEditRedoAction(0); 		
	}
	unsigned char msg[2];
	msg[0] = MOVELAST;
	msg[1] = 0;
	SendSockData((unsigned char*)msg,2);

	DrawBoard();
		 	
}

void CNetChessView::OnHelpHowtoplay() 
{
	CHowToPlayDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here*/ 

	
}

void CNetChessView::OnToolsDisconnect() 
{
	// TODO: Add your command handler code here
	 
	if(m_pClientSocket == NULL)
	{
		AfxMessageBox("Not connected to network");
		if(m_pServerSocket != NULL)
		{
			if(AfxMessageBox("Are you sure, you want to disconnect",MB_YESNO)==IDYES)
			{
				delete m_pServerSocket;
				m_pServerSocket = NULL;
			}
		}
		return;
	}
	if(m_pClientSocket != NULL)
	{ 
		if(AfxMessageBox("Are you sure, you want to disconnect",MB_YESNO)==IDYES)
		{
			m_pClientSocket->ShutDown(2);
			m_pClientSocket->Close();
			delete m_pClientSocket;
			m_pClientSocket = NULL; 
		}
	}
}

void CNetChessView::OnEditProperties() 
{
	// TODO: Add your command handler code here
	CPropertiesDlg dlg(this);
	if(m_pServerSocket != NULL)
	{
		if(m_pClientSocket != NULL)
		{
			CString ipaddr;int port;
			((CClientSocket*)m_pClientSocket)->GetInfo(ipaddr,port);
			dlg.SetInfo(SERVER,ipaddr,port,((CServerSocket*)m_pServerSocket)->m_portnumber);
		}
		else
		{
			dlg.SetInfo(SERVER," ",0,((CServerSocket*)m_pServerSocket)->m_portnumber);			 
		}
	}
	else if(m_pClientSocket != NULL)
	{
		CString ipaddr;int port;
		((CClientSocket*)m_pClientSocket)->GetInfo(ipaddr,port);
		dlg.SetInfo(CLIENT,ipaddr,port,0);
	}
	else
	{
		dlg.SetInfo(-1,"",0,0);
	}
	dlg.DoModal();	
}


void CNetChessView::OnToolsDraw() 
{
	// TODO: Add your command handler code here
	if(AfxMessageBox("Do you want to send Draw request?",MB_YESNO) == IDYES)
	{
		unsigned char data[50];
		data[0]=DRAW_REQUEST;
		strcpy((char*)&data[1],m_edit_name.GetBuffer(0));
		SendSockData(data,m_edit_name.GetLength()+2);	
	}
}

void CNetChessView::OnToolsResign() 
{
	// TODO: Add your command handler code here
	if(AfxMessageBox("Do you want to send Resign messge?",MB_YESNO) == IDYES)
	{
		unsigned char data[50];
		data[0]=RESIGN_REQUEST;
		strcpy((char*)&data[1],m_edit_name.GetBuffer(0));
		SendSockData(data,m_edit_name.GetLength()+2);	
		OnFileNewgame();
		SendToEngine(data,m_edit_name.GetLength()+2);
	}
}
void CNetChessView::SetPieceSide(COLOR_TYPE pieceside)
{
	m_pieceSide = pieceside;
	if(m_pieceSide == WHITE)
	{
		m_player_turn = true;
		m_white_on_top = false;
		SetPaneText(PLAYERNAME,"WHITE");
		m_gameInfoDlg.m_edit_white = m_edit_name;
	}
	else
	{
		m_player_turn = false;
		//Initialize()
//		OnInitialUpdate();
		FlipBoard();
		m_white_on_top = true;
		SetPaneText(PLAYERNAME,"BLACK");	
		m_gameInfoDlg.m_edit_black = m_edit_name;
	}
	m_blackTime = m_whiteTime =m_engineLevelDlg.m_edit_time_control == 0? 5*60: m_engineLevelDlg.m_edit_time_control*60;
	m_elapsedTime = 0;
	m_startTime = (int)time(0);
	m_manualEditingFlag = FALSE;
	m_demoFlag = FALSE;
	DrawBoard();

}

COLOR_TYPE CNetChessView::GetPlayerSide()
{
	return m_pieceSide;
}

void CNetChessView::OnViewLostpieces() 
{
	CLostPieceDlg dlg;
	dlg.SetHistory(m_History,m_iHistory);
	dlg.DoModal();
}

void CNetChessView::OnFileFeed() 
{
//obsolete function/remove later
}

void CNetChessView::OnToolsLearn() 
{
	// TODO: Add your command handler code here	
}

void CNetChessView::OnEditSetboard() 
{
	
}

void CNetChessView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	 
	CView::OnRButtonUp(nFlags, point);
}
bool CNetChessView::CheckCheckState(int piecetype, int piececolor,int x,int y)
{
	switch(piecetype)
	{
	case PAWN:			
			if(m_white_on_top == true)
			{
				if(piececolor == BLACK)
				{
					if(x-1>=0 && y-1>=0)
					{
						if(cb[x-1][y-1].GetPieceId() == KING_WHITE)
						{						
							return true;
						}
					}
					if(x-1>=0&&y+1<8)
					{
						if(cb[x-1][y+1].GetPieceId() == KING_WHITE) 
						{
							return true;
						}
					}
				}
				else
				{
					if(x+1 <8 && y-1>=0)
					{
						if(cb[x+1][y-1].GetPieceId() == KING_BLACK)
						{
							return true;
						}
					}
					if(x+1<8 && y+1 <8)
					{
						if(cb[x+1][y+1].GetPieceId() == KING_BLACK) 
						{
							return true;
						}
					}
				}
			}
			else
			{	
				if(piececolor == BLACK)
				{
					if(x+1<=7 && y-1 >=0)
					{
						if(cb[x+1][y-1].GetPieceId() == KING_WHITE)
						{
							return true;
						}
					}
					if(x+1<=7&&y+1<=7)
					{
						if(cb[x+1][y+1].GetPieceId() == KING_WHITE) 					
						{						
							return true;
						}
					}					 
				}
				else
				{
					if(x-1>=0&&y-1>=0)
					{
						if(cb[x-1][y-1].GetPieceId() == KING_BLACK)					
						{						
							return true;
						}
					}
					if(x-1>=0 && y+1<=7)
					{
						if(cb[x-1][y+1].GetPieceId() == KING_BLACK) 
						{						
							return true;
						}
					}
				}
			}			 
			return false;
		case ROOK:
			{			
			int pieceid=0;
			for(int i = x+1; i< 8; i++)
			{
				if((pieceid = cb[i][y].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			 
			for(int i = x-1; i > -1; i--)
			{
				if((pieceid = cb[i][y].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			 
			for(int i = y+1; i< 8; i++)
			{
				if((pieceid = cb[x][i].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			 
			for(int i = y-1; i > -1; i--)
			{
				if((pieceid = cb[x][i].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			 
			return false;
			}
			break;
		case KNIGHT:			
				if(piececolor == BLACK)
				{					
					if(
						(x-2 > -1 && y+1 < 8 && cb[x -2][y +1].GetPieceId()  == KING_WHITE) ||							 
						(x-1 > -1 && y+2 < 8 && cb[x -1][y+2].GetPieceId()  == KING_WHITE) ||
						(x+1 <8 && y+2 < 8 && cb[x +1][y+2].GetPieceId()  == KING_WHITE) ||
						(x+2 <8 && y+1 < 8 && cb[x +2][y+1].GetPieceId()  == KING_WHITE) ||						 
						(x+2 < 8 && y-1 > -1 && cb[x +2][y-1].GetPieceId()  == KING_WHITE) || 
						(x+1 < 8 && y-2 > -1 && cb[x +1][y-2].GetPieceId()  == KING_WHITE) ||
						(x-1 > -1 && y-2 > -1 && cb[x -1][y-2].GetPieceId()  == KING_WHITE) ||
						(x-2 > -1 && y-1 > -1 && cb[x -2][y-1].GetPieceId()  == KING_WHITE))

					{
						return true;
					}
					else return false;
				}
				else
				{
					if(
						(x-2 > -1 && y+1 < 8 && cb[x -2][y +1].GetPieceId()  == KING_BLACK) ||
						(x-1 > -1 && y+2 < 8&& cb[x -1][y+2].GetPieceId()  == KING_BLACK) ||
						(x+1 <8 && y+2 < 8 &&cb[x +1][y+2].GetPieceId()  == KING_BLACK) ||
						(x+2 <8 && y+1 < 8 &&cb[x +2][y+1].GetPieceId()  == KING_BLACK) ||
						(x+2 < 8 && y-1 > -1 &&cb[x +2][y-1].GetPieceId()  == KING_BLACK) ||
						(x+1 < 8 && y-2 > -1 &&cb[x +1][y-2].GetPieceId()  == KING_BLACK) ||
						(x-1 > -1 && y-2 > -1 &&cb[x -1][y-2].GetPieceId()  == KING_BLACK) ||
						(x-2 > -1 && y-1 > -1 && cb[x -2][y-1].GetPieceId()  == KING_BLACK))

					{
						return true;
					}
					else return false;
				}
			break;
		case BISHOP:
			{			
			int i=0,j=0,pieceid;
			for(i = x+1,j=y+1; i< 8 && j < 8; i++,j++)
			{
				if((pieceid = cb[i][j].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			
			i=0,j=0;
			for(j=y-1,i=x-1; j> -1 && i > -1 ;i--,j--)
			{
				if((pieceid = cb[i][j].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			
			i=0,j=0;
			for(j=y-1,i=x+1; j> -1 && i < 8;i++,j--)
			{
				if((pieceid = cb[i][j].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			
			i=0,j=0;
			for(j=y+1,i=x-1; j< 8 && i > -1;i--,j++)
			{
				if((pieceid = cb[i][j].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			 
			return false;
			}			 
			break;
		case QUEEN:
			{			
			int i=0,j=0,pieceid;
			for(i = x+1,j=y+1; i< 8 && j < 8; i++,j++)
			{
				if( (pieceid = cb[i][j].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			
			i=0,j=0;
			for(j=y-1,i=x-1; j> -1 && i > -1 ;i--,j--)
			{
				if( (pieceid = cb[i][j].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			
			i=0,j=0;
			for(j=y-1,i=x+1; j> -1 && i < 8;i++,j--)
			{
				if((pieceid = cb[i][j].GetPieceId())  > 0)
				{
					if(cb[x][y].GetPieceColor() == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			
			i=0,j=0;
			for(j=y+1,i=x-1; j< 8 && i > -1;i--,j++)
			{
				if((pieceid = cb[i][j].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			 
			}			 
			{
			int pieceid = 0;
			for(int i = x+1; i< 8; i++)
			{
				if( (pieceid = cb[i][y].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			 
			for(int i = x-1; i > -1; i--)
			{
				if( (pieceid = cb[i][y].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			 
			for(int i = y+1; i< 8; i++)
			{
				if((pieceid = cb[x][i].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			 
			for(int i = y-1; i > -1; i--)
			{
				if( (pieceid = cb[x][i].GetPieceId())  > 0)
				{
					if(piececolor == BLACK)
					{
						if(pieceid == KING_WHITE)
						{
							return true;
						}
					}
					else
					{
						if(pieceid == KING_BLACK)
						{
							return true;
						}
					}
					break;
				}
			}			 
			return false;
			}
			break;
		case KING:			
			return false;
			break;
		default:
			break;
		}	 

	return false;
}
bool CNetChessView::CheckKingMove(int fromx, int fromy, int tox, int toy)
{
	if( m_checkmove == FALSE)
		return true;
	for(int i=0;i<8;i++)
	{
		for(int j = 0;j<8;j++)
		{
			if(cb[i][j].GetPieceId() > 0&& cb[tox][toy].GetPieceColor() != cb[i][j].GetPieceColor())
			{
				if(CheckCheckState(cb[i][j].GetPieceType(),cb[i][j].GetPieceColor() ,i,j) == true)
				{
					return false;
				}
			}
		}
	}
	return true;
}
void CNetChessView::SetMoveHistory()
{
	unsigned int action = 0x0000;
	action = m_blackKingMovedFlag == true? (action | 0x0020) : (action & 0xffff);	
	action = m_whiteKingMovedFlag == true? (action | 0x0010) : (action & 0xffff);
	action = m_blackRookRank1MovedFlag == true? (action | 0x0008): (action & 0xffff);
	action = m_blackRookRank7MovedFlag == true?(action | 0x0004): (action & 0xffff);
	action = m_whiteRookRank1MovedFlag == true?(action | 0x0002): (action & 0xffff);
	action = m_whiteRookRank7MovedFlag == true?(action | 0x0001): (action & 0xffff);
	action = m_checkFlag == TRUE? (action | 0x0040): (action & 0xffff);
	action = m_castlingFlag == TRUE? (action | 0x0080): (action & 0xffff);
	action = m_promotionFlag == TRUE? (action | 0x0100): (action & 0xffff);
	action = m_enpassentFlag == TRUE? (action | 0x0200): (action & 0xffff);
	action = m_ambiguousMoveFileFlag == TRUE? (action | 0x0400): (action & 0xffff);
	action = m_ambiguousMoveRankFlag == TRUE? (action | 0x0800): (action & 0xffff);
	m_History[m_iHistory].SetPieceMoveAction(action);
	/*writeMessage("%d %d %d %d %d %d",m_blackKingMovedFlag,
		m_whiteKingMovedFlag,m_blackRookRank1MovedFlag,	
		m_blackRookRank7MovedFlag,	m_whiteRookRank1MovedFlag,
		m_whiteRookRank7MovedFlag);*/
}
void CNetChessView::GetMoveHistory()
{
	if(m_iHistory < 0)
	{
		m_ambiguousMoveRankFlag = FALSE;
		m_ambiguousMoveFileFlag = FALSE;
		m_enpassentFlag = FALSE;
		m_promotionFlag = FALSE;
		m_castlingFlag  = FALSE ;
		m_checkFlag     = FALSE;
		m_blackKingMovedFlag = false;
		m_whiteKingMovedFlag = false;
		m_blackRookRank1MovedFlag = false;
		m_blackRookRank7MovedFlag = false;
		m_whiteRookRank1MovedFlag = false ;
		m_whiteRookRank7MovedFlag = false;
		return;
	}
	unsigned int action = m_History[m_iHistory].GetPieceMoveAction();
	action = action & 0x0fff;
	m_ambiguousMoveRankFlag = (0x0800 & action) ==0 ? FALSE : TRUE;
	m_ambiguousMoveFileFlag = (0x0400 & action) == 0 ?FALSE : TRUE;
	m_enpassentFlag = (0x0200 & action) == 0 ? FALSE: TRUE;
	m_promotionFlag = (0x0100 & action) == 0 ? FALSE: TRUE;
	m_castlingFlag  = (0x0080 & action) == 0 ? FALSE : TRUE;
	m_checkFlag     = (0x0040 & action) == 0 ? FALSE : TRUE;
	m_blackKingMovedFlag = (0x0020 & action) == 0 ? false: true;
	m_whiteKingMovedFlag = (0x0010 & action) == 0 ? false : true;
	m_blackRookRank1MovedFlag = (0x0008 & action) == 0 ? false : true;
	m_blackRookRank7MovedFlag = (0x0004 & action) == 0 ? false : true;
	m_whiteRookRank1MovedFlag = (0x0002 & action) == 0 ? false : true;
	m_whiteRookRank7MovedFlag = (0x0001 & action) == 0 ? false : true;
	/*writeMessage("%d %d %d %d %d %d",m_blackKingMovedFlag,
		m_whiteKingMovedFlag,m_blackRookRank1MovedFlag,	
		m_blackRookRank7MovedFlag,	m_whiteRookRank1MovedFlag,
		m_whiteRookRank7MovedFlag);*/
}

void CNetChessView::writeMessage(char *str,...)
{
//#ifdef _DEBUG
	if(m_optDlg.m_check_netchess_log == TRUE)
	{
		char arr[9999];
		va_list va;     
		va_start(va,str);
		vsprintf(arr,str,va);
		CString filename = ".\\" + m_edit_name + "_Log.txt";
		FILE* fp=fopen(filename,"a+");
		if(fp != NULL)
		{
			time_t t= time(0);
			CTime ctime(t);			
			
			fprintf(fp,"%d/%d/%d %d:%d:%d: %s\n",
				ctime.GetDay(),ctime.GetMonth(),ctime.GetYear(),
				ctime.GetHour(),ctime.GetMinute(),ctime.GetSecond(),
				arr);
			fclose(fp);
		}
	}
//#endif
}

void CNetChessView::OnEditCheckmove() 
{
	// TODO: Add your command handler code here		
	if(m_manualEditingFlag == TRUE)
	{
		m_checkmove = m_checkmove == TRUE ? FALSE: TRUE;
		unsigned char data[50];
		data[0]=CHECKLEGALMOVE;
		data[1] = m_checkmove;
		strcpy((char*)&data[2],m_edit_name.GetBuffer(0));
		SendSockData(data,m_edit_name.GetLength()+2);	
		if(m_checkmove == TRUE)
			AfxMessageBox("Enabled checking valid move");
		else
			AfxMessageBox("Disabled checking valid move");
	}
}


void CNetChessView::OnUpdateEditCheckmove(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here	
	m_checkmove == TRUE ? pCmdUI->SetCheck(1) : pCmdUI->SetCheck(0);
	m_manualEditingFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);

}

void CNetChessView::OnEditManualeditEmpty() 
{
	// TODO: Add your command handler code here
	OnEditCopy();
	if(m_manualEditingFlag == TRUE)
	{
		for ( int i = 0; i < 8; i++)
		{	
			for( int j = 0; j < 8; j++)
			{
				cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);				 
			}	
		}
		m_iHistory = -1;
		DrawBoard();
		unsigned char data[1];
		data[0] = MANUALEDITING_EMPTY;
		SendSockData(data,1);
	}
	else
	{
		AfxMessageBox("Editing disabled");
	}
}

void CNetChessView::OnEditManualeditEnd() 
{
	// TODO: Add your command handler code here	
}

void CNetChessView::OnEditManualeditPlayerturn() 
{
	// TODO: Add your command handler code here
	if(m_manualEditingFlag == false)
	{
		AfxMessageBox("Editing disabled");
		return;
	}
	
	int ret = AfxMessageBox("Choose Player turn,White turn - Yes,Black turn - No",MB_YESNOCANCEL);
	if(ret == IDYES)
	{
		if(m_pClientSocket == NULL)
		{
			m_player_turn = true;
			m_pieceSide = WHITE;
		}
		else
		{
			unsigned char data[2];
			data[0]=MANUALEDITING_PLAYER_TURN;
			data[1] = false;
			m_player_turn = true;			
			SendSockData(data,2);		
		}
	}
	else if(ret == IDCANCEL)
	{
		return;
	}
	else
	{
		if(m_pClientSocket == NULL)
		{
			m_player_turn = true;
			m_pieceSide = BLACK;
		}
		else
		{
			unsigned char data[2];
			data[0]=MANUALEDITING_PLAYER_TURN;
			data[1] = true;
			m_player_turn = false;			
			SendSockData(data,2);		
		}
	}
}

void CNetChessView::OnEditManualeditStart() 
{
	// TODO: Add your command handler code here
	if(m_demoFlag == TRUE && m_pauseFlag == FALSE)
	{
		AfxMessageBox("Replay is in progress! Puase the demo to activate this feature");
		return;
	}
	if(m_manualEditingFlag == false)
	{
		if(AfxMessageBox("Requesting for Manual editing. Proceed?",MB_YESNO) == IDNO)
		{
			return;
		}
	}
	else
	{
		AfxMessageBox("Manual editing disabled");
	}
	if(m_pClientSocket == NULL)
	{
		m_manualEditingFlag = m_manualEditingFlag == TRUE ? FALSE: TRUE;
	}
	else
	{
		
		if(m_manualEditingFlag == FALSE)
		{
			unsigned char data[50];
			data[0]=MANUALEDITING_START;
			strcpy((char*)&data[1],m_edit_name.GetBuffer(0));
			SendSockData(data,m_edit_name.GetLength()+2);		
		}
		else
		{
			unsigned char data[2];;
			m_manualEditingFlag = FALSE;
			data[0]=MANUALEDITING_END;
			SendSockData(data,m_edit_name.GetLength()+2);		
		}
		//data[1] = m_checkmove;		
	}
}

void CNetChessView::OnUpdateEditManualeditStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		m_manualEditingFlag == TRUE ? pCmdUI->SetCheck(1) : pCmdUI->SetCheck(0);
		m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}


void CNetChessView::OnUpdateEditManualeditEmpty(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_manualEditingFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CNetChessView::OnUpdateEditManualeditPlayerturn(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_manualEditingFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CNetChessView::OnUpdateEditMovefirst(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_manualEditingFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CNetChessView::OnUpdateEditMovelast(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_manualEditingFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CNetChessView::OnUpdateEditRedo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_manualEditingFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CNetChessView::OnUpdateEditUndo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_manualEditingFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CNetChessView::OnUpdateViewDemo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_demoFlag == TRUE ? pCmdUI->SetCheck(1) : pCmdUI->SetCheck(0);
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}
void CNetChessView::doPGNRead(CString file,char type)
{
	m_fileReadFlag = TRUE;
//	OnInitialUpdate();
	unsigned char msg[2];
	msg[0] = PGNFILE;
	msg[1] = TRUE;
	SendSockData(msg,2);
	FILE *fp;
	if(type == 'f')
	{
		fp = fopen(file,"r");
		if(fp == NULL)
		{
			CString str;
			str.Format("Could not open the file %s",file);
			AfxMessageBox(str);
			return;
		}

		file = "";
		int count = 0;
		while(!feof(fp))
		{
			char c;
			fscanf(fp,"%c",&c);
			file += (CString)c;			
			count++;
			if(count > 15000)
				break;
		}
		fclose(fp);
	}
	filterPGNFile(file);	
	fp = fopen(".\\temp.pgn","w+");
	fprintf(fp,file.GetBuffer(0));		
	fclose(fp);
	fp=fopen(".\\temp.pgn","r");	
	char cstring1[255],cstring2[255],cstring3[255];
	fscanf(fp,"%s",cstring1);	
	while(strcmp(cstring1,"1.") != 0 && !feof(fp))
	{
		if(cstring1[0] == '[')
		{
			if(strcmp(&cstring1[1],"Event") == 0)
			{
				m_gameInfoDlg.m_edit_event = "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if((c != '"') && (c != ' '))
					{
						m_gameInfoDlg.m_edit_event += c;
					}
				}				
			}
			else if(strcmp(&cstring1[1],"Site") == 0)
			{
				m_gameInfoDlg.m_edit_site = "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if((c != '"') && (c != ' '))
					{
						m_gameInfoDlg.m_edit_site += c;
					}
				}				
			}
			else if(strcmp(&cstring1[1],"Date") == 0)
			{
				m_gameInfoDlg.m_edit_date = "";
				while(!feof(fp))
				{
					char c;					
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if((c != '"') && (c != ' '))
					{
						m_gameInfoDlg.m_edit_date += c;
					}
				}
			}
			else if(strcmp(&cstring1[1],"Round") == 0)
			{
				m_gameInfoDlg.m_edit_round = "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if((c != '"') && (c != ' '))
					{
						m_gameInfoDlg.m_edit_round += c;
					}
				}
			}
			else if(strcmp(&cstring1[1],"White") == 0)
			{
				m_gameInfoDlg.m_edit_white = "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if((c != '"') && (c != ' '))
					{
						m_gameInfoDlg.m_edit_white += c;
					}
				}
			}
			else if(strcmp(&cstring1[1],"Black") == 0)
			{
				m_gameInfoDlg.m_edit_black = "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if((c != '"') && (c != ' '))
					{
						m_gameInfoDlg.m_edit_black += c;
					}
				}
			}
			else if(strcmp(&cstring1[1],"Result") == 0)
			{
				m_gameInfoDlg.m_edit_result = "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if((c != '"') && (c != ' '))
					{
						m_gameInfoDlg.m_edit_result += c;
					}
				}
			}
			else if(strcmp(&cstring1[1],"FEN") == 0)
			{
				m_gameInfoDlg.m_edit_fenstring= "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if(c != '"')
					{
						m_gameInfoDlg.m_edit_fenstring += c;
					}
				}				
			}
			else if(strcmp(&cstring1[1],"ECO") == 0)
			{
				m_gameInfoDlg.m_edit_eco= "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if(c != '"')
					{
						m_gameInfoDlg.m_edit_eco += c;
					}
				}				
			}
			else if(strcmp(&cstring1[1],"PlyCount") == 0)
			{
				m_gameInfoDlg.m_edit_playcount= "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if(c != '"')
					{
						m_gameInfoDlg.m_edit_playcount += c;
					}
				}				
			}
			else if(strcmp(&cstring1[1],"BlackElo") == 0)
			{
				m_gameInfoDlg.m_edit_blackelo= "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if(c != '"')
					{
						m_gameInfoDlg.m_edit_blackelo += c;
					}
				}				
			}
			else if(strcmp(&cstring1[1],"WhiteElo") == 0)
			{
				m_gameInfoDlg.m_edit_whiteelo= "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if(c != '"')
					{
						m_gameInfoDlg.m_edit_whiteelo += c;
					}
				}				
			}
			else if(strcmp(&cstring1[1],"EventDate") == 0)
			{
				m_gameInfoDlg.m_event_date= "";
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
					{
						break;
					}
					else if(c != '"')
					{
						m_gameInfoDlg.m_event_date += c;
					}
				}				
			}

		}
		memset(cstring1,'\0',255);
		memset(cstring2,'\0',255);
		memset(cstring3,'\0',255);
		fscanf(fp,"%s",cstring1);
	}
	//Send Tag info
	unsigned char data[500];
	memset(data,'\0',500);
	int count = 0;
	data[count++] = GAMEINFO;
	data[count++] = m_gameInfoDlg.m_edit_event.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_event.GetBuffer(0),m_gameInfoDlg.m_edit_event.GetLength());
	count += m_gameInfoDlg.m_edit_event.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_site.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_site.GetBuffer(0),m_gameInfoDlg.m_edit_site.GetLength());
	count += m_gameInfoDlg.m_edit_site.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_date.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_date.GetBuffer(0),m_gameInfoDlg.m_edit_date.GetLength());
	count += m_gameInfoDlg.m_edit_date.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_round.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_round.GetBuffer(0),m_gameInfoDlg.m_edit_round.GetLength());
	count += m_gameInfoDlg.m_edit_round.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_white.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_white.GetBuffer(0),m_gameInfoDlg.m_edit_white.GetLength());
	count += m_gameInfoDlg.m_edit_white.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_black.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_black.GetBuffer(0),m_gameInfoDlg.m_edit_black.GetLength());
	count += m_gameInfoDlg.m_edit_white.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_result.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_result.GetBuffer(0),m_gameInfoDlg.m_edit_result.GetLength());
	count += m_gameInfoDlg.m_edit_result.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_fenstring.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_fenstring.GetBuffer(0),m_gameInfoDlg.m_edit_fenstring.GetLength());
	count += m_gameInfoDlg.m_edit_fenstring.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_eco.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_eco.GetBuffer(0),m_gameInfoDlg.m_edit_eco.GetLength());
	count += m_gameInfoDlg.m_edit_eco.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_playcount.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_playcount.GetBuffer(0),m_gameInfoDlg.m_edit_playcount.GetLength());
	count += m_gameInfoDlg.m_edit_playcount.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_blackelo.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_blackelo.GetBuffer(0),m_gameInfoDlg.m_edit_blackelo.GetLength());
	count += m_gameInfoDlg.m_edit_blackelo.GetLength();

	data[count++] = m_gameInfoDlg.m_edit_whiteelo.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_edit_whiteelo.GetBuffer(0),m_gameInfoDlg.m_edit_whiteelo.GetLength());
	count += m_gameInfoDlg.m_edit_whiteelo.GetLength();

	data[count++] = m_gameInfoDlg.m_event_date.GetLength();
	memcpy(&data[count],m_gameInfoDlg.m_event_date.GetBuffer(0),m_gameInfoDlg.m_event_date.GetLength());
	count += m_gameInfoDlg.m_event_date.GetLength();


	SendSockData(data,count);
	if(!m_gameInfoDlg.m_edit_fenstring.IsEmpty())
	{
		doFENPositionRead(m_gameInfoDlg.m_edit_fenstring,'F');
		unsigned char data[1024];
		memset(data,'\0',1024);
		data[0] = POSITION_DATA;
		int count = 1;
		for(int i=0;i<m_gameInfoDlg.m_edit_fenstring.GetLength();i++)
		{
			data[count++] = m_gameInfoDlg.m_edit_fenstring[i];
		}
		SendSockData(data,count);
	}

	if(feof(fp))
	{
		fclose(fp);
	//	if(type != 'f')
		DeleteFile(".\\temp.pgn");
		return;
	}
	fscanf(fp,"%s%s",cstring2,cstring3);
	if(strcmp(cstring1,"1.") == 0)
	{
		do
		{

			/*(strcmp(cstring1,"1.")== 0)
			{
				writeMessage("*************************");
				writeMessage("%s",GetHistoryString());
				writeMessage("*************************");
				Initialize();
				OnInitialUpdate();
				unsigned char msg[1];
				msg[0] = PGNFILE;
				SendSockData(msg,1);				
			}*/
			int ret = PGNMove(cstring2,WHITE);
			if(ret == 1)
			{
				break;			
			}
			if( strcmp(cstring3,"1-0") == 0 ||
				strcmp(cstring3,"0-1") == 0 ||
				strcmp(cstring3,"1/2-1/2") == 0 ||
				strcmp(cstring3,"*") == 0)
			{
				break;
			}
			Sleep(m_optDlg.m_edit_replay_interval*1000);
			ret = PGNMove(cstring3,BLACK);			
			if(ret == 1)
			{
				break;
			}			
			memset(cstring1,'\0',255);
			memset(cstring2,'\0',255);
			memset(cstring3,'\0',255);			
			fscanf(fp,"%s%s%s",cstring1,cstring2,cstring3);
			if(cstring1[0] == '[' || cstring2[0] == '[' || cstring3[0] == '[' ||
				cstring1[0] == '*' || cstring2[0] == '*' ||
				strcmp(cstring1,"1-0") == 0 ||
				strcmp(cstring1,"0-1") == 0 ||
				strcmp(cstring1,"1/2-1/2") == 0 ||
				strcmp(cstring2,"1-0") == 0 ||
				strcmp(cstring2,"0-1") == 0 ||
				strcmp(cstring2,"1/2-1/2") == 0)				
				break;
			Sleep(m_optDlg.m_edit_replay_interval*1000);

		}while(!feof(fp));
		//Check for last move
		int ret = PGNMove(cstring2,WHITE);
		 ret = PGNMove(cstring3,BLACK);
	}
	fclose(fp);
	//if(type != 'f')
	DeleteFile(".\\temp.pgn");
	m_fileReadFlag = FALSE;
	DrawBoard();
	
}
void CNetChessView::filterPGNFile(CString& filedata)
{
	CString tempstr; 
	for(int i=0; i<filedata.GetLength();i++)
	{
		if(filedata[i] == ';' || filedata[i] == '%')
		{
			i++;
			for(;i<filedata.GetLength() && filedata[i] != '\n';i++);
		}
		else if(filedata[i] == '{')
		{
			//get comment number
			//comment number
		/*	int lastindex;
			for(int k=tempstr.GetLength()-1; tempstr[k] != '.' &&k>=0;k--);
			lastindex = k;
			for(;tempstr[k] != ' ' && k>=0;k--);*/
			CString comment;
			i++;
			int count = 1;
			for(;i <filedata.GetLength();i++)
			{
				if(filedata[i] == '}')
				{
					count--;
					if(count == 0)
						break;
				}
				else if(filedata[i] == '{')
				{
					count++;
				}
				comment+= filedata[i];
			}
			//i++;
			//for(;i<filedata.GetLength() && filedata[i] != '}' ;i++);
		}
		else if(filedata[i] == '<')
		{
			i++;
			for(;i<filedata.GetLength() && filedata[i] != '>';i++);
		}
		else if(filedata[i] == '(')
		{
			CString comment;
			i++;
			int count = 1;
			for(;i <filedata.GetLength();i++)
			{
				if(filedata[i] == ')')
				{
					count--;
					if(count == 0)
					break;
				}
				else if(filedata[i] == '(')
				{
					count++;
				}
				comment += filedata[i];
			}
		}
		else if(filedata[i] == '!' || filedata[i] == '?')
		{   
		//nothing
		}
		else if(filedata[i] == '$')
		{
			i++;
			for(;filedata[i] != ' ' && filedata[i] != '\n';i++);
		}
		else if(filedata[i] == '[')
		{
			for(;i<filedata.GetLength() && filedata[i] != ']' ;i++)
			tempstr += filedata[i];
			if(i+1 < filedata.GetLength())
				tempstr += filedata[i++];
			tempstr += "\n";
		}
		else if(filedata[i] == '.' && (i+1 < filedata.GetLength() ? filedata[i+1] == '.' : 0) && (i+2 < filedata.GetLength() ? filedata[i+2] == '.' : 0))
		{
			int count = 0;
			i--;
			for(;i> -1 && filedata[i] != ' ' && filedata[i] != '\n';i--)
			{
				count++;    
				tempstr = tempstr.Left(tempstr.GetLength()-1);

			}
			i = i + count + 3;
		}
		else if(filedata[i] == '.' && (i+1 < filedata.GetLength() ? filedata[i+1] != ' ' : 0))
		{
			tempstr += filedata[i];
			tempstr += ' ';
		}
		else
		{
			tempstr += filedata[i];
		}
	}
	filedata = tempstr;
}
int CNetChessView::PGNMove(char cstring[255], int pieceside)
{
	m_checkFlag = m_castlingFlag = m_enpassentFlag = m_promotionFlag =
	m_ambiguousMoveRankFlag = m_ambiguousMoveFileFlag = FALSE;

	int len = strlen(cstring);
	if(m_white_on_top == true)//white is on top
	{
		switch(len)
		{
			case 2://pawn move
				{
					int to_i,to_j;
					to_j = 7-(int)(cstring[0] - 'a');
					to_i = 7-((int)('9' - cstring[1])-1);
					if(pieceside == WHITE)
					{
						if(cb[to_i-1][to_j].GetPieceId() != -1)
						{
							m_point.x = to_i-1;
							m_point.y = to_j;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
						else if(cb[to_i-2][to_j].GetPieceId() != -1)
						{
							m_point.x = to_i-2;
							m_point.y = to_j;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
					}
					else
					{
						if(cb[to_i+1][to_j].GetPieceId() != -1)
						{
							m_point.x = to_i+1;
							m_point.y = to_j;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
						else if(cb[to_i+2][to_j].GetPieceId() != -1)
						{
							m_point.x = to_i+2;
							m_point.y = to_j;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
					}
				}	
				break;
			case 3://piece move
				{
					if(strcmp(cstring,"O-O")==0)
					{
						if(pieceside == WHITE)
						{
							m_point.x = 0;
							m_point.y = 3;
							int to_i = 0;
							int to_j = 1;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
						else
						{
							m_point.x = 7;
							m_point.y = 3;
							int to_i = 7;
							int to_j = 1;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
					}
					else if((cstring[2] == '+') || (cstring[2] == '#'))
					{
						cstring[2] = '\0';
						PGNMove(cstring, pieceside);
					}
					 else if((cstring[2] > 'A') && cstring[2] <='Z')
					 {
						  //junk move nove valid
						  m_pickPieceDlg->m_pickpiecetype  = 1;
						  char str[255];
						  str[0]=cstring[2];    
						  m_pickPieceDlg->m_piecked_piece=GetPieceType(str,pieceside,(int&)m_pickPieceDlg->m_piece_type);
						  m_pickPieceDlg->m_piece_color=(COLOR_TYPE)pieceside;
						  cstring[2] = '\0';
						  PGNMove(cstring, pieceside);     
					 }
					else
					{
						int from_i,from_j,to_i,to_j;				
						to_j = 7-(int)(cstring[1] - 'a');
						to_i = 7-((int)('9' - cstring[2])-1);
						if(GetPieceIndex(cstring,pieceside,to_i,to_j,from_i,from_j) == true)
						{
							m_point.x = from_i;
							m_point.y = from_j;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
					}

				}			
				break;
			case 4://move with capture		
			case 5:		
				if((cstring[3] == '+') || (cstring[3] == '#'))
				{
					cstring[3] = '\0';
					PGNMove(cstring, pieceside);					
				}
				else if((cstring[4] == '+') || (cstring[4] == '#'))
				{
					cstring[4] = '\0';
					PGNMove(cstring, pieceside);
				}
				else if(cstring[2] == '=')
				{
					m_pickPieceDlg->m_pickpiecetype  = 1;
					char str[255];
					str[0]=cstring[3];				
					m_pickPieceDlg->m_piecked_piece=GetPieceType(str,pieceside,(int&)m_pickPieceDlg->m_piece_type);
					m_pickPieceDlg->m_piece_color=(COLOR_TYPE)pieceside;
					cstring[2] = '\0';
					PGNMove(cstring, pieceside);					
				}
				else if(strcmp(cstring,"O-O-O") == 0)
				{
					if(pieceside == WHITE)
					{
						m_point.x = 0;
						m_point.y = 3;
						int to_i = 0;
						int to_j = 5;
						m_mouseMoveFlag = true;
						CRect rect=cb[to_i][to_j].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						OnLButtonUpAction(0,pt);
					}
					else
					{
						m_point.x = 7;
						m_point.y = 3;
						int to_i = 7;
						int to_j = 5;
						m_mouseMoveFlag = true;
						CRect rect=cb[to_i][to_j].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						OnLButtonUpAction(0,pt);
					}
				}
				else if(cstring[2] =='x')
				{
					int from_i,from_j,to_i,to_j;				
					to_j= 7-(int)(cstring[3] - 'a');
					to_i= 7-((int)('9' - cstring[4])-1);
					if(GetPieceIndex(cstring,pieceside,to_i,to_j,from_i,from_j) == true)
					{
						m_point.x = from_i;
						m_point.y = from_j;
						m_mouseMoveFlag = true;
						CRect rect=cb[to_i][to_j].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						OnLButtonUpAction(0,pt);
					}
				}
				else if(cstring[3] =='x')
				{
					int to_i,to_j;				
					to_j= 7-(int)(cstring[4] - 'a');
					to_i= 7-((int)('9' - cstring[5])-1);
					m_point.x = (int)(cstring[1] - 'a');
					m_point.y = (int)('9' - cstring[2])-1;
					m_mouseMoveFlag = true;
					CRect rect=cb[to_i][to_j].GetRect();
					CPoint pt(rect.left+10,rect.top+10);
					OnLButtonUpAction(0,pt);				
				}
				else if(cstring[5] == 'q' || cstring[5] == 'Q')
				{				
					m_pickPieceDlg->m_pickpiecetype  = 1;
					char str[255];
					str[0]=cstring[4];				
					m_pickPieceDlg->m_piecked_piece=GetPieceType(str,pieceside,(int&)m_pickPieceDlg->m_piece_type);
					m_pickPieceDlg->m_piece_color=(COLOR_TYPE)pieceside;
					cstring[5] = '\0';
					PGNMove(cstring, pieceside);
				}
				else if(cstring[0] >='a' && cstring[0]<='h' &&
						cstring[2] >='a' && cstring[2]<='h' &&
						cstring[1] >='1' && cstring[1]<='8' &&
						cstring[3] >='1' && cstring[2]<='8')
				{
					int to_i,to_j;				
					to_j= 7-(int)(cstring[2] - 'a');
					to_i= 7-((int)('9' - cstring[3])-1);
					m_point.y= 7-(int)(cstring[0] - 'a');
					m_point.x= 7-((int)('9' - cstring[1])-1);
					m_mouseMoveFlag = true;
					CRect rect=cb[to_i][to_j].GetRect();
					CPoint pt(rect.left+10,rect.top+10);
					OnLButtonUpAction(0,pt);
					/*if(GetPieceIndex(cstring,pieceside,to_i,to_j,from_i,from_j) == true)
					{
						m_point.x = from_i;
						m_point.y = from_j;
						m_mouseMoveFlag = true;
						CRect rect=cb[to_i][to_j].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						OnLButtonUpAction(0,pt);
					}*/
				}
				else
				{
					int from_i,from_j,to_i,to_j;				
					to_j= 7-(int)(cstring[2] - 'a');
					to_i= 7-((int)('9' - cstring[3])-1);
					if(GetPieceIndex(cstring,pieceside,to_i,to_j,from_i,from_j) == true)
					{
						m_point.x = from_i;
						m_point.y = from_j;
						m_mouseMoveFlag = true;
						CRect rect=cb[to_i][to_j].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						OnLButtonUpAction(0,pt);
					}
				}
			break;
			case 6:
				if((cstring[5] == '+') || (cstring[5] == '#'))
				{
					cstring[5] = '\0';
					PGNMove(cstring, pieceside);
				}
				else if(cstring[4] == '=')
				{
					m_pickPieceDlg->m_pickpiecetype  = 1;
					char str[255];
					str[0]=cstring[5];				
					m_pickPieceDlg->m_piecked_piece=GetPieceType(str,pieceside,(int&)m_pickPieceDlg->m_piece_type);
					m_pickPieceDlg->m_piece_color=(COLOR_TYPE)pieceside;
					cstring[4] = '\0';
					PGNMove(cstring, pieceside);
				}
				break;
			case 7:
				if((cstring[6] == '+') || (cstring[6] == '#'))
				{
					cstring[6] = '\0';
					PGNMove(cstring, pieceside);
				}			
				break;
			default:
				//cstring[7] = '\0';
				//PGNMove(cstring, pieceside);
				break;
		}
	}
	else
	{
		switch(len)
		{
			case 2://pawn move
				{
					int to_i,to_j;
					to_j = (int)(cstring[0] - 'a');
					to_i = (int)('9' - cstring[1])-1;
					if(pieceside == WHITE)
					{
						if(cb[to_i+1][to_j].GetPieceId() != -1)
						{
							m_point.x = to_i+1;
							m_point.y = to_j;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
						else if(cb[to_i+2][to_j].GetPieceId() != -1)
						{
							m_point.x = to_i+2;
							m_point.y = to_j;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
					}
					else
					{
						if(cb[to_i-1][to_j].GetPieceId() != -1)
						{
							m_point.x = to_i-1;
							m_point.y = to_j;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
						else if(cb[to_i-2][to_j].GetPieceId() != -1)
						{
							m_point.x = to_i-2;
							m_point.y = to_j;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
					}
				}	
				break;
			case 3://piece move
				{
					if(strcmp(cstring,"O-O")==0)
					{
						if(pieceside == WHITE)
						{
							m_point.x = 7;
							m_point.y = 4;
							int to_i = 7;
							int to_j = 6;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
						else
						{
							m_point.x = 0;
							m_point.y = 4;
							int to_i = 0;
							int to_j = 6;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
					}
					else if((cstring[2] == '+') || (cstring[2] == '#'))
					{
						cstring[2] = '\0';
						PGNMove(cstring, pieceside);
					}
					 else if((cstring[2] > 'A') && cstring[2] <='Z')
					 {
						  //junk move nove valid
						  m_pickPieceDlg->m_pickpiecetype  = 1;
						  char str[255];
						  str[0]=cstring[2];    
						  m_pickPieceDlg->m_piecked_piece=GetPieceType(str,pieceside,(int&)m_pickPieceDlg->m_piece_type);
						  m_pickPieceDlg->m_piece_color=(COLOR_TYPE)pieceside;
						  cstring[2] = '\0';
						  PGNMove(cstring, pieceside);     
					 }
					else 
					{
						int from_i,from_j,to_i,to_j;				
						to_j = (int)(cstring[1] - 'a');
						to_i = (int)('9' - cstring[2])-1;
						if(GetPieceIndex(cstring,pieceside,to_i,to_j,from_i,from_j) == true)
						{
							m_point.x = from_i;
							m_point.y = from_j;
							m_mouseMoveFlag = true;
							CRect rect=cb[to_i][to_j].GetRect();
							CPoint pt(rect.left+10,rect.top+10);
							OnLButtonUpAction(0,pt);
						}
					}

				}			
				break;
			case 4://move with capture		
			case 5:		
				if((cstring[3] == '+') || (cstring[3] == '#'))
				{
					cstring[3] = '\0';
					PGNMove(cstring, pieceside);				
				}
				else if((cstring[4] == '+') || (cstring[4] == '#'))
				{
					cstring[4] = '\0';
					PGNMove(cstring, pieceside);
				}
				else if(cstring[2] == '=')
				{
					m_pickPieceDlg->m_pickpiecetype  = 1;
					char str[255];
					str[0]=cstring[3];				
					m_pickPieceDlg->m_piecked_piece=GetPieceType(str,pieceside,(int&)m_pickPieceDlg->m_piece_type);
					m_pickPieceDlg->m_piece_color=(COLOR_TYPE)pieceside;
					cstring[2] = '\0';
					PGNMove(cstring, pieceside);					
				}
				else if(strcmp(cstring,"O-O-O") == 0)
				{
					if(pieceside == WHITE)
					{
						m_point.x = 7;
						m_point.y = 4;
						int to_i = 7;
						int to_j = 2;
						m_mouseMoveFlag = true;
						CRect rect=cb[to_i][to_j].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						OnLButtonUpAction(0,pt);
					}
					else
					{
						m_point.x = 0;
						m_point.y = 4;
						int to_i = 0;
						int to_j = 2;
						m_mouseMoveFlag = true;
						CRect rect=cb[to_i][to_j].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						OnLButtonUpAction(0,pt);
					}
				}
				else if(cstring[2] =='x')
				{
					int from_i,from_j,to_i,to_j;				
					to_j= (int)(cstring[3] - 'a');
					to_i= (int)('9' - cstring[4])-1;
					if(GetPieceIndex(cstring,pieceside,to_i,to_j,from_i,from_j) == true)
					{
						m_point.x = from_i;
						m_point.y = from_j;
						m_mouseMoveFlag = true;
						CRect rect=cb[to_i][to_j].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						OnLButtonUpAction(0,pt);
					}
				}
				else if(cstring[3] =='x')
				{
					int to_i,to_j;				
					to_j= (int)(cstring[4] - 'a');
					to_i= (int)('9' - cstring[5])-1;
					m_point.x = (int)(cstring[1] - 'a');
					m_point.y = (int)('9' - cstring[2])-1;
					m_mouseMoveFlag = true;
					CRect rect=cb[to_i][to_j].GetRect();
					CPoint pt(rect.left+10,rect.top+10);
					OnLButtonUpAction(0,pt);				
				}
				else if(cstring[5] == 'q' || cstring[5] == 'Q')
				{				
					m_pickPieceDlg->m_pickpiecetype  = 1;
					char str[255];
					str[0]=cstring[4];				
					m_pickPieceDlg->m_piecked_piece=GetPieceType(str,pieceside,(int&)m_pickPieceDlg->m_piece_type);
					m_pickPieceDlg->m_piece_color=(COLOR_TYPE)pieceside;
					cstring[5] = '\0';
					PGNMove(cstring, pieceside);
				}
				else if(cstring[0] >='a' && cstring[0]<='h' &&
						cstring[2] >='a' && cstring[2]<='h' &&
						cstring[1] >='1' && cstring[1]<='8' &&
						cstring[3] >='1' && cstring[2]<='8')
				{
					int to_i,to_j;				
					to_j= (int)(cstring[2] - 'a');
					to_i= (int)('9' - cstring[3])-1;
					m_point.y= (int)(cstring[0] - 'a');
					m_point.x= (int)('9' - cstring[1])-1;
					m_mouseMoveFlag = true;
					CRect rect=cb[to_i][to_j].GetRect();
					CPoint pt(rect.left+10,rect.top+10);
					OnLButtonUpAction(0,pt);
					/*if(GetPieceIndex(cstring,pieceside,to_i,to_j,from_i,from_j) == true)
					{
						m_point.x = from_i;
						m_point.y = from_j;
						m_mouseMoveFlag = true;
						CRect rect=cb[to_i][to_j].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						OnLButtonUpAction(0,pt);
					}*/
				}
				else
				{
					int from_i,from_j,to_i,to_j;				
					to_j= (int)(cstring[2] - 'a');
					to_i= (int)('9' - cstring[3])-1;				
					
					if(GetPieceIndex(cstring,pieceside,to_i,to_j,from_i,from_j) == true)
					{
						m_point.x = from_i;
						m_point.y = from_j;
						m_mouseMoveFlag = true;
						CRect rect=cb[to_i][to_j].GetRect();
						CPoint pt(rect.left+10,rect.top+10);
						OnLButtonUpAction(0,pt);
					}
				}
			break;
			case 6:
				if((cstring[5] == '+') || (cstring[5] == '#'))
				{
					cstring[5] = '\0';
					PGNMove(cstring, pieceside);
				}
				else if(cstring[4] == '=')
				{
					m_pickPieceDlg->m_pickpiecetype  = 1;
					char str[255];
					str[0]=cstring[5];				
					m_pickPieceDlg->m_piecked_piece=GetPieceType(str,pieceside,(int&)m_pickPieceDlg->m_piece_type);
					m_pickPieceDlg->m_piece_color=(COLOR_TYPE)pieceside;
					cstring[4] = '\0';
					PGNMove(cstring, pieceside);
				}
				break;
			case 7:
				if((cstring[6] == '+') || (cstring[6] == '#'))
				{
					cstring[6] = '\0';
					PGNMove(cstring, pieceside);
				}			
				break;
			default:
				//cstring[7] = '\0';
				//PGNMove(cstring, pieceside);
				break;
		}
	}
	return 0;
}
bool CNetChessView::GetPieceIndex(char cstring[255],int pieceside,int to_i,int to_j,int &from_i,int &from_j) 
{

	int piece_id;
	COLOR_TYPE  piece_color;
	PIECE_TYPE  piece_type;
	STATE piece_state;	
	PIECE_SIDE piece_side;
	COLOR_TYPE  from_color_type;
	PIECE_TYPE  from_piece_type;
	int from_pieceid;
	int to_pieceid;
	COLOR_TYPE  to_colortype;
	PIECE_TYPE  to_piecetype;
	STATE to_piecestate = PIECE_NOT_MOVING;
	int from_row_id, to_row_id;
	int from_col_id, to_col_id;
	int flipflag = FALSE;
	if(m_white_on_top == true)
	{
		m_white_on_top = false;
		to_i = 7 - to_i;
		to_j = 7 - to_j;
		FlipBoard();
		flipflag = TRUE;						
	}
	if(m_white_on_top == false)
	{
		if(strlen(cstring)>3)
		{	
			if(cstring[0] >='a' && cstring[0] <='z' && cstring[1] == 'x')
			{
				for(int i=0;i<8;i++)
				{
					int j=(int)(cstring[0]-'a');
					m_point.x = i;
					m_point.y = j;
					int piecetype;
					bool tempblackKingMoveFlag = m_blackKingMovedFlag;
					bool tempwhiteKingMoveFlag = m_whiteKingMovedFlag;
					if(cb[i][j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype) && (CheckValidMove(to_i,to_j) == true))
					{
						from_i = i;
						from_j = j;
						cb[to_i][to_j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
						cb[to_i][to_j].SetPieceData(cb[from_i][from_j].GetPieceId(),cb[from_i][from_j].GetPieceColor(),cb[from_i][from_j].GetPieceType(),cb[from_i][from_j].GetPieceState());
						cb[from_i][from_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						if(m_enpassentFlag == TRUE)
						{							
							m_History[m_iHistory].GetHistory(
										piece_side,
										from_piece_type, from_color_type,from_pieceid,
										from_row_id,from_col_id, to_piecetype,
										to_colortype,to_pieceid,to_row_id,
										to_col_id);
							cb[to_row_id][to_col_id].GetPieceData(piece_id,piece_color,piece_type,piece_state);
							cb[to_row_id][to_col_id].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						}
						if(CheckKingMove(to_i,to_j,to_i,to_j) == false)
						{
							if(m_enpassentFlag == TRUE)
							{	
								cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
								cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
								cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);
							}
							else
							{
								cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
								cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
							}
							m_blackKingMovedFlag = tempblackKingMoveFlag;
							m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
							continue;
						}
						if(m_enpassentFlag == TRUE)
						{	
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
						}
						else
						{
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
						}
						m_blackKingMovedFlag = tempblackKingMoveFlag;
						m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
						if(flipflag == TRUE)
						{
							m_white_on_top = true;
							to_i = 7 - to_i;
							to_j = 7 - to_j;
							from_i = 7-from_i;
							from_j = 7-from_j;
							FlipBoard();
							flipflag = FALSE;						
						}						
						return true;
					}
				}
			}
			else if(cstring[1] >='a' && cstring[1] <='z' && cstring[1] != 'x' &&cstring[3] != '+')
			{
				for(int i=0;i<8;i++)
				{
					int j = cstring[1]-'a';
					m_point.x = i;
					m_point.y = j;
					int piecetype;
					bool tempblackKingMoveFlag = m_blackKingMovedFlag;
					bool tempwhiteKingMoveFlag = m_whiteKingMovedFlag;
					
					if(cb[i][j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype)&& (CheckValidMove(to_i,to_j) == true))
					{
						from_i = i;
						from_j = j;
						cb[to_i][to_j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
						cb[to_i][to_j].SetPieceData(cb[from_i][from_j].GetPieceId(),cb[from_i][from_j].GetPieceColor(),cb[from_i][from_j].GetPieceType(),cb[from_i][from_j].GetPieceState());
						cb[from_i][from_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						if(m_enpassentFlag == TRUE)
						{							
							m_History[m_iHistory].GetHistory(
										piece_side,
										from_piece_type, from_color_type,from_pieceid,
										from_row_id,from_col_id, to_piecetype,
										to_colortype,to_pieceid,to_row_id,
										to_col_id);
							cb[to_row_id][to_col_id].GetPieceData(piece_id,piece_color,piece_type,piece_state);
							cb[to_row_id][to_col_id].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						}
						if(CheckKingMove(to_i,to_j,to_i,to_j) == false)
						{
							if(m_enpassentFlag == TRUE)
							{	
								cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
								cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
								cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
							}
							else
							{
								cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
								cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
							}
							
							m_blackKingMovedFlag = tempblackKingMoveFlag;
							m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
							continue;
						}
						if(m_enpassentFlag == TRUE)
						{	
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
						}
						else
						{
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
						}
						
						m_blackKingMovedFlag = tempblackKingMoveFlag;
						m_whiteKingMovedFlag = tempwhiteKingMoveFlag;

						if(flipflag == TRUE)
						{
							m_white_on_top = true;
							to_i = 7 - to_i;
							to_j = 7 - to_j;
							from_i = 7-from_i;
							from_j = 7-from_j;
							FlipBoard();
							flipflag = FALSE;						
						}
						return true;
					}			
				}
			}
			else if(cstring[1] >='1' && cstring[1] <='8' &&
				cstring[0] >='a' && cstring[1] <='h')
			{
				int i = (int)('9'- cstring[1]) -1;
				int j = cstring[0]-'a';
 				m_point.x = i;
				m_point.y = j;
				int piecetype;
				bool tempblackKingMoveFlag = m_blackKingMovedFlag;
				bool tempwhiteKingMoveFlag = m_whiteKingMovedFlag;
				if(cb[i][j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype)&& (CheckValidMove(to_i,to_j) == true))
				{
					from_i = i;
					from_j = j;
					cb[to_i][to_j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
					cb[to_i][to_j].SetPieceData(cb[from_i][from_j].GetPieceId(),cb[from_i][from_j].GetPieceColor(),cb[from_i][from_j].GetPieceType(),cb[from_i][from_j].GetPieceState());
					cb[from_i][from_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					if(m_enpassentFlag == TRUE)
					{							
						m_History[m_iHistory].GetHistory(
									piece_side,
									from_piece_type, from_color_type,from_pieceid,
									from_row_id,from_col_id, to_piecetype,
									to_colortype,to_pieceid,to_row_id,
									to_col_id);
						cb[to_row_id][to_col_id].GetPieceData(piece_id,piece_color,piece_type,piece_state);
						cb[to_row_id][to_col_id].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
					}
					if(CheckKingMove(to_i,to_j,to_i,to_j) == false)
					{
						if(m_enpassentFlag == TRUE)
						{	
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
						}
						else
						{
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
						}
						m_blackKingMovedFlag = tempblackKingMoveFlag;
						m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
						return false;
					}
					if(m_enpassentFlag == TRUE)
					{	
						cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
						cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
					}
					else
					{
						cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
						cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
					}
					
					m_blackKingMovedFlag = tempblackKingMoveFlag;
					m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
					if(flipflag == TRUE)
					{
						m_white_on_top = true;
						to_i = 7 - to_i;
						to_j = 7 - to_j;
						from_i = 7-from_i;
						from_j = 7-from_j;
						FlipBoard();
						flipflag = FALSE;						
					}
					return true;
				}		
			}
			else if(cstring[1] >='1' && cstring[1] <='8')
			{
				for(int j=0;j<8;j++)
				{
					int i = (int)('9'- cstring[1]) -1;
 					m_point.x = i;
					m_point.y = j;
					int piecetype;
					bool tempblackKingMoveFlag = m_blackKingMovedFlag;
					bool tempwhiteKingMoveFlag = m_whiteKingMovedFlag;
					if(cb[i][j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype)&& (CheckValidMove(to_i,to_j) == true))
					{
						from_i = i;
						from_j = j;
						cb[to_i][to_j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
						cb[to_i][to_j].SetPieceData(cb[from_i][from_j].GetPieceId(),cb[from_i][from_j].GetPieceColor(),cb[from_i][from_j].GetPieceType(),cb[from_i][from_j].GetPieceState());
						cb[from_i][from_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						if(m_enpassentFlag == TRUE)
						{							
							m_History[m_iHistory].GetHistory(
										piece_side,
										from_piece_type, from_color_type,from_pieceid,
										from_row_id,from_col_id, to_piecetype,
										to_colortype,to_pieceid,to_row_id,
										to_col_id);
							cb[to_row_id][to_col_id].GetPieceData(piece_id,piece_color,piece_type,piece_state);
							cb[to_row_id][to_col_id].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						}
						if(CheckKingMove(to_i,to_j,to_i,to_j) == false)
						{
							if(m_enpassentFlag == TRUE)
							{	
								cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
								cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
								cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
							}
							else
							{
								cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
								cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
							}
							m_blackKingMovedFlag = tempblackKingMoveFlag;
							m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
							continue;
						}
						if(m_enpassentFlag == TRUE)
						{	
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
						}
						else
						{
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
						}
						
						m_blackKingMovedFlag = tempblackKingMoveFlag;
						m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
						if(flipflag == TRUE)
						{
							m_white_on_top = true;
							to_i = 7 - to_i;
							to_j = 7 - to_j;
							from_i = 7-from_i;
							from_j = 7-from_j;
							FlipBoard();
							flipflag = FALSE;						
						}
						return true;
					}		
				}
			}
			else
				for(int i=0;i<8;i++)
				{
					for(int j=0;j<8;j++)
					{
						m_point.x = i;
						m_point.y = j;
						int piecetype;
						bool tempblackKingMoveFlag = m_blackKingMovedFlag;
						bool tempwhiteKingMoveFlag = m_whiteKingMovedFlag;
						if(cb[i][j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype)&& (CheckValidMove(to_i,to_j) == true))
						{
							from_i = i;
							from_j = j;
							cb[to_i][to_j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
							cb[to_i][to_j].SetPieceData(cb[from_i][from_j].GetPieceId(),cb[from_i][from_j].GetPieceColor(),cb[from_i][from_j].GetPieceType(),cb[from_i][from_j].GetPieceState());
							cb[from_i][from_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							if(m_enpassentFlag == TRUE)
						{							
							m_History[m_iHistory].GetHistory(
										piece_side,
										from_piece_type, from_color_type,from_pieceid,
										from_row_id,from_col_id, to_piecetype,
										to_colortype,to_pieceid,to_row_id,
										to_col_id);
							cb[to_row_id][to_col_id].GetPieceData(piece_id,piece_color,piece_type,piece_state);
							cb[to_row_id][to_col_id].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						}
						if(CheckKingMove(to_i,to_j,to_i,to_j) == false)
						{
							if(m_enpassentFlag == TRUE)
							{	
								cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
								cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
								cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
							}
							else
							{
								cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
								cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
							}
							m_blackKingMovedFlag = tempblackKingMoveFlag;
							m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
							continue;
						}
						if(m_enpassentFlag == TRUE)
						{	
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
						}
						else
						{
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
						}
						
						m_blackKingMovedFlag = tempblackKingMoveFlag;
						m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
							if(flipflag == TRUE)
							{
								m_white_on_top = true;
								to_i = 7 - to_i;
								to_j = 7 - to_j;
								from_i = 7-from_i;
								from_j = 7-from_j;
								FlipBoard();
								flipflag = FALSE;						
							}
							return true;
						}
					}
				}
		}
		else
		{
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					m_point.x = i;
					m_point.y = j;
					int piecetype;
					bool tempblackKingMoveFlag = m_blackKingMovedFlag;
					bool tempwhiteKingMoveFlag = m_whiteKingMovedFlag;
		
					if(cb[i][j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype)&& (CheckValidMove(to_i,to_j) == true))
					{

						from_i = i;
						from_j = j;
						cb[to_i][to_j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
						cb[to_i][to_j].SetPieceData(cb[from_i][from_j].GetPieceId(),cb[from_i][from_j].GetPieceColor(),cb[from_i][from_j].GetPieceType(),cb[from_i][from_j].GetPieceState());
						cb[from_i][from_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						if(m_enpassentFlag == TRUE)
						{							
							m_History[m_iHistory].GetHistory(
										piece_side,
										from_piece_type, from_color_type,from_pieceid,
										from_row_id,from_col_id, to_piecetype,
										to_colortype,to_pieceid,to_row_id,
										to_col_id);
							cb[to_row_id][to_col_id].GetPieceData(piece_id,piece_color,piece_type,piece_state);
							cb[to_row_id][to_col_id].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						}
						if(CheckKingMove(to_i,to_j,to_i,to_j) == false)
						{
							if(m_enpassentFlag == TRUE)
							{	
								cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
								cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
								cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
							}
							else
							{
								cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
								cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
							}
							m_blackKingMovedFlag = tempblackKingMoveFlag;
							m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
							continue;
						}
						if(m_enpassentFlag == TRUE)
						{	
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							cb[to_row_id][to_col_id].SetPieceData(to_pieceid,to_colortype,to_piecetype,to_piecestate);								
						}
						else
						{
							cb[from_i][from_j].SetPieceData(cb[to_i][to_j].GetPieceId(),cb[to_i][to_j].GetPieceColor(),cb[to_i][to_j].GetPieceType(),cb[to_i][to_j].GetPieceState());
							cb[to_i][to_j].SetPieceData(piece_id,piece_color,piece_type,piece_state);
						}
						
						m_blackKingMovedFlag = tempblackKingMoveFlag;
						m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
						if(flipflag == TRUE)
						{
							m_white_on_top = true;
							to_i = 7 - to_i;
							to_j = 7 - to_j;
							from_i = 7-from_i;
							from_j = 7-from_j;
							FlipBoard();
							flipflag = FALSE;

						}
						return true;
					}
				}
			}
		}
	}
	/*else
	{
		if(strlen(cstring)>3)
		{
			if(cstring[0] >='a' && cstring[0] <='z' && cstring[1] == 'x')
			{
				for(int i=0;i<8;i++)
				{
					int j=(int)(cstring[0]-'a');
					m_point.x = 7-i;
					m_point.y = 7-j;
					int piecetype;
					if(cb[7-i][7-j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype)&& CheckValidMove(to_i,to_j) == true)
					{
						from_i = 7-i;
						from_j = 7-j;
						return true;
					}
				}
			}
			else if(cstring[1] >='a' && cstring[1] <='z' && cstring[1] != 'x' &&cstring[3] != '+')
			{
				for(int i=0;i<8;i++)
				{
					int j = cstring[1]-'a';
					m_point.x = 7-i;
					m_point.y = 7-j;
					int piecetype;
					if(cb[7-i][7-j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype)&& CheckValidMove(to_i,to_j) == true)
					{
						from_i = 7-i;
						from_j = 7-j;
						return true;
					}			
				}
			}
			else if(cstring[1] >='1' && cstring[1] <='8')
			{
				for(int j=0;j<8;j++)
				{
					int i = (int)('9'- cstring[1]) -1;
					m_point.x = 7-i;
					m_point.y = 7-j;
					int piecetype;
					if(cb[7-i][7-j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype)&& CheckValidMove(to_i,to_j) == true)
					{
						from_i = 7-i;
						from_j = 7-j;
						return true;
					}			
				}
			}
			else
				for(int i=0;i<8;i++)
				{
					for(int j=0;j<8;j++)
					{
						m_point.x = 7-i;
						m_point.y = 7-j;
						int piecetype;
						if(cb[7-i][7-j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype)&& CheckValidMove(to_i,to_j) == true)
						{
							from_i = 7-i;
							from_j = 7-j;
							return true;
						}
					}
				}
		}
		else
		{
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					m_point.x = 7-i;
					m_point.y = 7-j;
					int piecetype;
					if(cb[7-i][7-j].GetPieceId() == GetPieceType(cstring,pieceside,piecetype)&& CheckValidMove(to_i,to_j) == true)
					{
						from_i = 7-i;
						from_j = 7-j;
						return true;
					}
				}
			}
		}
	}*/
	return false;
}
int CNetChessView::GetPieceType(char cstring[255],int piececolor,int &piecetype)
{
	switch(cstring[0])
	{
		case 'N':
			if(piececolor == WHITE)
			{
				piecetype = KNIGHT;
				return KNIGHT_WHITE;

			}
			else
			{
				piecetype = KNIGHT;
				return KNIGHT_BLACK;
			}
			break;
		case 'K':
			if(piececolor == WHITE)
			{
				piecetype = KING;
				return KING_WHITE;
			}
			else
			{
				piecetype = KING;
				return KING_BLACK;
			}
			break;
		case 'R':
			if(piececolor == WHITE)
			{
				piecetype = ROOK;
				return ROOK_WHITE;
			}
			else
			{
				piecetype = ROOK;
				return ROOK_BLACK;
			}
			break;
		case 'B':
			if(piececolor == WHITE)
			{
				piecetype = BISHOP;
				return BISHOP_WHITE;
			}
			else
			{
				piecetype = BISHOP;
				return BISHOP_BLACK;
			}
			break;
		case 'Q':
			if(piececolor == WHITE)
			{
				piecetype = QUEEN;
				return QUEEN_WHITE;
			}
			else
			{
				piecetype = QUEEN;
				return QUEEN_BLACK;
			}
			break;
		default:
		{
			if(cstring[1] != 'x')
			{
				int j = (int)(cstring[0]-'a');
				int i = (int)('9'-cstring[1])-1;
				piecetype = cb[i][j].GetPieceType();
				return cb[i][j].GetPieceId();
			}
			else
			{
				if(piececolor == WHITE)
				{
					piecetype = PAWN;
					return PAWN_WHITE;
				}
				else
				{
					piecetype = PAWN;
					return PAWN_BLACK;
				}
			}
		}
	}
}
void CNetChessView::doFENRead(CString file,char type)
{
//	OnInitialUpdate();

	if(m_white_on_top == true)
	{		
		FlipBoard();
		m_white_on_top = false;
	}

	unsigned char msg[2];
	msg[0] = PGNFILE;
	msg[1] = TRUE;
	SendSockData(msg,2);

	struct CBA
	{
		char ChessBoard[65];
	} CBA[200];
	memset(CBA,'\0',sizeof(CBA));
	m_fileReadFlag = TRUE;	
	FILE *fp;
	if(type == 'f')
	{
		fp = fopen(file,"r");
	}
	else
	{

		fp = fopen(".\\temp.fen","w+");
		fprintf(fp,file.GetBuffer(0));		
		fclose(fp);
		fp=fopen(".\\temp.fen","r");
	}
	char cstring1[255],cstring2[255],cstring3[255],cstring4[255];		
	int totalMoves = 0;
	while(!feof(fp))
	{
		memset(cstring1,'\0',255);
		
		fscanf(fp,"%s%s%s%s",cstring1,cstring2,cstring3,cstring4);
		//fscanf(fp,"%s",cstring1);
		//read until end of line
		char c;
		while(!feof(fp))
		{
			fscanf(fp,"%c",&c);
			if(c == '\n') break;
		}
		int i = 0, j = 0;		
		for(int k = 0;k < (int)strlen(cstring1);k++,i++)
		{
			/*if(cstring1[k] == '/')
			{
				i++;
				j=0;
			}
			else if(cstring1[k] > '1' && cstring1[k] < '9')
			{
				int total = (int)('9' - cstring1[k]);
				for(;j<total;j++)
				{
					CBA[totalMoves].ChessBoard[i][j] = ' ';
				}				
			}
			else
			{
				j++;
				CBA[totalMoves].ChessBoard[i][j] = cstring1[k];
			}*/
			if(cstring1[k] >= '1' && cstring1[k] < '9')
			{
				int total = (int)(cstring1[k]-'0');
				for(int j=0;j<total;j++,i++)
				{
					CBA[totalMoves].ChessBoard[i] = ' ';
				}				
				i--;
			}
			else if(cstring1[k] == '/')
			{
				i--;
			}
			else
			{
				CBA[totalMoves].ChessBoard[i] = cstring1[k];
			}
		}
		totalMoves++;
	}
	fclose(fp);
	if(type != 'f')
		DeleteFile(".\\temp.fen");
	m_fileReadFlag = FALSE;
	//handle FEN data now
	COLOR_TYPE pieceside = BLACK;
	for(int k=1;k<totalMoves-1;k++)
	{
		//compare present ChessBoard to Previous Chess board and identify difference
		//first parse find the piece moved from position		
		pieceside = pieceside == WHITE ? BLACK : WHITE;
		char from_type;
		int from_pos;		
		for(int i=0; i < (int)strlen(CBA[k].ChessBoard); i++)
		{			
			if(CBA[k].ChessBoard[i] == ' ' && CBA[k].ChessBoard[i] != CBA[k-1].ChessBoard[i] && ((CBA[k-1].ChessBoard[i] > 'A' && CBA[k-1].ChessBoard[i] < 'Z') || (CBA[k-1].ChessBoard[i] > 'a' && CBA[k-1].ChessBoard[i] < 'z')) ) 
			{
				from_type = CBA[k-1].ChessBoard[i];	
				from_pos = i;
				if(from_type == 'R' || from_type == 'r')
					continue;
				break;
			}		
		}
		
		//second parse, find the to piece position
		char to_type;
		int to_pos;		
		for(int i=0; i < (int)strlen(CBA[k].ChessBoard); i++)
		{			
			if(CBA[k].ChessBoard[i] != ' ' && CBA[k].ChessBoard[i] != CBA[k-1].ChessBoard[i] &&
				((CBA[k].ChessBoard[i] > 'A' && CBA[k].ChessBoard[i] < 'Z') || (CBA[k].ChessBoard[i] > 'a' && CBA[k].ChessBoard[i] < 'z'))) 
			{				
				to_type = CBA[k].ChessBoard[i];				
				to_pos = i;
				if(to_type == 'R' || to_type == 'r')
					continue;
				break;
			}
		
		}
		int pos_count = -1;
		int from_i,from_j, to_i,to_j;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				pos_count++;			
				if(pos_count == from_pos)
				{
					from_i = i;
					from_j = j;
				}
				if(pos_count == to_pos)
				{
					to_i = i;
					to_j = j;
				}
			}
		}
		if((from_type == 'p' && to_type == 'q') || (from_type == 'P' && to_type == 'Q'))
		{			
			m_pickPieceDlg->m_pickpiecetype  = 1;			
			m_pickPieceDlg->m_piecked_piece= to_type;
			GetPieceInfo(to_type,m_pickPieceDlg->m_piece_color,m_pickPieceDlg->m_piece_type);
		}
		
		m_point.x = from_i;
		m_point.y = from_j;
		m_mouseMoveFlag = true;
		CRect rect=cb[to_i][to_j].GetRect();
		CPoint pt(rect.left+10,rect.top+10);
		OnLButtonUpAction(0,pt);
		Sleep(m_optDlg.m_edit_replay_interval*1000);
	}
	DrawBoard();
}

void CNetChessView::doFENPositionRead(CString filedata,char type)
{
	if(m_white_on_top == true)
	{
		FlipBoard();
		m_white_on_top = false;
	}
	for ( int i = 0; i < 8; i++)
	{	
		for( int j = 0; j < 8; j++)
		{
			cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			 
		}	
	}
	
	int i=0;
	int j=0;

	char file[1024],side[2],castlingInfo[5],enpassentInfo[3];
	
	memset(file,'\0',1024);
	sscanf(filedata.GetBuffer(0),"%s%s%s%s",file,side,castlingInfo,
		enpassentInfo);
	
	for(int k=0;k < (int)strlen(file) && file[k] != ' ';k++)
	{
		if(file[k] >= '1' && file[k] < '9')
		{
			int total = (int)(file[k] - '0');
			for(int count=0;count<total;count++,j++)
			{
				cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);				
			}			
		}
		else if(file[k] == '/')
		{
			j=0;
			i++;
		}
		else if(file[k] != ' ')
		{
			COLOR_TYPE ct;
			PIECE_TYPE pt;
			GetPieceInfo(file[k],ct,pt);
			cb[i][j].SetPieceData(file[k],ct,pt,PIECE_NOT_MOVING);
			j++;
		}
	}
	//set piece side	
	if(side[0] == 'w')
	{
		KillTimer(PIECE_SIDE_TIMER_EVENT_ID);
		SetTimer(PIECE_SIDE_TIMER_EVENT_ID,1000,NULL);
		
		if(m_pClientSocket == NULL)
		{
			m_pieceSide = WHITE;
			m_player_turn = true;
		}
		else
		{
			if(m_pieceSide == WHITE)
				m_player_turn = true;
			else
				m_player_turn = false;
		}
	}
	else if(side[0] == 'b')
	{
		KillTimer(PIECE_SIDE_TIMER_EVENT_ID);
		SetTimer(PIECE_SIDE_TIMER_EVENT_ID,1000,NULL);		
		if(m_pClientSocket == NULL)
		{
			m_pieceSide = BLACK;
			m_player_turn = true;
		}
		else
		{
			if(m_pieceSide == BLACK)
				m_player_turn = true;
			else
				m_player_turn = false;
		}
	}

	//set flags
	m_blackKingMovedFlag = true;
	m_whiteKingMovedFlag = true;
	m_blackRookRank1MovedFlag = true;
	m_whiteRookRank1MovedFlag = true;
	m_blackRookRank7MovedFlag = true;
	m_whiteRookRank7MovedFlag = true;
	CString str = castlingInfo;
	if(str.Find("K")>=0)
	{
		m_whiteKingMovedFlag = false;
		m_whiteRookRank1MovedFlag = false;
	}
	if(str.Find("Q")>=0)
	{
		m_whiteKingMovedFlag = false;
		m_whiteRookRank1MovedFlag = false;
	}
	if(str.Find("k")>=0)
	{
		m_blackKingMovedFlag = false;
		m_blackRookRank7MovedFlag = false;
	}
	if(str.Find("q")>=0)
	{
		m_blackKingMovedFlag = false;
		m_blackRookRank1MovedFlag = false;
	}	
	//set enpassent availability, it will take some time
	DrawBoard();
}


void CNetChessView::doEPDRead(CString file,char type)
{
	doFENRead(file,type);	
}

void CNetChessView::OnFileSubmitpgndata() 
{
	// TODO: Add your command handler code here
	if(m_iHistory > -1)
	{
		int ret= AfxMessageBox("Do you want to save the playing game",MB_YESNOCANCEL);
		if(ret == IDYES)
		{
			OnFileSave();			 
		}
		else if(ret == IDCANCEL)
		{
			return;
		}
	}
	CPGNDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		if(!dlg.m_edit_pgn_data.IsEmpty())
		{
			Initialize();
			BeginWaitCursor();
			//doPGNRead(dlg.m_edit_pgn_data,'s');
			OnFileOpen(dlg.m_edit_pgn_data);
			EndWaitCursor();
		}
	}
}

void CNetChessView::OnEditCopy() 
{	
	HANDLE hText = NULL;
	HANDLE hData;//, hClipData; 
	LPSTR lpData;//, lpClipData;                           /* pointers to clip data */
	LPSTR           lpszText;
//	CString str = GetFileSaveString();
	CString str;
	if(m_iHistory > -1)
	{
		CStringArray ar;
		str = GetHistoryString(ar,0);
	}
	else
	{
		int movecount = m_iHistory / 2;
		char side = m_pieceSide == WHITE ? 'w' : 'b';
		str = GetPositionString('F',movecount,side);
	}
//    hInst = hInstance;    

    if (!(hText 
          = GlobalAlloc(GMEM_MOVEABLE,(DWORD)str.GetLength()))) {        
        return;		

    }
      
    if (!(lpszText = (char*)GlobalLock(hText))) {        
        return;
    }

    strcpy(lpszText, str.GetBuffer(0));
    GlobalUnlock(hText);

	if (hText != NULL) {
        /* Allocate memory and copy the string to it */

        if (!(hData 
             = GlobalAlloc(GMEM_DDESHARE, GlobalSize (hText)))) {            
            return;
        }
        if (!(lpData =(char*) GlobalLock(hData))) {            
            return;
        }
        if (!(lpszText =(char*) GlobalLock (hText))) {            
            return;
        }

        strcpy(lpData, lpszText);
        GlobalUnlock(hData);
        GlobalUnlock (hText);

        /* Clear the current contents of the clipboard, and set
         * the data handle to the new string.
         */

        if (OpenClipboard()) {
            EmptyClipboard();
            SetClipboardData(CF_TEXT, hData);
            CloseClipboard();
        }
        hData = NULL;
	}
}

void CNetChessView::OnEditPaste() 
{
	HANDLE hText = NULL;
	LPSTR           lpszText;
	HANDLE hClipData;                            /* handles to clip data  */
	LPSTR  lpClipData;                           /* pointers to clip data */

    if (OpenClipboard()) {

        /* get text from the clipboard */

        if (!(hClipData = GetClipboardData(CF_TEXT))) {
            CloseClipboard();
        }
        if (hText != NULL) {
            GlobalFree(hText);
        }
        if (!(hText = GlobalAlloc(GMEM_MOVEABLE
                                    , GlobalSize(hClipData)))) {
            
            CloseClipboard();            
			return;
        }
        if (!(lpClipData = (char*)GlobalLock(hClipData))) {
            
            CloseClipboard();
			return;
        }
        if (!(lpszText = (char*)GlobalLock(hText))) {
            
            CloseClipboard();
            return;
        }
        strcpy(lpszText, lpClipData);
		CString str(lpszText);
        GlobalUnlock(hClipData);
        CloseClipboard();
        GlobalUnlock(hText);
        /* copy text to the application window */
	   OnFileOpen(str);
    }    
}

void CNetChessView::OnViewDemoPause() 
{
	// TODO: Add your command handler code here
	if(m_pauseFlag == TRUE && m_manualEditingFlag == TRUE)
	{
		AfxMessageBox("Manual editing is in progress, disable manual editing to activate this feature");
		return;	
	}
	m_pauseFlag == TRUE ? m_pauseFlag = FALSE: m_pauseFlag = TRUE;
}

void CNetChessView::OnViewDemoStart() 
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here	
	if(m_manualEditingFlag == TRUE)
	{	
		AfxMessageBox("Manual editing is in progress, disable manual editing to activate this feature");
		return;
	}
	if(m_demoFlag == TRUE)
	{
		return;
	}
	CDemoIntervalDlg dlg;
	if(m_demoFlag == FALSE)
	{
		if(dlg.DoModal() == IDCANCEL)
		{		
			return;
		}
	}
	else
	{
		m_demoFlag = FALSE;
		return;
	}
	if(m_pClientSocket == NULL)
	{		
		m_demoFlag = TRUE;
		m_manualEditingFlag = FALSE;
		OnEditMovefirst();
		m_demoTotal = 0;		
		m_demoInterval = dlg.m_edit_demo_interval;
		SetTimer(DEMO_TIMER_EVENT_ID,dlg.m_edit_demo_interval*1000,NULL);		
	}
	else
	{		
		if(m_demoFlag == FALSE)
		{
			unsigned char data[50];
			data[0]=DEMO_START;
			m_demoInterval = dlg.m_edit_demo_interval;
			strcpy((char*)&data[1],m_edit_name.GetBuffer(0));
			SendSockData(data,m_edit_name.GetLength()+2);	
		}
		else
		{
			unsigned char data[2];;
			m_demoFlag = FALSE;
			data[0]=DEMO_END;
			SendSockData(data,m_edit_name.GetLength()+2);		
		}
		//data[1] = m_checkmove;				
	}		
}

void CNetChessView::OnViewDemoStop() 
{
	// TODO: Add your command handler code here

	m_demoFlag = FALSE;	
}

void CNetChessView::OnUpdateViewDemoPause(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_pauseFlag == TRUE ? pCmdUI->SetCheck(1) : pCmdUI->SetCheck(0);
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnUpdateViewDemoStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here	
	m_demoFlag == TRUE ? pCmdUI->SetCheck(1) : pCmdUI->SetCheck(0);	
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnUpdateViewDemoStop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_demoFlag == FALSE ? pCmdUI->SetCheck(1) : pCmdUI->SetCheck(0);	
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnViewDemoGoto() 
{
	// TODO: Add your command handler code here
	if((m_demoFlag == TRUE && m_pauseFlag == TRUE) || m_manualEditingFlag == TRUE)
	{
		CStringArray historystring;
		GetHistoryString(historystring,1);
		if(historystring.GetSize() <= 0)
		{
			AfxMessageBox("No data found!");
			return;
		}
		CGoToMoveHistoryDlg dlg;
		for(int i=0;i<historystring.GetSize();i++)
		{
			dlg.m_historystring.Add(historystring.GetAt(i));
		}	
		dlg.DoModal();
	}
	else
	{
		AfxMessageBox("Start and pause the Replay or enable editing!");
	}
	return;
}
void CNetChessView::MoveTo(int pos)
{	
	int total = m_iHistory;
	for(int i=0;i<=total;i++)
	{
		OnEditUndoAction(0); 			
	}
	for(int i=1;i<=pos;i++)
	{
		OnEditRedoAction(0);				
	}
	m_demoTotal = pos;
	unsigned char msg[2];
	msg[0] = GOTO;
	memcpy(&msg[1],&pos,4);
	SendSockData((unsigned char*)msg,5);
	DrawBoard();
}

void CNetChessView::OnFileSaveAs() 
{
	// TODO: Add your command handler code here	
	
	CFileDialog fdialog(FALSE);
	if(fdialog.DoModal() == IDOK)
	{
		m_fileName = fdialog.GetPathName(); 	
		FILE *fp = fopen(m_fileName,"w");
		BeginWaitCursor();		
		if(fdialog.GetFileExt() == "FEN" || fdialog.GetFileExt() == "fen")
		{
			CString str = GetPositionHistoryString('F');
			str.Replace("\r","");
			fprintf(fp,"%s",str);
		}
		else if(fdialog.GetFileExt() == "EPD" || fdialog.GetFileExt() == "epd")
		{
			CString str = GetPositionHistoryString('E');
			str.Replace("\r","");
			fprintf(fp,"%s",str);
		}
		else
		{
			CStringArray ar;
			CString str = GetHistoryString(ar,0);
			str.Replace("\r","");
			fprintf(fp,"%s",str);
		}	
		EndWaitCursor();
		/*//if(fdialog.GetFileExt() == "PGN" || fdialog.GetFileExt() == "pgn")
		{
			BeginWaitCursor();

			CStringArray ar;
			CString str = GetHistoryString(ar,0);
			str.Replace("\r","");
			fprintf(fp,"%s",str);
			EndWaitCursor();
		}			
		/*else
		{
			int count=0;
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{				 
					PIECE_TYPE piece_type;
					COLOR_TYPE piece_color;
					int pieceid;
					STATE piece_state;
					cb[i][j].GetPieceData(pieceid,piece_color,piece_type,piece_state);
					if(piece_type != BLANK)
					{
					  count++;
					}
				}
			}

			fprintf(fp,"%d %d %d %d %d %d %d\n",count,m_optDlg.m_check_white_on_top,m_white_on_top, m_pieceSide, m_player_turn,m_whiteTime,m_blackTime);

			for(i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{				 
					PIECE_TYPE piece_type;
					COLOR_TYPE piece_color;
					int pieceid;
					STATE piece_state;
					cb[i][j].GetPieceData(pieceid,piece_color,piece_type,piece_state);
					if(piece_type != BLANK)
					{
					 fprintf(fp,"C %d %d %d %d %d\n",
 						 i,j,piece_type,piece_color,pieceid);
					}
				}
			}
			fprintf(fp,"%d\n",m_iHistory+1);
			 
			PIECE_SIDE piece_side;		 
			PIECE_TYPE from_piece_type;
			COLOR_TYPE from_color_type;
			int from_pieceid;
			int from_row_id;
			int from_col_id;
			PIECE_TYPE to_piece_type;
			COLOR_TYPE to_color_type;
			int to_pieceid;
			int to_row_id;
			int to_col_id;
			for(i=0;i<=m_iHistory;i++)
			{		 
				m_History[i].GetHistory(			 
					piece_side,from_piece_type,
					from_color_type,from_pieceid,
					from_row_id,from_col_id, to_piece_type,
					to_color_type,to_pieceid,to_row_id,
					to_col_id);
				int SpecialAction = m_History[i].GetSpecialAction();
				unsigned int action = m_History[i].GetPieceMoveAction();
				fprintf(fp,"H %d %d %d %d %d %d %d %d %d %d %d %d %u\n",
					piece_side,from_piece_type,
					from_color_type,from_pieceid,
					from_row_id,from_col_id, to_piece_type,
					to_color_type,to_pieceid,to_row_id,
					to_col_id, SpecialAction,action);	 
			} 
			
			DrawBoard();
			AfxMessageBox("Game is saved");
		}*/
		fclose(fp);
	}
}
void CNetChessView::CheckAmbiguousMove(int ini,int inj)
{	
	if(m_checkmove == FALSE)
		return;
	CPoint pt = m_point;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{			
			m_point.x = i;
			m_point.y = j;
			if(cb[i][j].GetPieceId() == cb[pt.x][pt.y].GetPieceId() && 
				cb[i][j].GetPieceId() != -1)				
			{				
				if(i == pt.x && j == pt.y)
					continue;
				bool tempblackKingMoveFlag = m_blackKingMovedFlag;
				bool tempwhiteKingMoveFlag = m_whiteKingMovedFlag;
				if(CheckValidMove(ini,inj) == true)
				{
					m_blackKingMovedFlag = tempblackKingMoveFlag;
					m_whiteKingMovedFlag = tempwhiteKingMoveFlag;

					if(i == pt.x)
					{
						m_ambiguousMoveFileFlag = TRUE;

					}
					else if(j == pt.y)
					{
						m_ambiguousMoveRankFlag = TRUE;
					}
					else
					{
						m_ambiguousMoveFileFlag = TRUE;
					}
					m_point = pt;
					return;
				}
			}
		}
	}
	m_point = pt;
}

void CNetChessView::OnFileGotopgngame() 
{
	// TODO: Add your command handler code here
	if(m_PGNFileData.GetSize() <=0)
		return;
	CGoToPGNGameDlg dlg;
	dlg.m_PGNFileIndex=m_PGNFileIndex;
	for(int i=0;i<m_PGNFileData.GetSize();i++)
	{
		dlg.m_PGNFileData.Add(m_PGNFileData.GetAt(i));		
	}
	if(dlg.DoModal() ==IDOK)
	{
		m_PGNFileIndex = dlg.m_PGNFileIndex;
		OnFileReloadthepgngame();		
	}
}

void CNetChessView::OnFileLoadfirstgame() 
{
	// TODO: Add your command handler code here
	BeginWaitCursor();
	m_PGNFileIndex=0;
	if(m_PGNFileData.GetSize() > 0 && m_PGNFileIndex >= 0)
	{
		Initialize();
		doPGNRead(m_PGNFileData.GetAt(m_PGNFileIndex),'s');
		if(m_iHistory > -1)
		{
			CString str;		
			str.Format("Loaded %d/%d PGN game",m_PGNFileIndex+1,m_PGNFileData.GetSize());
			SetPaneText(MESSAGEPANE,str,1);
		}
		else
		{
			CString filedata = m_PGNFileData.GetAt(m_PGNFileIndex);
			doFENPositionRead(filedata,'F');
			unsigned char data[1024];
			memset(data,'\0',1024);
			data[0] = POSITION_DATA;
			int count = 1;
			for(int i = 0; i< filedata.GetLength(); i++)
			{
				data[count++] = filedata[i];
			}
			SendSockData(data,count);
			CString str;		
			str.Format("Loaded %d/%d Position",m_PGNFileIndex+1,m_PGNFileData.GetSize());
			SetPaneText(MESSAGEPANE,str,1);
		}
	}
	EndWaitCursor();
}

void CNetChessView::OnFileLoadnextgame() 
{
	// TODO: Add your command handler code here
	BeginWaitCursor();
	m_PGNFileIndex++;
	if(m_PGNFileData.GetSize() < m_PGNFileIndex)
	{
		m_PGNFileIndex = m_PGNFileData.GetSize();
	}
	if(m_PGNFileData.GetSize() > m_PGNFileIndex && m_PGNFileIndex >=0 )
	{
		Initialize();		
		doPGNRead(m_PGNFileData.GetAt(m_PGNFileIndex),'s');
		if(m_iHistory > -1)
		{
			CString str;		
			str.Format("Loaded %d/%d PGN game",m_PGNFileIndex+1,m_PGNFileData.GetSize());
			SetPaneText(MESSAGEPANE,str,1);
		}
		else
		{
			CString filedata = m_PGNFileData.GetAt(m_PGNFileIndex);
			doFENPositionRead(filedata,'F');
			unsigned char data[1024];
			memset(data,'\0',1024);
			data[0] = POSITION_DATA;
			int count = 1;
			for(int i = 0; i< filedata.GetLength(); i++)
			{
				data[count++] = filedata[i];
			}
			SendSockData(data,count);
			CString str;		
			str.Format("Loaded %d/%d Position",m_PGNFileIndex+1,m_PGNFileData.GetSize());
			SetPaneText(MESSAGEPANE,str,1);
		}
	}
	EndWaitCursor();
}

void CNetChessView::OnFileOpenpgnfile() 
{
	// TODO: Add your command handler code here		
	CFileDialog fdialog(TRUE);
	if(fdialog.DoModal() == IDOK)
	{
		DrawBoard();
		BeginWaitCursor();
		m_PGNFileIndex=-1;;
		m_PGNFileData.RemoveAll();
		CString file = fdialog.GetPathName(); 	
		FILE *fp = fopen(file,"r");
		if(fp == NULL)
		{
			CString str;
			str.Format("Could not open the file %s",file);
			AfxMessageBox(str);
			return;
		}
		CString tempstr = "";
		CString s ="Loading file " + file;
		SetPaneText(MESSAGEPANE,s,1);		
		if(fdialog.GetFileExt() == "FEN" || fdialog.GetFileExt() == "fen")
		{
			while(!feof(fp))
			{
				char c;
				fscanf(fp,"%c",&c);
				if(c == '\n')
				{	
					if(tempstr.GetLength() > 0)
					{
						tempstr += (CString)"\r\n";						
						m_PGNFileData.Add(tempstr);
						tempstr = "";
					}
				}
				else
				{
					tempstr += c;
				}
			}
		}
		else if(fdialog.GetFileExt() == "EPD" || fdialog.GetFileExt() == "epd")
		{
			while(!feof(fp))
			{
				char c;
				fscanf(fp,"%c",&c);
				if(c == '\n')
				{						
					if(tempstr.GetLength() > 0)
					{
						tempstr += (CString)"\r\n";						
						m_PGNFileData.Add(tempstr);
						tempstr = "";
					}
				}
				else
				{
					tempstr += c;
				}
			}
		}
		else
		{
			while(!feof(fp))
			{
				char str[255];
				fscanf(fp,"%s",str);
				if(str[0] == '*' ||
					strcmp(str,"0-1") == 0 ||
					strcmp(str,"1-0") == 0 ||
					strcmp(str,"1/2-1/2") == 0)
				{
					tempstr += (CString)str + "\r\n";
					m_PGNFileData.Add(tempstr);
					tempstr = "";
				}
				else
				{
					if(str[strlen(str)-1] == ']')
					{
						tempstr += (CString)str + (CString)"\r\n";
					}
					else
					{     
					  if(tempstr.IsEmpty())
					  {
						   if(str[0] == '[' || str[0] == '1')
						   {
							tempstr += (CString)str + (CString)" ";
						   }
						   else
						   {
							tempstr = m_PGNFileData.GetAt(m_PGNFileData.GetSize()-1);
							tempstr += (CString)str;
							m_PGNFileData.RemoveAt(m_PGNFileData.GetSize()-1,1);
						   }
					  }
					  else
					  {
							tempstr += (CString)str + (CString)" ";
					  }
					}
				}
			}		
		}
		CString str;
		str.Format("Loaded %d games/positions",m_PGNFileData.GetSize(),fdialog.GetPathName());
		SetPaneText(MESSAGEPANE,str,1);
		fclose(fp);
		EndWaitCursor();
	}
	/*****************************************
	 **** This is used for tsting PGN files***
	 **** do not delete***********************
	 *****************************************/
	/*int total = m_PGNFileData.GetSize();	
	for(int i=0;i<total;i++)
	{
		char str[1000];;
		sprintf(str,"Testing game %d from file %s",i,fdialog.GetPathName());
		writeMessage(str);
		//doPGNRead(m_PGNFileData.GetAt(i),'s');
		OnFileLoadnextgame();
		//Sleep(00);
	}*/
}

void CNetChessView::OnFileReloadthepgngame() 
{
	// TODO: Add your command handler code here
	BeginWaitCursor();
	if(m_PGNFileData.GetSize() > 0 && m_PGNFileIndex != -1)
	{
		Initialize();
		doPGNRead(m_PGNFileData.GetAt(m_PGNFileIndex),'s');
		if(m_iHistory > -1)
		{
			CString str;		
			str.Format("Loaded %d/%d PGN game",m_PGNFileIndex+1,m_PGNFileData.GetSize());
			SetPaneText(MESSAGEPANE,str,1);
		}
		else
		{
			CString filedata = m_PGNFileData.GetAt(m_PGNFileIndex);
			doFENPositionRead(filedata,'F');
			unsigned char data[1024];
			memset(data,'\0',1024);
			data[0] = POSITION_DATA;
			int count = 1;
			for(int i = 0; i< filedata.GetLength(); i++)
			{
				data[count++] = filedata[i];
			}
			SendSockData(data,count);
			CString str;		
			str.Format("Loaded %d/%d Position",m_PGNFileIndex+1,m_PGNFileData.GetSize());
			SetPaneText(MESSAGEPANE,str,1);
		}
	}
	EndWaitCursor();
}

void CNetChessView::OnFileLoadprevpgngame() 
{
	// TODO: Add your command handler code here
	BeginWaitCursor();
	m_PGNFileIndex--;
	if(m_PGNFileIndex <0)
		m_PGNFileIndex = 0;
	if(m_PGNFileData.GetSize() > 0 && m_PGNFileIndex != -1)
	{
		Initialize();
		doPGNRead(m_PGNFileData.GetAt(m_PGNFileIndex),'s');
		if(m_iHistory > -1)
		{
			CString str;		
			str.Format("Loaded %d/%d PGN game",m_PGNFileIndex+1,m_PGNFileData.GetSize());
			SetPaneText(MESSAGEPANE,str,1);
		}
		else
		{
			CString filedata = m_PGNFileData.GetAt(m_PGNFileIndex);
			doFENPositionRead(filedata,'F');
			unsigned char data[1024];
			memset(data,'\0',1024);
			data[0] = POSITION_DATA;
			int count = 1;
			for(int i = 0; i< filedata.GetLength(); i++)
			{
				data[count++] = filedata[i];
			}
			SendSockData(data,count);
			CString str;		
			str.Format("Loaded %d/%d Position",m_PGNFileIndex+1,m_PGNFileData.GetSize());
			SetPaneText(MESSAGEPANE,str,1);
		}
	}
	EndWaitCursor();
}
void CNetChessView::OnFileLoadlastgame() 
{
	// TODO: Add your command handler code here
		// TODO: Add your command handler code here
	BeginWaitCursor();
	m_PGNFileIndex=m_PGNFileData.GetSize()-1;
	if(m_PGNFileIndex >= 0)
	{
		Initialize();
		doPGNRead(m_PGNFileData.GetAt(m_PGNFileIndex),'s');
		if(m_iHistory > -1)
		{
			CString str;		
			str.Format("Loaded %d/%d PGN game",m_PGNFileIndex+1,m_PGNFileData.GetSize());
			SetPaneText(MESSAGEPANE,str,1);
		}
		else
		{
			CString filedata = m_PGNFileData.GetAt(m_PGNFileIndex);
			doFENPositionRead(filedata,'F');
			unsigned char data[1024];
			memset(data,'\0',1024);
			data[0] = POSITION_DATA;
			int count = 1;
			for(int i = 0; i< filedata.GetLength(); i++)
			{
				data[count++] = filedata[i];
			}
			SendSockData(data,count);
			CString str;		
			str.Format("Loaded %d/%d Position",m_PGNFileIndex+1,m_PGNFileData.GetSize());
			SetPaneText(MESSAGEPANE,str,1);
		}
	}
	EndWaitCursor();
}

void CNetChessView::OnUpdateFileLoadlastgame(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);	
	m_PGNFileData.GetSize() > 0 ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
	
}

void CNetChessView::SetPaneText(int paneno,CString str,int log)
{
	if(log == 1)
		writeMessage("%s",str);
	((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->SetPaneText(paneno,str);
}

void CNetChessView::OnEditGameinfo() 
{
	// TODO: Add your command handler code here	
	
	if(m_gameInfoDlg.DoModal() == IDOK)
	{		
		if(m_observerFlag == TRUE)
			return;
		unsigned char data[500];
		memset(data,'\0',500);
		int count = 0;
		data[count++] = GAMEINFO;
		data[count++] = m_gameInfoDlg.m_edit_event.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_event.GetBuffer(0),m_gameInfoDlg.m_edit_event.GetLength());
		count += m_gameInfoDlg.m_edit_event.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_site.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_site.GetBuffer(0),m_gameInfoDlg.m_edit_site.GetLength());
		count += m_gameInfoDlg.m_edit_site.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_date.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_date.GetBuffer(0),m_gameInfoDlg.m_edit_date.GetLength());
		count += m_gameInfoDlg.m_edit_date.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_round.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_round.GetBuffer(0),m_gameInfoDlg.m_edit_round.GetLength());
		count += m_gameInfoDlg.m_edit_round.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_white.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_white.GetBuffer(0),m_gameInfoDlg.m_edit_white.GetLength());
		count += m_gameInfoDlg.m_edit_white.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_black.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_black.GetBuffer(0),m_gameInfoDlg.m_edit_black.GetLength());
		count += m_gameInfoDlg.m_edit_white.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_result.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_result.GetBuffer(0),m_gameInfoDlg.m_edit_result.GetLength());
		count += m_gameInfoDlg.m_edit_result.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_fenstring.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_fenstring.GetBuffer(0),m_gameInfoDlg.m_edit_fenstring.GetLength());
		count += m_gameInfoDlg.m_edit_fenstring.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_eco.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_eco.GetBuffer(0),m_gameInfoDlg.m_edit_eco.GetLength());
		count += m_gameInfoDlg.m_edit_eco.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_playcount.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_playcount.GetBuffer(0),m_gameInfoDlg.m_edit_playcount.GetLength());
		count += m_gameInfoDlg.m_edit_playcount.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_blackelo.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_blackelo.GetBuffer(0),m_gameInfoDlg.m_edit_blackelo.GetLength());
		count += m_gameInfoDlg.m_edit_blackelo.GetLength();

		data[count++] = m_gameInfoDlg.m_edit_whiteelo.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_edit_whiteelo.GetBuffer(0),m_gameInfoDlg.m_edit_whiteelo.GetLength());
		count += m_gameInfoDlg.m_edit_whiteelo.GetLength();

		data[count++] = m_gameInfoDlg.m_event_date.GetLength();
		memcpy(&data[count],m_gameInfoDlg.m_event_date.GetBuffer(0),m_gameInfoDlg.m_event_date.GetLength());
		count += m_gameInfoDlg.m_event_date.GetLength();

		SendSockData(data,count);
	}
	DrawBoard();
}

void CNetChessView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CNetChessView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
		case 35:
			if(m_manualEditingFlag == TRUE)
				OnEditMovelast();
			break;
		case 36:
			if(m_manualEditingFlag == TRUE)
				OnEditMovefirst();
			break;
		case 37://left
			if(m_manualEditingFlag == TRUE)
				OnEditUndo();
			break;
		case 40:
			OnFileLoadprevpgngame();
			break;
		case 39: //right
			if(m_manualEditingFlag == TRUE)
				OnEditRedo();
			break;
		case 38:
			OnFileLoadnextgame();
		default:
			break;			
	}	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CNetChessView::OnViewFlipboard() 
{
	// TODO: Add your command handler code here
	FlipBoard();
	m_white_on_top = m_white_on_top == true ? false : true;
	m_movedFromRect.left = -1;
	m_movedToRect.left = -1;		
	DrawBoard();
}

void CNetChessView::OnEditManualeditPauseclock() 
{
	// TODO: Add your command handler code here
	m_pauseclockFlag = m_pauseclockFlag == TRUE? FALSE: TRUE;
	if(m_pauseclockFlag == FALSE)
	{
		SetPaneText(MESSAGEPANE,"Game started!",1);
		if(m_whiteAsEngineFlag == TRUE && m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
			m_whiteEngine.WriteToEngine("resume");
		else if(m_blackAsEngineFlag == TRUE && m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
			m_blackEngine.WriteToEngine("resume");
	}
	else
	{
		SetPaneText(MESSAGEPANE,"Game paused!",1);
		if(m_iHistory > 0)
		{
			if(m_whiteAsEngineFlag == TRUE && m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
				m_whiteEngine.WriteToEngine("pause");
			else if(m_blackAsEngineFlag == TRUE && m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
				m_blackEngine.WriteToEngine("pause");
		}
	}
	unsigned char data[2];
	data[0] = CLOCK;
	data[1] = m_pauseclockFlag;
	SendSockData(data,2);
}

void CNetChessView::OnUpdateEditManualeditPauseclock(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_manualEditingFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);	
	m_pauseclockFlag == TRUE ? pCmdUI->SetCheck(1) : pCmdUI->SetCheck(0);
}

void CNetChessView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here	
}

void CNetChessView::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnUpdateFileGotopgngame(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here	
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
	m_PGNFileData.GetSize() > 0 ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);

}

void CNetChessView::OnUpdateFileLoadfirstgame(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
	m_PGNFileData.GetSize() > 0 ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CNetChessView::OnUpdateFileLoadnextgame(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
	m_PGNFileData.GetSize() > 0 ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CNetChessView::OnUpdateFileLoadprevpgngame(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
	m_PGNFileData.GetSize() > 0 ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}


void CNetChessView::OnUpdateFileOpen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnUpdateFileOpenpgnfile(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnUpdateFileReloadthepgngame(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
	m_PGNFileData.GetSize() > 0 ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);	
}

void CNetChessView::OnUpdateFileSubmitpgndata(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnUpdateToolsDraw(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnUpdateToolsResign(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnUpdateViewDemoGoto(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}

void CNetChessView::OnFileSaveboard() 
{
	// TODO: Add your command handler code here
	int flipflag = FALSE;
	if(m_white_on_top == true)
	{
		flipflag = TRUE;
		FlipBoard();
		m_white_on_top = false;
	}

	CFileDialog fdialog(FALSE);
	CString boardstate="";
	if(fdialog.DoModal() == IDOK)
	{
		int move = m_iHistory/2;
		char side = (m_pieceSide == WHITE ? 'w' : 'b');
		CString boardstate = GetPositionString('F',move,side);
		FILE *fp = fopen(fdialog.GetPathName(),"w");

		/*int count=0;		
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{				 
				PIECE_TYPE piece_type;
				COLOR_TYPE piece_color;
				int pieceid;
				STATE piece_state;
				cb[i][j].GetPieceData(pieceid,piece_color,piece_type,piece_state);
				if(piece_type != BLANK)
				{
					char str[100];
					sprintf(str,"%c%c%d ",
 					 pieceid,'a'+ j, i);
					boardstate += str;
				 count++;
				}
			}
		}
		fprintf(fp,"%d\n",count);*/
		fprintf(fp,"%s",boardstate.GetBuffer(0));
		fclose(fp);
	}
	if(flipflag == TRUE)
	{
		flipflag = FALSE;
		FlipBoard();
		m_white_on_top = true;
	}
}

void CNetChessView::OnUpdateFileSaveboard(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
void CNetChessView::GetPieceInfo(int PieceId, COLOR_TYPE &ct, PIECE_TYPE &pt)
{
	switch(PieceId)
	{
		case 'R':
			ct = WHITE;
			pt = ROOK;
			break;
		case 'B':
			ct = WHITE;
			pt = BISHOP;
			break;
		case 'N': 
			ct = WHITE;
			pt = KNIGHT;
			break;
		case 'Q':
			ct = WHITE;
			pt = QUEEN;
			break;
		case 'K':
			ct = WHITE;
			pt = KING;
			break;
		case 'P':
			ct = WHITE;
			pt = PAWN;
			break;
		case 'r':
			ct = BLACK;
			pt = ROOK;
			break;
		case 'b':
			ct = BLACK;
			pt = BISHOP;
			break;
		case 'n': 
			ct = BLACK;
			pt = KNIGHT;
			break;
		case 'q':
			ct = BLACK;
			pt = QUEEN;
			break;
		case 'k':
			ct = BLACK;
			pt = KING;
			break;
		case 'p':
			ct = BLACK;
			pt = PAWN;
			break;
		default:
			ct = NONE;
			pt = BLANK;
			break;
	}
	return;
}

void CNetChessView::OnViewObserverslist() 
{
	// TODO: Add your command handler code here
	CObserversDlg dlg;
	POSITION pos = m_pObserverSocketList.GetHeadPosition();
	for(int i=0;i < m_pObserverSocketList.GetCount();i++)
	{
		CClientSocket *csock = (CClientSocket*)m_pObserverSocketList.GetNext(pos);		
		dlg.m_stringArray.Add(csock->m_ipaddress);
	}
	dlg.DoModal();
}

void CNetChessView::OnUpdateViewObserverslist(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_pServerSocket == NULL ? pCmdUI->Enable(0) : pCmdUI->Enable(1);
}

void CNetChessView::OnFileConvert() 
{
	// TODO: Add your command handler code here
	if(m_pClientSocket != NULL)
	{
		AfxMessageBox("This feature is not supported in Client/Server mode!");
		return;
	}
	//OnFileOpenpgnfile();
	if( m_PGNFileData.GetSize() <= 0 )
	{
		AfxMessageBox("No files are loaded");
		return;
	}
	CString m_backupfileName="";
	if(m_fileName.GetLength() > 0)
	{
		m_backupfileName = m_fileName;
		m_optDlg.m_check_auto_save = FALSE;
		KillTimer(SAVE_TIMER_EVENT_ID);
	}

	CConvertDlg dlg;
	if(dlg.DoModal() ==IDOK)
	{
		CleanWindow();
		m_convertFlag = TRUE;
		int total = m_PGNFileData.GetSize();	
		m_PGNFileIndex = 0;
		for(int i=0;i<total;i++)
		{
			CString str;
			str.Format("Converting %d game and saving in %s filefile %s",i,dlg.m_edit_filename);
			SetPaneText(MESSAGEPANE,str,1);			
			OnFileLoadnextgame();
			m_fileName.Format("%s%d.%s",
				dlg.m_edit_filename.Left(dlg.m_edit_filename.GetLength() - 4),
				m_PGNFileIndex+1,dlg.m_edit_filename.Right(3));
			OnFileSave();			
		}
		CString str;
		str.Format("Converted %d/%d games",m_PGNFileIndex,total);
		SetPaneText(MESSAGEPANE,str,1);
	}
	m_convertFlag = FALSE;
	DrawBoard();
}

void CNetChessView::OnEditComment() 
{
	// TODO: Add your command handler code here
	if(m_iHistory < 0)
	{
		AfxMessageBox("Move history not available");
		return;
	}
	CCommentDlg dlg;
	dlg.m_edit_comment = m_History[m_iHistory].GetComment();
	if(dlg.DoModal() == IDOK)
	{
		m_History[m_iHistory].SetComment(dlg.m_edit_comment.GetBuffer(0));
	}
}

void CNetChessView::OnUpdateFileConvert(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);	
	m_PGNFileData.GetSize() > 0 ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);	
}
void CNetChessView::CleanWindow()
{
	CClientDC dc(this);
	COLORREF whitecolor(RGB(255,255,255));	 	 
	CBrush whitebrush(whitecolor);
	dc.SelectObject(whitebrush);
	CRect crect;
	GetClientRect(&crect); 
	dc.FillRect(&crect,&whitebrush);
}
BOOL CNetChessView::OnCommand(WPARAM wParam,LPARAM lParam)
{
	short id,id1;
	char id2[4];
	memcpy(&id2,&wParam,4);
	memcpy(&id,&id2[0],2);
	memcpy(&id1,&id2[2],2);
	switch(id)
	{
		case ID_EXTRA_LISTBOX:
		{
			if(id1 == LBN_SELCHANGE)
			{
				/*if((m_demoFlag == TRUE && m_pauseFlag == TRUE) || m_manualEditingFlag == TRUE)
				{
					int ret = m_listctrl_movehistory.GetCurSel();
					if(ret != LB_ERR)
						MoveTo(ret+1);		
				}
				else
				{
					AfxMessageBox("Start and pause the demo or enable editing!");
				}
				writeMessage("in LBN SELCHANGE event");*/
			}
		}
		break;
		case ID_EXTRA_BUTTON:
		{
			CString text;
			m_edit_comment.GetWindowText(text);
			if(m_iHistory > -1)
			{	
				text.Replace("\r\n"," ");
				text.Replace("\n", " ");
				text.Replace("\t", " ");
				m_History[m_iHistory].SetComment(text);
				SetPaneText(MESSAGEPANE,"Comment set to recent played move",1);
			}
			else
			{
				SetPaneText(MESSAGEPANE,"Move history not found",1);
			}
		}
		break;
		case ID_EXTRA_WHITE_COMPUTER:
			AfxMessageBox("White computer radio button clicked");
		break;
		case ID_EXTRA_WHITE_HUMAN:
			AfxMessageBox("White human radio button clicked");
		break;
		case ID_EXTRA_BLACK_COMPUTER:
			AfxMessageBox("black computer radio button clicked");
		break;
		case ID_EXTRA_BLACK_HUMAN:
			AfxMessageBox("black human radio button clicked");
		break;
		default:
			break;
	}
	return TRUE;
}

void CNetChessView::OnEditCopyepd() 
{
	// TODO: Add your command handler code here
	HANDLE hText = NULL;
	HANDLE hData;//, hClipData; 
	LPSTR lpData;//, lpClipData;                           /* pointers to clip data */
	LPSTR           lpszText;
//	CString str = GetFileSaveString();
	CString str;
	str = GetPositionHistoryString('E');	

//    hInst = hInstance;    

    if (!(hText 
          = GlobalAlloc(GMEM_MOVEABLE,(DWORD)str.GetLength()))) {        
        return;		

    }
      
    if (!(lpszText = (char*)GlobalLock(hText))) {        
        return;
    }

    strcpy(lpszText, str.GetBuffer(0));
    GlobalUnlock(hText);

	if (hText != NULL) {
        /* Allocate memory and copy the string to it */

        if (!(hData 
             = GlobalAlloc(GMEM_DDESHARE, GlobalSize (hText)))) {            
            return;
        }
        if (!(lpData =(char*) GlobalLock(hData))) {            
            return;
        }
        if (!(lpszText =(char*) GlobalLock (hText))) {            
            return;
        }

        strcpy(lpData, lpszText);
        GlobalUnlock(hData);
        GlobalUnlock (hText);

        /* Clear the current contents of the clipboard, and set
         * the data handle to the new string.
         */

        if (OpenClipboard()) {
            EmptyClipboard();
            SetClipboardData(CF_TEXT, hData);
            CloseClipboard();
        }
        hData = NULL;
	}
}

void CNetChessView::OnUpdateEditCopyfen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CNetChessView::OnUpdateEditCopyepd(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CNetChessView::OnEditCopyfen() 
{
	// TODO: Add your command handler code here
	HANDLE hText = NULL;
	HANDLE hData;//, hClipData; 
	LPSTR lpData;//, lpClipData;                           /* pointers to clip data */
	LPSTR           lpszText;
//	CString str = GetFileSaveString();
	CString str;
	str = GetPositionHistoryString('F');	

//    hInst = hInstance;    

    if (!(hText 
          = GlobalAlloc(GMEM_MOVEABLE,(DWORD)str.GetLength()))) {        
        return;		

    }
      
    if (!(lpszText = (char*)GlobalLock(hText))) {        
        return;
    }

    strcpy(lpszText, str.GetBuffer(0));
    GlobalUnlock(hText);

	if (hText != NULL) {
        /* Allocate memory and copy the string to it */

        if (!(hData 
             = GlobalAlloc(GMEM_DDESHARE, GlobalSize (hText)))) {            
            return;
        }
        if (!(lpData =(char*) GlobalLock(hData))) {            
            return;
        }
        if (!(lpszText =(char*) GlobalLock (hText))) {            
            return;
        }

        strcpy(lpData, lpszText);
        GlobalUnlock(hData);
        GlobalUnlock (hText);

        /* Clear the current contents of the clipboard, and set
         * the data handle to the new string.
         */

        if (OpenClipboard()) {
            EmptyClipboard();
            SetClipboardData(CF_TEXT, hData);
            CloseClipboard();
        }
        hData = NULL;
	}	
}

void CNetChessView::OnViewImage() 
{
	// TODO: Add your command handler code here
	CViewImage dlg;
	dlg.DoModal();
}

void CNetChessView::OnEditCopyepdposition() 
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	HANDLE hText = NULL;
	HANDLE hData;//, hClipData; 
	LPSTR lpData;//, lpClipData;                           /* pointers to clip data */
	LPSTR           lpszText;
//	CString str = GetFileSaveString();
	char side = m_pieceSide == WHITE ? 'w' : 'b';
	int count=-1;
	CString str;
	str = GetPositionString('F',count,side);	


//    hInst = hInstance;    

    if (!(hText 
          = GlobalAlloc(GMEM_MOVEABLE,(DWORD)str.GetLength()))) {        
        return;		

    }
      
    if (!(lpszText = (char*)GlobalLock(hText))) {        
        return;
    }

    strcpy(lpszText, str.GetBuffer(0));
    GlobalUnlock(hText);

	if (hText != NULL) {
        /* Allocate memory and copy the string to it */

        if (!(hData 
             = GlobalAlloc(GMEM_DDESHARE, GlobalSize (hText)))) {            
            return;
        }
        if (!(lpData =(char*) GlobalLock(hData))) {            
            return;
        }
        if (!(lpszText =(char*) GlobalLock (hText))) {            
            return;
        }

        strcpy(lpData, lpszText);
        GlobalUnlock(hData);
        GlobalUnlock (hText);

        /* Clear the current contents of the clipboard, and set
         * the data handle to the new string.
         */

        if (OpenClipboard()) {
            EmptyClipboard();
            SetClipboardData(CF_TEXT, hData);
            CloseClipboard();
        }
        hData = NULL;
	}	
	
}

void CNetChessView::OnEditCopyfenposition() 
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	HANDLE hText = NULL;
	HANDLE hData;//, hClipData; 
	LPSTR lpData;//, lpClipData;                           /* pointers to clip data */
	LPSTR           lpszText;
//	CString str = GetFileSaveString();

	char side = m_pieceSide == WHITE ? 'w' : 'b';
	int count=-1;
	CString str;
	str = GetPositionString('F',count,side);	

//    hInst = hInstance;    

    if (!(hText 
          = GlobalAlloc(GMEM_MOVEABLE,(DWORD)str.GetLength()))) {        
        return;		

    }
      
    if (!(lpszText = (char*)GlobalLock(hText))) {        
        return;
    }

    strcpy(lpszText, str.GetBuffer(0));
    GlobalUnlock(hText);

	if (hText != NULL) {
        /* Allocate memory and copy the string to it */

        if (!(hData 
             = GlobalAlloc(GMEM_DDESHARE, GlobalSize (hText)))) {            
            return;
        }
        if (!(lpData =(char*) GlobalLock(hData))) {            
            return;
        }
        if (!(lpszText =(char*) GlobalLock (hText))) {            
            return;
        }

        strcpy(lpData, lpszText);
        GlobalUnlock(hData);
        GlobalUnlock (hText);

        /* Clear the current contents of the clipboard, and set
         * the data handle to the new string.
         */

        if (OpenClipboard()) {
            EmptyClipboard();
            SetClipboardData(CF_TEXT, hData);
            CloseClipboard();
        }
        hData = NULL;
	}	
	
}

void CNetChessView::OnToolsWhiteengineLoad() 
{
	// TODO: Add your command handler code here
	if(m_whiteEngine.GetEngineFlag() == TRUE)
	{
		CString msg = m_whiteEngineString + (CString)" Engine aready loaded";
		SetPaneText(MESSAGEPANE,msg,1);
		return;
	}
	CFileDialog fdialog(TRUE);
	if(fdialog.DoModal() == IDOK)
	{
		if(!m_whiteEngineString.IsEmpty())
		{
			m_whiteEngine.WriteToEngine("quit");
		}
		if(fdialog.GetFileExt() == "EXE" ||fdialog.GetFileExt() == "exe")
		{
			m_whiteEngineString = fdialog.GetFileName();
			m_whiteEngine.Initialize(m_whiteEngineString,this);	
		}
		else
			AfxMessageBox("Invalid Engine");
	}
}

void CNetChessView::OnToolsBlackengineLoad() 
{
	// TODO: Add your command handler code here
	if(m_blackEngine.GetEngineFlag() == TRUE)
	{
		CString msg = m_blackEngineString + (CString)" Engine aready loaded";
		AfxMessageBox(msg);
		return;
	}
	CFileDialog fdialog(TRUE);
	if(fdialog.DoModal() == IDOK)
	{
		if(!m_blackEngineString.IsEmpty())
		{
			m_blackEngine.WriteToEngine("quit");
		}
		if(fdialog.GetFileExt() == "EXE" ||fdialog.GetFileExt() == "exe")
		{
			m_blackEngineString = fdialog.GetFileName();
			m_blackEngine.Initialize(m_blackEngineString,this);	
		}
		else
			AfxMessageBox("Invalid Engine");
	}
}

void CNetChessView::OnToolsWhiteengineStart() 
{
	// TODO: Add your command handler code here	
	if(m_whiteEngine.GetEngineFlag() == TRUE)
	{
		CString msg = m_whiteEngineString + (CString)" Engine aready started";
		AfxMessageBox(msg);
		return;
	}
	if(Globalfirsttime == 0)
	{
		if(m_whiteEngine.m_engineConfigDlg.DoModal() == IDCANCEL)
			return;
	}
	m_whiteEngine.StartEngine();
	if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_I)
	
	{
		m_whiteEngine.WriteToEngine("xboard");
		CString str;
		str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
			m_engineLevelDlg.m_edit_time_control,
			m_engineLevelDlg.m_edit_conv_clock_mode);
		m_whiteEngine.WriteToEngine(str);
	}
	else if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
	{
		m_whiteEngine.WriteToEngine("xboard");
		m_whiteEngine.WriteToEngine("protover 2");
		CString str;
		str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
			m_engineLevelDlg.m_edit_time_control,
			m_engineLevelDlg.m_edit_conv_clock_mode);
		m_whiteEngine.WriteToEngine(str);
	}
	else if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == UCI_I ||
		m_whiteEngine.m_engineConfigDlg.m_chessProtocol == UCI_II)
	
	{
			m_whiteEngine.WriteToEngine("uci");
	}

	m_whiteEngine.m_engineType = WHITE;
}

void CNetChessView::OnToolsBlackengineStart() 
{
	// TODO: Add your command handler code here
	if(m_blackEngine.GetEngineFlag() == TRUE)
	{
		CString msg = m_blackEngineString + (CString)" Engine aready started";
		AfxMessageBox(msg);
		return;
	}
	if(Globalfirsttime == 0)
	{
		if(m_blackEngine.m_engineConfigDlg.DoModal() == IDCANCEL)
			return;;
	}
	m_blackEngine.StartEngine();
	if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_I)			
	{
		m_blackEngine.WriteToEngine("xboard");
		CString str;
		str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
			m_engineLevelDlg.m_edit_time_control,
			m_engineLevelDlg.m_edit_conv_clock_mode);
		m_blackEngine.WriteToEngine(str);
	}
	else if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
	{
		m_blackEngine.WriteToEngine("xboard");
		m_blackEngine.WriteToEngine("protover 2");
		CString str;
		str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
			m_engineLevelDlg.m_edit_time_control,
			m_engineLevelDlg.m_edit_conv_clock_mode);
		m_blackEngine.WriteToEngine(str);
	}
	else if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == UCI_I ||
		m_blackEngine.m_engineConfigDlg.m_chessProtocol == UCI_II)
	
	{
			m_blackEngine.WriteToEngine("uci");
	}

	m_blackEngine.m_engineType = BLACK;
}

void CNetChessView::OnToolsWhiteengineStop() 
{
	// TODO: Add your command handler code here
	m_whiteEngine.StopEngine();
}

void CNetChessView::OnToolsBlackengineStop() 
{
	// TODO: Add your command handler code here
	m_blackEngine.StopEngine();
}

void CNetChessView::OnToolsWhiteengineClose() 
{
	// TODO: Add your command handler code here
	m_white_radio_button_human.SetCheck(1);
	m_white_radio_button_computer.SetCheck(0);
	m_whiteEngine.CloseEngine();
	m_pauseclockFlag = TRUE;
	unsigned char data[2];
	data[0] = CLOCK;
	data[1] = m_pauseclockFlag;
	SendSockData(data,2);

}

void CNetChessView::OnToolsBlackengineClose() 
{
	// TODO: Add your command handler code here
	m_black_radio_button_human.SetCheck(1);
	m_black_radio_button_computer.SetCheck(0);
	m_blackEngine.CloseEngine();
	m_pauseclockFlag = TRUE;
	unsigned char data[2];
	data[0] = CLOCK;
	data[1] = m_pauseclockFlag;
	SendSockData(data,2);
}

void CNetChessView::OnToolsWhiteengineConfigure() 
{
	// TODO: Add your command handler code here
	m_whiteEngine.m_engineConfigDlg.DoModal();
}

void CNetChessView::OnToolsBlackengineConfigure() 
{
	// TODO: Add your command handler code here
	m_blackEngine.m_engineConfigDlg.DoModal();
	
}


void CNetChessView::OnUpdateToolsWhiteengineClose(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE  && m_whiteEngine.m_engineLoadedFlag == TRUE? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
}

void CNetChessView::OnUpdateToolsWhiteengineLoad(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE  && (m_whiteEngine.m_engineLoadedFlag == FALSE && m_whiteEngine.m_engineDefaultFlag == FALSE) ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
	m_whiteEngine.m_engineLoadedFlag == TRUE ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0);
}

void CNetChessView::OnUpdateToolsWhiteengineStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE  && m_whiteEngine.m_engineLoadedFlag == TRUE ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;
}

void CNetChessView::OnUpdateToolsWhiteengineStop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;
}

void CNetChessView::OnUpdateToolsBlackengineClose(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE && m_blackEngine.m_engineLoadedFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
}

void CNetChessView::OnUpdateToolsBlackengineLoad(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE  && (m_blackEngine.m_engineLoadedFlag == FALSE && m_blackEngine.m_engineDefaultFlag == FALSE) ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
	m_blackEngine.m_engineLoadedFlag == TRUE  ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0) ;	
}

void CNetChessView::OnUpdateToolsBlackengineStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE && m_blackEngine.m_engineLoadedFlag == TRUE ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
}

void CNetChessView::OnUpdateToolsBlackengineStop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
}

void CNetChessView::OnUpdateToolsWhiteengineConfigure(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;
}

void CNetChessView::OnUpdateToolsBlackengineConfigure(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
}

void CNetChessView::OnToolsWhiteengineLog() 
{
	// TODO: Add your command handler code here
	CEngineLogDlg *dlg = new CEngineLogDlg();
	dlg->Create(IDD_DIALOG_ENGINE_LOG,this);
	dlg->m_edit_engine_log = m_whiteEngine.m_engineLog;
	dlg->m_pEngine = &m_whiteEngine;
	//dlg.DoModal();
	if(m_whiteEngine.m_engineFile.GetLength() > 0)
		dlg->SetWindowText("WHITE: " + m_whiteEngine.m_engineFile);
	dlg->ShowWindow(SW_SHOW);
	dlg->UpdateData(FALSE);
	/*CEngineLogDlg dlg;
	dlg.m_edit_engine_log = m_whiteEngine.m_engineLog;
	dlg.m_pEngine = &m_whiteEngine;
	dlg.DoModal();*/
	
}

void CNetChessView::OnUpdateToolsWhiteengineLog(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;
}

void CNetChessView::OnToolsBlackengineLog() 
{
	// TODO: Add your command handler code here

	CEngineLogDlg *dlg = new CEngineLogDlg();
	dlg->Create(IDD_DIALOG_ENGINE_LOG,this);
	dlg->m_edit_engine_log = m_blackEngine.m_engineLog;
	dlg->m_pEngine = &m_blackEngine;
	if(m_blackEngine.m_engineFile.GetLength() > 0)
		dlg->SetWindowText("BLACK: " +m_blackEngine.m_engineFile);
	//dlg.DoModal();
	dlg->ShowWindow(SW_SHOW);
	dlg->UpdateData(FALSE);
}

void CNetChessView::OnUpdateToolsBlackengineLog(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
}

void CNetChessView::OnToolsBlackengineMovenow() 
{
	// TODO: Add your command handler code here	
	
	if(m_blackAsEngineFlag == TRUE)
	{
		if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == UCI_I || 
			m_blackEngine.m_engineConfigDlg.m_chessProtocol == UCI_II)
		{
			int movecount = m_iHistory/2;
			char side;
			if(m_pClientSocket == NULL)
			  side = m_pieceSide == WHITE ? 'b' : 'w';
			else
			{
				if(m_pieceSide == WHITE && m_player_turn == true ||
					m_pieceSide == BLACK && m_player_turn == false)
					side = 'w';
				else if(m_pieceSide == WHITE && m_player_turn == false ||
					m_pieceSide == BLACK && m_player_turn == true)
					side = 'b';
			}
			CString str = GetPositionString('F',movecount,side);
			SetEnginePosition(m_blackEngine, str);			
		}
		else
		{
			//m_blackEngine.WriteToEngine("?");

			m_blackEngine.WriteToEngine("go");
		}
	/*	m_black_radio_button_computer.SetCheck(1);
		m_black_radio_button_human.SetCheck(0);*/
	}
	m_pauseclockFlag = FALSE;
	unsigned char data[2];
	data[0] = CLOCK;
	data[1] = m_pauseclockFlag;
	SendSockData(data,2);
}

void CNetChessView::OnUpdateToolsBlackengineMovenow(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE  && m_blackEngine.m_engineFlag == TRUE? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
}

/*void CNetChessView::OnToolsBlackenginesettingsBlackasengine() 
{
	// TODO: Add your command handler code here		
	m_blackAsEngineFlag = m_blackAsEngineFlag == TRUE ? FALSE : TRUE;
	
}*/

/*void CNetChessView::OnUpdateToolsBlackenginesettingsBlackasengine(CCmdUI* pCmdUI) 
{
	if(m_pClientSocket != NULL && m_pieceSide == WHITE)
	{
		pCmdUI->Enable(0);		
	}	
	else
	{
		m_blackAsEngineFlag == TRUE  ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0) ;
	}
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);
}*/

/*void CNetChessView::OnToolsWhiteenginesettingsWhiteasengine() 
{
	// TODO: Add your command handler code here
	m_whiteAsEngineFlag = m_whiteAsEngineFlag == TRUE ? FALSE : TRUE;
	
}*/




void CNetChessView::OnToolsWhiteengineMovenow() 
{
	// TODO: Add your command handler code here
	if(m_whiteAsEngineFlag == TRUE)
	{
		if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == UCI_I ||
			m_whiteEngine.m_engineConfigDlg.m_chessProtocol == UCI_II)
		{
			
			int movecount = m_iHistory/2;
			char side;
			if(m_pClientSocket == NULL)
			  side = m_pieceSide == WHITE ? 'b' : 'w';
			else
			{
				if(m_pieceSide == WHITE && m_player_turn == true ||
					m_pieceSide == BLACK && m_player_turn == false)
					side = 'w';
				else
					side = 'b';
			}			
			CString str = GetPositionString('F',movecount,side);
			SetEnginePosition(m_whiteEngine, str);			
		}
		else
		{
			//m_whiteEngine.WriteToEngine("?");
			m_whiteEngine.WriteToEngine("go");
		}	
	}	
	m_pauseclockFlag = FALSE;
	unsigned char data[2];
	data[0] = CLOCK;
	data[1] = m_pauseclockFlag;
	SendSockData(data,2);
}

void CNetChessView::OnUpdateToolsWhiteengineMovenow(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE && m_whiteEngine.m_engineFlag == TRUE ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;
	
}

void CNetChessView::OnViewLog() 
{
	// TODO: Add your command handler code here
	CNetChessLogDlg dlg;
	CString filename = ".\\" + m_edit_name + "_Log.txt";
	CFile file;
	if(file.Open(filename,CFile::modeRead| CFile::shareDenyNone) ==0)
	{
		CString str = "Could not open the log file "+ filename;
		AfxMessageBox(str);
		return;
	};
	/*if(file.GetLength() > 64 *1024)
	{
		CString str = filename + (CString)" file size is greater than 64K, Could not open the file";
		AfxMessageBox(str);
		return;
	}*/
	char *buf = (char*)malloc(64*1024);
	memset(buf,'\0',64*1024);
	file.Read(buf, 64*1024);
	file.Close();
	dlg.m_edit_netchess_log = buf;
	free(buf);
	buf = NULL;
	dlg.DoModal();
}


void CNetChessView::OnFileNewgame() 
{
	// TODO: Add your command handler code here

	m_blackTime = m_whiteTime = m_engineLevelDlg.m_edit_time_control == 0? 5*60: m_engineLevelDlg.m_edit_time_control*60;
	m_startTime = time(0);	
	if(OnFileNewAction() == 0)
	{
		unsigned char data=NEWGAME;
		SendSockData(&data,1);
	}

}

void CNetChessView::OnUpdateFileNewgame(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_observerFlag == TRUE ? pCmdUI->Enable(FALSE) : pCmdUI->Enable(TRUE);	
}



void CNetChessView::OnToolsBlackengineSettingsBlackasengine() 
{
	// TODO: Add your command handler code here
	
	if(m_pClientSocket != NULL && m_pieceSide == WHITE)
		return;
	if((m_pClientICSSocket != NULL) && (m_whiteAsEngineFlag == TRUE))
	{
		//ONLY ONE ENGINE CAN PLAY WITH ICS
		AfxMessageBox("ICS and White engine are playing");
		return;
	}
	m_blackAsEngineFlag = m_blackAsEngineFlag == TRUE ? FALSE : TRUE;

}

void CNetChessView::OnUpdateToolsBlackengineSettingsBlackasengine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if(m_pClientSocket != NULL && m_pieceSide == WHITE)
	{
		pCmdUI->SetCheck(0);
		pCmdUI->Enable(0);	
	}	
	else
	{
		m_blackAsEngineFlag == TRUE  ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0) ;
	}
	if(m_observerFlag == TRUE)
	{
		pCmdUI->Enable(FALSE);
	}
	
}

void CNetChessView::OnToolsWhiteengineSettingsWhiteasengine() 
{
	// TODO: Add your command handler code here
	
	if(m_pClientSocket != NULL && m_pieceSide == BLACK)
		return;
	if((m_pClientICSSocket != NULL) && (m_blackAsEngineFlag == TRUE))
	{
		//ONLY ONE ENGINE CAN PLAY WITH ICS
		AfxMessageBox("ICS and Black engine are playing");
		return;
	}
	m_whiteAsEngineFlag = m_whiteAsEngineFlag == TRUE ? FALSE : TRUE;	
}

void CNetChessView::OnUpdateToolsWhiteengineSettingsWhiteasengine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// TODO: Add your command update UI handler code here
	
	if(m_pClientSocket != NULL && m_pieceSide == BLACK)
	{
		pCmdUI->SetCheck(0);
		pCmdUI->Enable(0);		
	}	
	else
	{	
		m_whiteAsEngineFlag == TRUE  ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0) ;
	}
	if(m_observerFlag == TRUE)
	{
		pCmdUI->Enable(FALSE);
	}
}


void CNetChessView::OnWhiteenginePonder() 
{
	// TODO: Add your command handler code here
	m_whiteEngine.m_pondorFlag = m_whiteEngine.m_pondorFlag == TRUE ? FALSE : TRUE;
	if(	m_whiteEngine.m_pondorFlag == TRUE)
	{
		if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_I ||
			m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
		{	
			m_whiteEngine.WriteToEngine("hard");	
			m_whiteEngine.WriteToEngine("post");	
		}
		else
		{
			m_whiteEngine.WriteToEngine("setoption name Pondor value true");	
		}
	}
	else
	{
		if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_I ||
			m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
		{	
			m_whiteEngine.WriteToEngine("nopost");		
			m_whiteEngine.WriteToEngine("easy");		
		}
		else
		{
			m_whiteEngine.WriteToEngine("setoption name Pondor value false");	
		}
	}
}

void CNetChessView::OnUpdateWhiteenginePonder(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE && m_whiteEngine.m_engineFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;		
	m_whiteEngine.m_pondorFlag == TRUE ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0);
	
}

void CNetChessView::OnBlackenginePondor() 
{
	// TODO: Add your command handler code here
	m_blackEngine.m_pondorFlag = m_blackEngine.m_pondorFlag == TRUE ? FALSE : TRUE;

	if(	m_blackEngine.m_pondorFlag == TRUE)
	{
		if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_I ||
			m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
		{		
			m_blackEngine.WriteToEngine("hard");	
			m_blackEngine.WriteToEngine("post");	
		}
		else
		{
			m_blackEngine.WriteToEngine("setoption name Pondor value true");				
		}
	}
	else
	{
		if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_I ||
			m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
		{		
		
			m_blackEngine.WriteToEngine("nopost");	
			m_blackEngine.WriteToEngine("easy");	
		}
		else
		{
			m_blackEngine.WriteToEngine("setoption name Pondor value false");				
		}
	}
	
}

void CNetChessView::OnUpdateBlackenginePondor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE && m_blackEngine.m_engineFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;		
	m_blackEngine.m_pondorFlag == TRUE ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0);

}

void CNetChessView::OnEditLevels() 
{
	// TODO: Add your command handler code here
	if( m_engineLevelDlg.DoModal() == IDOK)
	{
		if(m_blackAsEngineFlag == TRUE)
		{
			CString str;
			str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
				m_engineLevelDlg.m_edit_time_control,
				m_engineLevelDlg.m_edit_conv_clock_mode);

			if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_I)			
			{
				m_blackEngine.WriteToEngine(str);
			}
			else if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
			{			
				m_blackEngine.WriteToEngine(str);
			}
		}

		if(m_whiteAsEngineFlag == TRUE)
		{
			CString str;
			str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
				m_engineLevelDlg.m_edit_time_control,
				m_engineLevelDlg.m_edit_conv_clock_mode);
		
			if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_I)			
			{
				m_whiteEngine.WriteToEngine(str);
			}
			else if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
			{
				m_whiteEngine.WriteToEngine(str);
			}
		}
	}
}

void CNetChessView::OnUpdateEditLevels(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CNetChessView::OnWhiteengineAnalyze() 
{
	// TODO: Add your command handler code here
	m_whiteEngine.m_analyzeFlag = m_whiteEngine.m_analyzeFlag == TRUE ? FALSE : TRUE;
	if(m_whiteAsEngineFlag == TRUE)
	{
		if(m_whiteEngine.m_analyzeFlag == TRUE)
		{
			if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_I)			
			{
				m_whiteEngine.WriteToEngine("analyze");
			}
			else if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
			{
				m_whiteEngine.WriteToEngine("analyze");
			}
			else
			{
				m_whiteEngine.WriteToEngine("setoption name analyze value true");
			}
		}
		else
		{
			if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_I)			
			{
				m_whiteEngine.WriteToEngine("exit");
			}
			else if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
			{
				m_whiteEngine.WriteToEngine("exit");
			}
		}
	}
}

void CNetChessView::OnUpdateWhiteengineAnalyze(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE && m_whiteEngine.m_engineFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;		
	m_whiteEngine.m_analyzeFlag == TRUE ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0);
	
}

void CNetChessView::OnBlackengineAnalyze() 
{
	// TODO: Add your command handler code here
	m_blackEngine.m_analyzeFlag = m_blackEngine.m_analyzeFlag == TRUE ? FALSE : TRUE;
	if(m_blackAsEngineFlag == TRUE)
	{
		if(m_blackEngine.m_analyzeFlag == TRUE)
		{
			if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_I)			
			{
				m_blackEngine.WriteToEngine("analyze");
			}
			else if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
			{
				m_blackEngine.WriteToEngine("analyze");
			}
			else
			{
				m_blackEngine.WriteToEngine("setoption name analyze value true");
			}
		}
		else
		{
			if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_I)			
			{
				m_blackEngine.WriteToEngine("exit");
			}
			else if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
			{
				m_blackEngine.WriteToEngine("exit");
			}
		}
	}
	
}

void CNetChessView::OnUpdateBlackengineAnalyze(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE && m_blackEngine.m_engineFlag == TRUE  ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;		
	m_blackEngine.m_analyzeFlag == TRUE ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0);

}

void CNetChessView::OnWhiteengineDefault() 
{
	// TODO: Add your command handler code here
	//if(!m_optDlg.m_edit_def_white_engine.IsEmpty()== TRUE)
	{
		
		/*if(!m_optDlg.m_edit_def_white_engine.IsEmpty())
		{
			m_whiteEngine.Initialize(m_optDlg.m_edit_def_white_engine,this);	
		}
		else
		{
			char directory[1000];
			memset(directory,'\0',1000);
			GetCurrentDirectory(1000,directory);
			AfxMessageBox(directory);
			CString str = (CString)directory + (CString)"\\crafty\\crafty_1920.exe";
			//AfxMessageBox(str);
			m_optDlg.m_edit_def_white_engine = str;
			m_optDlg.m_whiteEngineProtocol = WB_II;
			m_whiteEngine.Initialize(str,this);			
		}*/
		m_whiteEngine.m_engineDefaultFlag = m_whiteEngine.m_engineDefaultFlag == TRUE ? FALSE : TRUE;
		OnButtonWhiteRadioButtonComputer();
		/*CString str = "Default engine " + m_optDlg.m_edit_def_white_engine + " Loaded";		
		AfxMessageBox(str);*/
	}
//	else
//	{
//		AfxMessageBox("Wrong default engine settings, check in Edit->Preferences");
//	}
}

void CNetChessView::OnUpdateWhiteengineDefault(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE  && (m_whiteEngine.m_engineLoadedFlag == FALSE && m_whiteEngine.m_engineDefaultFlag == FALSE) ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;
	m_whiteEngine.m_engineDefaultFlag == TRUE  ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0) ;	
	
}

void CNetChessView::OnBlackengineDefault() 
{
	// TODO: Add your command handler code here
	//if(!m_optDlg.m_edit_def_white_engine.IsEmpty()== TRUE)
	{
		/*if(!m_optDlg.m_edit_def_black_engine.IsEmpty())
		{
			m_blackEngine.Initialize(m_optDlg.m_edit_def_black_engine,this);
		}
		else
		{
			char directory[1000];
			memset(directory,'\0',1000);
			GetCurrentDirectory(1000,directory);
			AfxMessageBox(directory);
			CString str;
			str = (CString)directory + (CString)"\\crafty\\crafty_1920.exe";
			m_optDlg.m_edit_def_black_engine = str;
			m_optDlg.m_blackEngineProtocol = WB_II;
			//AfxMessageBox(str);
			m_blackEngine.Initialize(str,this);			
		}*/
		m_blackEngine.m_engineDefaultFlag = m_blackEngine.m_engineDefaultFlag == TRUE ? FALSE : TRUE;
		/*CString str = "Default engine " + m_optDlg.m_edit_def_black_engine + " Loaded";		
		AfxMessageBox(str);*/
		OnButtonBlackRadioButtonComputer();
	}
	/*else
	{
		AfxMessageBox("Wrong default engine settings, check in Edit->Preferences");
	}*/	
}

void CNetChessView::OnUpdateBlackengineDefault(CCmdUI* pCmdUI) 
{
	m_blackAsEngineFlag == TRUE  && (m_blackEngine.m_engineLoadedFlag == FALSE && m_blackEngine.m_engineDefaultFlag == FALSE) ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;
	m_blackEngine.m_engineDefaultFlag == TRUE  ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0) ;	
	// TODO: Add your command update UI handler code here
	
}

void CNetChessView::OnEditGamestate() 
{
	CGameStateInfoDlg dlg;
	
	dlg.m_check_black_king = m_blackKingMovedFlag == false ? FALSE : TRUE;
	dlg.m_check_black_O_O = m_blackKingMovedFlag == true || m_blackRookRank7MovedFlag == true ? FALSE : TRUE;
	dlg.m_check_black_O_O_O = m_blackKingMovedFlag == true || m_blackRookRank1MovedFlag == true ? FALSE : TRUE;
	dlg.m_check_black_rook_a = m_blackRookRank1MovedFlag == false ? FALSE : TRUE;
	dlg.m_check_black_root_h = m_blackRookRank7MovedFlag == false ? FALSE : TRUE;
	dlg.m_check_white_king = m_whiteKingMovedFlag == false ? FALSE : TRUE;;
	dlg.m_check_white_O_O = m_whiteKingMovedFlag == true || m_whiteRookRank7MovedFlag == true ? FALSE : TRUE;
	dlg.m_check_white_O_O_O = m_whiteKingMovedFlag == true || m_whiteRookRank1MovedFlag == true ? FALSE : TRUE;
	dlg.m_check_white_rook_a = m_whiteRookRank1MovedFlag == false ? FALSE : TRUE;
	dlg.m_check_white_rook_h = m_whiteRookRank7MovedFlag == false ? FALSE : TRUE;
	dlg.m_pieceSide = m_pieceSide;
	if(dlg.DoModal() == IDOK)
	{
		m_blackKingMovedFlag = dlg.m_check_black_king == FALSE ? false : true;
		m_blackRookRank1MovedFlag = dlg.m_check_black_rook_a == FALSE? false : true;
		m_blackRookRank7MovedFlag = dlg.m_check_black_root_h == FALSE? false : true;
		m_whiteKingMovedFlag = dlg.m_check_white_king == FALSE? false : true;
		m_whiteRookRank1MovedFlag = dlg.m_check_white_rook_a == FALSE? false : true;
		m_whiteRookRank7MovedFlag = dlg.m_check_white_rook_h == FALSE? false : true;
		AfxMessageBox("Changed game state, Use Edit->Manual Edit->Player Turn to chage Player's turn");
	}
}

void CNetChessView::OnBlackengineReload() 
{
	// TODO: Add your command handler code here
	m_blackEngineString = m_blackEngine.m_engineFile;
	m_blackEngine.CloseEngine();	
	m_blackEngine.Initialize(m_blackEngineString,this);	
	
	if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == NOPROTOCOL)
	{
		if(m_blackEngine.m_engineConfigDlg.DoModal() == IDCANCEL)
			return;;
	}
	m_blackEngine.StartEngine();
	if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_I)			
	{
		m_blackEngine.WriteToEngine("xboard");
		CString str;
		str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
			m_engineLevelDlg.m_edit_time_control,
			m_engineLevelDlg.m_edit_conv_clock_mode);
		m_blackEngine.WriteToEngine(str);
	}
	else if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
	{
		m_blackEngine.WriteToEngine("xboard");
		m_blackEngine.WriteToEngine("protover 2");
		CString str;
		str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
			m_engineLevelDlg.m_edit_time_control,
			m_engineLevelDlg.m_edit_conv_clock_mode);
		m_blackEngine.WriteToEngine(str);
	}
	else if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == UCI_I ||
		m_blackEngine.m_engineConfigDlg.m_chessProtocol == UCI_II)
	
	{
			m_blackEngine.WriteToEngine("uci");
	}

	m_blackEngine.m_engineType = BLACK;
	

	m_blackEngine.m_engineType = WHITE;
	CString str= m_blackEngineString + " Engine reloaded";
	AfxMessageBox(str);
}

void CNetChessView::OnUpdateBlackengineReload(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE  && (m_blackEngine.m_engineLoadedFlag == TRUE || m_blackEngine.m_engineDefaultFlag == TRUE) ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;		
}

void CNetChessView::OnWhiteengineReload() 
{
	// TODO: Add your command handler code here
	m_whiteEngineString = m_whiteEngine.m_engineFile;
	m_whiteEngine.CloseEngine();
	m_whiteEngine.Initialize(m_whiteEngineString,this);
	if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == NOPROTOCOL)
	{
		if(m_whiteEngine.m_engineConfigDlg.DoModal() == IDCANCEL)
			return;
	}
	m_whiteEngine.StartEngine();
	if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_I)
	
	{
		m_whiteEngine.WriteToEngine("xboard");
		CString str;
		str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
			m_engineLevelDlg.m_edit_time_control,
			m_engineLevelDlg.m_edit_conv_clock_mode);
		m_whiteEngine.WriteToEngine(str);
	}
	else if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
	{
		m_whiteEngine.WriteToEngine("xboard");
		m_whiteEngine.WriteToEngine("protover 2");
		CString str;
		str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
			m_engineLevelDlg.m_edit_time_control,
			m_engineLevelDlg.m_edit_conv_clock_mode);
		m_whiteEngine.WriteToEngine(str);
	}
	else if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == UCI_I ||
		m_whiteEngine.m_engineConfigDlg.m_chessProtocol == UCI_II)
	
	{
			m_whiteEngine.WriteToEngine("uci");
	}

	m_whiteEngine.m_engineType = WHITE;
	CString str= m_whiteEngineString + " Engine reloaded";
	AfxMessageBox(str);
}

void CNetChessView::OnUpdateWhiteengineReload(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE  && (m_whiteEngine.m_engineLoadedFlag == TRUE || m_whiteEngine.m_engineDefaultFlag == TRUE) ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;		

}

void CNetChessView::OnToolsAreyouok() 
{
	// TODO: Add your command handler code here
	unsigned char data1[5];
	data1[0] = ARE_YOU_OK;
	memcpy(&data1[1],&((CClientSocket*)m_pClientSocket)->m_clientId,4);
	SendSockData(data1,5);
}

void CNetChessView::OnUpdateToolsAreyouok(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_pClientSocket != NULL ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;		
}

void CNetChessView::OnViewLearning() 
{
	// TODO: Add your command handler code here
	m_learningFlag = m_learningFlag == FALSE ? TRUE : FALSE;
}

void CNetChessView::OnUpdateViewLearning(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_learningFlag == FALSE ? pCmdUI->SetCheck(0) : pCmdUI->SetCheck(1);
}
void CNetChessView::SetLearning(int flag)
{
	int flipflag = FALSE;
	if(m_white_on_top == true)
	{
		m_white_on_top = false;
		m_point.x = 7 - m_point.x;
		m_point.y = 7 - m_point.y;
		FlipBoard();
		flipflag = TRUE;						
	}
	if(flag == TRUE)	
	{
		for(int i=0;i<8;i++)
		{
			for(int j = 0;j<8;j++)
			{
				if(cb[i][j].GetPieceColor() != cb[m_point.x][m_point.y].GetPieceColor())
				{
					bool tempblackKingMoveFlag = m_blackKingMovedFlag;
					bool tempwhiteKingMoveFlag = m_whiteKingMovedFlag;
					if(flipflag == TRUE)
					{
						if(CheckValidMove(i,j) == true)
						{
							cb[7-i][7-j].SetLearningFlag( TRUE );
						}
					}
					else
					{
						if(CheckValidMove(i,j) == true)
						{
							cb[i][j].SetLearningFlag( TRUE );
						}
					}
					m_blackKingMovedFlag = tempblackKingMoveFlag;
					m_whiteKingMovedFlag = tempwhiteKingMoveFlag;
				}
			}
		}
	}
	else
	{
		for(int i=0;i<8;i++)
		{
			for(int j = 0;j<8;j++)
			{
				cb[i][j].SetLearningFlag( FALSE );
			}
		}
	}
	if(flipflag == TRUE)
	{
		m_white_on_top = true;
		m_point.x = 7 - m_point.x;
		m_point.y = 7 - m_point.y;		
		FlipBoard();		
	}
}

void CNetChessView::OnEditEntermove() 
{
	// TODO: Add your command handler code here
	
	CEnterMoveDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		PGNMove(dlg.m_edit_move.GetBuffer(0), m_pieceSide == WHITE? WHITE: BLACK);
	}
	
}

void CNetChessView::OnIcsConfigure() 
{
	// TODO: Add your command handler code here
	if((m_blackAsEngineFlag == TRUE) && m_whiteAsEngineFlag == TRUE)
	{
		//ONLY ONE ENGINE CAN PLAY WITH ICS
		AfxMessageBox("Black and White engine are playing");
		return;
	}
	if(m_pICSConfigureDlg == NULL)
	{
		m_pICSConfigureDlg = new CICSConfigureDlg();
		m_pICSConfigureDlg->Create(IDD_DIALOG_ICS_CONFIGURE,this);
	}
	
	m_pICSConfigureDlg->ShowWindow(SW_SHOW);
	m_pICSConfigureDlg->UpdateData(FALSE);
	m_pICSConfigureDlg->SetView(this);
//	m_icsClient.m_icsConfigureDlg.DoModal();
}

void CNetChessView::ConnectToICSServer()
{
	
}

void CNetChessView::OnIcsWindow() 
{
	// TODO: Add your command handler code here
	//CString str = "GuestJMQL (++++) seeking 5 0 unrated blitz f (\"play 109\" to respond)";

	
	if(m_pICSWindowDlg == NULL)
	{		
		m_pICSWindowDlg = new CICSWindowDlg();
		m_pICSWindowDlg->Create(IDD_DIALOG_ICS_WINDOWS,this);
		m_pICSWindowDlg->SetView(this);
	}
	//dlg->Create(IDD_DIALOG_ICS_WINDOWS,this);
	if(m_pClientICSSocket != NULL)
	{
		CString str = "set interface NetChess by AVM RAO\r\n";
		m_pClientICSSocket->Send(str.GetBuffer(0),str.GetLength());
		str = "set style 12\r\n";
		m_pClientICSSocket->Send(str.GetBuffer(0),str.GetLength());
	}
	m_pICSWindowDlg->ShowWindow(SW_SHOW);
	m_pICSWindowDlg->UpdateData(FALSE);	
	m_pICSWindowDlg->m_pICSClient = &m_icsClient;
	
	//m_icsClient.Initialize(this);
}
void CNetChessView::HandleICSData(CString str)
{
	//parse ICS Server data
	int index = -1;
	/*if(str.Find("Creating") >=0 )
	{
		//Game accepted, now parse the game to start
		int index;
		if(index = str.Find("<12>") >= 0)
		{			
			CString newstr = str.Left(str.GetLength() - index + 1);
			//char *data = newstr.GetBuffer(0);
			ReadICSMessage(newstr);
			//This is the format for the 
			
		}
	}
	else */
	//CString str = data;
	/*handle who data, only for testing*/

	
	
	if((index = str.Find("<12>")) >= 0)
	{
		CString newstr = str.Right(str.GetLength() - index + 1);
		//char *data = newstr.GetBuffer(0);
		ReadICSMessage(newstr);
		//This is the format for the 
		if(m_pICSWindowDlg != NULL)
		{
			str.Replace("\n","\r\n");
			m_pICSWindowDlg->m_edit_ics_log = m_pICSWindowDlg->m_edit_ics_log + str;		
			m_pICSWindowDlg->Update(IDC_EDIT_ICS_LOG);
		}
			
	}
	else if(str.Find("login:") >=0)
	{	
		m_pICSConfigureDlg->Login();
		if(m_pICSWindowDlg != NULL)
		{
			str.Replace("\n","\r\n");
			m_pICSWindowDlg->m_edit_ics_log = m_pICSWindowDlg->m_edit_ics_log + str;		
			m_pICSWindowDlg->Update(IDC_EDIT_ICS_LOG);
		}
	}
	else if( int index2 = str.Find("seeking") >= 0)
	{
		char p[7][100];
		
		//CString str1 = str.Right(str.GetLength() - index2);
		sscanf(str.GetBuffer(0),"%s %s %s %s %s %s %s",p[0],p[1],p[2],p[3],p[4],p[5], p[6]);
		
		if(m_pICSWindowDlg != NULL)
		{
			CWnd* wnd = m_pICSWindowDlg->GetDlgItem(IDC_EDIT_PLAY_TYPE);
			CString st;
			st.Format("%s %s",p[5],p[6]);
			wnd->SetWindowText(st);
		}
		int index = 0;
		if((index = str.Find("play")) >= 0)
		{
			CString right = str.Right(str.GetLength() - index);
			
			int index2 = 0;
			index2 = right.Find("\"");
			CString temp = right.Mid(5,index2 - 5);			
			int player_index = atoi(temp.GetBuffer(0));
			if(m_seekListDlg != NULL)
			{
				CString st;
				st.Format("%s %s",p[5],p[6]);
				m_seekListDlg->InsertSeek(st,player_index);
			}
			if(m_pICSWindowDlg != NULL)
			{
				str.Replace("\n","\r\n");
				CWnd* wnd = m_pICSWindowDlg->GetDlgItem(IDC_EDIT_PLAY);
				wnd->SetWindowText(temp);
				m_pICSWindowDlg->m_edit_message = m_pICSWindowDlg->m_edit_message + str;
				m_pICSWindowDlg->Update(IDC_EDIT_MESSAGE);
			}
		}
	} 
	else if(str.Find("Logging you in as") >= 0)
	{
		int index = str.Find("\"");
		if(index >= 0)
		{
			str = str.Right(str.GetLength() - index - 1);
			index = str.Find("\"");
			str = str.Left(index);
			SetPaneText(PLAYERNAME,str);	
			if(m_pICSConfigureDlg != NULL)
			{
				m_pICSConfigureDlg->m_static_myname = str;
				CWnd* wnd = m_pICSConfigureDlg->GetDlgItem(IDC_STATIC_MYNAME);
				wnd->SetWindowText(str);

			}
			if(m_pICSWindowDlg !=  NULL)
				m_pICSWindowDlg->m_myName = str;

		}
	}
	else if(str.Find("resigns") >= 0)
	{
		AfxMessageBox(str);
	}
	else if(str.Find("Game aborted") >= 0)
	{
		AfxMessageBox(str);
	}	
	else if(str.Find("tells you:") >= 0)
	{
		if(m_icsChatDlg != NULL)
		{
			m_icsChatDlg->SetReceiveData((unsigned char*)str.GetBuffer(0));
			m_icsChatDlg->ShowWindow(SW_SHOW);
		}
	}
	else
	{
		if(m_pICSWindowDlg != NULL)
		{
			/*CString str = "set style 12\r\n";
			m_pClientICSSocket->Send(str.GetBuffer(0),str.GetLength());*/
			str.Replace("\n","\r\n");
			m_pICSWindowDlg->m_edit_message = m_pICSWindowDlg->m_edit_message + str;
			m_pICSWindowDlg->Update(IDC_EDIT_MESSAGE);
		}
	}
	 //m_icsClient.m_icsLog += str;
}
void CNetChessView::ReadICSMessage(CString str)
{
	char *data = str.GetBuffer(0);
	//char *data = "<12> rnbqkbnr pppppppp -------- -------- -------- -------- PPPPPPPP RNBQKBNR W -1 1 1 1 1 0 319 GuestYZMC GuestGGRS -1 5 12 39 39 300 300 1 none (0:00) none 1 0 0";
	ICSMsgStruct msg;
	//<12> rnbqkbnr pppppppp -------- -------- -------- -------- PPPPPPPP RNBQKBNR W -1 1 1 1 1 0 319 GuestYZMC GuestGGRS -1 5 12 39 39 300 300 1 none (0:00) none 1 0 0
	sscanf(data,"%s %s %s %s %s %s %s %s %s %c %d %d %d %d %d %d %d %s %s %d %d %d %d %d %d %d %d %s %s %s %d %d %d",
		msg.style,msg.boardString[0], msg.boardString[1], msg.boardString[2], msg.boardString[3], msg.boardString[4], msg.boardString[5], msg.boardString[6], msg.boardString[7],
		&msg.playerSide, &msg.dataset1[0],&msg.dataset1[1], &msg.dataset1[2], &msg.dataset1[3], &msg.dataset1[4], &msg.dataset1[5], &msg.dataset1[6],
		msg.firstplayername, msg.secondplayername, &msg.dataset2[0],&msg.dataset2[1], &msg.dataset2[2], &msg.dataset2[3], &msg.dataset2[4], &msg.dataset2[5], &msg.dataset2[6],&msg.dataset2[7],
		msg.moveNotation, msg.time, msg.PGNMoveNotation,&msg.dataset3[0],&msg.dataset3[1], &msg.dataset3[2]);
	m_gameInfoDlg.m_edit_white = msg.firstplayername;
	m_gameInfoDlg.m_edit_black = msg.secondplayername;	
	if(m_pICSConfigureDlg != NULL)
	{
		if(m_pICSConfigureDlg->m_static_myname == msg.firstplayername)
		{
			m_pICSConfigureDlg->m_opponent_name = msg.secondplayername;
		}
		else
		{
			m_pICSConfigureDlg->m_opponent_name = msg.firstplayername;
		}
	}
	m_whiteTime = msg.dataset2[5];
	m_blackTime = msg.dataset2[6];
	CString msgstr;
	ParseICSStyle12Message(msg,msgstr);
	if(m_pICSWindowDlg != NULL)
	{
		if(m_pICSWindowDlg->m_check_expand_move == TRUE)
		{		
			m_pICSWindowDlg->m_edit_message = m_pICSWindowDlg->m_edit_message + msgstr;
			CWnd* wnd = m_pICSWindowDlg->GetDlgItem(IDC_EDIT_MESSAGE);
			wnd->SetWindowText(m_pICSWindowDlg->m_edit_message);
		}
	}
	if(strcmp(msg.PGNMoveNotation,"none") == 0)
	{
		AfxMessageBox(msgstr);
	}
	else
	{			
		if(m_BoardToICSFlag == FALSE)
		{			
			m_ICSToBoardFlag = TRUE;
//			m_moveFlag = TRUE;
			if(m_whiteAsEngineFlag == TRUE)
				m_whiteEngine.SetEngineTime(msg.dataset2[5],msg.dataset2[6]);
			if(m_blackAsEngineFlag == TRUE)
				m_blackEngine.SetEngineTime(msg.dataset2[6],msg.dataset2[5]);
			CString boardmove = GetSingleMoveString(m_iHistory);
			//if(m_iHistory < 0)
			if(m_moveFlag == FALSE)
			{
				PGNMove(msg.PGNMoveNotation, m_pieceSide);
				
			}	
			m_moveFlag = FALSE;
			//SendToEngine((unsigned char*)data, str.GetLength());				
			
			/*else
			{
				//COLOR_TYPE ct = m_History[m_iHistory].GetFromPieceColorType();
				CString st = msg.PGNMoveNotation;
				//if((!(ct == WHITE && msg.playerSide == 'W') ||
				//	!(ct == BLACK && msg.playerSide == 'B'))
				{

					PGNMove(msg.PGNMoveNotation, m_pieceSide);
				}
			}*/			
		}
		m_BoardToICSFlag = FALSE;
	}
}
void CNetChessView::ParseICSStyle12Message(ICSMsgStruct msg, CString &str)
{	
	str = "**********Message Info analyzed by NetChess***********\r\n";
	if(msg.playerSide == 'W')
		str = str + "It is White turn to move\r\n";
	else
		str = str + "It is Black turn to move\r\n";

	if(msg.dataset1[0] == -1)
		str = str + "Double Pawn push\r\n";
	if(msg.dataset1[1] == 1)
		str = str + "White still can castle(short side)\r\n";
	else
		str = str + "White can not castle(short side)\r\n";

	if(msg.dataset1[2] == 1)
		str = str + "White still can castle(long side)\r\n";
	else
		str = str + "White can not castle(long side)\r\n";

	if(msg.dataset1[3] == 1)
		str = str + "Black still can castle(short side)\r\n";
	else
		str = str + "Black can not castle(short side)\r\n";

	if(msg.dataset1[4] == 1)
		str = str + "Black still can castle(long side)\r\n";
	else
		str = str + "Black can not castle(long side)\r\n";
	
	CString tempstr;
	tempstr.Format("the number of moves made since the last irreversible move are %d\r\n",msg.dataset1[5]); 
	str = str + tempstr;

	tempstr.Format("the game number %d\r\n",msg.dataset1[6]);
	str = str + tempstr;
	str = str + "White's player name: " + msg.firstplayername + "\r\n";
	str = str + "Black's player name: " + msg.secondplayername + "\r\n";
	//my relation to game
	switch(msg.dataset2[0])
	{
		case -3:
			str = str + "isolated position\r\n";
			break;
		case -2:
			str = str + "I am observing game being examined\r\n";
			break;
		case 2:
			str = str + "I am the examiner of this game\r\n";
			break;
		case -1:
			str = str + "I am playing, it is my opponent's move";
			break;
		case 1:
			str = str + "I am playing and it is my move\r\n";
			break;
		case 0:
			str = str + "I am observing a game being played\r\n";
			break;
		default:
			break;
	}
	tempstr.Format("Initial time of the match: %d seconds\r\n",msg.dataset2[1]);
	str = str + tempstr;
	tempstr.Format("Increament %d seconds\r\n",msg.dataset2[2]);
	str = str + tempstr;
	tempstr.Format("White material strength %d\r\n",msg.dataset2[3]);
	str = str + tempstr;
	tempstr.Format("Black material strength %d\r\n",msg.dataset2[4]);
	str = str + tempstr;
	tempstr.Format("White's remaining time: %d\r\n",msg.dataset2[5]);
	str = str + tempstr;
	tempstr.Format("Black's remaining time: %d\r\n",msg.dataset2[6]);
	str = str + tempstr;
	tempstr.Format("The number of the move about to be made: %d\r\n",msg.dataset2[7]);
	str = str + tempstr;	
	str = str + "verbose coordinate notation for the previous move: " + msg.moveNotation + "\r\n";
	str = str + "time taken to make previous move \"(min:sec)\": " + msg.time + "\r\n";
	str = str + "pretty notation for the previous move: " + msg.PGNMoveNotation + "\r\n";	
	str = str + "**********End Message Info ***********\r\n";
}
void CNetChessView::CreateMyProcess(CString cmd, CString cmdlineinfo)
{
   PROCESS_INFORMATION piProcInfo; 
   STARTUPINFO siStartInfo;
   BOOL bFuncRetn = FALSE; 
 
// Set up members of the PROCESS_INFORMATION structure. 
 
   ZeroMemory( &piProcInfo, sizeof(PROCESS_INFORMATION) );
 
// Set up members of the STARTUPINFO structure. 
 
   ZeroMemory( &siStartInfo, sizeof(STARTUPINFO) );
   siStartInfo.cb = sizeof(STARTUPINFO); 
   siStartInfo.hStdError = NULL;
   siStartInfo.hStdOutput = NULL;
   siStartInfo.hStdInput = NULL;
   siStartInfo.dwFlags |= STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
   siStartInfo.wShowWindow = SW_SHOW;
// Create the child process. 
   CString cmdl = cmd + " " + cmdlineinfo;
   bFuncRetn = CreateProcess(NULL, 
      cmdl.GetBuffer(0),       // command line 
      NULL,          // process security attributes 
      NULL,          // primary thread security attributes 
      TRUE,          // handles are inherited 
      0,             // creation flags 
      NULL,          // use parent's environment 
      NULL,          // use parent's current directory 
      &siStartInfo,  // STARTUPINFO pointer 
      &piProcInfo);  // receives PROCESS_INFORMATION 
   
   if (bFuncRetn == 0) 
   {
      return;
   }
   else 
   {   
      CloseHandle(piProcInfo.hProcess);
      CloseHandle(piProcInfo.hThread);
      return ;
   }
   return ;
}


void CNetChessView::OnHelpHttpwwwgeocitiescomraoavm() 
{
	// TODO: Add your command handler code here
	//CString cmdl = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + cmdlineinfo;
	char *name = NULL;
	CString data;	
	CString keyname = "SOFTWARE\\Clients\\StartMenuInternet";
	GetRegistryValue(HKEY_LOCAL_MACHINE, keyname, name, data);
	keyname = keyname + "\\" + data + "\\shell\\open\\command";
	GetRegistryValue(HKEY_LOCAL_MACHINE, keyname, name, data);
	//AfxMessageBox(data);
	CreateMyProcess(data,"http://www.geocities.com/raoavm");
}



void CNetChessView::OnWhiteengineSetboard() 
{
	// TODO: Add your command handler code here
	int movecount = m_iHistory/2;
//	char side = m_pieceSide == WHITE ? 'w' : 'b';
	char side; 
	if(m_pClientSocket == NULL)
		  side = m_pieceSide == WHITE ? 'w' : 'b';
	else
	{
		if(m_pieceSide == WHITE && m_player_turn == true ||
			m_pieceSide == BLACK && m_player_turn == false)
			side = 'w';
		else if(m_pieceSide == WHITE && m_player_turn == false ||
			m_pieceSide == BLACK && m_player_turn == true)
			side = 'b';
	}
	//char side  = 'w';
	CString str = GetPositionString('F',movecount,side);
	if(m_whiteAsEngineFlag == TRUE)
		SetEnginePosition(m_whiteEngine, str);	
}

void CNetChessView::OnBlackengineSetboard() 
{
	// TODO: Add your command handler code here
	int movecount = m_iHistory/2;
	char side; 
	if(m_pClientSocket == NULL)
		  side = m_pieceSide == WHITE ? 'w' : 'b';
		else
		{
			if(m_pieceSide == WHITE && m_player_turn == true ||
				m_pieceSide == BLACK && m_player_turn == false)
				side = 'w';
			else if(m_pieceSide == WHITE && m_player_turn == false ||
				m_pieceSide == BLACK && m_player_turn == true)
				side = 'b';
		}
	//char side;
	CString str = GetPositionString('F',movecount,side);
	//AfxMessageBox(str);
	
	if(m_blackAsEngineFlag == TRUE )
		SetEnginePosition(m_blackEngine, str);
}

void CNetChessView::OnUpdateWhiteengineSetboard(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE  && (m_whiteEngine.m_engineLoadedFlag == TRUE || m_whiteEngine.m_engineDefaultFlag == TRUE) ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
}

void CNetChessView::OnUpdateBlackengineSetboard(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE  && (m_blackEngine.m_engineLoadedFlag == TRUE || m_blackEngine.m_engineDefaultFlag == TRUE) ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
}


void CNetChessView::OnWhiteengineOnlyanalyze() 
{
	// TODO: Add your command handler code here
	m_whiteEngineOnlyAnalyze == TRUE ? m_whiteEngineOnlyAnalyze = FALSE : m_whiteEngineOnlyAnalyze = TRUE;
}

void CNetChessView::OnUpdateWhiteengineOnlyanalyze(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_whiteAsEngineFlag == TRUE  && (m_whiteEngine.m_engineLoadedFlag == TRUE || m_whiteEngine.m_engineDefaultFlag == TRUE) ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
	m_whiteEngineOnlyAnalyze == TRUE ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0) ;	
}

void CNetChessView::OnBlackengineOnlyanalyze() 
{
	// TODO: Add your command handler code here
	m_blackEngineOnlyAnalyze == TRUE ? m_blackEngineOnlyAnalyze = FALSE : m_blackEngineOnlyAnalyze = TRUE;
}

void CNetChessView::OnUpdateBlackengineOnlyanalyze(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_blackAsEngineFlag == TRUE  && (m_blackEngine.m_engineLoadedFlag == TRUE || m_blackEngine.m_engineDefaultFlag == TRUE) ? pCmdUI->Enable(1) :pCmdUI->Enable(0) ;	
	m_blackEngineOnlyAnalyze == TRUE ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0) ;	
}
void CNetChessView::GetRegistryValue(HKEY key, CString keyname, CString name, CString &data)
{
	char ldata[500];
	memset(ldata,'\0',500);
	CRegKey rg;
	unsigned long size;
	//rg.Create(key,name);
	if(rg.Open(key,keyname) == ERROR_SUCCESS)
	{
		if(rg.QueryValue(ldata,name,&size) == ERROR_SUCCESS)
		{	
			data = ldata;
			rg.Close();
		}
	}
}

void CNetChessView::OnIcsSeeklist() 
{
	// TODO: Add your command handler code here
			
	if(m_seekListDlg == NULL)
	{		
		m_seekListDlg = new CSeekListDlg();
		m_seekListDlg->Create(IDD_DIALOG_SEEK_LIST,this);
	}	
	m_seekListDlg->Update();
	m_seekListDlg->ShowWindow(SW_SHOW);
		//m_seekListDlg->UpdeData(FALSE);	
	
}

void CNetChessView::OnEditTimecontrol() 
{
	// TODO: Add your command handler code here
	if(m_timeControlDlg.DoModal() == IDOK)
	{
		CString wbstr;
		switch(m_timeControlDlg.m_radio_clock_type)
		{
			case CONVENTIONAL: //conventional
				{
					wbstr.Format("level %d %d 0",m_timeControlDlg.m_edit_wb_number_of_moves, m_timeControlDlg.m_edit_wb_time);
				}
				break;
			case ICSTYPE: //ics style
				{
					wbstr.Format("level 0 %d %d",m_timeControlDlg.m_edit_wb_base_time, m_timeControlDlg.m_edit_wb_inc_time);
				}
				break;
			case MOVETIME: //exact moves
				{
					wbstr.Format("st %d",m_timeControlDlg.m_wb_exact_seconds);
				}
				break;
			default:
				break;
		}
		CString ucistr;
		ucistr.Format("wtime %d\r\nbtime %d\r\nwinc %d\r\nbinc %d",
		m_timeControlDlg.m_edit_uci_wtime*1000,
		m_timeControlDlg.m_edit_uci_btime*1000,
		m_timeControlDlg.m_edit_uci_winc*1000,
		m_timeControlDlg.m_edit_uci_binc*1000);

		if(m_whiteAsEngineFlag == TRUE)
		{
			if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_I || m_whiteEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
			{
				m_whiteEngine.WriteToEngine(wbstr);
			}
			else if(m_whiteEngine.m_engineConfigDlg.m_chessProtocol == UCI_I || m_whiteEngine.m_engineConfigDlg.m_chessProtocol == UCI_II)
			{			
				if(m_timeControlDlg.m_check_infinite == TRUE)
				{
					m_whiteEngine.WriteToEngine("infinite");
				}
				else
				{
					m_whiteEngine.WriteToEngine(ucistr);
				}
			}
		}
		if(m_blackAsEngineFlag == TRUE)
		{
			if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_I || m_blackEngine.m_engineConfigDlg.m_chessProtocol == WB_II)
			{
				m_whiteEngine.WriteToEngine(wbstr);
			}
			else if(m_blackEngine.m_engineConfigDlg.m_chessProtocol == UCI_I || m_blackEngine.m_engineConfigDlg.m_chessProtocol == UCI_II)
			{
				if(m_timeControlDlg.m_check_infinite == TRUE)
				{
					m_blackEngine.WriteToEngine("infinite");
				}
				else
				{
					m_blackEngine.WriteToEngine(ucistr);
				}
			}
		}
	}
}

void CNetChessView::OnUpdateIcsConfigure(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		m_pClientICSSocket != NULL  ? pCmdUI->SetCheck(1) :pCmdUI->SetCheck(0) ;	
}
void CNetChessView::OnButtonWhiteRadioButtonComputer()
{
	if(!m_optDlg.m_edit_def_white_engine.IsEmpty())
	{
		m_whiteEngine.Initialize(m_optDlg.m_edit_def_white_engine,this);	
	}
	else
	{
		char directory[1000];
		memset(directory,'\0',1000);
		GetCurrentDirectory(1000,directory);
		//AfxMessageBox(directory);
		CString str = (CString)directory + (CString)"\\crafty\\crafty_1920.exe";
		//AfxMessageBox(str);
		m_optDlg.m_edit_def_white_engine = str;
		m_optDlg.m_whiteEngineProtocol = WB_II;
		m_whiteEngine.Initialize(str,this);			
	}
	Globalfirsttime = 0;
	m_whiteAsEngineFlag = FALSE;
	OnToolsWhiteengineSettingsWhiteasengine();
	
	m_whiteEngine.Initialize(m_optDlg.m_edit_def_white_engine,this);	
	m_whiteEngine.m_engineDefaultFlag = TRUE;
	m_white_radio_button_computer.SetCheck(1);
	m_white_radio_button_human.SetCheck(0);
	//set white as enghine
	//default engine to be loaded
	//implement start functionalty by selecting the protocol
	m_whiteEngine.m_engineConfigDlg.m_chessProtocol = m_optDlg.m_whiteEngineProtocol;
	m_whiteEngine.m_engineType = WHITE;
	/*m_whiteEngine.StartEngine();
	m_whiteEngine.WriteToEngine("xboard");
	m_whiteEngine.WriteToEngine("protover 2");

	CString str;
	str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
		m_engineLevelDlg.m_edit_time_control,
		m_engineLevelDlg.m_edit_conv_clock_mode);
	m_whiteEngine.WriteToEngine(str);*/
	Globalfirsttime = 1;
	OnToolsWhiteengineStart();
	Globalfirsttime = 0;
///	Sleep(5000);
	//setboard
	OnWhiteengineSetboard();
	if(m_pieceSide == WHITE)
	{
		//OnWhiteengineSetboard();
	//move now
		OnToolsWhiteengineMovenow();
	}
}
void CNetChessView::OnButtonWhiteRadioButtonHuman()
{
	Globalfirsttime = 1;
	OnToolsWhiteengineClose();
	OnToolsWhiteengineSettingsWhiteasengine();
}
void CNetChessView::OnButtonBlackRadioButtonComputer()
{
	if(!m_optDlg.m_edit_def_black_engine.IsEmpty())
	{
		m_blackEngine.Initialize(m_optDlg.m_edit_def_black_engine,this);
	}
	else
	{
		char directory[1000];
		memset(directory,'\0',1000);
		GetCurrentDirectory(1000,directory);
		//AfxMessageBox(directory);
		CString str;
		str = (CString)directory + (CString)"\\crafty\\crafty_1920.exe";
		m_optDlg.m_edit_def_black_engine = str;
		m_optDlg.m_blackEngineProtocol = WB_II;
		//AfxMessageBox(str);
		m_blackEngine.Initialize(str,this);			
	}	
	/*CString str = "Default engine " + m_optDlg.m_edit_def_black_engine + " Loaded";		
	AfxMessageBox(str);*/
	Globalfirsttime = 0;
	m_blackAsEngineFlag = FALSE; //below call will make it as TRUE
	OnToolsBlackengineSettingsBlackasengine();
	m_black_radio_button_computer.SetCheck(1);
	m_black_radio_button_human.SetCheck(0);
	//m_blackAsEngineFlag = TRUE;
	m_blackEngine.Initialize(m_optDlg.m_edit_def_black_engine,this);	
	m_blackEngine.m_engineDefaultFlag = TRUE;
	//set white as enghine
	//default engine to be loaded
	//implement start functionalty by selecting the protocol
	m_blackEngine.m_engineConfigDlg.m_chessProtocol = m_optDlg.m_blackEngineProtocol;
	m_blackEngine.m_engineType = BLACK;
	/*m_blackEngine.StartEngine();
	m_blackEngine.WriteToEngine("xboard");
	m_blackEngine.WriteToEngine("protover 2");
	CString str;
  	str.Format("level %d %d %d",m_engineLevelDlg.m_edig_movestimecontrol,
		m_engineLevelDlg.m_edit_time_control,
		m_engineLevelDlg.m_edit_conv_clock_mode);
	m_blackEngine.WriteToEngine(str);*/
	Globalfirsttime = 1;
	OnToolsBlackengineStart();
	Globalfirsttime = 0;
	//setboard
//	Sleep(5000);
	
	//move now
	OnBlackengineSetboard();
	if(m_pieceSide == BLACK)
	{
		
		OnToolsBlackengineMovenow();
	}
}
void CNetChessView::OnButtonBlackRadioButtonHuman()
{
	Globalfirsttime = 0;
	OnToolsBlackengineClose();
	OnToolsBlackengineSettingsBlackasengine();
}


void CNetChessView::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CView::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	
	//Globalfirsttime = 1;
}

void CNetChessView::OnIcsChat() 
{
	// TODO: Add your command handler code here
	m_icsChatDlg->ShowWindow(SW_SHOW);	
}
void CNetChessView::SendICSMessage(char* message, int let)
{
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = (CString)message+"\r\n";
		pClientSocket->Send(str, str.GetLength());		
	}
}
/*
void CNetChessView::OnToolsMailfrom() 
{
	// TODO: Add your command handler code here
	((CMailFromDlg*)m_pMailFromDlg)->ShowWindow(SW_SHOW);
	/*Mail Server Username: madhuri+prasannatech.com
Incoming Mail Server: mail.prasannatech.com
Incoming Mail Server: (SSL) mail.prasannatech.com
Outgoing Mail Server: mail.prasannatech.com (server requires authentication) port 25
Outgoing Mail Server: (SSL) mail.prasannatech.com (server requires authentication) port 465
Supported Incoming Mail Protocols: POP3, POP3S (SSL/TLS), IMAP, IMAPS (SSL/TLS)
Supported Outgoing Mail Protocols: SMTP, SMTPS (SSL/TLS)

[ Go Back ]
		CSMTPConnection smtp;
        smtp.Connect("mail.someisp.com");
        CSMTPMessage m;
        m.AddRecipient(CSMTPAddress("pjn@indigo.ie"));
        m.m_From = CSMTPAddress("adeveloper@someisp.com");
        m.m_sSubject = "NetChess by AVM RAO: Mail Chess Move!";
        m.AddBody("if you can read this then the CSMTPConnection code is working");
        smtp.SendMessage(m);



}

/*void CNetChessView::OnToolsMailto() 
{
	// TODO: Add your command handler code here
	((CMailToDlg*)m_pMailToDlg)->ShowWindow(SW_SHOW);
}

void CNetChessView::OnToolsMailclient() 
{
	// TODO: Add your command handler code here
	m_mailClientFlag = m_mailClientFlag == TRUE ? FALSE : TRUE;	
}

void CNetChessView::OnUpdateToolsMailclient(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_mailClientFlag == TRUE ? pCmdUI->SetCheck(1) : pCmdUI->SetCheck(0);
}

void CNetChessView::OnToolsMailconnect() 
{
	// TODO: Add your command handler code here
	
}

void CNetChessView::OnUpdateToolsMailconnect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_mailClientFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CNetChessView::OnUpdateToolsMailfrom(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_mailClientFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);
}

void CNetChessView::OnUpdateToolsMailto(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_mailClientFlag == TRUE ? pCmdUI->Enable(TRUE) : pCmdUI->Enable(FALSE);	
}*/
void CNetChessView::SendMail(char *msg, int len)
{
/*	if(m_mailClientFlag == TRUE)
	{
		CSMTPConnection smtp;
        if(smtp.Connect(((CMailToDlg*)m_pMailToDlg)->m_edit_mail_server) == TRUE)
		{
			CSMTPMessage m;
			m.AddRecipient(CSMTPAddress(((CMailToDlg*)m_pMailToDlg)->m_edit_to));
			m.m_From = CSMTPAddress(((CMailToDlg*)m_pMailToDlg)->m_edit_from);
			m.m_sSubject = "NetChess by AVM RAO: Mail Chess Move!";
			m.AddBody("if you can read this then the CSMTPConnection code is working");
			int movecount = m_iHistory/2;
			char side = m_pieceSide == WHITE ? 'w' : 'b';		
			CString str = GetPositionString('F',movecount,side);
			m.AddBody(str);
			smtp.SendMessage(m);
		}
	}*/
}


void CNetChessView::OnViewReplayAll()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here	
	if (m_manualEditingFlag == TRUE)
	{
		AfxMessageBox("Manual editing is in progress, disable manual editing to activate this feature");
		return;
	}
	if (m_demoFlag == TRUE)
	{
		return;
	}
	CDemoIntervalDlg dlg;
	if (m_demoFlag == FALSE)
	{
		if (dlg.DoModal() == IDCANCEL)
		{
			return;
		}
	}
	else
	{
		m_demoFlag = FALSE;
		return;
	}
	if (m_pClientSocket == NULL)
	{
		m_demoFlag = TRUE;
		m_manualEditingFlag = FALSE;
		OnEditMovefirst();
		m_demoTotal = 0;
		m_demoInterval = dlg.m_edit_demo_interval;
		SetTimer(DEMO_TIMER_EVENT_ID_ALL, dlg.m_edit_demo_interval * 1000, NULL);
	}
	else
	{
		if (m_demoFlag == FALSE)
		{
			unsigned char data[50];
			data[0] = DEMO_START;
			m_demoInterval = dlg.m_edit_demo_interval;
			strcpy((char*)&data[1], m_edit_name.GetBuffer(0));
			SendSockData(data, m_edit_name.GetLength() + 2);
		}
		else
		{
			unsigned char data[2];;
			m_demoFlag = FALSE;
			data[0] = DEMO_END;
			SendSockData(data, m_edit_name.GetLength() + 2);
		}
		//data[1] = m_checkmove;				
	}
}


void CNetChessView::OnUpdateReplayAll(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(1);
}
