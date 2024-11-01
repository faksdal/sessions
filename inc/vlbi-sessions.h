/*
 * ivsSessions.h
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */
#pragma once

#include <vector>
#include <fstream>
#include <termios.h>



////////////// S E S S I O N L I S T  D E F I N I T I O N //////////////////////
//
// Sessionlist, to hold the data for each session. This is what makes up the
// data in the dynamic <vector>-list
//
class SessionList{
public:
	std::string		sessionType;
	std::string		date;
	std::string		sessionCode;
	std::string		doy;
	std::string		time;
	std::string		dur;
	std::string		stations;
	std::string		sked;
	std::string		corr;
	std::string		status;
	std::string		dbcCode;
	std::string		subm;
	std::string		del;
	bool			visible;
	bool			highlighted;
};
////////////// S E S S I O N L I S T  D E F I N I T I O N //////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
// Different states used by the parser.
// I'm using a state machine to parse the input file, and these enums reflects
// the different states it can have.
//
enum class State{	READY,
					NEW_LINE,
					FILE_FORMAT,
					HEADER,
					SESSION_TYPE,
					DATE,
					SESSION_CODE,
					DOY,
					TIME,
					DUR,
					STATIONS,
					SKED,
					CORR,
					STATUS,
					DBC_CODE,
					SUBM,
					DEL,
					HORIZONTAL_DIVIDER,
					FOOTER,
					CHECK_NEW_LINE,
					ADD_LIST_ITEM
};
////////////////////////////////////////////////////////////////////////////////



///////////////// C L A S S  D E F I N I T I O N ///////////////////////////////
///////////////////// i v s S e s s i o n s ////////////////////////////////////
//
// Class definition, ivsSessions
//
class ivsSessions{

////////////////////////// C O M M O N S ///////////////////////////////////////
	//
	// Common variables
	//
	// True if session is intensive, false otherwise. We need to know if the
	// session is intensive, because the file layout differs between the two.
	bool	intensiveFlag;

	// Intermediate working buffer
	std::string		buffer;
////////////////////////// C O M M O N S ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


///////////////////////S E S S I O N L I S T ///////////////////////////////////
//
// Private sessionlist variables
//
	// Working buffers, serves as intermediate placeholders for data, used to
	// add elements to the list. Represents corresponding data fields in the
	// list definition.
	std::string		_sessionType;
	std::string		_date;
	std::string		_sessionCode;
	std::string		_doy;
	std::string		_time;
	std::string		_dur;
	std::string		_stations;
	std::string		_sked;
	std::string		_corr;
	std::string		_status;
	std::string		_dbcCode;
	std::string		_subm;
	std::string		_del;
	bool			_visible;
	bool			_highlighted;

	// Dynamic list to hold all sessions
	std::vector<SessionList>	sessionList;


///////////////////////S E S S I O N L I S T ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



/////////////// F I L E  O P E R A T I O N S ///////////////////////////////////
//
// Private file operation variables and functions
//
	std::string		fo_inputFileName;
	std::string		fo_inputBuffer;
	std::string		fo_outputBuffer;
	std::ifstream	fo_inputFileStream;
	std::streampos	fo_inputFileSize;
	std::streampos	fo_inputFilePosition;

	void readfile(void);
/////////////// F I L E  O P E R A T I O N S ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



///////////////////////////P A R S E R /////////////////////////////////////////
//
// Private variables and functions related to input processing
//
	std::string		header1, header2;
	std::string		fileFormat;
	unsigned long	fo_inputBufferIndex;
	State		state;
	const char*	ptr;

	bool	setIntensiveFlag(void);
	void	clearAllBuffers(void);
	void	parser(void);
	void	addListItem(void);
///////////////////////////P A R S E R /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////




/////////////// K E Y B O A R D  I N P U T ///////////////////////////////////
//
// Private functions and variables related to keybard input
//
	short	activeRow;
	char	readKey(void);
	void	processKeypress(void);


/////////////// K E Y B O A R D  I N P U T ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



////////////// T E R M I N A L  O U T P U T ////////////////////////////////////
//
// Private variables and functions related to terminal output
//
	int	rows, columns;
	int	listStartRow, listEndRow;
	int	header1Row, header2Row;

	std::string	itemListColor;

	struct termios orig_termios;
	struct termios initialTerminalState;

	void	saveTerminalState(termios &_originalTermios);
	void	restoreTerminalState(const termios &_originalTermios);
	void	die(const char *s);
	void	disableRawMode(void);
	void	enableRawMode(void);
	void	print(int _x, int _y, std::string _text);
	void	setupDisplay(void);
	void	terminalSize(void);
	void	clearScreen(void);
	void	printHeaders(void);
	void	printSessionList(unsigned long _startItem);
////////////// T E R M I N A L  O U T P U T ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


public:
	////////////////////////////////////////////////////////////////////////////
	//
	// Public constructor and destructor
	//
	ivsSessions(std::string _inputFileName);
	virtual ~ivsSessions();
	////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////
	//
	// Public function to run the class object
	//
	void run(void);
	////////////////////////////////////////////////////////////////////////////
};
///////////////// C L A S S  D E F I N I T I O N ///////////////////////////////
///////////////////// i v s S e s s i o n s ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*

#define CTRL_KEY(k) ((k) & 0x1f)

struct SearchFields{
	bool	active;
	short	xLocation, yLocation, cursorLocation;

	std::string	textColor;
	std::string	searchText;
};
*/
