// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__6C2D7081_2DC2_40BE_A9BC_060AB45E1BD0__INCLUDED_)
#define AFX_MAINFRM_H__6C2D7081_2DC2_40BE_A9BC_060AB45E1BD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	void OnShellNotify(WPARAM wParam,LPARAM lParam);
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CStatusBar  m_wndStatusBar;
	INT m_extendedViewFlag;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
 
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewHide();
	afx_msg void OnViewStatusBar();
	afx_msg void OnViewToolbar();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg BOOL OnQueryEndSession();
	afx_msg void OnEndSession(BOOL bEnding);
	afx_msg void OnShellClose();
	afx_msg void OnShellView();
	afx_msg void OnViewExtend();
	afx_msg void OnUpdateViewExtend(CCmdUI* pCmdUI);
	afx_msg void OnViewGame1();
	afx_msg void OnUpdateViewGame1(CCmdUI* pCmdUI);
	afx_msg void OnViewGame2();
	afx_msg void OnUpdateViewGame2(CCmdUI* pCmdUI);
	afx_msg void OnViewGame3();
	afx_msg void OnUpdateViewGame3(CCmdUI* pCmdUI);
	afx_msg void OnViewGame4();
	afx_msg void OnUpdateViewGame4(CCmdUI* pCmdUI);
	afx_msg void OnViewGame5();
	afx_msg void OnUpdateViewGame5(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewExtendedview(CCmdUI* pCmdUI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnActivateApp(BOOL bActive, HTASK hTask);
	afx_msg void OnHelpHttpwwwgeocitiescomraoavm();
	afx_msg void OnViewExtendedview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
public:
	void SetPaneText(int paneno,CString str);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__6C2D7081_2DC2_40BE_A9BC_060AB45E1BD0__INCLUDED_)
