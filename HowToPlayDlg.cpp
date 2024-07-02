// HowToPlayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "HowToPlayDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHowToPlayDlg dialog


CHowToPlayDlg::CHowToPlayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHowToPlayDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHowToPlayDlg)
	m_edit_howtoplay = _T("");
	//}}AFX_DATA_INIT
}


void CHowToPlayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHowToPlayDlg)
	DDX_Text(pDX, IDC_EDIT_HOWTOPLAY, m_edit_howtoplay);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHowToPlayDlg, CDialog)
	//{{AFX_MSG_MAP(CHowToPlayDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHowToPlayDlg message handlers

BOOL CHowToPlayDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	m_edit_howtoplay =
		"Introduction:\r\n"
		"==========\r\n\r\n"
		"NetChess version 2.1 developed by AVM RAO is a Graphical User Interface (GUI) for playing chess game. This software can be used \r\n"
		"\t1.	To play chess between two players over network using TCP/IP (LAN) or in internet/intranet (Network vs Network)\r\n"
		"\t2.	To send instant message(chat) while playing chess\r\n"
		"\t3.	To observe the chess game played between two players over network\r\n"
		"\t4.	To play chess between two players on the same board\r\n"
		"\t5.	As PGN, FEN, EPD converter. This can be used\r\n"
		"\t\ta.	To convert PGN to FEN or EPD format\r\n"
		"\t\tb.	To convert FEG to PGN or EPD forma\r\n"
		"\t\tc.	To convert EPD to PGN or FEN format\r\n"
		"\t6.	As PGN, FEN or EPD gave viewer. This can also be used to load the games and analyze using chess engines\r\n"
		"\t7.	To play chess using chess engines (Supports engines with WinBoard I, II and UCI I, II protocols)\r\n"
		"\t\ta.	Human vs Chess Engine with White side\r\n"
		"\t\tb.	Human vs Chess Engine with Black side\r\n"
		"\t\tc.	Chess Engine with White side vs Chess Engine with Black side on the same board\r\n"
		"\t\td.	Chess Engine with White side vs Chess Engine with Black side over network\r\n"	
		"\t8.	To play with chess engines on the same board or over network\r\n"
		"\t9.	To play chess using Internet Chess Servers (ICS)\r\n"
		"\t10.	To play chess via email\r\n\r\n"

"How to establish a chess connection in a network\r\n"

"\tTo play chess in a network, you and your opponent must be in the network. Before starting the game over network, If you are running as Chess server, give IP address and port number to your opponent (Use Windows Start->Run->command->ipconfig/all to get the IP address). If you are running as client, ask IP address and port number from your opponent. Once IP address is known, use \"ping <ipaddress>\" to check the network connection with the server machine. If the other machine is able to ping, then NetChess can be used to play chess over network. If a firewall exists between two machines, then the port must be opened at firewall. Otherwise, NetChess will not work. Ask your network administrator for necessary help. Following steps describes the procedure to establish a chess connection in a network\r\n"

"\t1.	Run NetChess on two machines\r\n"

"\t2.	Run as Server in one machine and as Client in another machine (See steps 3 and 4)\r\n"

"\t3.	To run as Server, click Tools->Server or Server toolbar button and enter your name and port number (Default port number is 55555). Inform Server machine IP address and port number to the other player running as Client. Wait for the connection. First connection is your opponent and observers can be connected from second connection onwards.\r\n"

"\t4.	To run as Client, click Tools->Client or Client toolbar button and enter your name, server IP Address and Port number (if you don't know Server IP address, ask IP address and port number from the player running as Server)\r\n"

"\t5.	Server side player will decide Piece side or can opt for toss (You can discuss and decide who will play with White piece side). Once server accepts the piece side, connection will be established and piece side information will be sent to the client. \r\n"

"\t6.	Once the connection is established, click on \"Edit->Manual Edit->Start Editing\" to enable editing. Mutual agreement is required to enable Manual Editing feature. This step is required to enable the clock. Once the clock is enabled, it is advisable to disable manual editing feature. This will prevent unwanted undo, redo, movefirst, movelast, setting pieces etc... operations.\r\n"

