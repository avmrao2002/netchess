// ConvertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "ConvertDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConvertDlg dialog


CConvertDlg::CConvertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConvertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConvertDlg)
	m_edit_filename = _T("");
	//}}AFX_DATA_INIT
}


void CConvertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConvertDlg)
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_edit_filename);
	DDV_MaxChars(pDX, m_edit_filename, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConvertDlg, CDialog)
	//{{AFX_MSG_MAP(CConvertDlg)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, OnButtonBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConvertDlg message handlers


BOOL CConvertDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_type = IDC_RADIO_FEN;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CConvertDlg::OnButtonBrowse() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE);
	if(dlg.DoModal() == IDOK)
	{
		if(dlg.GetFileExt() == "FEN" ||
			dlg.GetFileExt() == "fen" ||
			dlg.GetFileExt() == "EPD" ||
			dlg.GetFileExt() == "epd" ||
			dlg.GetFileExt() == "PGN" ||
			dlg.GetFileExt() == "pgn")
		{

			m_edit_filename = dlg.GetPathName();
		}
		else
		{
			AfxMessageBox("Enter proper extention");
		}
	}
	UpdateData(FALSE);
}


void CConvertDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(m_edit_filename.Right(3) == "FEN" ||
			m_edit_filename.Right(3) == "fen" ||
			m_edit_filename.Right(3) == "EPD" ||
			m_edit_filename.Right(3) == "epd"||
			m_edit_filename.Right(3) == "PGN" ||
			m_edit_filename.Right(3) == "pgn")
	{
		CDialog::OnOK();
	}
	else
	{
		AfxMessageBox("Enter file proper extention");
	}	
}
