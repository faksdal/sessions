/*
 * run.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include <cstdlib>  // For system()
#include <iostream>

#include <unistd.h>	// STDIN_FILENO

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// The main part of the program, run() runs until the user exits the program.
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::run(void)
{
	// Save the current terminal screen, so we can restore upon exit
	system("tput smcup");

	// Read from inputfile and parse the content.
	// The parser populates the sessionList, making it available
	// for us to use.
	readfile();
	parser();

	setupDisplay();

	printHeaders();
	printSessionList(0);

	while(1){
		processKeypress(STDIN_FILENO);
	}
}
