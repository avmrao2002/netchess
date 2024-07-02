// EngineLevelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "EngineLevelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEngineLevelDlg dialog


CEngineLevelDlg::CEngineLevelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEngineLevelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEngineLevelDlg)
	m_edit_conv_clock_mode = 0;
	m_edig_movestimecontrol = 40;
	m_edit_time_control = 5;
	//}}AFX_DATA_INIT
}


void CEngineLevelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEngineLevelDlg)
	DDX_Text(pDX, IDC_EDIT_CONV_CLOCK_MODE, m_edit_conv_clock_mode);
	DDV_MinMaxInt(pDX, m_edit_conv_clock_mode, 0, 100);
	DDX_Text(pDX, IDC_EDIT_MOVESTIMECONTROL, m_edig_movestimecontrol);
	DDV_MinMaxInt(pDX, m_edig_movestimecontrol, 0, 300);
	DDX_Text(pDX, IDC_EDIT_TIME_CONTROL, m_edit_time_control);
	DDV_MinMaxInt(pDX, m_edit_time_control, 0, 5000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEngineLevelDlg, CDialog)
	//{{AFX_MSG_MAP(CEngineLevelDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEngineLevelDlg message handlers
