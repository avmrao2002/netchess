// ObserversDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "ObserversDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CObserversDlg dialog


CObserversDlg::CObserversDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CObserversDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CObserversDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CObserversDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CObserversDlg)
	DDX_Control(pDX, IDC_LIST_OBSERVERS, m_list_observers);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CObserversDlg, CDialog)
	//{{AFX_MSG_MAP(CObserversDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CObserversDlg message handlers

BOOL CObserversDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	for(int i=0;i<m_stringArray.GetSize();i++)
	{
		m_list_observers.AddString(m_stringArray.ElementAt(i));
	}
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
