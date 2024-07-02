/////////////////////////////////////////////////////////////////////////////
// CEngine view

#ifndef ENGINE_INCLUDE
#define ENGINE_INCLUDE
#include "resource.h"
#include "EngineConfigDlg.h"
//enum {MAXBUF=1000};
class CEngine
{
public:
	CEngine();
	virtual ~CEngine();
	int m_engineFlag;	
	int m_engineLoadedFlag;
	int m_engineDefaultFlag;
	HANDLE m_hChildStdinRd, m_hChildStdinWr, m_hChildStdinWrDup, 
		   m_hChildStdoutRd, m_hChildStdoutWr,m_hChildStdoutRdDup;	        
	CString m_engineFile;
	CView* m_pActiveView;
	CString m_engineLog;
	COLOR_TYPE m_engineType;
	CEngineConfigDlg m_engineConfigDlg;
	INT m_pondorFlag;
	INT m_analyzeFlag;
	CString m_engineName;
	CString m_engineAuthor;
	CStringArray m_arrOptions;
	CStringArray m_arrFeatures;
	CString m_tempString;
	
protected:
	
	
	
// Attributes
public:
	int Initialize(CString,CView*);
	BOOL CreateEngineProcess(VOID); 
	VOID WriteToEngine(CString); 
	void WriteToBoard(CString);
	//UINT ReadFromEngine(LPVOID buf);
	void StopEngine();
	void StartEngine();
	void CloseEngine();
	int GetEngineFlag();
	void parseFeatures();
	void parseFeaturesValue(CString feature,CString& value);
	int parseFeaturesValue(CString feature);
	void SetEngineTime(int mytime,int opponenttime);
	int m_ping;
	int m_setboard;
	int m_playother;
	int m_san;
	int m_usermove;
	int m_time;
	int m_draw;
	int m_sigint;
	int m_sigterm;
	int m_reuse;
	int m_analyze;
	CString m_myname;
	CString m_variants;
	int m_colors;
	int m_ics;
	int m_name;
	int m_pause;
	int m_done;	
// Operations
public:


// Implementation
protected:
	

};
#endif

/////////////////////////////////////////////////////////////////////////////
