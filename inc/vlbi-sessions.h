/*
 * ivsSessions.h
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */
#pragma once
//#ifndef INC_IVSSESSIONS_H_
//#define INC_IVSSESSIONS_H_


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
	//std::string		includedStations;
	//std::string		excludedStations;
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
	//
	// Intermediate working buffer
	std::string		buffer;
	//
	// Header text
	std::string		header1, header2, fileFormat;
	//
	// Keeps track of where we're at in the input buffer
	unsigned long	fo_inputBufferIndex;
	//
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
	//std::string		_includedStations;
	//std::string		_excludedStations;
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
	// Private functions related to input processing
	//
	//int		readHeadersIntoMemory(const char* _ptr);
	//
	//bool	processLine(unsigned long &_startX, unsigned long _length);
	bool	setIntensiveFlag(void);
	//
	void	clearAllBuffers(void);
	//void	advanceBuffer(unsigned long &_start, unsigned long &_len);
	void	parser(void);
	//void	processInput(void);
	void	addListItem(void);
	////////////////////////////////////////////////////////////////////////////



	////////////////////////////////////////////////////////////////////////////
	//
	// Private functions related to screen output
	//
	void	printHeaders(void);
	void	printSessionList(unsigned long _startItem);
	////////////////////////////////////////////////////////////////////////////


public:
	ivsSessions(std::string _inputFileName);
	virtual ~ivsSessions();

	void run(void);

	////////////////////////////////////////////////////////////////////////////
	//
	// fileoperations
	//
	void readfile(void);
	////////////////////////////////////////////////////////////////////////////
};
////////////////////////////////////////////////////////////////////////////////

/*
#define INTENSIVE_HEADING_1	"   SESSION      DATE     SESSION    DOY TIME   DUR       STATIONS                             SKED CORR  STATUS  DBC  SUBM DEL"
#define INTENSIVE_HEADING_2	"     TYPE     yyyymmdd     CODE     ddd hh:mm  h:mm                                                     yyyymmdd CODE      days"
#define NORMAL_HEADING_1	"   SESSION      DATE     SESSION    DOY TIME   DUR                         STATIONS                        SKED CORR  STATUS  DBC  SUBM DEL"
#define NORMAL_HEADING_2	"     TYPE     yyyymmdd     CODE     ddd hh:mm  h:mm                                                                  yyyymmdd CODE      days"

#define CTRL_KEY(k) ((k) & 0x1f)



struct SessionList{
	std::string		sessionType;
	std::string		date;
	std::string		sessionCode;
	std::string		doy;
	std::string		time;
	std::string		dur;
	std::string		includedStations;
	std::string		excludedStations;
	std::string		sked;
	std::string		corr;
	std::string		status;
	std::string		dbcCode;
	std::string		subm;
	std::string		del;
	bool			visible;
	bool			highlighted;
};



struct SearchFields{
	bool	active;
	short	xLocation, yLocation, cursorLocation;

	std::string	textColor;
	std::string	searchText;
};



class ivsSessions{

	std::string		_sessionType;
	std::string		_date;
	std::string		_sessionCode;
	std::string		_doy;
	std::string		_time;
	std::string		_dur;
	std::string		_includedStations;
	std::string		_excludedStations;
	std::string		_sked;
	std::string		_corr;
	std::string		_status;
	std::string		_dbcCode;
	std::string		_subm;
	std::string		_del;
	std::string		buffer, textColor;

	int				startIndex, endIndex;
	int				columns, rows;
	int				listStartRow, listEndRow;

	bool			_visible, intensives;

	std::vector<SessionList>	ivsListItems;
	std::vector<SearchFields>	searchFieldList;

	struct termios orig_termios;



	// inline private functions
	void	hideCursor(void)			{ std::cout << "\033[?25l"; }
	void	showCursor(void)			{ std::cout << "\033[?25h"; }
	// std::cout << "\033[10;20H";     // Move cursor to row 10, column 20


	void	print(int _x, int _y, std::string _text);
	void	print(int _x, int _y, int _number);
	void	clearScreen(void);
	void	moveCursor(int _x, int _y);
	void	terminalSize(void);
	void	enableRawMode(void);
	void	disableRawMode(void);
	void	die(const char *s);
	char	readKey(void);
	void	processKeypress(void);
	void	refreshScreen(void);

	void	clearAllBuffers(void);
	void	printHeaders(void);
	void	printItemList(int _startItem);
	void	setupSearchFields(void);
	void	printSearchFields(void);

public:
	ivsSessions(const char* _ptr, unsigned long _size, bool _intensives);
	virtual ~ivsSessions();

	void	run(void);
};
*/
//#endif /* INC_IVSSESSIONS_H_ */
