#if !defined(AFX_GAMESTATEINFODLG_H__3E26A546_7B47_4867_A398_2E0CBE3C0E3D__INCLUDED_)
#define AFX_GAMESTATEINFODLG_H__3E26A546_7B47_4867_A398_2E0CBE3C0E3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GameStateInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGameStateInfoDlg dialog

class CGameStateInfoDlg : public CDialog
{
// Construction
public:
	CGameStateInfoDlg(CWnd* pParent = NULL);   // standard constructor
	int m_pieceSide;
// Dialog Data
	//{{AFX_DATA(CGameStateInfoDlg)
	enum { IDD = IDD_DIALOG_GAME_STATE };
	BOOL	m_check_black_king;
	BOOL	m_check_black_O_O;
	BOOL	m_check_black_O_O_O;
	BOOL	m_check_black_rook_a;
	BOOL	m_check_black_root_h;
	BOOL	m_check_white_king;
	BOOL	m_check_white_O_O;
	BOOL	m_check_white_O_O_O;
	BOOL	m_check_white_rook_a;
	BOOL	m_check_white_rook_h;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameStateInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGameStateInfoDlg)
	afx_msg void OnRadioBlack();
	afx_msg void OnRadioWhite();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMESTATEINFODLG_H__3E26A546_7B47_4867_A398_2E0CBE3C0E3D__INCLUDED_)
