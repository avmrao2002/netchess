// GroupButton.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "GroupButton.h"
#include "Netchessview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGroupButton

CGroupButton::CGroupButton()
{
}

CGroupButton::~CGroupButton()
{
}


BEGIN_MESSAGE_MAP(CGroupButton, CButton)
	//{{AFX_MSG_MAP(CGroupButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
//	ON_MESSAGE(WM_COMMAND,OnCommand)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGroupButton message handlers
BOOL CGroupButton::OnCommand(WPARAM wParam,LPARAM lParam)
{
	short id,id1;
	char id2[4];
	memcpy(&id2,&wParam,4);
	memcpy(&id,&id2[0],2);
	memcpy(&id1,&id2[2],2);
	switch(id)
	{
		
		case ID_EXTRA_WHITE_COMPUTER:
				((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->OnButtonWhiteRadioButtonComputer();
		break;
		case ID_EXTRA_WHITE_HUMAN:
			((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->OnButtonWhiteRadioButtonHuman();
		break;
		case ID_EXTRA_BLACK_COMPUTER:
			((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->OnButtonBlackRadioButtonComputer();
		break;
		case ID_EXTRA_BLACK_HUMAN:
			((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->OnButtonBlackRadioButtonHuman();
		break;
		default:
			break;
	}
	return TRUE;
}
