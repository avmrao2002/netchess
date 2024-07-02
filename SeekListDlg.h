#if !defined(AFX_SEEKLISTDLG_H__4152185E_B8C2_4132_B4D5_C8921F56C8E9__INCLUDED_)
#define AFX_SEEKLISTDLG_H__4152185E_B8C2_4132_B4D5_C8921F56C8E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SeekListDlg.h : header file
//
struct SeekList
{
	int seekindex;
	char seektype[100];
};

typedef CTypedPtrList<CPtrList,SeekList*> SeekListPtr;
/////////////////////////////////////////////////////////////////////////////
// CSeekListDlg dialog

class CSeekListDlg : public CDialog
{
// Construction
public:
	CSeekListDlg(CWnd* pParent = NULL);   // standard constructor
	SeekListPtr m_seekListPtr;
	void InsertSeek(CString str,int);
	void Update();
	
// Dialog Data
	//{{AFX_DATA(CSeekListDlg)
	enum { IDD = IDD_DIALOG_SEEK_LIST };
	CListBox	m_list_seek;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeekListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSeekListDlg)
	afx_msg void OnButtonPlay();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEEKLISTDLG_H__4152185E_B8C2_4132_B4D5_C8921F56C8E9__INCLUDED_)
