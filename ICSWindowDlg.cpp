// ICSWindowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "ICSWindowDlg.h"
#include "ClientSocket.h"
#include "NetChessView.h"
#include "ICSPlayersListDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define LOG_ICS_UPDATE_TIMER 6000
/////////////////////////////////////////////////////////////////////////////
// CICSWindowDlg dialog


CICSWindowDlg::CICSWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CICSWindowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CICSWindowDlg)
	m_edit_command = _T("");
	m_edit_ics_log = _T("");
	m_edit_play = _T("");
	m_edit_play_type = _T("");
	m_edit_message = _T("");
	m_check_expand_move = FALSE;
	//}}AFX_DATA_INIT
}


void CICSWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CICSWindowDlg)
	DDX_Text(pDX, IDC_EDIT_COMMAND, m_edit_command);
	DDX_Text(pDX, IDC_EDIT_ICS_LOG, m_edit_ics_log);
	DDX_Text(pDX, IDC_EDIT_PLAY, m_edit_play);
	DDX_Text(pDX, IDC_EDIT_PLAY_TYPE, m_edit_play_type);
	DDX_Text(pDX, IDC_EDIT_MESSAGE, m_edit_message);
	DDX_Check(pDX, IDC_CHECK_EXPAND_MOVE, m_check_expand_move);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CICSWindowDlg, CDialog)
	//{{AFX_MSG_MAP(CICSWindowDlg)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_BN_CLICKED(IDC_BUTTON_ABORT, OnButtonAbort)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_SEEK, OnButtonSeek)
	ON_BN_CLICKED(IDC_BUTTON_QUIT, OnButtonQuit)
	ON_BN_CLICKED(IDC_BUTTON_DRAW, OnButtonDraw)
	ON_BN_CLICKED(IDC_BUTTON_GAMES, OnButtonGames)
	ON_BN_CLICKED(IDC_BUTTON_PLAYERS, OnButtonPlayers)
	ON_BN_CLICKED(IDC_BUTTON_RESIGN, OnButtonResign)
	ON_BN_CLICKED(IDC_BUTTON_SHOUT_0, OnButtonShout0)
	ON_BN_CLICKED(IDC_BUTTON_SHOUT_1, OnButtonShout1)
	ON_BN_CLICKED(IDC_BUTTON_SOUGHT, OnButtonSought)
	ON_BN_CLICKED(IDC_BUTTON_VIEW, OnButtonView)
	ON_BN_CLICKED(IDC_BUTTON_WHO, OnButtonWho)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_STYLE12, OnButtonStyle12)
	ON_BN_CLICKED(IDC_BUTTON_ACCEPT, OnButtonAccept)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_LIST, OnButtonViewList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CICSWindowDlg message handlers

void CICSWindowDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	//if(m_edit_ics_log != m_pICSClient->m_icsLog)
	{
	//	m_edit_ics_log = m_pICSClient->m_icsLog;
	}
	//UpdateData(FALSE);
	CWnd* wnd= GetDlgItem(IDC_EDIT_ICS_LOG);
	wnd->PostMessage(WM_VSCROLL,SB_BOTTOM,0);	
	wnd= GetDlgItem(IDC_EDIT_MESSAGE);
	wnd->PostMessage(WM_VSCROLL,SB_BOTTOM,0);	
	CDialog::OnTimer(nIDEvent);
}

void CICSWindowDlg::OnButtonGo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	
	//m_pICSClient->WriteToICSServer(m_edit_command);
	//m_edit_ics_log = m_pICSClient->m_icsLog;
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = m_edit_command+"\r\n";
		pClientSocket->Send(str, str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}

	UpdateData(FALSE);
}

void CICSWindowDlg::Update(int id)
{
	if(id == IDC_EDIT_ICS_LOG)
	{
		CWnd *wnd = (CWnd*)GetDlgItem(IDC_EDIT_ICS_LOG);
		wnd->SetWindowText(m_edit_ics_log);
		wnd->PostMessage(WM_PAINT);
	}
	else 
	{
		CWnd *wnd = (CWnd*)GetDlgItem(IDC_EDIT_MESSAGE);
		wnd->SetWindowText(m_edit_message);
		wnd->PostMessage(WM_PAINT);
	}
}

BOOL CICSWindowDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//	CWnd* wnd= GetDlgItem(IDC_EDIT_ICS_LOG);
//	wnd->PostMessage(WM_VSCROLL,SB_BOTTOM,0);	
	SetTimer(LOG_ICS_UPDATE_TIMER,100,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CICSWindowDlg::OnOK() 
{
	// TODO: Add extra validation here	
	CDialog::OnOK();
}

void CICSWindowDlg::OnButtonAbort() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "abort\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonPlay() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "play " +m_edit_play + "\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}
void CICSWindowDlg::SendPlay(int index) 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str;
		str.Format("play %d\r\n",index);
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonSeek() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "seek 1\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonQuit() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "quit\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		//(CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->SetClientSocket
		((CNetChessView*)m_pView)->m_pClientICSSocket = NULL;
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}
void CICSWindowDlg::SetView(CView *view)
{
	m_pView = view;
}

void CICSWindowDlg::OnButtonDraw() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "draw\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonGames() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "games\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonPlayers() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "players\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonResign() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "resign\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonShout0() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "shout 0\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonShout1() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "shout 1\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonSought() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "sought\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonView() 
{
	// TODO: Add your control notification handler code here
	HANDLE hText = NULL;
	HANDLE hData;//, hClipData; 
	LPSTR lpData;//, lpClipData;                           /* pointers to clip data */
	LPSTR           lpszText;
//	CString str = GetFileSaveString();
	CString str  = m_edit_ics_log + m_edit_message;
	
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

void CICSWindowDlg::OnButtonWho() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "who\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonHelp() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "help\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonClear() 
{
	// TODO: Add your control notification handler code here
	m_edit_ics_log = "";
	m_edit_message = "";
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonStyle12() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "set style 12\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonAccept() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "accept\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);	
}

void CICSWindowDlg::OnButtonOpen() 
{
	// TODO: Add your control notification handler code here
	CClientSocket *pClientSocket = (CClientSocket*)((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(TRUE);
	if(pClientSocket != NULL)
	{
		CString str = "open\r\n";
		pClientSocket->Send(str.GetBuffer(0),str.GetLength());
		m_edit_ics_log = m_edit_ics_log + str;
	}
	UpdateData(FALSE);
}

void CICSWindowDlg::OnButtonViewList() 
{
	UpdateData(TRUE);
	CString str = m_edit_ics_log + "\r\n" + m_edit_message;
	CICSPlayersListDlg dlg;
	dlg.m_edit_ics_list = str;
	dlg.DoModal();		// TODO: Add your control notification handler code here
	
}

void CICSWindowDlg::OnButtonViewLastMove() 
{
	// TODO: Add your control notification handler code here
	
}
