// PickPieceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "PickPieceDlg.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPickPieceDlg dialog


CPickPieceDlg::CPickPieceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPickPieceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPickPieceDlg)
	m_static_status = _T("Selected nothing");
	//}}AFX_DATA_INIT

	m_piecked_piece = -2;
	m_piece_type = BLANK;
	m_piece_color = NONE;
	m_pickpiecetype = -2;
}


void CPickPieceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPickPieceDlg)
	DDX_Text(pDX, IDC_STATIC_STATUS, m_static_status);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPickPieceDlg, CDialog)
	//{{AFX_MSG_MAP(CPickPieceDlg)
	ON_BN_CLICKED(IDC_STATIC_BISHOP_BLACK, OnStaticBishopBlack)
	ON_BN_CLICKED(IDC_STATIC_BISHOP_WHITE, OnStaticBishopWhite)
	ON_BN_CLICKED(IDC_STATIC_BITMAP_KNIGHT, OnStaticBitmapKnight)
	ON_BN_CLICKED(IDC_STATIC_KING_BLACK, OnStaticKingBlack)
	ON_BN_CLICKED(IDC_STATIC_KING_WHITE, OnStaticKingWhite)
	ON_BN_CLICKED(IDC_STATIC_KNIGHT_BLACK, OnStaticKnightBlack)
	ON_BN_CLICKED(IDC_STATIC_PAWN_BLACK, OnStaticPawnBlack)
	ON_BN_CLICKED(IDC_STATIC_PAWN_WHITE, OnStaticPawnWhite)
	ON_BN_CLICKED(IDC_STATIC_QUEEN_BLACK, OnStaticQueenBlack)
	ON_BN_CLICKED(IDC_STATIC_QUEEN_WHITE, OnStaticQueenWhite)
	ON_BN_CLICKED(IDC_STATIC_ROOT_BLACK, OnStaticRootBlack)
	ON_BN_CLICKED(IDC_STATIC_ROOT_WHITE, OnStaticRootWhite)
	ON_BN_CLICKED(IDC_STATIC_EMPTY, OnStaticEmpty)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPickPieceDlg message handlers

void CPickPieceDlg::OnStaticBishopBlack() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = BISHOP_BLACK;
	m_piece_type = BISHOP;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Bishop";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticBishopWhite() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = BISHOP_WHITE;
	m_piece_type = BISHOP;
	m_piece_color = WHITE;
	m_static_status ="Selected White Bishop";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticBitmapKnight() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = KNIGHT_WHITE;	
	m_piece_type = KNIGHT;
	m_piece_color = WHITE;
	m_static_status ="Selected White Knight";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticKingBlack() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = KING_BLACK;
	m_piece_type = KING;
	m_piece_color = BLACK;
	m_static_status ="Selected King Black";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticKingWhite() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = KING_WHITE;
	m_piece_type = KING;
	m_piece_color = WHITE;
	m_static_status ="Selected White King";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticKnightBlack() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = KNIGHT_BLACK;
	m_piece_type = KNIGHT;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Knight";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticPawnBlack() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = PAWN_BLACK;
	m_piece_type = PAWN;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Pawn";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticPawnWhite() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = PAWN_WHITE;
	m_piece_type = PAWN;
	m_piece_color = WHITE;
	m_static_status ="Selected White Pawn";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticQueenBlack() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = QUEEN_BLACK;
	m_piece_type = QUEEN;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Queen";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticQueenWhite() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = QUEEN_WHITE;
	m_piece_type = QUEEN;
	m_piece_color = WHITE;
	m_static_status ="Selected White Queen";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticRootBlack() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = ROOK_BLACK;
	m_piece_type = ROOK;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Rook";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticRootWhite() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = ROOK_WHITE;
	m_piece_type = ROOK;
	m_piece_color = WHITE;
	m_static_status ="Selected White Rook";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticEmpty() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = -1;
	m_piece_type = BLANK;
	m_piece_color = NONE;
	m_static_status ="Selected Blank";
	UpdateData(FALSE);
}

BOOL CPickPieceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	if(m_pickpiecetype == -1)
	{
		if(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetPlayerSide() == BLACK)
		{	 
			CWnd* wnd = GetDlgItem(IDC_STATIC_BISHOP_BLACK );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KING_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KNIGHT_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_PAWN_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_QUEEN_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_ROOT_BLACK);
			wnd->EnableWindow();			 

			
		}
		else if(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetPlayerSide() == WHITE)
		{

			CWnd* wnd = GetDlgItem(IDC_STATIC_BISHOP_WHITE);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_BITMAP_KNIGHT );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KING_WHITE );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_PAWN_WHITE);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_QUEEN_WHITE );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_ROOT_WHITE);
			wnd->EnableWindow();	  
		}
	}
	else
	{
			CWnd* wnd = GetDlgItem(IDC_STATIC_BISHOP_WHITE);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_BITMAP_KNIGHT );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KING_WHITE );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_PAWN_WHITE);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_QUEEN_WHITE );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_ROOT_WHITE);
			wnd->EnableWindow();	  
			wnd = GetDlgItem(IDC_STATIC_BISHOP_BLACK );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KING_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KNIGHT_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_PAWN_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_QUEEN_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_ROOT_BLACK);
			wnd->EnableWindow();			 
			wnd = GetDlgItem(IDC_STATIC_EMPTY);
			wnd->EnableWindow();			 
	}
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPickPieceDlg::OnOK() 
{
	// TODO: Add extra validation here
	m_pickpiecetype = -1;
	CDialog::OnOK();
}

void CPickPieceDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	m_pickpiecetype = -1;
	CDialog::OnCancel();
}

void CPickPieceDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	if(m_pickpiecetype == -1)
	{
		if(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetPlayerSide() == BLACK)
		{	 
			CWnd* wnd = GetDlgItem(IDC_STATIC_BISHOP_BLACK );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KING_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KNIGHT_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_PAWN_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_QUEEN_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_ROOT_BLACK);
			wnd->EnableWindow();			 
			
		}
		else if(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetPlayerSide() == WHITE)
		{
			CWnd* wnd = GetDlgItem(IDC_STATIC_BISHOP_WHITE);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_BITMAP_KNIGHT );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KING_WHITE );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_PAWN_WHITE);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_QUEEN_WHITE );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_ROOT_WHITE);
			wnd->EnableWindow();	  
		}
	}
	else
	{
			CWnd* wnd = GetDlgItem(IDC_STATIC_BISHOP_WHITE);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_BITMAP_KNIGHT );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KING_WHITE );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_PAWN_WHITE);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_QUEEN_WHITE );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_ROOT_WHITE);
			wnd->EnableWindow();	  
			wnd = GetDlgItem(IDC_STATIC_BISHOP_BLACK );
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KING_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_KNIGHT_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_PAWN_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_QUEEN_BLACK);
			wnd->EnableWindow();
			wnd = GetDlgItem(IDC_STATIC_ROOT_BLACK);
			wnd->EnableWindow();			 
			wnd = GetDlgItem(IDC_STATIC_EMPTY);
			wnd->EnableWindow();			 
	}
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}
