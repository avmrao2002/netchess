#if !defined(AFX_CONVERTDLG_H__4844E9D7_F4BD_481C_929C_FC439583F338__INCLUDED_)
#define AFX_CONVERTDLG_H__4844E9D7_F4BD_481C_929C_FC439583F338__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConvertDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConvertDlg dialog

class CConvertDlg : public CDialog
{
// Construction
public:
	CConvertDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConvertDlg)
	enum { IDD = IDD_DIALOG_CONVERT };
	CString	m_edit_filename;
	//}}AFX_DATA
	int m_type;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConvertDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonBrowse();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVERTDLG_H__4844E9D7_F4BD_481C_929C_FC439583F338__INCLUDED_)
