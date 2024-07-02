// ICSMessageChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "ICSMessageChatDlg.h"
#include "NetChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CICSMessageChatDlg dialog


CICSMessageChatDlg::CICSMessageChatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CICSMessageChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CICSMessageChatDlg)
	m_edit_send_message = _T("");
	m_edit_receive_message = _T("");
	//}}AFX_DATA_INIT
}


void CICSMessageChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CICSMessageChatDlg)
	DDX_Text(pDX, IDC_EDIT_MESSAGE, m_edit_send_message);
	DDX_Text(pDX, IDC_EDIT_RECEIVE_MESSAGE, m_edit_receive_message);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CICSMessageChatDlg, CDialog)
	//{{AFX_MSG_MAP(CICSMessageChatDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CICSMessageChatDlg message handlers

void CICSMessageChatDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	unsigned char data[1001];
	memset(data,'\0',1001);
	CString textmsg;
	textmsg.Format("%s tell %s %s",TEXT,((CNetChessView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView())->m_pICSConfigureDlg->m_opponent_name,m_edit_send_message);
	((CNetChessView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView())->SendICSMessage((char*)textmsg.GetBuffer(0),textmsg.GetLength());

	m_edit_receive_message += m_edit_send_message +  (CString)"\r\n";
	m_edit_send_message = "";

	UpdateData(FALSE);
	CWnd* wnd= GetDlgItem(IDC_EDIT_RECEIVE_MESSAGE);
	wnd->PostMessage(WM_VSCROLL,SB_BOTTOM,0);

}
void CICSMessageChatDlg::SetReceiveData(unsigned char* data)
{
	 
	m_edit_receive_message += (data + (CString)"\r\n");
	UpdateData(FALSE);
	CWnd* wnd= GetDlgItem(IDC_EDIT_RECEIVE_MESSAGE);
	wnd->PostMessage(WM_VSCROLL,SB_BOTTOM,0);
	
}

