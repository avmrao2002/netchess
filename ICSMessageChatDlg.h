#if !defined(AFX_ICSMESSAGECHATDLG_H__AF4F860F_063A_4525_8F4A_2C7E61254F4C__INCLUDED_)
#define AFX_ICSMESSAGECHATDLG_H__AF4F860F_063A_4525_8F4A_2C7E61254F4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICSMessageChatDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CICSMessageChatDlg dialog

class CICSMessageChatDlg : public CDialog
{
// Construction
public:
	CICSMessageChatDlg(CWnd* pParent = NULL);   // standard constructor
	void SetReceiveData(unsigned char* data);
// Dialog Data
	//{{AFX_DATA(CICSMessageChatDlg)
	enum { IDD = IDD_DIALOG_MESSAGE_ICS };
	CString	m_edit_send_message;
	CString	m_edit_receive_message;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICSMessageChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	
protected:

	// Generated message map functions
	//{{AFX_MSG(CICSMessageChatDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICSMESSAGECHATDLG_H__AF4F860F_063A_4525_8F4A_2C7E61254F4C__INCLUDED_)
