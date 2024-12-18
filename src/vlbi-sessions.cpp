/*
 * ivsSessions.cpp
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */
//#pragma GCC diagnostic ignored "-Wunused-value" *_ptr

#include <cstdlib>  // For system()
//#include <vector>
//

//#include <ctype.h>
//#include <errno.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <sys/ioctl.h>

#include <string>
#include <iostream>

#include "vlbi-sessions.h"


////////////////////////////////////////////////////////////////////////////////
// The constructor - you know the drill...
////////////////////////////////////////////////////////////////////////////////
ivsSessions::ivsSessions(std::string _inputFileName)
{
	fo_inputFileName			= _inputFileName;
	intensiveFlag				= false;
	fo_inputBufferIndex			= 0;
	db.terminal_rows			= 0;
	db.terminal_columns			= 0;
	ptr							= 0;
	state						= State::READY;
	db.terminal_list_end_row	= 0;
	db.terminal_list_start_row	= 0;
	_highlighted				= 0;
	_visible					= 0;
	db.terminal_header_1_row	= 0;
	db.terminal_header_2_row	= 0;

	// Save the current terminal screen, so we can restore upon exit
	system("tput smcup");
}



////////////////////////////////////////////////////////////////////////////////
// The destructor
////////////////////////////////////////////////////////////////////////////////
ivsSessions::~ivsSessions()
{
	// OBSOLETE: this is handled by keyboard input class
	// Restore terminal to previous state
	//disableRawMode();

	// Restore display
	system("tput rmcup");

	// Print a nice thank-you-message to the user :-)
	std::cout << "\r\nThank you for using sessions!\r\n";
}



/*
void ivsSessions::moveCursor(int _x, int _y)
{
	std::cout << "\033[" << _y << ";" << _x << "H" << std::flush;
}
*/

/*

char ivsSessions::readKey(void)
{
	int nread;
	char ch;

	while ((nread = read(STDIN_FILENO, &ch, 1)) != 1) {
		if (nread == -1 && errno != EAGAIN)
			die("read");
	}
	return ch;
}



void ivsSessions::refreshScreen(void)
{
	  write(STDOUT_FILENO, "\x1b[2J", 4);
	  write(STDOUT_FILENO, "\x1b[H", 3);
}
*/
