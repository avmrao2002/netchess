// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "NetChessDoc.h"
#include "NetChessView.h"
#include "ClientSocket.h"
#include "ServerSocket.h"
#include "AcceptDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions

void CServerSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	 
	CClientSocket *ClientSocket = new CClientSocket();
	Accept(*ClientSocket);
	CString name; unsigned int port;
 
	if(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetClientSocket(FALSE) != NULL)
	{
		ClientSocket->GetPeerName(name,port);
		((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->SetObserverSocket(ClientSocket);	
		ClientSocket->AsyncSelect(FD_READ | FD_CLOSE);		
		return;
	}
	ClientSocket->GetPeerName(name,port);
	ClientSocket->m_ipaddress = name;
	ClientSocket->m_port = port;
	CString msg;
	msg.Format(" requested for playing chess");
	msg = name + msg;
	CAcceptDlg dlg;
	dlg.m_AcceptString = msg;
	if(dlg.DoModal() == IDOK)
	{		
		((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->SetClientSocket(ClientSocket, FALSE);	
		ClientSocket->AsyncSelect(FD_READ | FD_CLOSE);
		ClientSocket->m_clientId = (int)time(0);
		unsigned char data[50];
		memset(data,'\0',50);
		data[0] = CONNECT_ACCEPT;
		data[1] = dlg.m_pieceSide; 
		memcpy(&data[2],&ClientSocket->m_clientId,4);
		strcpy((char*)&data[6],((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_edit_name.GetBuffer(0));	
		char clength[6];
		int length = ((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_edit_name.GetLength()+7;
		memcpy(clength,&length,4);
		ClientSocket->Send(clength,4);	 
		ClientSocket->Send(&data,length);	 			 
		((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->SetPieceSide(dlg.m_pieceSide);
	}
	else
	{
		unsigned char data= CONNECT_REJECT;
		char clength[5];
		int length = 1;
		memcpy(clength,&length,4);
		ClientSocket->Send(clength,4);	 
		ClientSocket->Send(&data,length);	 			 
		ClientSocket->ShutDown(2);
		ClientSocket->Close();
		delete ClientSocket;
		ClientSocket = NULL;
		return;
	}	
	CAsyncSocket::OnAccept(nErrorCode);
}

void CServerSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	AfxMessageBox("Connection closed");	
	CAsyncSocket::OnClose(nErrorCode);
}

void CServerSocket::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnConnect(nErrorCode);
}

void CServerSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnReceive(nErrorCode);
}

void CServerSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnSend(nErrorCode);
}

int CServerSocket::Receive(void* lpBuf, int nBufLen, int nFlags) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CAsyncSocket::Receive(lpBuf, nBufLen, nFlags);
}

int CServerSocket::Send(const void* lpBuf, int nBufLen, int nFlags) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CAsyncSocket::Send(lpBuf, nBufLen, nFlags);
}
void CServerSocket::CreateServer(int Port)
{	 	 
	if(	this->Create(Port) == 0)
	{
		AfxMessageBox("Chess is already running");
		exit(0);
	}
	Listen(); 
	AsyncSelect(FD_ACCEPT | FD_CLOSE);	 
}
void CServerSocket::SetInfo(int portnumber)
{
	m_portnumber = portnumber;
}