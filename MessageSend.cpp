// MessageSend.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "MessageSend.h"
#include "NetChessDoc.h"
#include "NetChessView.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMessageSend dialog


CMessageSend::CMessageSend(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageSend::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMessageSend)
	m_edit_message = _T("");
	m_edit_receive_message = _T("");
	//}}AFX_DATA_INIT
}


void CMessageSend::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMessageSend)
	DDX_Text(pDX, IDC_EDIT_MESSAGE, m_edit_message);
	DDV_MaxChars(pDX, m_edit_message, 1000);
	DDX_Text(pDX, IDC_EDIT_RECEIVE_MESSAGE, m_edit_receive_message);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMessageSend, CDialog)
	//{{AFX_MSG_MAP(CMessageSend)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMessageSend message handlers

void CMessageSend::OnOK() 
{
	//msgDlg.m_edit_send_message
	UpdateData(TRUE);
	unsigned char data[1001];
	memset(data,'\0',1001);
	if(((CNetChessView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView())->m_observerFlag == TRUE)
	{
		int clientid = ((CClientSocket*)((CNetChessView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView())->m_pClientSocket)->m_clientId;
		data[0] = OBSERVER_TEXT;
		CString textmsg = m_edit_name + ": " + m_edit_message;	
		memcpy(&data[1],&clientid,4);
		sprintf((char*)&data[5],"%s",textmsg.GetBuffer(0));
		((CNetChessView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView())->SendSockData(data,textmsg.GetLength()+6);	
	}
	else
	{
		CString textmsg;
		textmsg.Format("%s %s:%s",TEXT, m_edit_name, m_edit_message);	 			
		((CNetChessView*)((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView())->SendSockData((unsigned char*)textmsg.GetBuffer(0),textmsg.GetLength());	
	}
	m_edit_receive_message += (CString)m_edit_name + ": " + m_edit_message +  (CString)"\r\n";
	
	//textmsg.ReleaseBuffer(0); 
	m_edit_message = "";
	UpdateData(FALSE);
	CWnd* wnd= GetDlgItem(IDC_EDIT_RECEIVE_MESSAGE);
	wnd->PostMessage(WM_VSCROLL,SB_BOTTOM,0);
	//CDialog::OnOK();
}
void CMessageSend::SetReceiveData(unsigned char* data)
{
	 
	m_edit_receive_message += (data + (CString)"\r\n");
	UpdateData(FALSE);
	CWnd* wnd= GetDlgItem(IDC_EDIT_RECEIVE_MESSAGE);
	wnd->PostMessage(WM_VSCROLL,SB_BOTTOM,0);
	
}

void CMessageSend::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
