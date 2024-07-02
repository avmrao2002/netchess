/////////////////////////////////////////////////////////////////////////////
// CEngine
#include "stdafx.h"
#include "Engine.h"
#include "NetChessView.h"
#define MAXBUF 1000
UINT ReadFromEngine(LPVOID buf)
{
	;
	CEngine *ce = (CEngine*)buf;
	char chBuf[MAXBUF];	
	DWORD dwRead;
	ce->m_engineFlag = TRUE;
	CString oneLineData="";	
	while(ce->m_engineFlag == TRUE)
	{		
		memset(chBuf,'\0',MAXBUF);
				ReadFile( ce->m_hChildStdoutRdDup, chBuf, MAXBUF, &dwRead, 
         NULL);
		for(DWORD i=0;i<dwRead;i++)
		{
			if(chBuf[i] == '\r' || chBuf[i] == '\n')
			{
				ce->WriteToBoard(oneLineData);
				oneLineData = "";
			}
			else
			{
				oneLineData += chBuf[i];
			}
		}
		
		Sleep(100);
	}
	CloseHandle(ce->m_hChildStdinRd);
	CloseHandle(ce->m_hChildStdinWrDup);
	CloseHandle(ce->m_hChildStdoutWr);
	CloseHandle(ce->m_hChildStdoutRdDup);	        

	AfxMessageBox("Reading from Engine is stopped");
	return 0;
}


CEngine::CEngine()
{
	m_engineFlag = FALSE;
	m_pondorFlag = FALSE;
	m_analyzeFlag = FALSE;
	m_engineName = "";
	m_engineAuthor = "";
	m_arrOptions.RemoveAll();
	m_engineLoadedFlag = FALSE;
	m_engineDefaultFlag = FALSE;
}

CEngine::~CEngine()
{
}

int CEngine::Initialize(CString enginename,CView* ncv)
{	

   SECURITY_ATTRIBUTES saAttr; 
   BOOL fSuccess;  
   m_engineFile = enginename;
   m_pActiveView = ncv;
// Set the bInheritHandle flag so pipe handles are inherited. 
 
   saAttr.nLength = sizeof(SECURITY_ATTRIBUTES); 
   saAttr.bInheritHandle = TRUE; 
   saAttr.lpSecurityDescriptor = NULL;  
 
// Create a pipe for the child process's STDOUT. 
 
   if (!CreatePipe(&m_hChildStdoutRd, &m_hChildStdoutWr, &saAttr, 0)) 
   {
      AfxMessageBox("Could not initialize engine");
	  return -1;
   }
 
// Create noninheritable read handle and close the inheritable read 
// handle. 
 
    fSuccess = DuplicateHandle(GetCurrentProcess(), m_hChildStdoutRd,
        GetCurrentProcess(), &m_hChildStdoutRdDup , 0,
        FALSE, DUPLICATE_SAME_ACCESS);
    if( !fSuccess )
	{
         AfxMessageBox("Could not initialize engine");
		 return -1;
	}
    CloseHandle(m_hChildStdoutRd);
 
// Create a pipe for the child process's STDIN. 
 
   if (! CreatePipe(&m_hChildStdinRd, &m_hChildStdinWr, &saAttr, 0)) 
   {
         AfxMessageBox("Could not initialize engine");
		 return -1;
	}
 
// Duplicate the write handle to the pipe so it is not inherited. 
 
   fSuccess = DuplicateHandle(GetCurrentProcess(), m_hChildStdinWr, 
      GetCurrentProcess(), &m_hChildStdinWrDup, 0, 
      FALSE,                  // not inherited 
      DUPLICATE_SAME_ACCESS); 
    if (! fSuccess) 
    {
          AfxMessageBox("Could not initialize engine");
		 return -1;
	}
 
   CloseHandle(m_hChildStdinWr); 
 
// Now create the child process. 
   
   fSuccess = CreateEngineProcess();
   if (! fSuccess) 
   {
      AfxMessageBox("Could not initialize engine");
	  return -1;
   } 
   m_engineLoadedFlag = TRUE;
   //Create read thread
   return 1;
}

BOOL CEngine::CreateEngineProcess(VOID)
{
   PROCESS_INFORMATION piProcInfo; 
   STARTUPINFO siStartInfo;
   BOOL bFuncRetn = FALSE; 
 
// Set up members of the PROCESS_INFORMATION structure. 
 
   ZeroMemory( &piProcInfo, sizeof(PROCESS_INFORMATION) );
 
// Set up members of the STARTUPINFO structure. 
 
   ZeroMemory( &siStartInfo, sizeof(STARTUPINFO) );
   siStartInfo.cb = sizeof(STARTUPINFO); 
   siStartInfo.hStdError = m_hChildStdoutWr;
   siStartInfo.hStdOutput = m_hChildStdoutWr;
   siStartInfo.hStdInput = m_hChildStdinRd;
   siStartInfo.dwFlags |= STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
   siStartInfo.wShowWindow = SW_HIDE;
// Create the child process. 
    
   bFuncRetn = CreateProcess(NULL, 
      m_engineFile.GetBuffer(0),       // command line 
      NULL,          // process security attributes 
      NULL,          // primary thread security attributes 
      TRUE,          // handles are inherited 
      0,             // creation flags 
      NULL,          // use parent's environment 
      NULL,          // use parent's current directory 
      &siStartInfo,  // STARTUPINFO pointer 
      &piProcInfo);  // receives PROCESS_INFORMATION 
   
   if (bFuncRetn == 0) 
   {
      return -1;
   }
   else 
   {   
      CloseHandle(piProcInfo.hProcess);
      CloseHandle(piProcInfo.hThread);
      return bFuncRetn;
   }
   return -1;
}

