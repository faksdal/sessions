/*
 * run.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include <iostream>
#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// The main part of the program, run() runs until the user exits the program.
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::run(void)
{
	////////////////////////////////////////////////////////////////////////////
	// Read from inputfile and parse the content.
	// The parser populates the sessionList, making it available
	// for us to use.
	readfile();
	parser();
	////////////////////////////////////////////////////////////////////////////

	terminalSize();	// should be moved into a function responsible for setting up the display

	printHeaders();
	printSessionList(3);
}
