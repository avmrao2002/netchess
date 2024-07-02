#if !defined(HISTORY_H)
#define HISTORY_H

class CHistory
{
private:	 
	 PIECE_SIDE m_piece_side;
	 PIECE_TYPE m_from_piece_type;
	 COLOR_TYPE m_from_color_type;
	 int m_from_pieceid;
	 int m_from_row_id;
	 int m_from_col_id;
	 char m_comment[1024];
	 char m_moveInfo[1024];

	 PIECE_TYPE m_to_piece_type;
	 COLOR_TYPE m_to_color_type;
	 int m_to_pieceid;
	 int m_to_row_id;
	 int m_to_col_id;
	 int m_specialAction;
	 unsigned int m_pieceMoveAction;
	 int m_halfMoveCount;

public:
	CHistory();
	~CHistory();
	void SetHistory(PIECE_SIDE piece_side,PIECE_TYPE from_piece_type,
	 COLOR_TYPE from_color_type,
	 int from_pieceid,
	 int from_row_id,
	 int from_col_id, 
	 PIECE_TYPE to_piece_type,
	 COLOR_TYPE to_color_type,
	 int to_pieceid,
	 int to_row_id,
	 int to_col_id);

	void GetHistory(PIECE_SIDE& piece_side,PIECE_TYPE &from_piece_type,
	 COLOR_TYPE &from_color_type,
	 int &from_pieceid,
	 int &from_row_id,
	 int &from_col_id, 
	 PIECE_TYPE &to_piece_type,
	 COLOR_TYPE &to_color_type,
	 int &to_pieceid,
	 int &to_row_id,
	 int &to_col_id);	 
 
	void SetSpecialAction(int act);
	int GetSpecialAction();
	void SetPieceMoveAction(unsigned int action);
	unsigned int GetPieceMoveAction(); 
	BOOL GetAmbiguousMoveRankFlag();
	BOOL GetAmbiguousMoveFileFlag();
	BOOL GetEnPassentFlag();
	BOOL GetPromotionFlag();
	BOOL GetCastlingFlag();
	BOOL GetCheckFlag();
	void SetComment(char *);
	void SetComment(CString&);
	void GetComment(CString&);
	CString GetComment();
	void SetMoveInfo(char*);
	void SetMoveInfo(CString str);
	void GetMoveInfo(CString&);
	CString GetMoveInfo();
	void SetHalfMoveCount(int);
	void GetHalfMoveCount(int&);
	int GetHalfMoveCount();
	COLOR_TYPE GetFromPieceColorType();


protected:
};
#endif