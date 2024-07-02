// GameStateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "GameStateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGameStateDlg dialog


CGameStateDlg::CGameStateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGameStateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGameStateDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGameStateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGameStateDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGameStateDlg, CDialog)
	//{{AFX_MSG_MAP(CGameStateDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameStateDlg message handlers
