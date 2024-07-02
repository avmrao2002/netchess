// MailFromDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "MailFromDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMailFromDlg dialog


CMailFromDlg::CMailFromDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMailFromDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMailFromDlg)
	m_edit_mail_server = _T("");
	m_edit_password = _T("");
	m_edit_port = 0;
	m_edit_user_name = _T("");
	//}}AFX_DATA_INIT
}


void CMailFromDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMailFromDlg)
	DDX_Text(pDX, IDC_EDIT_MAIL_SERVER, m_edit_mail_server);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_edit_password);
	DDX_Text(pDX, IDC_EDIT_PORT, m_edit_port);
	DDX_Text(pDX, IDC_EDIT_USER_NAME, m_edit_user_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMailFromDlg, CDialog)
	//{{AFX_MSG_MAP(CMailFromDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMailFromDlg message handlers
