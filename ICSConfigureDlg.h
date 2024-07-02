#if !defined(AFX_ICSCONFIGUREDLG_H__B8A7DE42_5AD2_4729_B4B6_AC602B454D08__INCLUDED_)
#define AFX_ICSCONFIGUREDLG_H__B8A7DE42_5AD2_4729_B4B6_AC602B454D08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICSConfigureDlg.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CICSConfigureDlg dialog

class CICSConfigureDlg : public CDialog
{
// Construction
public:
	CICSConfigureDlg(CWnd* pParent = NULL);   // standard constructor
	CView *m_pView;
	void SetView(CView*);
	void Login();
	CString m_ics_server_name;
// Dialog Data
	//{{AFX_DATA(CICSConfigureDlg)
	enum { IDD = IDD_DIALOG_ICS_CONFIGURE };
	CComboBox	m_cobmo_ics_server_name;
	CString	m_edit_password;
	int		m_edit_port_number;
	CString	m_edit_user_name;
	CString	m_static_myname;
	//}}AFX_DATA
	CString m_opponent_name;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICSConfigureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CICSConfigureDlg)
	afx_msg void OnButtonConnect();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonDisconnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICSCONFIGUREDLG_H__B8A7DE42_5AD2_4729_B4B6_AC602B454D08__INCLUDED_)
