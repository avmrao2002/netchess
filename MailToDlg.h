#if !defined(AFX_MAILTODLG_H__AD1E6C5F_BD00_4F04_89C8_7182BD67D005__INCLUDED_)
#define AFX_MAILTODLG_H__AD1E6C5F_BD00_4F04_89C8_7182BD67D005__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MailToDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMailToDlg dialog

class CMailToDlg : public CDialog
{
// Construction
public:
	CMailToDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMailToDlg)
	enum { IDD = IDD_DIALOG_MAIL_TO };
	CString	m_edit_from;
	CString	m_edit_mail_server;
	CString	m_edit_to;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMailToDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMailToDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAILTODLG_H__AD1E6C5F_BD00_4F04_89C8_7182BD67D005__INCLUDED_)
