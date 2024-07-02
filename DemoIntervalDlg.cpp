// DemoIntervalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "DemoIntervalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoIntervalDlg dialog


CDemoIntervalDlg::CDemoIntervalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoIntervalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemoIntervalDlg)
	m_edit_demo_interval = 1;
	//}}AFX_DATA_INIT
}


void CDemoIntervalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoIntervalDlg)
	DDX_Text(pDX, IDC_EDIT_DEMO_INTERVAL, m_edit_demo_interval);
	DDV_MinMaxInt(pDX, m_edit_demo_interval, 1, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDemoIntervalDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoIntervalDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoIntervalDlg message handlers

void CDemoIntervalDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
