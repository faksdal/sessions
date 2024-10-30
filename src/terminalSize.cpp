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
    columns	= ws.ws_col;
    rows	= ws.ws_row;

    /*
    if (1 || ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
    	//if (write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12)
    		//return;
    	//editorReadKey();
    	//return;
    }
    else{
    	columns = ws.ws_col;
    	rows = ws.ws_row;
    	//return;
    }
	*/
}
