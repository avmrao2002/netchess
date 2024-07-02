#if !defined(AFX_ENGINELEVELDLG_H__98A061E4_45CC_422B_A78B_5AB325C9BE3A__INCLUDED_)
#define AFX_ENGINELEVELDLG_H__98A061E4_45CC_422B_A78B_5AB325C9BE3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EngineLevelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEngineLevelDlg dialog

class CEngineLevelDlg : public CDialog
{
// Construction
public:
	CEngineLevelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEngineLevelDlg)
	enum { IDD = IDD_DIALOG_ENGINE_LEVEL };
	int		m_edit_conv_clock_mode;
	int		m_edig_movestimecontrol;
	int		m_edit_time_control;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEngineLevelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEngineLevelDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENGINELEVELDLG_H__98A061E4_45CC_422B_A78B_5AB325C9BE3A__INCLUDED_)
