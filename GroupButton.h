#if !defined(AFX_GROUPBUTTON_H__30950FB8_D50C_4660_A3AE_DEE7D59DEA69__INCLUDED_)
#define AFX_GROUPBUTTON_H__30950FB8_D50C_4660_A3AE_DEE7D59DEA69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GroupButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGroupButton window

class CGroupButton : public CButton
{
// Construction
public:
	CGroupButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGroupButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGroupButton();
	BOOL OnCommand(WPARAM wParam,LPARAM lParam);
	// Generated message map functions
protected:
	//{{AFX_MSG(CGroupButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUPBUTTON_H__30950FB8_D50C_4660_A3AE_DEE7D59DEA69__INCLUDED_)
