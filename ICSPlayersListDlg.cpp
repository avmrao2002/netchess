// ICSPlayersListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "ICSPlayersListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CICSPlayersListDlg dialog


CICSPlayersListDlg::CICSPlayersListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CICSPlayersListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CICSPlayersListDlg)
	m_edit_ics_list = _T("");
	m_static_list = _T("");
	//}}AFX_DATA_INIT
}


void CICSPlayersListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CICSPlayersListDlg)
	DDX_Text(pDX, IDC_EDIT_ICS_LIST, m_edit_ics_list);
	DDX_Text(pDX, IDC_STATIC_LIST, m_static_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CICSPlayersListDlg, CDialog)
	//{{AFX_MSG_MAP(CICSPlayersListDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CICSPlayersListDlg message handlers

BOOL CICSPlayersListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
/*		CRect           rect;
	int             iIcon, iItem, iSubItem, iActualItem;
	LV_ITEM         lvitem;
	CString         strItem1= _T("ITEM");
	CString         strItem2= _T("SUB_ITEM");
	CString         strIconDesc[4], strIconShortDesc[4];
	LPTSTR          pStrTemp1, pStrTemp2;
	CListHdrApp     *pApp;
	HD_ITEM curItem;
	pApp = (CListHdrApp *)AfxGetApp();
	srand((unsigned) time(NULL));  // start the random number generator

	// create image list for header items
	CImageList *m_pImageHdrSmall = new CImageList();
	ASSERT(m_pImageHdrSmall != NULL);    // serious allocation failure checking
	m_pImageHdrSmall->Create(16, 16, ILC_MASK, 2, 2);
	m_pImageHdrSmall->Add(pApp->LoadIcon(IDI_HDRICON1));
	m_pImageHdrSmall->Add(pApp->LoadIcon(IDI_HDRICON2));

	// fill in image lists
	m_pImageList = new CImageList();
	m_pImageListSmall = new CImageList();
	ASSERT(m_pImageList != NULL && m_pImageListSmall != NULL);    // serious allocation failure checking
	m_pImageList->Create(32, 32, TRUE,  4, 4);
	m_pImageListSmall->Create(16, 16, TRUE, 4, 4);
	m_pImageList->Add(pApp->LoadIcon(IDI_ICONLIST1));
	m_pImageList->Add(pApp->LoadIcon(IDI_ICONLIST2));
	m_pImageList->Add(pApp->LoadIcon(IDI_ICONLIST3));
	m_pImageList->Add(pApp->LoadIcon(IDI_ICONLIST4));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_ICONLIST1));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_ICONLIST2));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_ICONLIST3));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_ICONLIST4));

	// initialize the standard and custom hot cursors
	m_hMyHotCursor= pApp->LoadCursor(IDC_SPYGLASS);
	m_hStdHotCursor= m_listctrl.GetHotCursor();
	// retrieve embedded header control
	CHeaderCtrl* pHdrCtrl= NULL;
	pHdrCtrl= m_listctrl.GetHeaderCtrl();

	pHdrCtrl->SetImageList(m_pImageHdrSmall);
	// add bmaps to each header item
	pHdrCtrl->GetItem(0, &curItem);
	curItem.mask= HDI_IMAGE | HDI_FORMAT;
	curItem.iImage= 0;
	curItem.fmt= HDF_LEFT | HDF_IMAGE | HDF_STRING;
	pHdrCtrl->SetItem(0, &curItem);

	pHdrCtrl->GetItem(1, &curItem);
	curItem.mask= HDI_IMAGE | HDI_FORMAT;
	curItem.iImage= 1;
	curItem.fmt= HDF_LEFT | HDF_IMAGE | HDF_STRING;
	pHdrCtrl->SetItem(1, &curItem);
	strIconDesc[0]= _T("Blue Ellipse, Yellow Triangle, Red Rectangle");
	strIconDesc[1]= _T("Yellow Ellipse, Red Triangle, Blue Rectangle");
	strIconDesc[2]= _T("Red Ellipse, Blue Triangle, Yellow Rectangle");
	strIconDesc[3]= _T("Red Ellipse, Yellow Triangle, Blue Rectangle");
	strIconShortDesc[0]= _T("BE, YT, RR (Title)");
	strIconShortDesc[1]= _T("YE, RT, BR (Title)");
	strIconShortDesc[2]= _T("RE, BT, YR (Title)");
	strIconShortDesc[3]= _T("RE, YT, BR (Title)");


//	pApp = (CListHdrApp *)AfxGetApp();
//	m_listctrl.SetImageList(m_pImageList, LVSIL_NORMAL);
//	m_listctrl.SetImageList(m_pImageListSmall, LVSIL_SMALL);

	// insert two columns (REPORT mode) and modify the new header items
	m_listctrl.GetWindowRect(&rect);
	m_listctrl.InsertColumn(0, strItem1, LVCFMT_LEFT,
		rect.Width() * 1/3, 0);
	m_listctrl.InsertColumn(1, strItem2, LVCFMT_LEFT,
		rect.Width() * 2/3, 1);
//	ModifyHeaderItems();

	for (iItem = 0; iItem < 20; iItem++)  // insert the items and subitems into the list view.
		for (iSubItem = 0; iSubItem < 2; iSubItem++)
		{
			if (iSubItem == 0)
				iIcon = rand() % 4;  // choose the icon and legend for the entry

			lvitem.mask = LVIF_TEXT | (iSubItem == 0? LVIF_IMAGE : 0);
			lvitem.iItem = (iSubItem == 0)? iItem : iActualItem;
			lvitem.iSubItem = iSubItem;

			// calculate the main and sub-item strings for the current item
			pStrTemp1= strIconShortDesc[iIcon].GetBuffer(strIconShortDesc[iIcon].GetLength());
			pStrTemp2= strIconDesc[iIcon].GetBuffer(strIconDesc[iIcon].GetLength());
			lvitem.pszText = iSubItem == 0? pStrTemp1 : pStrTemp2;

			lvitem.iImage = iIcon;
			if (iSubItem == 0)
				iActualItem = m_listctrl.InsertItem(&lvitem); // insert new item
			else
				m_listctrl.SetItem(&lvitem); // modify existing item (the sub-item text)
		}*/
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CICSPlayersListDlg::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	strcpy((char*)cs.lpszName,"test");
	
	return CDialog::PreCreateWindow(cs);
}
