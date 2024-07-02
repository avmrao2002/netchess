// EnterMoveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "EnterMoveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnterMoveDlg dialog


CEnterMoveDlg::CEnterMoveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnterMoveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnterMoveDlg)
	m_edit_move = _T("");
	//}}AFX_DATA_INIT
}


void CEnterMoveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnterMoveDlg)
	DDX_Text(pDX, IDC_EDIT_MOVE, m_edit_move);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnterMoveDlg, CDialog)
	//{{AFX_MSG_MAP(CEnterMoveDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnterMoveDlg message handlers
