// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__7D203266_2EAA_41DB_B721_EEF4C52B849A__INCLUDED_)
#define AFX_STDAFX_H__7D203266_2EAA_41DB_B721_EEF4C52B849A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#include <afxtempl.h>
#include <afxpriv2.h>
#include <atlbase.h>
#include <objbase.h>
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#define MY_MESSAGE_SHELLNOTIFY WM_USER + 1
#include <afxsock.h>		// MFC socket extensions

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
enum COLOR_TYPE {NONE,BLACK,WHITE};

enum CLOCKTYPE {CONVENTIONAL, ICSTYPE, MOVETIME, NOTIME};

enum PIECE_SIDE {TOP,BOTTOM};

enum PIECE_TYPE {BLANK,PAWN,ROOK,KNIGHT,BISHOP,QUEEN,KING,}; 

enum ACTION {MOVE,TEXT=1,OBSERVER_TEXT,PGNFILE,
			UNDO,REDO,MOVEFIRST,MOVELAST,NEWGAME,
			CONNECT_REQUEST,CONNECT_REJECT,CONNECT_ACCEPT, CONNECT_INFO,
			RESIGN_REQUEST, RESIGN_ACCEPT, RESIGN_REJECT, 
			DRAW_REQUEST,DRAW_REJECT,DRAW_ACCEPT,			
			MANUALEDITING_START,MANUALEDITING_END,
			MANUALEDITING_EMPTY,MANUALEDITING_PLAYERS_TURN,
			MANUALEDITING_ACCEPT,CHECKLEGALMOVE,
			MANUALEDITING_REJECT,MANUALEDITING_PLAYER_TURN,
			DEMO_START,DEMO_START_ACCEPT,DEMO_REJECT,DEMO_END,
			REFRESH,GOTO,GAMEINFO,CLOCK,OBSERVER,SYNC_REQUEST,
			SYNC_SERVER, FILEDATA, POSITION_DATA,
			ARE_YOU_OK,YES_IAM_FINE, ENGINE_DATA
			};
enum ENGINE_COMMANDS  { CHECKMATE,
			WHITE_UCI_OPTIONS, BLACK_UCI_OPTIONS, 
			BLACK_ISREADYOK,WHITE_ISREADYOK, 
			WHITE_FEATURES,BLACK_FEATURES, 
			BLACK_WON_WHITE, BLACK_WON_BLACK, 
			WHITE_WON_WHITE, WHITE_WON_BLACK,
			MATCH_DRAWN_BLACK, MATCH_DRAWN_WHITE,
			CHECK_MOVE,
			ACCEPT_DRAW_BLACK, ACCEPT_DRAW_WHITE, 
			ILLEGAL_MOVE_WHITE, ILLEGAL_MOVE_BLACK,
			ERROR_WHITE, ERROR_BLACK,
			RESIGN_WHITE, RESIGN_BLACK,
			TELLOPPONENT_WHITE, TELLOPPONENT_BLACK,
			TELLOTHERS_WHITE, TELLOTHERS_BLACK,
			HINT_BLACK, HINT_WHITE

};

enum STATE {PIECE_MOVING,PIECE_NOT_MOVING};
enum CHESS_PROTOCOL {WB_I=1,WB_II,UCI_I,UCI_II,NOPROTOCOL};
#define MESSAGEPANE 0
#define PLAYERNAME 1
#define WHITETIMENAME 2
#define WHITETIME 3
#define BLACKTIMENAME 4
#define BLACKTIME 5
#define PLAYERSIDE 6


#define CLIENT 1
#define SERVER 2
#define OTHER	3
#define MAXHISTORY 400
#define ID_MY_MESSAGE_COLORDATA WM_USER + 1
#define ID_MY_MESSAGE_ENGINE	 WM_USER + 2
#define SHELL_ICON_TIMER_EVENT_ID	1000
#define PIECE_SIDE_TIMER_EVENT_ID	1001
#define DEMO_TIMER_EVENT_ID			1002
#define SAVE_TIMER_EVENT_ID			1003
#define ICS_TIMER					1004
#define DEMO_TIMER_EVENT_ID_ALL		1005

#define ROOK_WHITE           'R'
#define KNIGHT_WHITE         'N'
#define BISHOP_WHITE         'B'
#define QUEEN_WHITE          'Q'
#define KING_WHITE           'K'
#define PAWN_WHITE           'P'

#define ROOK_BLACK           'r'
#define KNIGHT_BLACK         'n'
#define BISHOP_BLACK         'b'
#define QUEEN_BLACK          'q'
#define KING_BLACK           'k'
#define PAWN_BLACK           'p'

/*#define CASTLING			1
#define ENPASSENT			2
#define CHECK				3
#define PROMOTION			8
#define AMBIGIOUS_MOVE_FILE 9
#define AMBIGIOUS_MOVE_RANK 10
#define NOTHING				25*/

#define ID_EXTRA_EDIT  5001
#define ID_EXTRA_LISTBOX  5002
#define ID_EXTRA_BUTTON  5003
#define ID_EXTRA_WHITE_GROUPBOX 5004
#define ID_EXTRA_BLACK_GROUPBOX 5005
#define ID_EXTRA_WHITE_COMPUTER 5006
#define ID_EXTRA_WHITE_HUMAN	5007
#define ID_EXTRA_BLACK_COMPUTER 5008
#define ID_EXTRA_BLACK_HUMAN	5009

#endif // !defined(AFX_STDAFX_H__7D203266_2EAA_41DB_B721_EEF4C52B849A__INCLUDED_)
