#if !defined(AFX_GAMESTATEDLG_H__C7D34AB0_CCD1_468F_BEDE_138001D6E185__INCLUDED_)
#define AFX_GAMESTATEDLG_H__C7D34AB0_CCD1_468F_BEDE_138001D6E185__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GameStateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGameStateDlg dialog

class CGameStateDlg : public CDialog
{
// Construction
public:
	CGameStateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGameStateDlg)
	enum { IDD = IDD_DIALOG_GAME_STATE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameStateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGameStateDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMESTATEDLG_H__C7D34AB0_CCD1_468F_BEDE_138001D6E185__INCLUDED_)
