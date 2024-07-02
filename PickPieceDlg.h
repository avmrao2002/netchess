#if !defined(AFX_PICKPIECEDLG_H__4F7BD626_A194_4121_9475_3222FA82C92A__INCLUDED_)
#define AFX_PICKPIECEDLG_H__4F7BD626_A194_4121_9475_3222FA82C92A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PickPieceDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPickPieceDlg dialog

class CPickPieceDlg : public CDialog
{
// Construction
 
public:
	CPickPieceDlg(CWnd* pParent = NULL);   // standard constructor
	int m_piecked_piece;
	PIECE_TYPE m_piece_type;
	COLOR_TYPE m_piece_color;
	int m_pickpiecetype;

// Dialog Data
	//{{AFX_DATA(CPickPieceDlg)
	enum { IDD = IDD_DIALOG_PICK_PIECE };
	CString	m_static_status;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPickPieceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPickPieceDlg)
	afx_msg void OnStaticBishopBlack();
	afx_msg void OnStaticBishopWhite();
	afx_msg void OnStaticBitmapKnight();
	afx_msg void OnStaticKingBlack();
	afx_msg void OnStaticKingWhite();
	afx_msg void OnStaticKnightBlack();
	afx_msg void OnStaticPawnBlack();
	afx_msg void OnStaticPawnWhite();
	afx_msg void OnStaticQueenBlack();
	afx_msg void OnStaticQueenWhite();
	afx_msg void OnStaticRootBlack();
	afx_msg void OnStaticRootWhite();
	afx_msg void OnStaticEmpty();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICKPIECEDLG_H__4F7BD626_A194_4121_9475_3222FA82C92A__INCLUDED_)
