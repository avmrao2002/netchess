// EngineLogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "netchess.h"
#include "EngineLogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define LOG_UPDATE_TIMER 5000
/////////////////////////////////////////////////////////////////////////////
// CEngineLogDlg dialog


CEngineLogDlg::CEngineLogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEngineLogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEngineLogDlg)
	m_edit_engine_log = _T("");
	m_edit_engine_command = _T("");
	//}}AFX_DATA_INIT
}


void CEngineLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEngineLogDlg)
	DDX_Text(pDX, IDC_EDIT_ENGINE_LOG, m_edit_engine_log);
	DDX_Text(pDX, IDC_EDIT_ENGINE_COMMAND, m_edit_engine_command);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEngineLogDlg, CDialog)
	//{{AFX_MSG_MAP(CEngineLogDlg)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_COPY, OnButtonCopy)
	ON_EN_CHANGE(IDC_EDIT_ENGINE_LOG, OnChangeEditEngineLog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEngineLogDlg message handlers

void CEngineLogDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	
	m_pEngine->WriteToEngine(m_edit_engine_command);
	m_edit_engine_log = m_pEngine->m_engineLog;
	UpdateData(FALSE);
}

void CEngineLogDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_edit_engine_log != m_pEngine->m_engineLog)
	{
		m_edit_engine_log = m_pEngine->m_engineLog;
		UpdateData(FALSE);
	}
	CWnd* wnd= GetDlgItem(IDC_EDIT_ENGINE_LOG);
	wnd->PostMessage(WM_VSCROLL,SB_BOTTOM,0);

	CDialog::OnTimer(nIDEvent);
}

BOOL CEngineLogDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
	SetTimer(LOG_UPDATE_TIMER,3000,NULL);
	CWnd* wnd= GetDlgItem(IDC_EDIT_ENGINE_LOG);
	wnd->PostMessage(WM_VSCROLL,SB_BOTTOM,0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEngineLogDlg::OnOK() 
{
	// TODO: Add extra validation here
	KillTimer(	LOG_UPDATE_TIMER);
	CDialog::OnOK();
}

void CEngineLogDlg::OnButtonClear() 
{
	// TODO: Add your control notification handler code here
	m_edit_engine_log = m_pEngine->m_engineLog = "";
	UpdateData(FALSE);
}

void CEngineLogDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
	CFileDialog dlg(FALSE);
	if(dlg.DoModal() ==IDOK)
	{
		CFile file;
		file.Open(dlg.GetPathName(),CFile::modeCreate | CFile::modeWrite);
		file.Write(m_edit_engine_log,m_edit_engine_log.GetLength());
		file.Close();
	}	
}

void CEngineLogDlg::OnButtonCopy() 
{
	HANDLE hText = NULL;
	HANDLE hData;//, hClipData; 
	LPSTR lpData;//, lpClipData;                           /* pointers to clip data */
	LPSTR           lpszText;
//	CString str = GetFileSaveString();
	CString str  = m_edit_engine_log;
	
//    hInst = hInstance;    

    if (!(hText 
          = GlobalAlloc(GMEM_MOVEABLE,(DWORD)str.GetLength()))) {        
        return;		

    }
      
    if (!(lpszText = (char*)GlobalLock(hText))) {        
        return;
    }

    strcpy(lpszText, str.GetBuffer(0));
    GlobalUnlock(hText);

	if (hText != NULL) {
        /* Allocate memory and copy the string to it */

        if (!(hData 
             = GlobalAlloc(GMEM_DDESHARE, GlobalSize (hText)))) {            
            return;
        }
        if (!(lpData =(char*) GlobalLock(hData))) {            
            return;
        }
        if (!(lpszText =(char*) GlobalLock (hText))) {            
            return;
        }

        strcpy(lpData, lpszText);
        GlobalUnlock(hData);
        GlobalUnlock (hText);

        /* Clear the current contents of the clipboard, and set
         * the data handle to the new string.
         */

        if (OpenClipboard()) {
            EmptyClipboard();
            SetClipboardData(CF_TEXT, hData);
            CloseClipboard();
        }
        hData = NULL;
	}	
}

void CEngineLogDlg::OnChangeEditEngineLog() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
