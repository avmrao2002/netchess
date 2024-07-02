#if !defined(AFX_ICSWINDOWDLG_H__6B4CF9EB_DE42_4F8C_BA8F_02C1E8832F47__INCLUDED_)
#define AFX_ICSWINDOWDLG_H__6B4CF9EB_DE42_4F8C_BA8F_02C1E8832F47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICSWindowDlg.h : header file
//
#include "ICSClient.h"
/////////////////////////////////////////////////////////////////////////////
// CICSWindowDlg dialog

class CICSWindowDlg : public CDialog
{
// Construction
public:
	CICSWindowDlg(CWnd* pParent = NULL);   // standard constructor
	CICSClient *m_pICSClient;
	CView *m_pView;
	void Update(int);
	void SetView(CView *view);
	void SendPlay(int index);
	CString m_myName;
// Dialog Data
	//{{AFX_DATA(CICSWindowDlg)
	enum { IDD = IDD_DIALOG_ICS_WINDOWS };
	CString	m_edit_command;
	CString	m_edit_ics_log;
	CString	m_edit_play;
	CString	m_edit_play_type;
	CString	m_edit_message;
	BOOL	m_check_expand_move;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICSWindowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CICSWindowDlg)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonGo();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonAbort();
	afx_msg void OnButtonPlay();
	afx_msg void OnButtonSeek();
	afx_msg void OnButtonQuit();
	afx_msg void OnButtonDraw();
	afx_msg void OnButtonGames();
	afx_msg void OnButtonPlayers();
	afx_msg void OnButtonResign();
	afx_msg void OnButtonShout0();
	afx_msg void OnButtonShout1();
	afx_msg void OnButtonSought();
	afx_msg void OnButtonView();
	afx_msg void OnButtonWho();
	afx_msg void OnButtonHelp();
	afx_msg void OnButtonClear();
	afx_msg void OnButtonStyle12();
	afx_msg void OnButtonAccept();
	afx_msg void OnButtonOpen();
	afx_msg void OnButtonViewList();
	afx_msg void OnButtonViewLastMove();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICSWINDOWDLG_H__6B4CF9EB_DE42_4F8C_BA8F_02C1E8832F47__INCLUDED_)