VOID CEngine::WriteToEngine(CString data)
{
	if(m_engineFlag == TRUE)
	{
		data += "\n";
		DWORD dwWritten;		
		WriteFile(m_hChildStdinWrDup, data, data.GetLength(), 
			 &dwWritten, NULL);
		data.Replace("\n","\r\n");
		m_engineLog += data;
	}
}

void CEngine::StopEngine()
{
	m_engineFlag = FALSE;
}

void CEngine::StartEngine()
{
	if(m_engineFlag == FALSE)
	{
		m_engineFlag = TRUE;
		AfxBeginThread((AFX_THREADPROC)ReadFromEngine,(LPVOID)this);
	//fxMessageBox("Engine started");		
	}
}
int CEngine::GetEngineFlag()
{
	return m_engineFlag;
}

void CEngine::CloseEngine()
{
	//find how to close the process
	m_arrOptions.RemoveAll();
	m_arrFeatures.RemoveAll();
	WriteToEngine("quit");
	
	m_engineLoadedFlag = FALSE;
	m_engineDefaultFlag = FALSE;
	m_engineFlag = FALSE;
	m_pondorFlag = FALSE;
	m_analyzeFlag = FALSE;
	m_engineName = "";
	m_engineAuthor = "";
	m_tempString = "";
	m_engineLog = "";
	
/*	CloseHandle(m_hChildStdinRd);
	CloseHandle(m_hChildStdinWrDup);
	CloseHandle(m_hChildStdoutWr);
	CloseHandle(m_hChildStdoutRdDup)*/
}

VOID CEngine::WriteToBoard(CString str)
{
	m_engineLog += str + (CString)"\r\n";	
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->HandleEngineData(m_engineType,str);
}
int CEngine::parseFeaturesValue(CString feature)
{
	for(int i= 0;i< m_arrFeatures.GetSize(); i++)
	{
		int ret = m_arrFeatures[i].Find(feature,0);
		if(ret >= 0)
		{
			char arr[2];
			arr[1] = '\0';
			arr[0] = m_arrFeatures[i][ret+feature.GetLength()+1];
			return atoi(arr);			
		}
	}
	return 0;
}
void CEngine::parseFeaturesValue(CString feature,CString& value)
{
	for(int i= 0;i< m_arrFeatures.GetSize(); i++)
	{
		int ret = m_arrFeatures[i].Find(feature);
		if(ret >= 0)
		{
			CString str = m_arrFeatures[i].Right(m_arrFeatures[i].GetLength() - (ret+feature.GetLength()+2));
			int ret1 = str.Find("\"");
			value = str.Left(ret1);			
		}
	}
	return;
}

void CEngine::SetEngineTime(int mytime,int opponenttime)
{
	if(m_engineConfigDlg.m_chessProtocol == WB_I || m_engineConfigDlg.m_chessProtocol == WB_II)
	{
		int mt = mytime*100;
		int ot = opponenttime*100;
		CString str;
		str.Format("time %d",mt);
		WriteToEngine(str);
		str.Format("otime %d",ot);
		WriteToEngine(str);
	}
	else if(m_engineConfigDlg.m_chessProtocol == UCI_I || m_engineConfigDlg.m_chessProtocol == UCI_II)
	{
		int mt = mytime*1000;
		int ot = opponenttime*1000;
		CString str;
		str.Format("wtime %d",mt);
		WriteToEngine(str);
		str.Format("btime %d",ot);
		WriteToEngine(str);
	}
}

void CEngine::parseFeatures()
{
	//int m_ping;
	m_ping = parseFeaturesValue("ping");
	m_setboard = parseFeaturesValue("setboard");
	m_playother= parseFeaturesValue("playother");
	m_san = parseFeaturesValue("san");
	m_usermove = parseFeaturesValue("usermove");
	m_time = parseFeaturesValue("time");
	m_draw = parseFeaturesValue("draw");
	m_analyze = parseFeaturesValue("analyze");		
	m_sigint = parseFeaturesValue("sigint");		
	m_sigterm = parseFeaturesValue("sigterm");		
	m_reuse = parseFeaturesValue("reuse");
	m_colors = parseFeaturesValue("colors");
	m_ics = parseFeaturesValue("ics");
	m_name = parseFeaturesValue(" name");
	m_pause = parseFeaturesValue("pause");
	m_done = parseFeaturesValue("done");	
	parseFeaturesValue("myname",m_myname);
	parseFeaturesValue("variants",m_variants);	
}
