// ICSConfigureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "ICSConfigureDlg.h"
#include "NetChessView.h"
#include "ClientSocket.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CICSConfigureDlg dialog


CICSConfigureDlg::CICSConfigureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CICSConfigureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CICSConfigureDlg)
	m_edit_password = _T("");
	m_edit_port_number = 5000;
	m_edit_user_name = _T("guest");
	m_static_myname = _T("");
	//}}AFX_DATA_INIT
	m_ics_server_name = "";
}


void CICSConfigureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CICSConfigureDlg)
	DDX_Control(pDX, IDC_COMBO_ICS_SERVER_NAME, m_cobmo_ics_server_name);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_edit_password);
	DDX_Text(pDX, IDC_EDIT_PORT_NUMBER, m_edit_port_number);
	DDX_Text(pDX, IDC_EDIT_USER_NAME, m_edit_user_name);
	DDX_Text(pDX, IDC_STATIC_MYNAME, m_static_myname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CICSConfigureDlg, CDialog)
	//{{AFX_MSG_MAP(CICSConfigureDlg)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, OnButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, OnButtonDisconnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CICSConfigureDlg message handlers

void CICSConfigureDlg::OnButtonConnect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	CWnd *wnd = GetDlgItem(IDC_STATIC_STATUS);
	CString str;
	wnd->GetWindowText(str);
	if(str == "Connecting..." && ((CNetChessView*)m_pView)->m_pClientICSSocket != NULL)
	{
		((CNetChessView*)m_pView)->m_pClientICSSocket->Close();
		delete ((CNetChessView*)m_pView)->m_pClientICSSocket;
		((CNetChessView*)m_pView)->m_pClientICSSocket = NULL;
		AfxMessageBox("Reconnecting ...");
	}

	CClientSocket *sock = NULL;
	if(((CNetChessView*)m_pView)->m_pClientICSSocket == NULL)
	{
		m_cobmo_ics_server_name.GetWindowText(m_ics_server_name);
		sock = new CClientSocket();
		((CNetChessView*)m_pView)->m_pClientICSSocket = sock;

		sock->SetInfo(m_ics_server_name, m_edit_port_number);

		sock->Create();

		sock->SetICSFlag(TRUE);		
		int error = -1;
		if((error = sock->Connect(m_ics_server_name, m_edit_port_number)) ==0)
		{
			//error = GetLastError());
			//if(error > -1)
			{
				CWnd *wnd = GetDlgItem(IDC_STATIC_STATUS);
				wnd->SetWindowText("Connecting...");
			}
		}
		else
		{
			CWnd *wnd = GetDlgItem(IDC_STATIC_STATUS);
			wnd->SetWindowText("Not Connected");
			delete ((CNetChessView*)m_pView)->m_pClientICSSocket;
			((CNetChessView*)m_pView)->m_pClientICSSocket = NULL;
		}		
	}
	else
		AfxMessageBox("Already connected to ICS Server");

	
}

void CICSConfigureDlg::SetView(CView *view)
{
	m_pView = view;
}

void CICSConfigureDlg::Login()
{
	CClientSocket *sock = (CClientSocket*)((CNetChessView*)m_pView)->m_pClientICSSocket;	
	m_edit_user_name = m_edit_user_name + "\r\n";
	sock->Send(m_edit_user_name.GetBuffer(0),m_edit_user_name.GetLength());
	Sleep(1000);
	m_edit_password = m_edit_password + "\r\n";
	sock->Send(m_edit_password.GetBuffer(0),m_edit_password.GetLength());
	Sleep(1000);
	CString str = "style 12\r\n";
	sock->Send(str.GetBuffer(0), str.GetLength());
	CWnd *wnd = GetDlgItem(IDC_STATIC_STATUS);
	wnd->SetWindowText("Connected.");
	((CNetChessView*)m_pView)->m_icsFlag = TRUE;

}

BOOL CICSConfigureDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CWnd *wnd = GetDlgItem(IDC_COMBO_ICS_SERVER_NAME);
	wnd->SetWindowText("freechess.org");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CICSConfigureDlg::OnButtonDisconnect() 
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);
	CWnd *wnd = GetDlgItem(IDC_STATIC_STATUS);	
	if(((CNetChessView*)m_pView)->m_pClientICSSocket != NULL)
	{
		((CNetChessView*)m_pView)->m_pClientICSSocket->Close();
		delete ((CNetChessView*)m_pView)->m_pClientICSSocket;
		((CNetChessView*)m_pView)->m_pClientICSSocket = NULL;		
		wnd->SetWindowText("Disconnected");
	}
	else
		wnd->SetWindowText("Not connected");


}
