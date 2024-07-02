// UCIEngineOptions.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "UCIEngineOptions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUCIEngineOptions dialog


CUCIEngineOptions::CUCIEngineOptions(CWnd* pParent /*=NULL*/)
	: CDialog(CUCIEngineOptions::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUCIEngineOptions)
	m_edit_read_options = _T("");
	m_edit_set_options = _T("");
	//}}AFX_DATA_INIT
	m_arrSetOptions.RemoveAll();
}


void CUCIEngineOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUCIEngineOptions)
	DDX_Control(pDX, IDC_LIST_SET_OPTIONS, m_lb_set_options);
	DDX_Text(pDX, IDC_EDIT_READ_OPTIONS, m_edit_read_options);
	DDX_Text(pDX, IDC_EDIT_SET_OPTIONS, m_edit_set_options);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUCIEngineOptions, CDialog)
	//{{AFX_MSG_MAP(CUCIEngineOptions)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_LBN_SELCHANGE(IDC_LIST_SET_OPTIONS, OnSelchangeListSetOptions)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUCIEngineOptions message handlers

void CUCIEngineOptions::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_lb_set_options.AddString(m_edit_set_options);
	m_edit_set_options = "";
	UpdateData(FALSE);
}

void CUCIEngineOptions::OnSelchangeListSetOptions() 
{
	// TODO: Add your control notification handler code here
	
}

void CUCIEngineOptions::OnOK() 
{
	// TODO: Add extra validation here
	for(int i = 0; i < m_lb_set_options.GetCount(); i++)
	{
		CString str;
		m_lb_set_options.GetText(i,str);
		m_arrSetOptions.Add(str);		
	}
					
	CDialog::OnOK();
}
