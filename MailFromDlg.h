#if !defined(AFX_MAILFROMDLG_H__17049B1B_18DE_4786_9811_F98B1060BC3B__INCLUDED_)
#define AFX_MAILFROMDLG_H__17049B1B_18DE_4786_9811_F98B1060BC3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MailFromDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMailFromDlg dialog

class CMailFromDlg : public CDialog
{
// Construction
public:
	CMailFromDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMailFromDlg)
	enum { IDD = IDD_DIALOG_MAIL_FROM };
	CString	m_edit_mail_server;
	CString	m_edit_password;
	int		m_edit_port;
	CString	m_edit_user_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMailFromDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMailFromDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAILFROMDLG_H__17049B1B_18DE_4786_9811_F98B1060BC3B__INCLUDED_)
