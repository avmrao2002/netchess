// Options.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "MyColorDialog.h"
#include "Options.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptions dialog


COptions::COptions(CWnd* pParent /*=NULL*/)
	: CDialog(COptions::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptions)
	m_check_auto_save = FALSE;
	m_check_save_with_history = FALSE;
	m_edit_replay_interval = 0;
	m_check_netchess_log = FALSE;
	m_check_pgn_mail_format = FALSE;
	m_edit_def_black_engine = _T("");
	m_edit_def_white_engine = _T("");
	m_edit_font = _T("");
	m_edit_font_size = 0;
	m_check_extended_view = FALSE;
	m_check_save_game = FALSE;
	m_check_black_engine_auto_start = TRUE;
	//}}AFX_DATA_INIT
	COLORREF w(RGB(192,192,192)),b(RGB(64,128,128));//b(RGB(128,128,128));
	m_crefWhiteColor =  w;
	m_crefBlackColor =  b;
	COLORREF wp(RGB(255,255,255)),bp(RGB(0,0,0));//b(RGB(128,128,128));
	m_crefWhitePieceColor =  wp;
	m_crefBlackPieceColor =  bp;
	m_pieceType = 1;
	m_whiteClrDlg = false;
	m_blackClrDlg = false;
	m_UCImove = 1;
	m_boardFont = DEFAULT;

}


void COptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptions)
	DDX_Check(pDX, IDC_CHECK_AUTO_SAVE, m_check_auto_save);
	DDX_Check(pDX, IDC_CHECK_SAVE_WITH_HISTORY, m_check_save_with_history);
	DDX_Text(pDX, IDC_EDIT_INTERVAL, m_edit_replay_interval);
	DDV_MinMaxInt(pDX, m_edit_replay_interval, 0, 20);
	DDX_Check(pDX, IDC_CHECK_NETCHESS_LOG, m_check_netchess_log);
	DDX_Check(pDX, IDC_CHECK_PGN_MAIL_FORMAT, m_check_pgn_mail_format);
	DDX_Text(pDX, IDC_EDIT_DEF_BLACK_ENGINE, m_edit_def_black_engine);
	DDX_Text(pDX, IDC_EDIT_DEF_WHITE_ENGINE, m_edit_def_white_engine);
	DDX_Text(pDX, IDC_EDIT_FONT, m_edit_font);
	DDX_Text(pDX, IDC_EDIT_FONT_SIZE, m_edit_font_size);
	DDX_Check(pDX, IDC_CHECK_EXTENDED_VIEW, m_check_extended_view);
	DDX_Check(pDX, IDC_CHECK_SAVE_LAST_GAME, m_check_save_game);
	DDX_Check(pDX, IDC_CHECK_BLACK_ENGINE_AUTO_START, m_check_black_engine_auto_start);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptions, CDialog)
	//{{AFX_MSG_MAP(COptions)
	ON_BN_CLICKED(IDC_BUTTON_BLACK_COLOR, OnButtonBlackColor)
	ON_BN_CLICKED(IDC_BUTTON_WHITE_COLOR, OnButtonWhiteColor)
	ON_BN_CLICKED(IDC_CHECK_AUTO_SAVE, OnCheckAutoSave)
	ON_BN_CLICKED(IDC_CHECK_SAVE_WITH_HISTORY, OnCheckSaveWithHistory)
	ON_BN_CLICKED(IDC_BUTTON_APPLY_SAVE, OnButtonApplySave)
	ON_BN_CLICKED(IDC_RADIO_FEN_STRING, OnRadioFenString)
	ON_BN_CLICKED(IDC_RADIO_STARTPOS, OnRadioStartpos)
	ON_BN_CLICKED(IDC_BUTTON_BLACK_BROWSE, OnButtonBlackBrowse)
	ON_BN_CLICKED(IDC_BUTTON_WHITE_BROWSE, OnButtonWhiteBrowse)
	ON_BN_CLICKED(IDC_FONT, OnFont)
	ON_BN_CLICKED(IDC_RADIO_FONT_BOARD, OnRadioFontBoard)
	ON_BN_CLICKED(IDC_RADIO_DEFAULT, OnRadioDefault)
	ON_BN_CLICKED(IDC_BUTTON_WHITE_COLOR2, OnButtonWhiteColor2)
	ON_BN_CLICKED(IDC_BUTTON_BLACK_COLOR2, OnButtonBlackColor2)
	ON_WM_SHOWWINDOW()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_RADIO_BLACKENGINE_UCII, OnRadioBlackengineUcii)
	ON_BN_CLICKED(IDC_RADIO_BLACKENGINE_UCIII, OnRadioBlackengineUciii)
	ON_BN_CLICKED(IDC_RADIO_BLACKENGINE_WBI, OnRadioBlackengineWbi)
	ON_BN_CLICKED(IDC_RADIO_BLACKENGINE_WBII, OnRadioBlackengineWbii)
	ON_BN_CLICKED(IDC_RADIO_WHITEENGINE_UCII, OnRadioWhiteengineUcii)
	ON_BN_CLICKED(IDC_RADIO_WHITEENGINE_UCIII, OnRadioWhiteengineUciii)
	ON_BN_CLICKED(IDC_RADIO_WHITEENGINE_WBI, OnRadioWhiteengineWbi)
	ON_BN_CLICKED(IDC_RADIO_WHITEENGINE_WBII, OnRadioWhiteengineWbii)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptions message handlers

