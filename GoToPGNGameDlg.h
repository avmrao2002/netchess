#if !defined(AFX_GOTOPGNGAMEDLG_H__222491B2_B59F_4FFA_B0F4_5422973082A8__INCLUDED_)
#define AFX_GOTOPGNGAMEDLG_H__222491B2_B59F_4FFA_B0F4_5422973082A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GoToPGNGameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGoToPGNGameDlg dialog

class CGoToPGNGameDlg : public CDialog
{
// Construction
public:
	CGoToPGNGameDlg(CWnd* pParent = NULL);   // standard constructor
	CStringArray m_PGNFileData;
	int m_PGNFileIndex;
// Dialog Data
	//{{AFX_DATA(CGoToPGNGameDlg)
	enum { IDD = IDD_DIALOG_GOTO_PGN_GAME };
	CString	m_edit_pgn_data;
	CString	m_static_game_number;
	UINT	m_edit_game_number;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoToPGNGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGoToPGNGameDlg)
	afx_msg void OnButtonFirst();
	afx_msg void OnButtonLast();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonPrev();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonGo();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOTOPGNGAMEDLG_H__222491B2_B59F_4FFA_B0F4_5422973082A8__INCLUDED_)
