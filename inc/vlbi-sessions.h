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



////////////////////////////////////////////////////////////////////////////////
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


////////////////////////////////////////////////////////////////////////////////
//
// Class definition, ivsSessions
//
class ivsSessions{
	////////////////////////////////////////////////////////////////////////////
	//
	// Common variables
	//
	// True if session is intensive, false otherwise. We need to know if the
	// session is intensive, because the file layout differs between the two.
	bool	intensiveFlag;

	// Intermediate working buffer
	std::string		buffer;

	// Header text
	std::string		header1, header2;

	// Holds the string from the inputfile containing information
	// about the master file format version number
	std::string		fileFormat;

	// Keeps track of where we're at in the input buffer
	unsigned long	fo_inputBufferIndex;

	// Holds the current state of the parser
	State		state;

	// Pointer to the input buffer as read from file. The parser uses pointer
	// arithmetic to do its job
	const char*	ptr;
	////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////
	//
	// Sessionlist variables
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
	//
	// Dynamic list to hold all sessions
	std::vector<SessionList>	sessionList;
	////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////
	//
	// File operation variables
	//
	std::string		fo_inputFileName;
	std::string		fo_inputBuffer;
	std::string		fo_outputBuffer;
	std::ifstream	fo_inputFileStream;
	std::streampos	fo_inputFileSize;
	std::streampos	fo_inputFilePosition;
	//std::string		fo_outputBuffer;
	//std::string		fo_outputFileName;
	//std::ofstream	fo_outputFileStream;
	//std::streampos	fo_outputFilePosition;
	//
	//std::streamsize	MAXLINELENGTH = 256;
	//unsigned long	fo_inputBufferIndex;
	////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////
	//
	// Variables related to terminal output
	int	rows, columns;
	//
	////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////
	//
	// Private functions related to input processing
	//
	//
	bool	setIntensiveFlag(void);
	//
	void	clearAllBuffers(void);
	void	parser(void);
	void	addListItem(void);
	////////////////////////////////////////////////////////////////////////////



	////////////////////////////////////////////////////////////////////////////
	//
	// Private functions related to screen output
	//
	void	terminalSize(void);
	void	printHeaders(void);
	void	printSessionList(unsigned long _startItem);
	////////////////////////////////////////////////////////////////////////////


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


	////////////////////////////////////////////////////////////////////////////
	//
	// Public function related to file operations
	//
	void readfile(void);
	////////////////////////////////////////////////////////////////////////////
};
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