void COptions::OnButtonBlackColor() 
{
	// TODO: Add your control notification handler code here
	CMyColorDialog cdlg;
	if(cdlg.DoModal() == IDOK)
	{
		m_crefBlackColor=cdlg.GetColor();		 
		CStatic *pblack = (CStatic*)GetDlgItem(IDC_STATIC_BLACK);
		CRect rect;
		CClientDC dc((CWnd*)pblack);
		pblack->GetClientRect(rect);		 
		CBrush brush(m_crefBlackColor);
		CBrush *pOldBrush = (CBrush*)dc.SelectObject(brush); 
		dc.FillRect(&rect,&brush);
		UpdateData(FALSE);
		m_whiteClrDlg = false;
		m_blackClrDlg = true;
	}	
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}

void COptions::OnButtonWhiteColor() 
{
	// TODO: Add your control notification handler code here
	CMyColorDialog cdlg;
	if(cdlg.DoModal() == IDOK)
	{
		m_crefWhiteColor = cdlg.GetColor();
		CStatic *pwhite = (CStatic*)GetDlgItem(IDC_STATIC_WHITE);
		CRect rect;
		CClientDC dc((CWnd*)pwhite);
		pwhite->GetClientRect(rect);		 
		CBrush brush(m_crefWhiteColor);
		CBrush *pOldBrush = (CBrush*)dc.SelectObject(brush); 
		dc.FillRect(&rect,&brush);
		UpdateData(FALSE);
		m_whiteClrDlg = true;
		m_blackClrDlg = false;
		//dc.SelectObject(*pOldBrush);
	}	
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}

