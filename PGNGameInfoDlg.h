#if !defined(AFX_PGNGAMEINFODLG_H__A6AF6DBA_74C9_4682_A899_F3C931B82FD7__INCLUDED_)
#define AFX_PGNGAMEINFODLG_H__A6AF6DBA_74C9_4682_A899_F3C931B82FD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PGNGameInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPGNGameInfoDlg dialog

class CPGNGameInfoDlg : public CDialog
{
// Construction
public:
	CPGNGameInfoDlg(CWnd* pParent = NULL);   // standard constructor
	void ClearDialog();
// Dialog Data
	//{{AFX_DATA(CPGNGameInfoDlg)
	enum { IDD = IDD_DIALOG_GAME_INFO };
	CString	m_edit_black;
	CString	m_edit_date;
	CString	m_edit_event;
	CString	m_edit_result;
	CString	m_edit_round;
	CString	m_edit_site;
	CString	m_edit_white;
	CString	m_edit_fenstring;
	CString	m_edit_blackelo;
	CString	m_edit_eco;
	CString	m_event_date;
	CString	m_edit_playcount;
	CString	m_edit_whiteelo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPGNGameInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPGNGameInfoDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PGNGAMEINFODLG_H__A6AF6DBA_74C9_4682_A899_F3C931B82FD7__INCLUDED_)
