// ViewImage.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "ViewImage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewImage dialog


CViewImage::CViewImage(CWnd* pParent /*=NULL*/)
	: CDialog(CViewImage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CViewImage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CViewImage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewImage)
	DDX_Control(pDX, IDC_STATIC_IMAGE, m_static_image);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewImage, CDialog)
	//{{AFX_MSG_MAP(CViewImage)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_SELECT_IMAGE, OnButtonSelectImage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewImage message handlers

BOOL CViewImage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CViewImage::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	if(!m_fileName.IsEmpty())	
	{
		//DisplayImage(m_fileName);
	}
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}

void CViewImage::OnButtonSelectImage() 
{
	//CClientDC dc(this);
	CFileDialog fdialog(TRUE);
	m_fileName = "";
	if(fdialog.DoModal() == IDOK)
	{
		if(DisplayImage(fdialog.GetFileName()) == 0)
		{
			m_fileName = fdialog.GetFileName();
		}
	}	
}

int CViewImage::DisplayImage(CString file)
{
		IPicture *ppic=NULL;
		CBitmap loadBitmap;				
		CWnd* btn =GetDlgItem(IDC_STATIC_IMAGE);
		CRect rect;		
		btn->GetClientRect(rect);
		CClientDC dc(btn);		

		HANDLE hImg = LoadImage(NULL,file,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		if(hImg != NULL)
		{		
			loadBitmap.Attach(hImg);
			CDC bmpdc;
			bmpdc.CreateCompatibleDC(&dc);
			bmpdc.SelectObject(loadBitmap);
			BITMAP bmp;
			 
			dc.SetStretchBltMode(HALFTONE);
			POINT pt;
			SetBrushOrgEx(dc.GetSafeHdc(),0,0,&pt);
 			loadBitmap.GetBitmap(&bmp);
			dc.StretchBlt(0,0,rect.right,rect.bottom,&bmpdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);	
		}
		else
		{
			CoInitialize(NULL);			 			
			CFile pf;
			if(pf.Open(file, CFile::modeRead) == 0)
			{
				CoUninitialize();
				AfxMessageBox("Could not open the file");
				return -1;
			}
			CArchive ar(&pf, CArchive::load | CArchive::bNoFlushOnDelete);
			CArchiveStream arcstream(&ar);
			OleLoadPicture((IStream*)&arcstream,0,FALSE,
				IID_IPicture,(void**)&ppic);
			pf.Close();
			if(ppic == NULL)
			{
				CoUninitialize();
				AfxMessageBox("The selected image file type is not supported");
				return -1;
			}
			else
			{
				long height,weight;
				ppic->get_Height(&height);
				ppic->get_Width(&weight);
				ppic->Render(dc.GetSafeHdc(),
					 rect.left,rect.top,				 
					rect.right,rect.bottom,
					0, height,weight,-height,NULL);			 
			}
			CoUninitialize();
		}
	return 0;
}
