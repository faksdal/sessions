/*
 * getDisplaySize.cpp
 *
 *  Created on: Oct 30, 2024
 *      Author: leijon
 */

#include <iostream>

#include <unistd.h>		// STDOUT_FILENO, TIOCGWINSZ
#include <sys/ioctl.h>	// struct winsize

#include "vlbi-sessions.h"



void ivsSessions::terminalSize(void)
{
	struct	winsize	ws;

	// Use ioctl() to get the window size
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
		std::cerr << "Error: Unable to get terminal size" << std::endl;
		return;
	}
	// Assign terminal size to variables
    db.terminal_columns	= ws.ws_col;
    db.terminal_rows	= ws.ws_row;

}
