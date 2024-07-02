#if !defined(AFX_MYCOLOREDIT_H__FDDBFC0B_D852_4C26_B5B2_EC32389035A4__INCLUDED_)
#define AFX_MYCOLOREDIT_H__FDDBFC0B_D852_4C26_B5B2_EC32389035A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyColorEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyColorEdit window

class CMyColorEdit : public CEdit
{
// Construction
public:
	CMyColorEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyColorEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyColorEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyColorEdit)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOLOREDIT_H__FDDBFC0B_D852_4C26_B5B2_EC32389035A4__INCLUDED_)
