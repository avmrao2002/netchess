#if !defined(AFX_VIEWIMAGE_H__A5C608D6_BF9E_4C8E_ACC6_8ECACC6F5DF7__INCLUDED_)
#define AFX_VIEWIMAGE_H__A5C608D6_BF9E_4C8E_ACC6_8ECACC6F5DF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewImage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CViewImage dialog

class CViewImage : public CDialog
{
// Construction
public:
	CViewImage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CViewImage)
	enum { IDD = IDD_DIALOG_IMAGE };
	CStatic	m_static_image;
	//}}AFX_DATA
	CString m_fileName;
	int DisplayImage(CString file);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewImage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CViewImage)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnButtonSelectImage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWIMAGE_H__A5C608D6_BF9E_4C8E_ACC6_8ECACC6F5DF7__INCLUDED_)