"\t7.	To start clock, in Manual edit mode, click Edit ->Manual Edit -> Pause game (uncheck). This will also enables clock on the other player chess board.\r\n"

"\t8.	Status bar shows \"Game started!\" and clock start working. Now start playing the game\r\n"

"\t9.	Once the connection is established, use Tools->Send Message to send instant message or to Chat.\r\n"

"\t10.	White side player starts the game\r\n\r\n"
 

"How to connect as an Observer:\r\n"

"\tWhen two players are playing the chess over network and you would like to watch and chat then connect as an Observer. You can be observer only when two players have established a chess connection. You will be observer from second connection onwards to the chess server. Following steps describes the procedure to connect as an observer\r\n"

"\t1.	Prerequisite is Server and client must have established chess connection\r\n"

"\t2.	Know server IP address and port number (Ask for IP address and port number from server side player)\r\n"

"\t3.	Connect to Server by clicking Tools->Client and enter Name, Server IP address and port number\r\n"

"\t4.	Server may accept or reject your request\r\n"

"\t5.	During the Observer mode, you can only view or chat with others. Message will be broadcast to Server, client and all other observers. You can also do save and copy operations\r\n"

"\t6.	Connection and disconnection can be done any time during the play\r\n"
 

"\r\nHow to use as PGN/FEN/EPD viewer:\r\n"

"\tManual editing feature should be enabled to view the chess games. NetChess can be used to view a single game or multiple games. This supports PGN, FEN, EPD positions or games.\r\n"

"Single game view:\r\n"

"\t1.	Open the game using File->Open or Copy and paste the game\r\n"

"\t2.	Use MoveFirst, MoveLast, Undo, Redo(Edit->Manual Editing->… or arrow marks on the tool bar) to navigate through the game\r\n"

"\t3.	If FEN/EPD positions are not proper order, use \"Multiple gave view\"\r\n"

"Multiple game views:\r\n"

"\t1.	Load multiple games using File->Load games\r\n"

"\t2.	Navigate through multiple games using LoadFirstGame, LoadPrevGame, LoadNextGame, LoadLastGame , Reload Game options in File commands or use <<, <, >, >> buttons in toolbar\r\n"

"\t3.	Once a single game is loaded, use move navigation(single game view) to navigate through the moves\r\n"

"Automatic view (Replay):\r\n"

"\t1.	Open the game using File->Open or Copy and paste the game\r\n"

"\t2.	Use View ->Replay ->Start to start Replay the game. Manual editing should be disabled to replay the game\r\n"

"\t3.	Game interval is based on configuration parameter in Edit->Preferences\r\n"
 

"\r\nHow to use NetChess as PGN/FEN/EPD Converter\r\n"

"\t1.	Load the game using File->Load games\r\n"

"\t2.	Use File->Convert to convert between FEN, EPD and PGN formats to other formats\r\n"
"\ta.	PGN format can be converted to FEN or EPD positions\r\n"
"\tb.	FEN format can be converted to EPD or PGN format\r\n"
"\tc.	EPD format can be converted to FEN or PGN format\r\n"

"\t3.	Select the file, and click on convert. Each game will be converted and saved into <filename><sequence number>.<selected format>\r\n"

"\t4.	Note: As this is file operation, it will take several minutes to complete the task and completion time will be based on number of games loaded\r\n"

 

"\r\nHow to play with Chess engine as White pieces side player:\r\n"

"\t1.	Select White Engine -> White as Engine (Observe a check mark to the menu item). On selecting White as Engine menu item, Default, Load and Engine Console menu items will be enabled\r\n"

"\t2.	If default game is already selected in Edit->Preferences, and want to start the default engine, select White Engine -> Default menu item\r\n"

"\t3.	If you want to load a new engine, click White Engine -> Load and select the engine executable from File dialog. Once the engine is loaded,  Reload, Start and Engine console menu items will be enabled\r\n"

