#include "stdafx.h"
#include "History.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CHistory::CHistory()
{
	m_piece_side = BOTTOM;
	m_from_piece_type = BLANK;
	m_from_color_type = NONE;
	m_from_pieceid = -1;
	m_from_row_id = 0;
	m_from_col_id = 0;
	m_to_piece_type = BLANK;
	m_to_color_type = NONE;
	m_to_pieceid = -1;
	m_to_row_id = 0;
	m_to_col_id = 0;
	memset(&m_comment,'\0',1024);
	m_halfMoveCount = 0;
}
CHistory::~CHistory()
{
}
void CHistory::SetHistory(
	 PIECE_SIDE piece_side,
	 PIECE_TYPE from_piece_type,
	 COLOR_TYPE from_color_type,
	 int from_pieceid,
	 int from_row_id,
	 int from_col_id, 
	 PIECE_TYPE to_piece_type,
	 COLOR_TYPE to_color_type,
	 int to_pieceid,
	 int to_row_id,
	 int to_col_id)

{
	m_piece_side = piece_side;
	m_from_piece_type = from_piece_type;
	m_from_color_type=from_color_type;
	m_from_pieceid=from_pieceid;
	m_from_row_id=from_row_id;
	m_from_col_id=from_col_id;
	m_to_piece_type=to_piece_type;
	m_to_color_type=to_color_type;
	m_to_pieceid=to_pieceid;
	m_to_row_id=to_row_id;
	m_to_col_id=to_col_id;
//	m_specialAction = NOTHING;
	memset(m_comment,'\0',1024);
	memset(m_moveInfo,'\0',1024);
	m_halfMoveCount = 0;
}

void CHistory::GetHistory(
	PIECE_SIDE &piece_side,
	PIECE_TYPE &from_piece_type,
	 COLOR_TYPE &from_color_type,
	 int &from_pieceid,
	 int &from_row_id,
	 int &from_col_id, 
	 PIECE_TYPE &to_piece_type,
	 COLOR_TYPE &to_color_type,
	 int &to_pieceid,
	 int &to_row_id,
	 int &to_col_id)
{
	piece_side = m_piece_side;
	from_piece_type = m_from_piece_type;
	from_color_type=m_from_color_type;
	from_pieceid=m_from_pieceid;
	from_row_id=m_from_row_id;
	from_col_id=m_from_col_id;
	to_piece_type=m_to_piece_type;
	to_color_type=m_to_color_type;
	to_pieceid=m_to_pieceid;
	to_row_id=m_to_row_id;
	to_col_id=m_to_col_id;
}
void CHistory::SetComment(char str[1024])
{
	memset(m_comment,'\0',1024);
	memcpy(m_comment,str,1024);
}
void CHistory::SetComment(CString& str)
{
	memset(m_comment,'\0',1024);
	strcpy_s(m_comment,str.GetBuffer(0));
}
void CHistory::GetComment(CString& cmt)
{
	cmt.Format("%s",m_comment);
}
void CHistory::SetHalfMoveCount(int cnt)
{
	m_halfMoveCount = cnt;
}
void CHistory::GetHalfMoveCount(int& cnt)
{
	cnt = m_halfMoveCount;
}
int CHistory::GetHalfMoveCount()
{
	return m_halfMoveCount;
}
CString CHistory::GetComment()
{
	CString str;
	str.Format("%s",m_comment);
	return str;
}
void CHistory::SetMoveInfo(char str[1024])
{
	memset(m_moveInfo,'\0',1024);
	memcpy(m_moveInfo,str,1024);
}
void CHistory::SetMoveInfo(CString str)
{
	memset(m_moveInfo,'\0',1024);
	memcpy(m_moveInfo,str.GetBuffer(0),str.GetLength());
}
void CHistory::GetMoveInfo(CString& info)
{
	info.Format("%s",m_moveInfo);
}
CString CHistory::GetMoveInfo()
{
	CString str;
	str.Format("%s",m_moveInfo);
	return str;
}
void CHistory::SetSpecialAction(int action)
{
	m_specialAction = action;	 
}
int CHistory::GetSpecialAction()
{
	return m_specialAction;
}
void CHistory::SetPieceMoveAction(unsigned int action)
{
	m_pieceMoveAction = action;
}
unsigned int CHistory::GetPieceMoveAction()
{
	return m_pieceMoveAction;
}
BOOL CHistory::GetAmbiguousMoveRankFlag()
{
	if((0x0800 & m_pieceMoveAction) != 0)
		return TRUE;
	else 
		return FALSE;
}

BOOL CHistory::GetAmbiguousMoveFileFlag()
{
	if((0x0400 & m_pieceMoveAction) != 0)
		return TRUE;
	else return FALSE;
}

BOOL CHistory::GetEnPassentFlag()
{
	if((0x0200 & m_pieceMoveAction) != 0)
		return TRUE;
	else return FALSE;
}

BOOL CHistory::GetPromotionFlag()
{
	if((0x0100 & m_pieceMoveAction) != 0)
		return TRUE;
	else return FALSE;
}

BOOL CHistory::GetCastlingFlag()
{
	if((0x0080 & m_pieceMoveAction) != 0)
		return TRUE;
	else return FALSE;
}

BOOL CHistory::GetCheckFlag()
{
	if( (0x0040 & m_pieceMoveAction) != 0)
		return TRUE;
	else
		return FALSE;
}
COLOR_TYPE CHistory::GetFromPieceColorType()
{
	return m_from_color_type;
}

