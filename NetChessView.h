// NetChessView.h : interface of the CNetChessView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_)
#define AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"
#include "ChessBoard.h"
#include "Options.h"
#include "History.h"
#include "PickPieceDlg.h"
#include "NetChessDoc.h"
#include "Engine.h"
#include "ICSClient.h"
#include "PGNGameInfoDlg.h"
#include "EngineLevelDlg.h"
#include "GameStateInfoDlg.h"
#include "MyColorEdit.h"
#include "ICSWindowDlg.h"
#include "TimeControlDlg.h"
#include "GroupButton.h"
#include "ICSMessageChatDlg.h"
typedef CTypedPtrList<CPtrList,CAsyncSocket*> CClientSocketList;

//ICS Style format
//<12> rnbqkbnr pppppppp -------- -------- -------- -------- PPPPPPPP RNBQKBNR W -1 1 1 1 1 0 319 GuestYZMC GuestGGRS -1 5 12 39 39 300 300 1 none (0:00) none 1 0 0
struct ICSMsgStruct
{
	char style[6];
	char boardString[8][10];
	char playerSide;
	int dataset1[7];
	char firstplayername[20];
	char secondplayername[20];
	int dataset2[8];
	char moveNotation[20];
	char time[10];
	char PGNMoveNotation[20];
	int dataset3[3];
	public:
			ICSMsgStruct()
			{
				memset(style,'\0',6);
				for(int i=0;i<8;i++)
				{
					memset(boardString[i],'\0',10);
				}
				for(int i=0;i<7;i++)
				{
					dataset1[i] = 0;
				}
				memset(firstplayername,'\0',20);
				memset(secondplayername,'\0',20);
				for(int i=0;i<8;i++)
				{
					dataset2[i] = 0;
				}
				memset(moveNotation,'\0',20);
				memset(time,'\0',10);
				memset(PGNMoveNotation,'\0',20);
				for(int i=0;i<3;i++)
				{
					dataset3[i] = 0;
				}
			}
};


class CNetChessView : public CView
{
public:
	//CNetChessView();
	int m_blackTime, m_whiteTime,m_startTime;
	COLOR_TYPE  m_pieceSide;
	bool m_mouseMoveFlag;
	CRect m_moveRect;
	CPoint m_point;
	int m_SpecialAction;
	CAsyncSocket *m_pClientSocket;
	CAsyncSocket *m_pServerSocket;
	CAsyncSocket *m_pClientICSSocket;
	CClientSocketList m_pObserverSocketList;
	CDialog *m_ChatDlg;
	CDialog *m_pMailFromDlg;
	CDialog *m_pMailToDlg;
	bool m_LetterFlag;
	bool m_NumberFlag;
	bool m_white_on_top;	 
	bool m_player_turn;
	bool m_blackKingMovedFlag;
	bool m_whiteKingMovedFlag;
	bool m_blackRookRank1MovedFlag;
	bool m_whiteRookRank1MovedFlag;
	bool m_blackRookRank7MovedFlag;
	bool m_whiteRookRank7MovedFlag;
	int	 m_checkFlag;
	int  m_castlingFlag;
	int  m_enpassentFlag;
	int  m_promotionFlag;
	int  m_ambiguousMoveRankFlag;
	int  m_ambiguousMoveFileFlag;	
	int m_topHistory;
	int m_squareWidth;
	bool m_manualEditingFlag;
	CRect m_movedFromRect;
	CRect m_movedToRect; 
	int m_moveFlag;
	int m_convertFlag;
	int  m_clientId;
	int m_halfMoveCount;
	int m_ICSToBoardFlag;
	int m_BoardToICSFlag;
	int m_icsFlag;
	CString m_whiteEngineString;
	CString m_blackEngineString;
	CEngine m_whiteEngine;
	CEngine m_blackEngine;
	CEngineLevelDlg m_engineLevelDlg;
	INT m_learningFlag;
	CICSClient m_icsClient;
	CICSWindowDlg *m_pICSWindowDlg; 
	CICSConfigureDlg *m_pICSConfigureDlg;
	CSeekListDlg	*m_seekListDlg;
	CICSMessageChatDlg *m_icsChatDlg;
	CString m_edit_name;
	bool m_timerFlag;	 
	COptions m_optDlg;
	CChessBoard cb[16][16];
	CHistory  m_History[MAXHISTORY];
	int m_iHistory; 
	CPickPieceDlg *m_pickPieceDlg;
	int m_checkmove;
	int m_demoFlag;
	int m_demoTotal;
	int m_demoInterval;
	int m_fileReadFlag;
	int m_pauseFlag;
	int m_pauseclockFlag;
	int m_elapsedTime;
	int m_whiteAsEngineFlag;
	int m_blackAsEngineFlag;
	int m_mailClientFlag;
	CString m_fileName;
	CStringArray m_PGNFileData;
	int m_PGNFileIndex;
	//CString m_PGNEvent,m_PGNSite, m_PGNRound, m_PGNDate, m_PGNWhite,m_PGNBlack, m_PGNResult, m_FENString;
	CPGNGameInfoDlg m_gameInfoDlg;
	int  m_observerFlag;
	CMyColorEdit m_edit_comment;
	CButton m_button_comment;
	CListBox m_listctrl_movehistory;
	CString m_lastsMoveInfo;
	int m_blackEngineOnlyAnalyze, m_whiteEngineOnlyAnalyze;
	CTimeControlDlg m_timeControlDlg;
	CGroupButton m_white_group_button;
	CButton m_white_radio_button_computer;
	CButton m_white_radio_button_human;
	CGroupButton m_black_group_button;
	CButton m_black_radio_button_computer;
	CButton m_black_radio_button_human;
	void OnButtonWhiteRadioButtonComputer();
	void OnButtonWhiteRadioButtonHuman();
	void OnButtonBlackRadioButtonComputer();
	void OnButtonBlackRadioButtonHuman();
	void SendICSMessage(char*,int);
	void SendMail(char *msg, int len);

	
protected: // create from serialization only
	CNetChessView();
	DECLARE_DYNCREATE(CNetChessView)
	 

// Attributes
public:
	
