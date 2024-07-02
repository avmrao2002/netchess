// MyColorEdit.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "MyColorEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyColorEdit

CMyColorEdit::CMyColorEdit()
{
}

CMyColorEdit::~CMyColorEdit()
{
}


BEGIN_MESSAGE_MAP(CMyColorEdit, CEdit)
	//{{AFX_MSG_MAP(CMyColorEdit)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyColorEdit message handlers

HBRUSH CMyColorEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	/*COLORREF cr(RGB(192,192,192));
	pDC->SetBkColor(cr);
	CBrush br(cr);
	pDC->SelectObject(&br);
	return br;*/
	
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return NULL;
}

HBRUSH CMyColorEdit::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CEdit::OnCtlColor(pDC, pWnd, nCtlColor);
/*	COLORREF cr(RGB(192,192,192));
	pDC->SetBkColor(cr);
	CBrush br(cr);
	pDC->SelectObject(&br);
	return br;*/
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
