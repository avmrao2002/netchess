#if !defined(AFX_GOTOMOVEHISTORYDLG_H__F3A403E2_8053_41C4_99D9_E522C0B9883A__INCLUDED_)
#define AFX_GOTOMOVEHISTORYDLG_H__F3A403E2_8053_41C4_99D9_E522C0B9883A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GoToMoveHistoryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGoToMoveHistoryDlg dialog

class CGoToMoveHistoryDlg : public CDialog
{
// Construction
public:
	CGoToMoveHistoryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGoToMoveHistoryDlg)
	enum { IDD = IDD_DIALOG_DEMO_GOTO };
	CListBox	m_move_history;
	//}}AFX_DATA
	CStringArray m_historystring;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoToMoveHistoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGoToMoveHistoryDlg)
	afx_msg void OnSelchangeListHistory();
	afx_msg void OnDblclkListHistory();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOTOMOVEHISTORYDLG_H__F3A403E2_8053_41C4_99D9_E522C0B9883A__INCLUDED_)
