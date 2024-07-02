#if !defined(AFX_ICSPLAYERSLISTDLG_H__6F636BEA_E2D6_4919_B939_65790AC612AD__INCLUDED_)
#define AFX_ICSPLAYERSLISTDLG_H__6F636BEA_E2D6_4919_B939_65790AC612AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICSPlayersListDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CICSPlayersListDlg dialog

class CICSPlayersListDlg : public CDialog
{
// Construction
public:
	CICSPlayersListDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CICSPlayersListDlg)
	enum { IDD = IDD_DIALOG_ICS_PLAYERS_LIST };
	CString	m_edit_ics_list;
	CString	m_static_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICSPlayersListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CICSPlayersListDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICSPLAYERSLISTDLG_H__6F636BEA_E2D6_4919_B939_65790AC612AD__INCLUDED_)