	void DrawBoard();
	CNetChessDoc* GetDocument();
	void SetClientSocket(CAsyncSocket*, int);
	void HandleData(unsigned char* data, int length, int flag);
	void SendSockData(unsigned char *data,int length);
	bool CheckValidMove(int,int);
	void KillTimerEvent();
	void OnEditRedoAction(int redraw);
	void OnEditUndoAction(int redraw);
	CAsyncSocket* GetClientSocket(int);
	void Initialize();
	int GetBitmapId(int piece_id);
	void SetPieceSide(COLOR_TYPE piecetype);
	COLOR_TYPE GetPlayerSide();
	void CleanWindow();
	void HandleEngineData(COLOR_TYPE,CString str);
	void SetLearning(int flag);
	int GetPieceString(int piece_id, CString &piece);
	void DrawCoordinateSystem(CDC *dc);
	void DrawInExtendedView(CDC *dc);
	void DrawMovingPiece(CDC *dc, COLORREF cr);
	void ShowConvertMessage(CDC &ldc);
	void FillBorder(CDC& ldc, CRect rect, COLOR_TYPE ct);
	int DrawEachPiece(CDC &ldc, int i, int j);
	void HandleICSData(CString str);
	void ReadICSMessage(CString str);
	void ConnectToICSServer();
	BOOL OnCommand(WPARAM wParam,LPARAM lParam);
	void OnMessageColorData(WPARAM wParam,LPARAM lParam);
	void OnMyEngineMessage(WPARAM wParam,LPARAM lParam);
	void OnLButtonDownAction(UINT nFlags, CPoint point);
	int OnLButtonUpAction(UINT nFlags, CPoint point);
	void OnRButtonDownAction(UINT nFlags, CPoint point);
	void OnMouseMoveAction(UINT nFlags, CPoint point);
	int OnFileNewAction();	
	CString GetHistoryString(CStringArray& historystring,int);
	void SetShellIconData(char* data, int id);
	bool CheckCheckState(int piecetype, int piececolor,int x,int y);
	bool CheckKingMove(int fromx, int fromy, int tox, int toy);
	void SetMoveHistory();
	void GetMoveHistory();
	void writeMessage(char *str,...);
	void doPGNRead(CString file,char type);
	void filterPGNFile(CString& filedata);
	int PGNMove(char cstring[255], int pieceside);
	bool GetPieceIndex(char type[255],int pieceside,int to_i,int to_j,int &from_i,int &from_j) ;
	int GetPieceType(char type[255],int piececolor,int&);
	void doFENRead(CString file,char type);
	void MoveTo(int pos);
	CString GetFileSaveString();
	void OnFileOpen(CString str);
	void CheckAmbiguousMove(int i,int j);
	void SetPaneText(int paneno,CString str,int log=0);
	void FlipBoard();
	void SetObserverSocket(CAsyncSocket* sock);
	void SendObserverData(unsigned char *data,int length);
	void RemoveFromObserverList(CAsyncSocket*);
	void GetPieceInfo(int PieceId, COLOR_TYPE &ct, PIECE_TYPE &pt);
	CString GetSingleMoveString(int i);
	CString GetPositionHistoryString(int);
	void doEPDRead(CString file,char type);
	void doFENPositionRead(CString file,char type);
	CString GetPositionString(int type, int& movecount,char &side);
	void SendToEngine(unsigned char *data,int length);
	CString GetSingleMoveStringOldFormat(int i);
	void SetEnginePosition(CEngine& engine,CString position);
	void CreateMyProcess(CString, CString);
	void GetRegistryValue(HKEY key, CString keyname, CString name, CString &data);
	void ParseICSStyle12Message(ICSMsgStruct msg, CString &str);
	int ChessPtInBoard(CPoint point, COLOR_TYPE &sqcolor, CRect &rect );

