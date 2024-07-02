// GoToPGNGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "GoToPGNGameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoToPGNGameDlg dialog


CGoToPGNGameDlg::CGoToPGNGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGoToPGNGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGoToPGNGameDlg)
	m_edit_pgn_data = _T("");
	m_static_game_number = _T("");
	m_edit_game_number = 0;
	//}}AFX_DATA_INIT
	m_edit_game_number =m_PGNFileIndex;
}


void CGoToPGNGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGoToPGNGameDlg)
	DDX_Text(pDX, IDC_EDIT_PGN_DATA, m_edit_pgn_data);
	DDX_Text(pDX, IDC_STATIC_GAME_NUMBER, m_static_game_number);
	DDX_Text(pDX, IDC_EDIT_GAME_NUMBER, m_edit_game_number);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGoToPGNGameDlg, CDialog)
	//{{AFX_MSG_MAP(CGoToPGNGameDlg)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, OnButtonFirst)
	ON_BN_CLICKED(IDC_BUTTON_LAST, OnButtonLast)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoToPGNGameDlg message handlers

void CGoToPGNGameDlg::OnButtonFirst() 
{
	// TODO: Add your control notification handler code here
	m_PGNFileIndex = 0;	
	m_edit_pgn_data = m_PGNFileData.GetAt(m_PGNFileIndex);
	m_static_game_number.Format("of %d",m_PGNFileData.GetSize());
	m_edit_game_number =m_PGNFileIndex+1;
	UpdateData(FALSE);
}

void CGoToPGNGameDlg::OnButtonLast() 
{
	// TODO: Add your control notification handler code here
	m_PGNFileIndex = m_PGNFileData.GetSize()-1;
	m_edit_pgn_data = m_PGNFileData.GetAt(m_PGNFileIndex);
	m_static_game_number.Format("of %d",m_PGNFileData.GetSize());
	m_edit_game_number =m_PGNFileIndex+1;
	UpdateData(FALSE);
}

void CGoToPGNGameDlg::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	m_PGNFileIndex++;
	if(m_PGNFileIndex >= m_PGNFileData.GetSize())
		m_PGNFileIndex = m_PGNFileData.GetSize()-1;	

	m_edit_pgn_data = m_PGNFileData.GetAt(m_PGNFileIndex);
	m_static_game_number.Format("of %d",m_PGNFileData.GetSize());
	m_edit_game_number =m_PGNFileIndex+1;
	UpdateData(FALSE);

}

void CGoToPGNGameDlg::OnButtonPrev() 
{
	// TODO: Add your control notification handler code here
	m_PGNFileIndex--;
	if(m_PGNFileIndex < 0)
		m_PGNFileIndex = 0;
	m_edit_pgn_data = m_PGNFileData.GetAt(m_PGNFileIndex);
	m_static_game_number.Format("of %d",m_PGNFileData.GetSize());
	m_edit_game_number =m_PGNFileIndex+1;
	UpdateData(FALSE);	
}

BOOL CGoToPGNGameDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here	
	if(m_PGNFileIndex < 0)
		m_PGNFileIndex = 0;
	if(m_PGNFileIndex >= m_PGNFileData.GetSize())
		m_PGNFileIndex = m_PGNFileData.GetSize()-1;
	m_edit_game_number =m_PGNFileIndex+1;
	m_edit_pgn_data = m_PGNFileData.GetAt(m_PGNFileIndex);
	m_static_game_number.Format("of %d",m_PGNFileData.GetSize());
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/*void CGoToPGNGameDlg::OnChangeEditGameNumber() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
	if(m_edit_game_number > 0 && m_edit_game_number < m_PGNFileData.GetSize())
	{
		m_PGNFileIndex = 0;	
		m_edit_game_number =m_PGNFileIndex+1;
		m_edit_pgn_data = m_PGNFileData.GetAt(m_PGNFileIndex);
		m_static_game_number.Format("of %d",m_PGNFileData.GetSize());
	}
}*/

void CGoToPGNGameDlg::OnButtonGo() 
{
	// TODO: Add your control notification handler code here	
	UpdateData(TRUE);
	if(m_edit_game_number > 0 && m_edit_game_number < m_PGNFileData.GetSize())
	{
		m_PGNFileIndex = 0;	
		m_PGNFileIndex = m_edit_game_number-1;
		if(m_PGNFileIndex < 0)
			m_PGNFileIndex = 0;
		m_edit_pgn_data = m_PGNFileData.GetAt(m_PGNFileIndex);
		m_static_game_number.Format("of %d",m_PGNFileData.GetSize());
		UpdateData(FALSE);
	}
}

void CGoToPGNGameDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
		case 35:
			OnButtonLast();
			break;
		case 36:
	
				OnButtonFirst();
			break;
		case 37://left
	
				OnButtonPrev();
			break;
		case 39: //right	
				OnButtonNext();
			break;
		default:
			break;			
	}
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
