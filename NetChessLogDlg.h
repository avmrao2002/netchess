#if !defined(AFX_NETCHESSLOGDLG_H__3BB133B1_AD46_4634_AD53_F7E204E008A7__INCLUDED_)
#define AFX_NETCHESSLOGDLG_H__3BB133B1_AD46_4634_AD53_F7E204E008A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NetChessLogDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNetChessLogDlg dialog

class CNetChessLogDlg : public CDialog
{
// Construction
public:
	CNetChessLogDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNetChessLogDlg)
	enum { IDD = IDD_DIALOG_NETCHESS_LOG };
	CString	m_edit_netchess_log;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetChessLogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNetChessLogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETCHESSLOGDLG_H__3BB133B1_AD46_4634_AD53_F7E204E008A7__INCLUDED_)
