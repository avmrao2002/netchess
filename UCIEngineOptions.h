#if !defined(AFX_UCIENGINEOPTIONS_H__8317B2BE_CEE7_4CBD_ABA9_3C499DA63DEA__INCLUDED_)
#define AFX_UCIENGINEOPTIONS_H__8317B2BE_CEE7_4CBD_ABA9_3C499DA63DEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UCIEngineOptions.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUCIEngineOptions dialog

class CUCIEngineOptions : public CDialog
{
// Construction
public:
	CUCIEngineOptions(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUCIEngineOptions)
	enum { IDD = IDD_DIALOG_UCI_OPTIONS };
	CListBox	m_lb_set_options;
	CString	m_edit_read_options;
	CString	m_edit_set_options;
	//}}AFX_DATA

	CStringArray m_arrSetOptions;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUCIEngineOptions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUCIEngineOptions)
	afx_msg void OnButtonAdd();
	afx_msg void OnSelchangeListSetOptions();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UCIENGINEOPTIONS_H__8317B2BE_CEE7_4CBD_ABA9_3C499DA63DEA__INCLUDED_)
