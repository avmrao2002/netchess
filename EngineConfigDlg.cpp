// EngineConfigDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "EngineConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEngineConfigDlg dialog


CEngineConfigDlg::CEngineConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEngineConfigDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEngineConfigDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT	
	m_chessProtocol = NOPROTOCOL;
}


void CEngineConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEngineConfigDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEngineConfigDlg, CDialog)
	//{{AFX_MSG_MAP(CEngineConfigDlg)
	ON_BN_CLICKED(IDC_RADIO_UCII, OnRadioUcii)
	ON_BN_CLICKED(IDC_RADIO_UCIII, OnRadioUciii)
	ON_BN_CLICKED(IDC_RADIO_WBI, OnRadioWbi)
	ON_BN_CLICKED(IDC_RADIO_WBII, OnRadioWbii)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEngineConfigDlg message handlers

void CEngineConfigDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

BOOL CEngineConfigDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CButton *wnd = NULL;
	switch(m_chessProtocol)
	{
		case WB_I:
			wnd = (CButton*)GetDlgItem(IDC_RADIO_WBI);
			break;
		case WB_II:
			wnd = (CButton*)GetDlgItem(IDC_RADIO_WBII);
			break;
		case UCI_I:
			wnd = (CButton*)GetDlgItem(IDC_RADIO_UCII);
			break;
		case UCI_II:
			wnd = (CButton*)GetDlgItem(IDC_RADIO_UCIII);
			break;
	}
	if(wnd != NULL)
		wnd->SetCheck(1);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEngineConfigDlg::OnRadioUcii() 
{
	// TODO: Add your control notification handler code here
	m_chessProtocol = UCI_I;
}

void CEngineConfigDlg::OnRadioUciii() 
{
	// TODO: Add your control notification handler code here
	m_chessProtocol = UCI_II;
}

void CEngineConfigDlg::OnRadioWbi() 
{
	// TODO: Add your control notification handler code here
	m_chessProtocol = WB_I;
}

void CEngineConfigDlg::OnRadioWbii() 
{
	// TODO: Add your control notification handler code here
	m_chessProtocol = WB_II;
}
