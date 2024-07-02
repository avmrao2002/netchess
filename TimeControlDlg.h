#if !defined(AFX_TIMECONTROLDLG_H__8744B862_4C41_40FA_9411_7A113BA76580__INCLUDED_)
#define AFX_TIMECONTROLDLG_H__8744B862_4C41_40FA_9411_7A113BA76580__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TimeControlDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTimeControlDlg dialog

class CTimeControlDlg : public CDialog
{
// Construction
public:
	CTimeControlDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTimeControlDlg)
	enum { IDD = IDD_DIALOG_TIME_CONTROL };
	BOOL	m_check_infinite;
	int		m_edit_wb_base_time;
	int		m_wb_exact_seconds;
	int		m_edit_uci_binc;
	int		m_edit_uci_btime;
	int		m_edit_uci_movetime;
	int		m_edit_uci_winc;
	int		m_edit_uci_wtime;
	int		m_edit_wb_inc_time;
	int		m_edit_wb_number_of_moves;
	int		m_edit_wb_time;
	//}}AFX_DATA

	int m_radio_clock_type;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTimeControlDlg)
	afx_msg void OnRadioConventionalClock();
	afx_msg void OnRadioExactNumber();
	afx_msg void OnRadioIncreamentalClock();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECONTROLDLG_H__8744B862_4C41_40FA_9411_7A113BA76580__INCLUDED_)
