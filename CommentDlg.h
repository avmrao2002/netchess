#if !defined(AFX_COMMENTDLG_H__35E2A778_FD5D_4D35_858E_46FB5F08D222__INCLUDED_)
#define AFX_COMMENTDLG_H__35E2A778_FD5D_4D35_858E_46FB5F08D222__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CommentDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommentDlg dialog

class CCommentDlg : public CDialog
{
// Construction
public:
	CCommentDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCommentDlg)
	enum { IDD = IDD_DIALOG_COMMENT };
	CString	m_edit_comment;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCommentDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMENTDLG_H__35E2A778_FD5D_4D35_858E_46FB5F08D222__INCLUDED_)
