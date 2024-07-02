// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "NetChess.h"

#include "MainFrm.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//extern CView *views[5];
extern int Globalfirsttime;
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_HIDE, OnViewHide)
	ON_COMMAND(ID_VIEW_STATUS_BAR, OnViewStatusBar)
	ON_COMMAND(ID_VIEW_TOOLBAR, OnViewToolbar)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_QUERYENDSESSION()
	ON_WM_ENDSESSION()
	ON_COMMAND(ID_SHELL_CLOSE, OnShellClose)
	ON_COMMAND(ID_SHELL_VIEW, OnShellView)	
	ON_COMMAND(ID_VIEW_EXTEND, OnViewExtend)
	ON_UPDATE_COMMAND_UI(ID_VIEW_EXTEND, OnUpdateViewExtend)
	ON_COMMAND(ID_VIEW_GAME1, OnViewGame1)
	ON_UPDATE_COMMAND_UI(ID_VIEW_GAME1, OnUpdateViewGame1)
	ON_COMMAND(ID_VIEW_GAME2, OnViewGame2)
	ON_UPDATE_COMMAND_UI(ID_VIEW_GAME2, OnUpdateViewGame2)
	ON_COMMAND(ID_VIEW_GAME3, OnViewGame3)
	ON_UPDATE_COMMAND_UI(ID_VIEW_GAME3, OnUpdateViewGame3)
	ON_COMMAND(ID_VIEW_GAME4, OnViewGame4)
	ON_UPDATE_COMMAND_UI(ID_VIEW_GAME4, OnUpdateViewGame4)
	ON_COMMAND(ID_VIEW_GAME5, OnViewGame5)
	ON_UPDATE_COMMAND_UI(ID_VIEW_GAME5, OnUpdateViewGame5)
	ON_UPDATE_COMMAND_UI(ID_VIEW_EXTENDEDVIEW, OnUpdateViewExtendedview)
	ON_WM_SIZE()
	ON_WM_ACTIVATE()
	ON_COMMAND(ID_HELP_HTTPWWWGEOCITIESCOMRAOAVM, OnHelpHttpwwwgeocitiescomraoavm)
	ON_COMMAND(ID_VIEW_EXTENDEDVIEW, OnViewExtendedview)
	//}}AFX_MSG_MAP
	//ON_MESSAGE(MY_MESSAGE_SHELLNOTIFY, OnShellNotify)


	

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_extendedViewFlag = TRUE;
	char data1[100];
	char defaultBuf[40]="default";
	char CurrentDir[255];
	GetWindowsDirectory(CurrentDir,MAX_PATH);
	strcat(CurrentDir,"\\NetChess.ini");
	memset(data1,'\0',100);
	if(GetPrivateProfileString("NetChess","ExtendedView",defaultBuf,data1,100,CurrentDir)>0)
	{
		if(strcmp(data1,"1") == 0)
		{
			m_extendedViewFlag = TRUE;
		}
	}
	

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	if(m_extendedViewFlag == TRUE)
	{
		if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
			| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
			!m_wndToolBar.LoadToolBar(IDR_MAINFRAME_EXTENDED))
		{
			TRACE0("Failed to create toolbar\n");
			return -1;      // fail to create
		}
	}
	else
	{
		if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
		{
			TRACE0("Failed to create toolbar\n");
			return -1;      // fail to create
		}
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	if(m_extendedViewFlag == TRUE)
	{
		/*m_wndStatusBar.SetPaneInfo(0,ID_SEPARATOR,0,355);
		m_wndStatusBar.SetPaneInfo(1,ID_SEPARATOR,0,55);
		m_wndStatusBar.SetPaneInfo(2,ID_SEPARATOR,0,35);
		m_wndStatusBar.SetPaneText(2,"WHITE");
		m_wndStatusBar.SetPaneInfo(3,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(3,"0:0:0");
		m_wndStatusBar.SetPaneInfo(4,ID_SEPARATOR,0,35);
		m_wndStatusBar.SetPaneText(4,"BLACK");
		m_wndStatusBar.SetPaneInfo(5,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(5,"0:0:0");*/

		m_wndStatusBar.SetPaneInfo(MESSAGEPANE,ID_SEPARATOR,0,300);	;
		m_wndStatusBar.SetPaneInfo(PLAYERNAME,ID_SEPARATOR,0,55);
		m_wndStatusBar.SetPaneInfo(WHITETIMENAME,ID_SEPARATOR,0,35);
		m_wndStatusBar.SetPaneText(WHITETIMENAME,"WHITE");
		m_wndStatusBar.SetPaneInfo(WHITETIME,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(WHITETIME,"0:0:0");
		m_wndStatusBar.SetPaneInfo(BLACKTIMENAME,ID_SEPARATOR,0,35);
		m_wndStatusBar.SetPaneText(BLACKTIMENAME,"BLACK");
		m_wndStatusBar.SetPaneInfo(BLACKTIME,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(BLACKTIME,"0:0:0");
		m_wndStatusBar.SetPaneInfo(PLAYERSIDE,ID_SEPARATOR,0,55);
	}
	else
	{
		m_wndStatusBar.SetPaneInfo(MESSAGEPANE,ID_SEPARATOR,0,170);
		m_wndStatusBar.SetPaneInfo(PLAYERNAME,ID_SEPARATOR,0,30);
		m_wndStatusBar.SetPaneInfo(WHITETIMENAME,ID_SEPARATOR,0,30);
		m_wndStatusBar.SetPaneText(WHITETIMENAME,"WHITE");
		m_wndStatusBar.SetPaneInfo(WHITETIME,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(WHITETIME,"0:0:0");
		m_wndStatusBar.SetPaneInfo(BLACKTIMENAME,ID_SEPARATOR,0,30);
		m_wndStatusBar.SetPaneText(BLACKTIMENAME,"BLACK");
		m_wndStatusBar.SetPaneInfo(BLACKTIME,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(BLACKTIME,"0:0:0");
	}
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style = WS_OVERLAPPED | WS_SYSMENU | WS_BORDER|WS_MINIMIZEBOX;
	if(m_extendedViewFlag == TRUE)
	{
		cs.cx =610;
		cs.cy = 540;
		cs.x = 30;
		cs.y = 30;
	}
	else
	{
		cs.cx =388;
		cs.cy = 470;
		cs.x = 40;
		cs.y = 10;
	}
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnViewHide() 
{
	CNetChessView* pView = (CNetChessView*)GetActiveView();
	if(pView->m_timerFlag == false)
	{
		NOTIFYICONDATA nicondata;
		char data[64] = "NetChess by A.V.M.Rao";
		 
		nicondata.hWnd = this->GetSafeHwnd();;
		nicondata.uID = 10;
		nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
		nicondata.cbSize = sizeof(nicondata);
		nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
		nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		strcpy(nicondata.szTip,data);
		Shell_NotifyIcon(NIM_ADD,&nicondata);
	}
	this->ShowWindow(SW_HIDE);
	 
}
void CMainFrame::OnShellNotify(WPARAM wParam,LPARAM lParam)
{
 
	switch(lParam)
	{
		case WM_LBUTTONDOWN:			 
			{
				this->ShowWindow(SW_SHOW);			
			}
			break;
		case WM_LBUTTONUP:
			{	
				CNetChessView* pView = (CNetChessView*)GetActiveView();
		 
				if(pView->m_timerFlag == true)
				{
					pView->KillTimerEvent();					 
				}
				NOTIFYICONDATA nicondata;
				char data[64] = "NetChess by A.V.M.Rao";
				nicondata.hWnd = this->GetSafeHwnd();;
				nicondata.uID = 10;
				nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
				nicondata.cbSize = sizeof(nicondata);
				nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
				nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
				strcpy(nicondata.szTip,data);
				Shell_NotifyIcon(NIM_DELETE,&nicondata);
				 
			}
			break;
		case WM_RBUTTONDOWN:
			{
				CRect rect;
				GetWindowRect(rect);
				CMenu menu;
				menu.LoadMenu(IDR_SHELL_MENU);
				CMenu *pMenu = menu.GetSubMenu(0);
				pMenu->TrackPopupMenu(TPM_LEFTALIGN |
				TPM_LEFTBUTTON | TPM_RIGHTBUTTON,rect.bottom,rect.right ,this);
				//this->ShowWindow(SW_HIDE);
			}
			break;
	}
} 

void CMainFrame::OnViewStatusBar() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnViewToolbar() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	NOTIFYICONDATA nicondata;
	char data[64] = "NetChess by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	CNetChessView* pView = (CNetChessView*)GetActiveView();
	pView->m_blackEngine.CloseEngine();
	pView->m_whiteEngine.CloseEngine();
	
	CFrameWnd::OnClose();
}

void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
	NOTIFYICONDATA nicondata;
	char data[64] = "NetChess by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	CNetChessView* pView = (CNetChessView*)GetActiveView();
	pView->m_blackEngine.CloseEngine();
	pView->m_whiteEngine.CloseEngine();

	// TODO: Add your message handler code here
	
}

BOOL CMainFrame::OnQueryEndSession() 
{
	if (!CFrameWnd::OnQueryEndSession())
		return FALSE;
	NOTIFYICONDATA nicondata;
	char data[64] = "NetChess by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	
	// TODO: Add your specialized query end session code here
	
	return TRUE;
}

void CMainFrame::OnEndSession(BOOL bEnding) 
{
	CFrameWnd::OnEndSession(bEnding);
	NOTIFYICONDATA nicondata;
	char data[64] = "NetChess by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	
	// TODO: Add your message handler code here
	
}

void CMainFrame::OnShellClose() 
{
	// TODO: Add your command handler code here
	NOTIFYICONDATA nicondata;
	char data[64] = "NetChess by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	
	SendMessage(WM_CLOSE);
}

void CMainFrame::OnShellView() 
{
	// TODO: Add your command handler code here
	NOTIFYICONDATA nicondata;
	char data[64] = "NetChess by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	
	this->ShowWindow(SW_SHOW);	
}
void CMainFrame::SetPaneText(int paneno,CString str)
{	
	m_wndStatusBar.SetPaneText(paneno,str);
}

void CMainFrame::OnViewExtend() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnUpdateViewExtend(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}


void CMainFrame::OnViewGame1() 
{
	// TODO: Add your command handler code here
//	SetActiveView(views[0]);	
}

void CMainFrame::OnUpdateViewGame1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
//	GetActiveView() == views[0] ? pCmdUI->Enable(0): pCmdUI->Enable(1);
}

void CMainFrame::OnViewGame2() 
{
	// TODO: Add your command handler code here
	//SetActiveView(views[1]);
}

void CMainFrame::OnUpdateViewGame2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//GetActiveView() == views[1] ? pCmdUI->Enable(0): pCmdUI->Enable(1);
}

void CMainFrame::OnViewGame3() 
{
	// TODO: Add your command handler code here
	//SetActiveView(views[2]);
}

void CMainFrame::OnUpdateViewGame3(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//GetActiveView() == views[2] ? pCmdUI->Enable(0): pCmdUI->Enable(1);
}

void CMainFrame::OnViewGame4() 
{
	// TODO: Add your command handler code here
	//SetActiveView(views[3]);
}

void CMainFrame::OnUpdateViewGame4(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//GetActiveView() == views[3] ? pCmdUI->Enable(0): pCmdUI->Enable(1);
}

void CMainFrame::OnViewGame5() 
{
	// TODO: Add your command handler code here
	//SetActiveView(views[4]);
}

void CMainFrame::OnUpdateViewGame5(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//GetActiveView() == views[4] ? pCmdUI->Enable(0): pCmdUI->Enable(1);	
}

void CMainFrame::OnViewExtendedview() 
{
	// TODO: Add your command handler code here
	m_extendedViewFlag == TRUE ? m_extendedViewFlag = FALSE :	m_extendedViewFlag = TRUE ;
	Globalfirsttime = 1;
	if(m_extendedViewFlag == TRUE)
	{
		
		SetWindowPos(&wndTop,40,10,610,540,SWP_SHOWWINDOW);
		m_wndToolBar.LoadToolBar(IDR_MAINFRAME_EXTENDED);
		/*m_wndStatusBar.SetPaneInfo(0,ID_SEPARATOR,0,355);
		m_wndStatusBar.SetPaneInfo(1,ID_SEPARATOR,0,55);
		m_wndStatusBar.SetPaneInfo(2,ID_SEPARATOR,0,35);
		m_wndStatusBar.SetPaneText(2,"WHITE");
		m_wndStatusBar.SetPaneInfo(3,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(3,"0:0:0");
		m_wndStatusBar.SetPaneInfo(4,ID_SEPARATOR,0,35);
		m_wndStatusBar.SetPaneText(4,"BLACK");
		m_wndStatusBar.SetPaneInfo(5,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(5,"0:0:0");
		*/
		m_wndStatusBar.SetPaneInfo(MESSAGEPANE,ID_SEPARATOR,0,300);	;
		m_wndStatusBar.SetPaneInfo(PLAYERNAME,ID_SEPARATOR,0,55);
		m_wndStatusBar.SetPaneInfo(WHITETIMENAME,ID_SEPARATOR,0,35);
		m_wndStatusBar.SetPaneText(WHITETIMENAME,"WHITE");
		m_wndStatusBar.SetPaneInfo(WHITETIME,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(WHITETIME,"0:0:0");
		m_wndStatusBar.SetPaneInfo(BLACKTIMENAME,ID_SEPARATOR,0,35);
		m_wndStatusBar.SetPaneText(BLACKTIMENAME,"BLACK");
		m_wndStatusBar.SetPaneInfo(BLACKTIME,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(BLACKTIME,"0:0:0");
		m_wndStatusBar.SetPaneInfo(PLAYERSIDE,ID_SEPARATOR,0,55);
	}
	else
	{
		SetWindowPos(&wndTop,40,10,388,470,SWP_SHOWWINDOW);
		m_wndToolBar.LoadToolBar(IDR_MAINFRAME);
		/*m_wndStatusBar.SetPaneInfo(0,ID_SEPARATOR,0,140);
		m_wndStatusBar.SetPaneInfo(1,ID_SEPARATOR,0,60);
		m_wndStatusBar.SetPaneInfo(2,ID_SEPARATOR,0,30);
		m_wndStatusBar.SetPaneText(2,"WHITE");
		m_wndStatusBar.SetPaneInfo(3,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(3,"0:0:0");
		m_wndStatusBar.SetPaneInfo(4,ID_SEPARATOR,0,30);
		m_wndStatusBar.SetPaneText(4,"BLACK");
		m_wndStatusBar.SetPaneInfo(5,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(5,"0:0:0");
		*/
		m_wndStatusBar.SetPaneInfo(MESSAGEPANE,ID_SEPARATOR,0,170);
		m_wndStatusBar.SetPaneInfo(PLAYERNAME,ID_SEPARATOR,0,30);
		m_wndStatusBar.SetPaneInfo(WHITETIMENAME,ID_SEPARATOR,0,30);
		m_wndStatusBar.SetPaneText(WHITETIMENAME,"WHITE");
		m_wndStatusBar.SetPaneInfo(WHITETIME,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(WHITETIME,"0:0:0");
		m_wndStatusBar.SetPaneInfo(BLACKTIMENAME,ID_SEPARATOR,0,30);
		m_wndStatusBar.SetPaneText(BLACKTIMENAME,"BLACK");
		m_wndStatusBar.SetPaneInfo(BLACKTIME,ID_SEPARATOR,0,40);
		m_wndStatusBar.SetPaneText(BLACKTIME,"0:0:0");
	}

	PostMessage(WM_PAINT);
}

void CMainFrame::OnUpdateViewExtendedview(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	m_extendedViewFlag == TRUE ? pCmdUI->SetCheck(1) :	pCmdUI->SetCheck(0) ;
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}

void CMainFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CFrameWnd::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	
}


void CMainFrame::OnHelpHttpwwwgeocitiescomraoavm() 
{
	// TODO: Add your command handler code here
	
}