	//

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetChessView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNetChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNetChessView)
	afx_msg void OnEditOptions();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnToolsClient();
	afx_msg void OnToolsServer();
	afx_msg void OnToolsSendmessage();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnViewLetter();
	afx_msg void OnUpdateViewLetter(CCmdUI* pCmdUI);
	afx_msg void OnViewNumber();
	afx_msg void OnUpdateViewNumber(CCmdUI* pCmdUI);
	afx_msg void OnFileSavehistory();
	afx_msg void OnEditUndo();
	afx_msg void OnEditRedo();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnUpdateToolsServer(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsClient(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnViewHistory();
	afx_msg void OnToolsWhiteontop();
	afx_msg void OnEditMovefirst();
	afx_msg void OnEditMovelast();
	afx_msg void OnHelpHowtoplay();
	afx_msg void OnToolsDisconnect();
	afx_msg void OnEditProperties();
	afx_msg void OnToolsDraw();
	afx_msg void OnToolsResign();
	afx_msg void OnViewLostpieces();
	afx_msg void OnFileFeed();
	afx_msg void OnToolsLearn();
	afx_msg void OnEditSetboard();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnEditCheckmove();
	afx_msg void OnUpdateEditCheckmove(CCmdUI* pCmdUI);
	afx_msg void OnEditManualeditEmpty();
	afx_msg void OnEditManualeditEnd();
	afx_msg void OnEditManualeditPlayerturn();
	afx_msg void OnEditManualeditStart();
	afx_msg void OnUpdateEditManualeditStart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditManualeditEmpty(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditManualeditPlayerturn(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditMovefirst(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditMovelast(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditRedo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewDemo(CCmdUI* pCmdUI);
	afx_msg void OnFileSubmitpgndata();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnViewDemoPause();
	afx_msg void OnViewDemoStart();
	afx_msg void OnViewDemoStop();
	afx_msg void OnUpdateViewDemoPause(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewDemoStart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewDemoStop(CCmdUI* pCmdUI);
	afx_msg void OnViewDemoGoto();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileGotopgngame();
	afx_msg void OnFileLoadfirstgame();
	afx_msg void OnFileLoadnextgame();
	afx_msg void OnFileOpenpgnfile();
	afx_msg void OnFileReloadthepgngame();
	afx_msg void OnFileLoadprevpgngame();
	afx_msg void OnEditGameinfo();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnViewFlipboard();
	afx_msg void OnEditManualeditPauseclock();
	afx_msg void OnUpdateEditManualeditPauseclock(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileGotopgngame(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileLoadfirstgame(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileLoadnextgame(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileLoadprevpgngame(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileOpen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileOpenpgnfile(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileReloadthepgngame(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSubmitpgndata(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsDraw(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsResign(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewDemoGoto(CCmdUI* pCmdUI);
	afx_msg void OnFileSaveboard();
	afx_msg void OnUpdateFileSaveboard(CCmdUI* pCmdUI);
	afx_msg void OnViewObserverslist();
	afx_msg void OnUpdateViewObserverslist(CCmdUI* pCmdUI);
	afx_msg void OnFileConvert();
	afx_msg void OnEditComment();
	afx_msg void OnUpdateFileConvert(CCmdUI* pCmdUI);
	afx_msg void OnFileLoadlastgame();
	afx_msg void OnUpdateFileLoadlastgame(CCmdUI* pCmdUI);
	afx_msg void OnEditCopyepd();
	afx_msg void OnUpdateEditCopyfen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCopyepd(CCmdUI* pCmdUI);
	afx_msg void OnEditCopyfen();
	afx_msg void OnViewImage();
	afx_msg void OnEditCopyepdposition();
	afx_msg void OnEditCopyfenposition();
	afx_msg void OnViewLog();	
	afx_msg void OnFileNewgame();
	afx_msg void OnUpdateFileNewgame(CCmdUI* pCmdUI);
	afx_msg void OnToolsBlackengineClose();
	afx_msg void OnUpdateToolsBlackengineClose(CCmdUI* pCmdUI);
	afx_msg void OnToolsBlackengineConfigure();
	afx_msg void OnUpdateToolsBlackengineConfigure(CCmdUI* pCmdUI);
	afx_msg void OnToolsBlackengineLoad();
	afx_msg void OnUpdateToolsBlackengineLoad(CCmdUI* pCmdUI);
	afx_msg void OnToolsBlackengineLog();
	afx_msg void OnUpdateToolsBlackengineLog(CCmdUI* pCmdUI);
	afx_msg void OnToolsBlackengineMovenow();
	afx_msg void OnUpdateToolsBlackengineMovenow(CCmdUI* pCmdUI);
	afx_msg void OnToolsBlackengineSettingsBlackasengine();
	afx_msg void OnUpdateToolsBlackengineSettingsBlackasengine(CCmdUI* pCmdUI);
	afx_msg void OnToolsBlackengineStart();
	afx_msg void OnUpdateToolsBlackengineStart(CCmdUI* pCmdUI);
	afx_msg void OnToolsBlackengineStop();
	afx_msg void OnUpdateToolsBlackengineStop(CCmdUI* pCmdUI);
	afx_msg void OnToolsWhiteengineClose();
	afx_msg void OnUpdateToolsWhiteengineClose(CCmdUI* pCmdUI);
	afx_msg void OnToolsWhiteengineConfigure();
	afx_msg void OnUpdateToolsWhiteengineConfigure(CCmdUI* pCmdUI);
	afx_msg void OnToolsWhiteengineLoad();
	afx_msg void OnUpdateToolsWhiteengineLoad(CCmdUI* pCmdUI);
	afx_msg void OnToolsWhiteengineLog();
	afx_msg void OnUpdateToolsWhiteengineLog(CCmdUI* pCmdUI);
	afx_msg void OnToolsWhiteengineMovenow();
	afx_msg void OnUpdateToolsWhiteengineMovenow(CCmdUI* pCmdUI);
	afx_msg void OnToolsWhiteengineSettingsWhiteasengine();
	afx_msg void OnUpdateToolsWhiteengineSettingsWhiteasengine(CCmdUI* pCmdUI);
	afx_msg void OnToolsWhiteengineStart();
	afx_msg void OnUpdateToolsWhiteengineStart(CCmdUI* pCmdUI);
	afx_msg void OnToolsWhiteengineStop();
	afx_msg void OnUpdateToolsWhiteengineStop(CCmdUI* pCmdUI);
	afx_msg void OnWhiteenginePonder();
	afx_msg void OnUpdateWhiteenginePonder(CCmdUI* pCmdUI);
	afx_msg void OnBlackenginePondor();
	afx_msg void OnUpdateBlackenginePondor(CCmdUI* pCmdUI);
	afx_msg void OnEditLevels();
	afx_msg void OnUpdateEditLevels(CCmdUI* pCmdUI);
	afx_msg void OnWhiteengineAnalyze();
	afx_msg void OnUpdateWhiteengineAnalyze(CCmdUI* pCmdUI);
	afx_msg void OnBlackengineAnalyze();
	afx_msg void OnUpdateBlackengineAnalyze(CCmdUI* pCmdUI);
	afx_msg void OnWhiteengineDefault();
	afx_msg void OnUpdateWhiteengineDefault(CCmdUI* pCmdUI);
	afx_msg void OnBlackengineDefault();
	afx_msg void OnUpdateBlackengineDefault(CCmdUI* pCmdUI);
	afx_msg void OnEditGamestate();
	afx_msg void OnBlackengineReload();
	afx_msg void OnUpdateBlackengineReload(CCmdUI* pCmdUI);
	afx_msg void OnWhiteengineReload();
	afx_msg void OnUpdateWhiteengineReload(CCmdUI* pCmdUI);
	afx_msg void OnToolsAreyouok();
	afx_msg void OnUpdateToolsAreyouok(CCmdUI* pCmdUI);
	afx_msg void OnViewLearning();
	afx_msg void OnUpdateViewLearning(CCmdUI* pCmdUI);
	afx_msg void OnEditEntermove();
	afx_msg void OnIcsConfigure();
	afx_msg void OnIcsWindow();
	afx_msg void OnHelpHttpwwwgeocitiescomraoavm();
	afx_msg void OnWhiteengineSetboard();
	afx_msg void OnBlackengineSetboard();
	afx_msg void OnUpdateWhiteengineSetboard(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBlackengineSetboard(CCmdUI* pCmdUI);
	afx_msg void OnWhiteengineOnlyanalyze();
	afx_msg void OnUpdateWhiteengineOnlyanalyze(CCmdUI* pCmdUI);
	afx_msg void OnBlackengineOnlyanalyze();
	afx_msg void OnUpdateBlackengineOnlyanalyze(CCmdUI* pCmdUI);
	afx_msg void OnIcsSeeklist();
	afx_msg void OnEditTimecontrol();
	afx_msg void OnUpdateIcsConfigure(CCmdUI* pCmdUI);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnIcsChat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnViewReplayAll();
	afx_msg void OnUpdateReplayAll(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // debug version in NetChessView.cpp
inline CNetChessDoc* CNetChessView::GetDocument()
   { return (CNetChessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_)
