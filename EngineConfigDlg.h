#if !defined(AFX_ENGINECONFIGDLG_H__10037863_C45B_4382_B87C_CB00F15D40D3__INCLUDED_)
#define AFX_ENGINECONFIGDLG_H__10037863_C45B_4382_B87C_CB00F15D40D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EngineConfigDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEngineConfigDlg dialog

class CEngineConfigDlg : public CDialog
{
// Construction
public:
	CEngineConfigDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEngineConfigDlg)
	enum { IDD = IDD_DIALOG_ENGINE_CONFIGURE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CHESS_PROTOCOL m_chessProtocol;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEngineConfigDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEngineConfigDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioUcii();
	afx_msg void OnRadioUciii();
	afx_msg void OnRadioWbi();
	afx_msg void OnRadioWbii();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENGINECONFIGDLG_H__10037863_C45B_4382_B87C_CB00F15D40D3__INCLUDED_)
