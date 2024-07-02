#if !defined(AFX_DEMOINTERVALDLG_H__8A1D34FD_867D_44AA_A071_3182361D064B__INCLUDED_)
#define AFX_DEMOINTERVALDLG_H__8A1D34FD_867D_44AA_A071_3182361D064B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoIntervalDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoIntervalDlg dialog

class CDemoIntervalDlg : public CDialog
{
// Construction
public:
	CDemoIntervalDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDemoIntervalDlg)
	enum { IDD = IDD_DIALOG_DEMO_INTERVAL };
	int		m_edit_demo_interval;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoIntervalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDemoIntervalDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOINTERVALDLG_H__8A1D34FD_867D_44AA_A071_3182361D064B__INCLUDED_)
