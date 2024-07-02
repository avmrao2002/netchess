/////////////////////////////////////////////////////////////////////////////
// CEngine
#include "stdafx.h"
#include "ICSClient.h"
#include "NetChessView.h"

CICSClient::CICSClient()
{
	m_icsClientFlag = FALSE;	
}

CICSClient::~CICSClient()
{
}

int CICSClient::Initialize(CView* ncv)
{

   m_icsClientLoadedFlag = TRUE;
   
   return 1;
}

BOOL CICSClient::CreateICSClientProcess(VOID)
{
   return -1;
}

VOID CICSClient::WriteToICSServer(CString data)
{

}

void CICSClient::StopICSClient()
{

}

void CICSClient::StartICSClient()
{
}

int CICSClient::GetICSClientFlag()
{
	return m_icsClientFlag;
}

void CICSClient::CloseICSConnection()
{

}

VOID CICSClient::WriteToBoard(CString str)
{

}

void CICSClient::LoginToServer(CString userid, CString password)
{

}
