// NetChessLogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "NetChessView.h"
#include "NetChessLogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetChessLogDlg dialog


CNetChessLogDlg::CNetChessLogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetChessLogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetChessLogDlg)
	m_edit_netchess_log = _T("");
	//}}AFX_DATA_INIT
}


void CNetChessLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetChessLogDlg)
	DDX_Text(pDX, IDC_EDIT_NETCHESS_LOG, m_edit_netchess_log);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNetChessLogDlg, CDialog)
	//{{AFX_MSG_MAP(CNetChessLogDlg)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetChessLogDlg message handlers

BOOL CNetChessLogDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNetChessLogDlg::OnButtonClear() 
{
	if(m_edit_netchess_log.IsEmpty())
		return;
	// TODO: Add your control notification handler code here	
	if(AfxMessageBox("Do you want to clear the Log stored the in the file?",MB_YESNO) == IDYES)
	{
		CString filename = ".\\" + ((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_edit_name + "_Log.txt";
		CFile file;
		if(file.Open(filename,CFile::modeCreate| CFile::shareDenyNone) ==0)
		{
			CString str = "Could not clear the log file "+ filename;
			AfxMessageBox(str);
			return;
		};
		file.Close();
		m_edit_netchess_log = _T("");
		UpdateData(FALSE);
	}
}
