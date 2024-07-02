// TimeControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "TimeControlDlg.h"
#include "NetChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeControlDlg dialog


CTimeControlDlg::CTimeControlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeControlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimeControlDlg)
	m_check_infinite = FALSE;
	m_edit_wb_base_time = 2;
	m_wb_exact_seconds = 20;
	m_edit_uci_binc = 12;
	m_edit_uci_btime = 300;
	m_edit_uci_movetime = 20;
	m_edit_uci_winc = 12;
	m_edit_uci_wtime = 300;
	m_edit_wb_inc_time = 12;
	m_edit_wb_number_of_moves = 40;
	m_edit_wb_time = 5;
	//}}AFX_DATA_INIT
	m_radio_clock_type = NOTIME;
}


void CTimeControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeControlDlg)
	DDX_Check(pDX, IDC_CHECK_INFINITE, m_check_infinite);
	DDX_Text(pDX, IDC_EDIT_WB_BASE_TIME, m_edit_wb_base_time);
	DDX_Text(pDX, IDC_EDIT_WB_EXACT_SECONDS, m_wb_exact_seconds);
	DDX_Text(pDX, IDC_EDIT_UCI_BINC, m_edit_uci_binc);
	DDX_Text(pDX, IDC_EDIT_UCI_BTIME, m_edit_uci_btime);
	DDX_Text(pDX, IDC_EDIT_UCI_MOVETIME, m_edit_uci_movetime);
	DDX_Text(pDX, IDC_EDIT_UCI_WINC, m_edit_uci_winc);
	DDX_Text(pDX, IDC_EDIT_UCI_WTIME, m_edit_uci_wtime);
	DDX_Text(pDX, IDC_EDIT_WB_INC_TIME, m_edit_wb_inc_time);
	DDX_Text(pDX, IDC_EDIT_WB_NUMBER_OF_MOVES, m_edit_wb_number_of_moves);
	DDX_Text(pDX, IDC_EDIT_WB_TIME, m_edit_wb_time);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTimeControlDlg, CDialog)
	//{{AFX_MSG_MAP(CTimeControlDlg)
	ON_BN_CLICKED(IDC_RADIO_CONVENTIONAL_CLOCK, OnRadioConventionalClock)
	ON_BN_CLICKED(IDC_RADIO_EXACT_NUMBER, OnRadioExactNumber)
	ON_BN_CLICKED(IDC_RADIO_INCREAMENTAL_CLOCK, OnRadioIncreamentalClock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeControlDlg message handlers

void CTimeControlDlg::OnRadioConventionalClock() 
{
	// TODO: Add your control notification handler code here
	m_radio_clock_type = CONVENTIONAL;
}

void CTimeControlDlg::OnRadioExactNumber() 
{
	// TODO: Add your control notification handler code here
	m_radio_clock_type = MOVETIME;
}

void CTimeControlDlg::OnRadioIncreamentalClock() 
{
	// TODO: Add your control notification handler code here
	m_radio_clock_type = ICSTYPE;
}

void CTimeControlDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);	
	CDialog::OnOK();
}

BOOL CTimeControlDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
		// TODO: Add extra initialization here
	CButton *wnd = (CButton*)GetDlgItem(IDC_RADIO_CONVENTIONAL_CLOCK);
	wnd->SetCheck(1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
