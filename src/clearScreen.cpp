/*
 * clearScreen.cpp
 *
 *  Created on: 30 Oct 2024
 *      Author: jole
 */

#include <unistd.h>		// STDOUT_FILENO, TIOCGWINSZ

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::clearScreen(void)
{
	// Clear the terminal
	//std::cout << "\033[2J\033[1;1H" << std::flush;
	write(STDOUT_FILENO, "\x1b[2J", 4);
}
