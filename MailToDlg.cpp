// MailToDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "MailToDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMailToDlg dialog


CMailToDlg::CMailToDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMailToDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMailToDlg)
	m_edit_from = _T("");
	m_edit_mail_server = _T("");
	m_edit_to = _T("");
	//}}AFX_DATA_INIT
}


void CMailToDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMailToDlg)
	DDX_Text(pDX, IDC_EDIT_FROM, m_edit_from);
	DDX_Text(pDX, IDC_EDIT_MAIL_SERVER, m_edit_mail_server);
	DDX_Text(pDX, IDC_EDIT_TO, m_edit_to);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMailToDlg, CDialog)
	//{{AFX_MSG_MAP(CMailToDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMailToDlg message handlers
