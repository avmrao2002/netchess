#if !defined(AFX_ENGINELOGDLG_H__51B5271B_A277_4BD2_BE80_EE198EEDF847__INCLUDED_)
#define AFX_ENGINELOGDLG_H__51B5271B_A277_4BD2_BE80_EE198EEDF847__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EngineLogDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEngineLogDlg dialog
#include "Engine.h"
class CEngineLogDlg : public CDialog
{
// Construction
public:
	CEngineLogDlg(CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(CEngineLogDlg)
	enum { IDD = IDD_DIALOG_ENGINE_LOG };
	CString	m_edit_engine_log;
	CString	m_edit_engine_command;
	//}}AFX_DATA

	CEngine *m_pEngine;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEngineLogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEngineLogDlg)
	afx_msg void OnButtonSend();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonClear();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonCopy();
	afx_msg void OnChangeEditEngineLog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENGINELOGDLG_H__51B5271B_A277_4BD2_BE80_EE198EEDF847__INCLUDED_)
