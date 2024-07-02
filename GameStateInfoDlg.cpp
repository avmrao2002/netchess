// GameStateInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "GameStateInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGameStateInfoDlg dialog


CGameStateInfoDlg::CGameStateInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGameStateInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGameStateInfoDlg)
	m_check_black_king = FALSE;
	m_check_black_O_O = FALSE;
	m_check_black_O_O_O = FALSE;
	m_check_black_rook_a = FALSE;
	m_check_black_root_h = FALSE;
	m_check_white_king = FALSE;
	m_check_white_O_O = FALSE;
	m_check_white_O_O_O = FALSE;
	m_check_white_rook_a = FALSE;
	m_check_white_rook_h = FALSE;
	//}}AFX_DATA_INIT
}


void CGameStateInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGameStateInfoDlg)
	DDX_Check(pDX, IDC_CHECK_BLACK_KING, m_check_black_king);
	DDX_Check(pDX, IDC_CHECK_BLACK_O_O, m_check_black_O_O);
	DDX_Check(pDX, IDC_CHECK_BLACK_O_O_O, m_check_black_O_O_O);
	DDX_Check(pDX, IDC_CHECK_BLACK_ROOK_A, m_check_black_rook_a);
	DDX_Check(pDX, IDC_CHECK_BLACK_ROOK_H, m_check_black_root_h);
	DDX_Check(pDX, IDC_CHECK_WHITE_KING, m_check_white_king);
	DDX_Check(pDX, IDC_CHECK_WHITE_O_O, m_check_white_O_O);
	DDX_Check(pDX, IDC_CHECK_WHITE_O_O_O, m_check_white_O_O_O);
	DDX_Check(pDX, IDC_CHECK_WHITE_ROOK_A, m_check_white_rook_a);
	DDX_Check(pDX, IDC_CHECK_WHITE_ROOT_H, m_check_white_rook_h);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGameStateInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CGameStateInfoDlg)
	ON_BN_CLICKED(IDC_RADIO_BLACK, OnRadioBlack)
	ON_BN_CLICKED(IDC_RADIO_WHITE, OnRadioWhite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameStateInfoDlg message handlers

void CGameStateInfoDlg::OnRadioBlack() 
{
	// TODO: Add your control notification handler code here
	m_pieceSide = BLACK;
}

void CGameStateInfoDlg::OnRadioWhite() 
{
	// TODO: Add your control notification handler code here
	m_pieceSide = WHITE;
}

BOOL CGameStateInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	if(m_pieceSide ==WHITE)
	{
		CButton *btn = (CButton*)GetDlgItem(IDC_RADIO_WHITE);
		btn->SetCheck(1);
	}
	else
	{
		CButton *btn = (CButton*)GetDlgItem(IDC_RADIO_BLACK);
		btn->SetCheck(1);
	}
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
