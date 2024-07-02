#if !defined(AFX_PGNDLG_H__C3804FCD_76DE_469D_BE25_8167D7F373FA__INCLUDED_)
#define AFX_PGNDLG_H__C3804FCD_76DE_469D_BE25_8167D7F373FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PGNDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPGNDlg dialog

class CPGNDlg : public CDialog
{
// Construction
public:
	CPGNDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPGNDlg)
	enum { IDD = IDD_DIALOG_PGN_DATA };
	CString	m_edit_pgn_data;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPGNDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPGNDlg)
	afx_msg void OnButtonOpen();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PGNDLG_H__C3804FCD_76DE_469D_BE25_8167D7F373FA__INCLUDED_)
