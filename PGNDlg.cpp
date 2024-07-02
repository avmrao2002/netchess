// PGNDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "PGNDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPGNDlg dialog


CPGNDlg::CPGNDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPGNDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPGNDlg)
	m_edit_pgn_data = _T("");
	//}}AFX_DATA_INIT
}


void CPGNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPGNDlg)
	DDX_Text(pDX, IDC_EDIT_PGN_DATA, m_edit_pgn_data);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPGNDlg, CDialog)
	//{{AFX_MSG_MAP(CPGNDlg)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPGNDlg message handlers

void CPGNDlg::OnButtonOpen() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fdialog(TRUE);
	if(fdialog.DoModal() == IDOK)
	{
		CString file = fdialog.GetPathName(); 
		FILE *fp = fopen(file,"r");
		if(fp == NULL)
		{
			CString str;
			str.Format("Could not open the file %s",file);
			AfxMessageBox(str);
			return;
		}

		m_edit_pgn_data = "";
		int count = 0;
		int foundflag = 0;
		while(!feof(fp))
		{
			/*char str[255];
			fscanf(fp,"%s",str);
			if(str[0] == '[' || str[1] == '[')
			{
				while(!feof(fp))
				{
					char c;
					fscanf(fp,"%c",&c);
					if(c == ']')
						break;
					
				}				
			}			
			if(strcmp(str,"1.") == 0)
			{
				count++;				
				if(count > 1)
				{
					break;
				}

			}
			if(str[0] == '[')
				continue;*/
			char c;
			fscanf_s(fp,"%c",&c);
			if(c == '\n')
				m_edit_pgn_data += "\r\n";
			else
				m_edit_pgn_data += c;
			if(m_edit_pgn_data.GetLength() > 4000)
				break;
		}
		fclose(fp);
	}
	UpdateData(FALSE);
}

void CPGNDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