"\t4.	Once the game is loaded (After step 3), click Start to start the engine. Select the Engine protocol (WinBoard I, WinBoard II, UCI I, UCI II). Note the features/options supported by the engine. If required, send the options for UCI engines\r\n"

"\t5.	Click \"Move Now\" to start the engine to play the first move\r\n"

"\t6.	White Engine -> Engine console can be used to view engine interactions and to send additional commands to engine\r\n"

"\t7.	To close/quit the engine, click White Engine -> Close. This will quit the engine. To play again, Load the engine again\r\n"

"\t8.	Important Note: Before exiting NetChess, close chess engines. Else Chess engines will not be stopped and the process will be running in the background. This consumes most of CPU time. When this problem is encountered, use Task Manager to end chess engine process.\r\n"
 

"\r\nHow to play with Chess engine as Black pieces side player\r\n"

"\t1.	Select Black Engine -> Black as Engine (Observe a check to the menu item). On selecting Black as Engine menu item, Default, Load and Engine Console menu items will be enabled\r\n"

"\t2.	If default game is already selected in Edit->Preferences, and want to start the default engine, select Black Engine -> Default menu item\r\n"

"\t3.	If you want to load a new engine, click Black Engine -> Load and select the engine executable from File dialog. Once the engine is loaded,  Reload, Start and Engine console menu items will be enabled\r\n"

"\t4.	Once the game is loaded (After step 3), click Start to start the engine. Select the Engine protocol (WinBoard I, WinBoard II, UCI I, UCI II). Note the features/options supported by the engine. If required, send the options for UCI engines\r\n"

"\t5.	If you are playing with White piece side, then move now\r\n"

"\t6.	Black Engine -> Engine console can be used to view engine interactions and to send additional commands to engine\r\n"

"\t7.	To close/quit the engine, click Black Engine -> Close. This will quit the engine. To play again, Load the engine again\r\n"

"\t8.	Important Note: Before exiting NetChess, close chess engines. Else Chess engines will not be stopped, and the process will be running in the background. This consumes most of the CPU time. In this case, use Task Manager to end chess engine process.\r\n"
 

"\r\nHow to play White and Black with Check engines on the same board\r\n"

"\t1.	Follow the steps mentioned in How to play with Chess engine as White pieces side player till step 4\r\n"

"\t2.	Follow the steps mentioned in How to play with Chess engine as Black pieces side player till step 4\r\n"

"\t3.	Once two engines are loaded and started, Click White Engine -> Move Now\r\n"

"\t4.	Engine console can be used to view engine interactions and to send additional commands to engine\r\n"

"\t5.	To close/quit the engine, click Black/White Engine -> Close. This will quit the engine. To play again, Load the engine again\r\n"

"\t6.	Important Note: Before exiting NetChess, close chess engines. Else Chess engines will not be stopped, and the process will be running in the background. This consumes most of the CPU time. In this case, use Task Manager to end chess engine process.\r\n"

 

"\r\nHow to play with White side using chess engine on One board and Black side suing chess engine on other board in Network mode\r\n"

"\t1.	Establish a network connection as mentioned in How to establish a connection in a network\r\n"

"\t2.	Configure White Engine in first board as mentioned in How to play with Chess engine as White pieces side player\r\n"

"\t3.	Configure Black Engine in second board as mentioned in How to play with Chess engine as Black pieces side player\r\n"

"\t4.	Click White Engine-> Move now in the first board(White piece side board)\r\n"

"\t5.	NetChess can also be used to play chess with chess engine in one machine and without engine (as Human player) in other machine\r\n"
 

"\r\nHow To play chess via email:\r\n"

"\t1.	Start chess board and move now\r\n"

"\t2.	Click Edit->Copy to copy as PGN\r\n"

"\t3.	Send the PGN data as mail (Your friend receives the PGN file, follow step 4 to play)\r\n"

"\t4.	(Other player) Receive the PGN file as mail\r\n"

