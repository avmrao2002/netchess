// PGNGameInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "PGNGameInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPGNGameInfoDlg dialog


CPGNGameInfoDlg::CPGNGameInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPGNGameInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPGNGameInfoDlg)
	m_edit_black = _T("");
	m_edit_date = _T("");
	m_edit_event = _T("");
	m_edit_result = _T("");
	m_edit_round = _T("");
	m_edit_site = _T("");
	m_edit_white = _T("");
	m_edit_fenstring = _T("");
	m_edit_blackelo = _T("");
	m_edit_eco = _T("");
	m_event_date = _T("");
	m_edit_playcount = _T("");
	m_edit_whiteelo = _T("");
	//}}AFX_DATA_INIT
}


void CPGNGameInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPGNGameInfoDlg)
	DDX_Text(pDX, IDC_EDIT_BLACK, m_edit_black);
	DDX_Text(pDX, IDC_EDIT_DATE, m_edit_date);
	DDX_Text(pDX, IDC_EDIT_EVENT, m_edit_event);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_edit_result);
	DDX_Text(pDX, IDC_EDIT_ROUND, m_edit_round);
	DDX_Text(pDX, IDC_EDIT_SITE, m_edit_site);
	DDX_Text(pDX, IDC_EDIT_WHITE, m_edit_white);
	DDX_Text(pDX, IDC_EDIT_FENSTRING, m_edit_fenstring);
	DDX_Text(pDX, IDC_EDIT_BLACKELO, m_edit_blackelo);
	DDX_Text(pDX, IDC_EDIT_ECO, m_edit_eco);
	DDX_Text(pDX, IDC_EDIT_EVENT_DATE, m_event_date);
	DDX_Text(pDX, IDC_EDIT_PLAYCOUNT, m_edit_playcount);
	DDX_Text(pDX, IDC_EDIT_WHITEELO, m_edit_whiteelo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPGNGameInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CPGNGameInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPGNGameInfoDlg message handlers

BOOL CPGNGameInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CPGNGameInfoDlg::ClearDialog()
{
	m_edit_black = _T("");
	m_edit_date = _T("");
	m_edit_event = _T("");
	m_edit_result = _T("");
	m_edit_round = _T("");
	m_edit_site = _T("");
	m_edit_white = _T("");
	m_edit_fenstring = _T("");
	m_edit_blackelo = _T("");
	m_edit_eco = _T("");
	m_event_date = _T("");
	m_edit_playcount = _T("");
	m_edit_whiteelo = _T("");
	m_event_date = _T("");
}
