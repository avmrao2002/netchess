// SeekListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "SeekListDlg.h"
#include "NetChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSeekListDlg dialog


CSeekListDlg::CSeekListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSeekListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSeekListDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

}


void CSeekListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSeekListDlg)
	DDX_Control(pDX, IDC_LIST_SEEK_LIST, m_list_seek);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSeekListDlg, CDialog)
	//{{AFX_MSG_MAP(CSeekListDlg)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeekListDlg message handlers

void CSeekListDlg::OnButtonPlay() 
{
	// TODO: Add your control notification handler code here
	CListBox *lb = (CListBox*)GetDlgItem(IDC_LIST_SEEK_LIST);
	int index = lb->GetCurSel();
	if(index > -1)
	{
		CString str;
		lb->GetText(index, str);
		char data[100];
		int i=0;
		sscanf(str.GetBuffer(0),"%s %d", data, &i);
		if(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_pICSWindowDlg != NULL)
			((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_pICSWindowDlg->SendPlay(i);
	}
	//m_seekListPtr.
}
void CSeekListDlg::InsertSeek(CString str,int index)
{

	SeekList *sl = new SeekList();
	sl->seekindex = index;
	strcpy(sl->seektype,str.GetBuffer(0));	
	m_seekListPtr.AddTail(sl);	
	if(m_seekListPtr.GetCount() > 100)
	{
		m_seekListPtr.RemoveHead();		
	}
	Update();
}
void CSeekListDlg::Update()
{	
	m_list_seek.ResetContent();
	POSITION ps = m_seekListPtr.GetHeadPosition();
	for(int i=0; i < m_seekListPtr.GetCount(); i++)
	{		
		CString str;
		SeekList *sl = (SeekList*)m_seekListPtr.GetNext(ps);		
		if(sl != NULL)
		{
			str.Format("%s %d", sl->seektype, sl->seekindex);			
			m_list_seek.InsertString(-1, str);
		}
	}
	UpdateData(FALSE);
}
BOOL CSeekListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