"\t5.	Copy and paste the PGN file in NetChess\r\n"

"\t6.	Move now\r\n"

"\t7.	Repeat step 1) to 6)\r\n"

 
"\r\nHow to configure chess engine\r\n"

"\t1.	Chess engine can be configured as either White side player or black side player\r\n"

"\t2.	Each chess engine will have a binary file available in the chess engine directory\r\n"

"\t3.	Enable the \"White as Engine\" for White side player and \"Black as Engine\" for Black side player\r\n"

"\t4.	You can set default chess by configuring the chess engine in Edit->Preferences\r\n"

"\t5.	Once the Chess engine menu is enabled and want to play with default chess engine Click \r\n"

"\t6.	White Engine -> Default(for white side) or Black Engine ->Default(for black side)\r\n"

"\t7.	For loading a chess engine without default chess engine, White/Black Engine->Load and select the Chess engine binary\r\n"

"\t8.	Select the Engine protocol  by clicking White/Black Engine -> Start\r\n"

"\t9.	To move click White Engine -> Move now\r\n"

"\t10.	Engine console can be used to view engine interactions and send additional commands\r\n"

"\t11.	Once the game is complete don't forget to close the engine(Engine->Close)\r\n"
 
"\tHow to save and restart the game over network or on the same board\r\n"

"\t1.	Save the game as PGN format(File->Save will save the game in PGN format)\r\n"

"\t2.	If you would like to play chess over network with the saved game, establish a network connection as mentioned in the section How to establish a connection in a network\r\n"

"\t3.	Once the connection is established, File->Open or Copy and Page the game. This can be done by any player\r\n"

"\t4.	If the game is on the same board continue from step 5\r\n"

"\t5.	Decide who has to continue the chess and Change the players turn using Edit->Manual Editing -> Player's Turn\r\n"

"\t6.	Start playing the chess\r\n"

"\t7.	Chess engines also configured accordingly\r\n"

 
"\r\nHow to use as a client for Internet Chess Servers\r\n"

"\t1.	Click on ICS->Configure menu item. Configure dialog box will be display. Enter Internet Chess Server name, port number, Username and password. If you do not have user name, enter \"guest\" and leave \"password\" blank.\r\n"

"\t2.	Click on connect to connect to the server. Once the connection is established, the status will be changes as \"Connected\"\r\n"

"\t3.	Close the Configure dialog box and click ICS-> ICS Console to view the commands and messages from ICS\r\n"

"\t4.	ICS Console dialog box contains commands area, short command button and message area.\r\n"
"\ta.	Click on Clear button to clear the message and command areas\r\n"
"\tb.	Click on View button to view the message and command in a separate window\r\n"
"\tc.	Click on Copy button to copy the message and command areas to clipboard\r\n"
"\td.	Enter the command and click on Go button to send the command to the ICS\r\n"
"\te.	Click on Style12 to send the style of the board to 12 type\r\n"
"\tf.	Click on Accept to send the accept command to ICS\r\n"
"\tg.	Seek data will be displayed on the one of the edit box. Click on play to send the play command\r\n"
"\th.	Click on Abort button to send the abort message to ICS\r\n"
"\ti.	Click on Draw, Resign, Accept etc.. buttons to send the respective message to the ICS\r\n"
"\tj.	Click on quit to close the ICS connection. Re-connect by ICS->Configure dialog box\r\n"

"\t5.	Load engine and enable \"Only analyze\" and \"analyze\", setboard commands to get the analysis information for the current playing game with ICS\r\n"

"\t6.	Click on ICS ->Seek List to display the latest seek list. Select the seek and click play to send play command to ICS\r\n\r\n"

		
		"Use Help->Help to for more information on usage of this software\r\n"
		
		"Please send your comments or suggestions/troubles to raoavm@yahoo.com\r\n"
		"Visit at http://www.geocities.com/raoavm/index.html for more freeware games\r\n\r\n"
		"Enjoy the freeware GUI for Chess!!!\r\n"; 

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