BOOL COptions::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CStatic *pwhite = (CStatic*)GetDlgItem(IDC_STATIC_WHITE);

	CRect rect;
	CClientDC dc((CWnd*)pwhite);
	pwhite->GetClientRect(rect);		 
	CBrush brush(m_crefWhiteColor);
	CBrush *pOldBrush = (CBrush*)dc.SelectObject(brush); 
	dc.FillRect(&rect,&brush);	

	CStatic *pblack = (CStatic*)GetDlgItem(IDC_STATIC_BLACK);	 
	CClientDC bdc((CWnd*)pblack);
	pblack->GetClientRect(rect);		 
	CBrush bbrush(m_crefBlackColor);
	CBrush *pOldBBrush = (CBrush*)bdc.SelectObject(bbrush); 
	bdc.FillRect(&rect,&bbrush);
	UpdateData(FALSE);
	if(m_UCImove == 1)
	{
		CButton *btn = (CButton*)GetDlgItem(IDC_RADIO_FEN_STRING);
		btn->SetCheck(1);
	}
	else
	{
		CButton *btn = (CButton*)GetDlgItem(IDC_RADIO_STARTPOS);
		btn->SetCheck(1);
	}
	if(m_boardFont == DEFAULT)
	{
		CButton *btn = (CButton*)GetDlgItem(IDC_RADIO_DEFAULT);
		btn->SetCheck(1);
		btn = (CButton*)GetDlgItem(IDC_RADIO_FONT_BOARD);
		btn->SetCheck(0);
		btn = (CButton*)GetDlgItem(IDC_FONT);
		btn->EnableWindow(FALSE);
	}
	else
	{
		CButton *btn = (CButton*)GetDlgItem(IDC_RADIO_DEFAULT);
		btn->SetCheck(0);
		btn = (CButton*)GetDlgItem(IDC_RADIO_FONT_BOARD);
		btn->SetCheck(1);
		btn = (CButton*)GetDlgItem(IDC_FONT);
		btn->EnableWindow(TRUE);
	}

	switch(m_whiteEngineProtocol)
	{
		CButton *btn;
		case WB_I:
			
			btn = (CButton*)GetDlgItem(IDC_RADIO_WHITEENGINE_WBI);
			btn->SetCheck(1);
			break;
		case WB_II:
			//CButton *btn;
			btn = (CButton*)GetDlgItem(IDC_RADIO_WHITEENGINE_WBII);
			btn->SetCheck(1);
			break;
		case UCI_I:
			//CButton *btn;
			btn = (CButton*)GetDlgItem(IDC_RADIO_WHITEENGINE_UCII);
			btn->SetCheck(1);
			break;
		case UCI_II:
			//CButton *btn;
			btn = (CButton*)GetDlgItem(IDC_RADIO_WHITEENGINE_UCIII);
			btn->SetCheck(1);
			break;
		default:
			break;
	}
	switch(m_blackEngineProtocol)
	{
		CButton *btn;
		case WB_I:
			
			btn = (CButton*)GetDlgItem(IDC_RADIO_BLACKENGINE_WBI);
			btn->SetCheck(1);
			break;
		case WB_II:
			//CButton *btn;
			btn = (CButton*)GetDlgItem(IDC_RADIO_BLACKENGINE_WBII);
			btn->SetCheck(1);
			break;
		case UCI_I:
			//CButton *btn;
			btn = (CButton*)GetDlgItem(IDC_RADIO_BLACKENGINE_UCII);
			btn->SetCheck(1);
			break;
		case UCI_II:
			//CButton *btn;
			btn = (CButton*)GetDlgItem(IDC_RADIO_BLACKENGINE_UCIII);
			btn->SetCheck(1);
			break;
		default:
			break;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COptions::OnOK() 
{
	m_whiteClrDlg = false;
	m_blackClrDlg = false;	
	CDialog::OnOK();
}
void COptions ::SetColor(COLORREF cr)
{	
	UpdateData(TRUE);
	if(m_whiteClrDlg == true)
	{
		m_crefWhiteColor = cr;
	}
	else 
	{
		m_crefBlackColor = cr;
	}
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}


void COptions::OnCheckAutoSave() 
{
	// TODO: Add your control notification handler code here
	if(m_check_auto_save == TRUE)
	{
		((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->SetTimer(PIECE_SIDE_TIMER_EVENT_ID,15000,NULL);
	}
	else
	{
		((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->KillTimer(PIECE_SIDE_TIMER_EVENT_ID);
	}
	UpdateData(TRUE);
}

void COptions::OnCheckSaveWithHistory() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
}

void COptions::OnButtonApplySave() 
{
	UpdateData(TRUE);
	char CurrentDir[255];
	GetWindowsDirectory(CurrentDir,MAX_PATH );
	strcat_s(CurrentDir,"\\NetChess.ini");	
	CString str;
	str.Format("%d",m_check_auto_save);
	WritePrivateProfileString("NetChess","AutoSave",str,CurrentDir);
	str.Format("%d",m_check_save_with_history);
	WritePrivateProfileString("NetChess","SaveWithComments",str,CurrentDir);
	str.Format("%d",m_edit_replay_interval);
	WritePrivateProfileString("NetChess","Interval",str,CurrentDir);
	str.Format("%d",m_check_netchess_log);
	WritePrivateProfileString("NetChess","Log",str,CurrentDir);
	str.Format("%d",m_check_pgn_mail_format);	
	WritePrivateProfileString("NetChess","PGNMailFormat",str,CurrentDir);

	str.Format("%d",m_check_extended_view);	
	WritePrivateProfileString("NetChess","ExtendedView",str,CurrentDir);

	str.Format("%d",m_crefWhiteColor);	
	WritePrivateProfileString("NetChess","WhiteColor",str,CurrentDir);
	str.Format("%d",m_crefBlackColor);
	WritePrivateProfileString("NetChess","BlackColor",str,CurrentDir);
	
	str.Format("%d",m_crefWhitePieceColor);	
	WritePrivateProfileString("NetChess","WhitePieceColor",str,CurrentDir);
	str.Format("%d",m_crefBlackPieceColor);
	WritePrivateProfileString("NetChess","BlackPieceColor",str,CurrentDir);

	str.Format("%d",m_UCImove);
	WritePrivateProfileString("NetChess","UCIMove",str,CurrentDir);	
	
	WritePrivateProfileString("NetChess","DefaultWhiteEngine",m_edit_def_white_engine,CurrentDir);

	str.Format("%d",m_whiteEngineProtocol);
	WritePrivateProfileString("NetChess","DefaultWhiteEngineProtocol",str,CurrentDir);
	
	WritePrivateProfileString("NetChess","DefaultBlackEngine",m_edit_def_black_engine,CurrentDir);

	str.Format("%d",m_blackEngineProtocol);
	WritePrivateProfileString("NetChess","DefaultBlackEngineProtocol", str,CurrentDir);

	str.Format("%d",m_boardFont);	
	WritePrivateProfileString("NetChess","Font",str,CurrentDir);

	str.Format("%d", m_edit_font_size);	
	WritePrivateProfileString("NetChess","FontSize",str,CurrentDir);

	str.Format("%s",m_edit_font);	
	WritePrivateProfileString("NetChess","FontFaceName",str,CurrentDir);

	str.Format("%d",m_check_save_game);	
	WritePrivateProfileString("NetChess","SaveGame",str,CurrentDir);	

	str.Format("%d",m_check_black_engine_auto_start);	
	WritePrivateProfileString("NetChess","BlackEngineAutoStart",str,CurrentDir);	

	/*CStringArray ar;
	str = ((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetHistoryString(ar,0);
	str.Replace("\r","");
	str = str + "\n";
	WritePrivateProfileString("NetChess","PGNFormat",str,CurrentDir);*/


	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(WM_PAINT,0,0);

}


void COptions::OnRadioFenString() 
{
	// TODO: Add your control notification handler code here
	m_UCImove = 1;//FEN String
}

void COptions::OnRadioStartpos() 
{
	// TODO: Add your control notification handler code here
	m_UCImove = 2; //Start pos	
}

void COptions::OnButtonBlackBrowse() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fdialog(TRUE);
	if(fdialog.DoModal() == IDOK)
	{	
		
		m_edit_def_black_engine = fdialog.GetPathName(); 	
	}
	UpdateData(FALSE);
}

void COptions::OnButtonWhiteBrowse() 
{
	CFileDialog fdialog(TRUE);
	if(fdialog.DoModal() == IDOK)
	{	
		
		m_edit_def_white_engine = fdialog.GetPathName(); 	
	}
	UpdateData(FALSE);
}

void COptions::OnFont() 
{
		// TODO: Add your control notification handler code here

	CFontDialog dlg;
	
	if(dlg.DoModal()==IDOK)
	{
		m_edit_font = dlg.GetFaceName();
		m_edit_font_size = dlg.GetSize()/10;
		LOGFONT lplogfont;
		dlg.GetCurrentFont(&lplogfont);
		//lplogfont.lfWidth = 20;
		//m_font.CreateFontIndirect(&lplogfont);
		m_font.DeleteObject();
		m_font.CreatePointFont(m_edit_font_size*10,m_edit_font);
			//240,"Chess Merida");
	}
	UpdateData(FALSE);
}

void COptions::OnRadioFontBoard() 
{
	// TODO: Add your control notification handler code here
	m_boardFont = FONT;
	CButton *btn;//= (CButton*)GetDlgItem(IDC_RADIO_FONT_BOARD);
	//btn->SetCheck(1);
	//btn = (CButton*)GetDlgItem(IDC_RADIO_DEFAULT);
	//btn->SetCheck(0);
	btn = (CButton*)GetDlgItem(IDC_FONT);
	btn->EnableWindow(TRUE);
	
}

void COptions::OnRadioDefault() 
{
	// TODO: Add your control notification handler code here
	m_boardFont = DEFAULT;
	CButton *btn;/* = (CButton*)GetDlgItem(IDC_RADIO_DEFAULT);
	btn->SetCheck(1);
	btn = (CButton*)GetDlgItem(IDC_RADIO_FONT_BOARD);
	btn->SetCheck(0);*/
	btn = (CButton*)GetDlgItem(IDC_FONT);
	btn->EnableWindow(FALSE);
}

void COptions::OnButtonWhiteColor2() 
{
	// TODO: Add your control notification handler code here
	CMyColorDialog cdlg;
	if(cdlg.DoModal() == IDOK)
	{
		m_crefWhitePieceColor = cdlg.GetColor();
		CStatic *pwhite = (CStatic*)GetDlgItem(IDC_STATIC_WHITE2);
		CRect rect;
		CClientDC dc((CWnd*)pwhite);
		pwhite->GetClientRect(rect);		 
		CBrush brush(m_crefWhitePieceColor);
		CBrush *pOldBrush = (CBrush*)dc.SelectObject(brush); 
		dc.FillRect(&rect,&brush);
		UpdateData(FALSE);
		//m_whiteClrDlg = true;
		//m_blackClrDlg = false;
		//dc.SelectObject(*pOldBrush);
	}	
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);

	
}

void COptions::OnButtonBlackColor2() 
{
	// TODO: Add your control notification handler code here
	
	CMyColorDialog cdlg;
	if(cdlg.DoModal() == IDOK)
	{
		m_crefBlackPieceColor=cdlg.GetColor();		 
		CStatic *pblack = (CStatic*)GetDlgItem(IDC_STATIC_BLACK2);
		CRect rect;
		CClientDC dc((CWnd*)pblack);
		pblack->GetClientRect(rect);		 
		CBrush brush(m_crefBlackPieceColor);
		CBrush *pOldBrush = (CBrush*)dc.SelectObject(brush); 
		dc.FillRect(&rect,&brush);
		UpdateData(FALSE);
		//m_whiteClrDlg = false;
		//m_blackClrDlg = true;
	}	
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}

void COptions::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here		
}

void COptions::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CStatic *pwhite = (CStatic*)GetDlgItem(IDC_STATIC_WHITE);

	CRect rect;
	CClientDC cdc((CWnd*)pwhite);
	pwhite->GetClientRect(rect);
	COLORREF c(RGB(255,255,255));
	//CBrush brush(m_crefWhiteColor);
	CBrush brush(c);
	CBrush *pOldBrush = (CBrush*)cdc.SelectObject(brush); 
	cdc.FillRect(&rect,&brush);	

	CStatic *pblack = (CStatic*)GetDlgItem(IDC_STATIC_BLACK);	 
	CClientDC bdc((CWnd*)pblack);
	pblack->GetClientRect(rect);		 
	CBrush bbrush(m_crefBlackColor);
	CBrush *pOldBBrush = (CBrush*)bdc.SelectObject(bbrush);
	UpdateData(FALSE);
	// Do not call CDialog::OnPaint() for painting messages
}

void COptions::OnRadioBlackengineUcii() 
{
	// TODO: Add your control notification handler code here
	m_blackEngineProtocol = UCI_I;
}

void COptions::OnRadioBlackengineUciii() 
{
	// TODO: Add your control notification handler code here
	m_blackEngineProtocol = UCI_II;
}

void COptions::OnRadioBlackengineWbi() 
{
	// TODO: Add your control notification handler code here
	m_blackEngineProtocol = WB_I;
}

void COptions::OnRadioBlackengineWbii() 
{
	// TODO: Add your control notification handler code here
	m_blackEngineProtocol = WB_II;
}

void COptions::OnRadioWhiteengineUcii() 
{
	// TODO: Add your control notification handler code here
	m_whiteEngineProtocol = UCI_I;
}

void COptions::OnRadioWhiteengineUciii() 
{
	// TODO: Add your control notification handler code here
	m_whiteEngineProtocol = UCI_II;
}

void COptions::OnRadioWhiteengineWbi() 
{
	// TODO: Add your control notification handler code here
	m_whiteEngineProtocol = WB_I;
}

void COptions::OnRadioWhiteengineWbii() 
{
	// TODO: Add your control notification handler code here
	m_whiteEngineProtocol = WB_II;
}
