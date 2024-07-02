#if !defined(AFX_ENTERMOVEDLG_H__5BAC30E5_BE54_4EEC_BC33_D63C77EEA2EF__INCLUDED_)
#define AFX_ENTERMOVEDLG_H__5BAC30E5_BE54_4EEC_BC33_D63C77EEA2EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnterMoveDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnterMoveDlg dialog

class CEnterMoveDlg : public CDialog
{
// Construction
public:
	CEnterMoveDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEnterMoveDlg)
	enum { IDD = IDD_DIALOG_ENTER_MOVE };
	CString	m_edit_move;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnterMoveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnterMoveDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTERMOVEDLG_H__5BAC30E5_BE54_4EEC_BC33_D63C77EEA2EF__INCLUDED_)
