// GoToMoveHistoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "GoToMoveHistoryDlg.h"
#include "NetChessView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoToMoveHistoryDlg dialog


CGoToMoveHistoryDlg::CGoToMoveHistoryDlg(CWnd* pParent /*=NULL*/)
: CDialog(CGoToMoveHistoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGoToMoveHistoryDlg)
	//}}AFX_DATA_INIT
}


void CGoToMoveHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGoToMoveHistoryDlg)
	DDX_Control(pDX, IDC_LIST_HISTORY, m_move_history);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGoToMoveHistoryDlg, CDialog)
	//{{AFX_MSG_MAP(CGoToMoveHistoryDlg)
	ON_LBN_SELCHANGE(IDC_LIST_HISTORY, OnSelchangeListHistory)
	ON_LBN_DBLCLK(IDC_LIST_HISTORY, OnDblclkListHistory)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoToMoveHistoryDlg message handlers

void CGoToMoveHistoryDlg::OnSelchangeListHistory() 
{
	// TODO: Add your control notification handler code here
	CListBox *lb = (CListBox*)GetDlgItem(IDC_LIST_HISTORY);
	int ret = lb->GetCurSel();
	if(ret != LB_ERR)
	{
		((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->MoveTo(ret+1);
	}
}

void CGoToMoveHistoryDlg::OnDblclkListHistory() 
{
	// TODO: Add your control notification handler code here
	
}

BOOL CGoToMoveHistoryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
//	CListBox *lb = (CListBox*)GetDlgItem(IDC_LIST_HISTORY);
	for(int i=0;i<m_historystring.GetSize();i++)
	{
		m_move_history.InsertString(-1,m_historystring.GetAt(i));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
