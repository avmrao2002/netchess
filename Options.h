#if !defined(AFX_OPTIONS_H__7DFB9D71_1840_4BB6_8452_C5E968A37A72__INCLUDED_)
#define AFX_OPTIONS_H__7DFB9D71_1840_4BB6_8452_C5E968A37A72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Options.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptions dialog

class COptions : public CDialog
{
// Construction
	 
public:
	COptions(CWnd* pParent = NULL);   // standard constructor
	COLORREF m_crefWhiteColor;
	COLORREF m_crefBlackColor;
	COLORREF m_crefWhitePieceColor;
	COLORREF m_crefBlackPieceColor;

	bool m_whiteClrDlg;
	bool m_blackClrDlg;
	int m_pieceType;
	int m_UCImove;
	CFont m_font;
	void SetColor(COLORREF cr);
	enum BoardFont {DEFAULT=1,FONT=2};
	int m_boardFont;
	COLORREF m_fontColor;
	CHESS_PROTOCOL m_whiteEngineProtocol;
	CHESS_PROTOCOL m_blackEngineProtocol;
	 

// Dialog Data
	//{{AFX_DATA(COptions)
	enum { IDD = IDD_DIALOG_OPTIONS };
	BOOL	m_check_auto_save;
	BOOL	m_check_save_with_history;
	int		m_edit_replay_interval;
	BOOL	m_check_netchess_log;
	BOOL	m_check_pgn_mail_format;
	CString	m_edit_def_black_engine;
	CString	m_edit_def_white_engine;
	CString	m_edit_font;
	int		m_edit_font_size;
	BOOL	m_check_extended_view;
	BOOL	m_check_save_game;
	BOOL	m_check_black_engine_auto_start;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptions)
	afx_msg void OnButtonBlackColor();
	afx_msg void OnButtonWhiteColor();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCheckAutoSave();
	afx_msg void OnCheckSaveWithHistory();
	afx_msg void OnButtonApplySave();
	afx_msg void OnRadioFenString();
	afx_msg void OnRadioStartpos();
	afx_msg void OnButtonBlackBrowse();
	afx_msg void OnButtonWhiteBrowse();
	afx_msg void OnFont();
	afx_msg void OnRadioFontBoard();
	afx_msg void OnRadioDefault();
	afx_msg void OnButtonWhiteColor2();
	afx_msg void OnButtonBlackColor2();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnPaint();
	afx_msg void OnRadioBlackengineUcii();
	afx_msg void OnRadioBlackengineUciii();
	afx_msg void OnRadioBlackengineWbi();
	afx_msg void OnRadioBlackengineWbii();
	afx_msg void OnRadioWhiteengineUcii();
	afx_msg void OnRadioWhiteengineUciii();
	afx_msg void OnRadioWhiteengineWbi();
	afx_msg void OnRadioWhiteengineWbii();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONS_H__7DFB9D71_1840_4BB6_8452_C5E968A37A72__INCLUDED_)
