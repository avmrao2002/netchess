// HistoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "HistoryDlg.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistoryDlg dialog


CHistoryDlg::CHistoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistoryDlg)
	m_edit_history = _T("");
	//}}AFX_DATA_INIT
}

CHistoryDlg::CHistoryDlg(CWnd* pParent /*=NULL*/,CHistory *history,int historycount)
	: CDialog(CHistoryDlg::IDD, pParent)
{ 
	m_edit_history = _T(""); 
	m_History = history;
	m_iHistory = historycount;

}

void CHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoryDlg)
	DDX_Text(pDX, IDC_EDIT_HISTORY, m_edit_history);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHistoryDlg, CDialog)
	//{{AFX_MSG_MAP(CHistoryDlg)
	ON_BN_CLICKED(IDC_RADIO_EPD, OnRadioEpd)
	ON_BN_CLICKED(IDC_RADIO_FEN, OnRadioFen)
	ON_BN_CLICKED(IDC_RADIO_PGN, OnRadioPgn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryDlg message handlers

BOOL CHistoryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CStringArray cr;
	CButton *btn = (CButton*)GetDlgItem(IDC_RADIO_PGN);
	btn->SetCheck(1);
	m_edit_history = ((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetHistoryString(cr,0);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHistoryDlg::OnRadioEpd() 
{
	// TODO: Add your control notification handler code here
	m_edit_history = ((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetPositionHistoryString('E');
	UpdateData(FALSE);
}

void CHistoryDlg::OnRadioFen() 
{
	// TODO: Add your control notification handler code here
	m_edit_history = ((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetPositionHistoryString('F');
	UpdateData(FALSE);
}

void CHistoryDlg::OnRadioPgn() 
{
	// TODO: Add your control notification handler code here
	CStringArray cr;
	m_edit_history = ((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetHistoryString(cr,0);
	UpdateData(FALSE);
}
