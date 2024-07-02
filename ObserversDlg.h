#if !defined(AFX_OBSERVERSDLG_H__C4CDB3C9_8C80_4A4D_82C9_426ADD3B5523__INCLUDED_)
#define AFX_OBSERVERSDLG_H__C4CDB3C9_8C80_4A4D_82C9_426ADD3B5523__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ObserversDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CObserversDlg dialog

class CObserversDlg : public CDialog
{
// Construction
public:
	CObserversDlg(CWnd* pParent = NULL);   // standard constructor
	CStringArray m_stringArray;
// Dialog Data
	//{{AFX_DATA(CObserversDlg)
	enum { IDD = IDD_DIALOG_OBSERVERS };
	CListBox	m_list_observers;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CObserversDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CObserversDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OBSERVERSDLG_H__C4CDB3C9_8C80_4A4D_82C9_426ADD3B5523__INCLUDED_)
