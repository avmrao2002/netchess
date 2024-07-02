/////////////////////////////////////////////////////////////////////////////
// CEngine view

#ifndef ICSCLIENT_INCLUDE
#define ICSCLIENT_INCLUDE
#include "resource.h"
#include "ICSConfigureDlg.h"
#include "ICSPlayersListDlg.h"
#include "SeekListDlg.h"

enum {MAXBUF=1000};
class CICSClient
{
public:
	CICSClient();
	virtual ~CICSClient();
	int m_icsClientFlag;	
	int m_icsClientLoadedFlag;
	int m_icsDefaultFlag;
	HANDLE m_hChildStdinRd, m_hChildStdinWr, m_hChildStdinWrDup, 
		   m_hChildStdoutRd, m_hChildStdoutWr,m_hChildStdoutRdDup;	        
	CString m_icsServer;
	int m_icsPort;
	CString m_icsLoginId;
	CString m_icsPassword;
	CView* m_pActiveView;
	CString m_icsLog;
	COLOR_TYPE m_icsColorType;
	/*CICSConfigureDlg m_icsConfigureDlg;
	CICSPlayersListDlg m_playersListDlg;
	CICSPlayersListDlg m_gamesListDlg;
	CICSPlayersListDlg m_whoListDlg;
	CICSPlayersListDlg m_soughtListDlg;*/
	CSeekListDlg m_seekListDlg;


	/*INT m_pondorFlag;
	INT m_analyzeFlag;
	CString m_engineName;
	CString m_engineAuthor;
	CStringArray m_arrOptions;
	CStringArray m_arrFeatures;
	CString m_tempString;*/
	
protected:
	
	
	
// Attributes
public:
	int Initialize(CView*);
	BOOL CreateICSClientProcess(VOID); 
	VOID WriteToICSServer(CString); 
	void WriteToBoard(CString);
	//UINT ReadFromEngine(LPVOID buf);
	void StopICSClient();
	void StartICSClient();
	void CloseICSConnection();
	int GetICSClientFlag();
	void parseFeatures();
	void parseFeaturesValue(CString feature,CString& value);
	int parseFeaturesValue(CString feature);
	void LoginToServer(CString userid, CString password);
// Operations
public:


// Implementation
protected:
	

};
#endif

/////////////////////////////////////////////////////////////////////////////
