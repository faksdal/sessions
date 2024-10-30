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
	//bool	quit = false;

	// Save the current terminal screen, so we can restore upon exit
	system("tput smcup");

	////////////////////////////////////////////////////////////////////////////
	// Read from inputfile and parse the content.
	// The parser populates the sessionList, making it available
	// for us to use.
	readfile();
	parser();
	////////////////////////////////////////////////////////////////////////////
	setupDisplay();

	printHeaders();
	printSessionList(0);

	while(1){
		char c = '\0';
		if(read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
			die("read");

		if(iscntrl(c)) {
			std::cout << (int)c << "\r\n"; //std::endl;
			//printf("%d\r\n", c);
		}
		else{
			std::cout << (int)c << "('" << (char)c << "')\r\n";// << std::endl;
			//printf("%d ('%c')\r\n", c, c);
		}
		if(c == 'q')
			break;
	}

	//disableRawMode();

}
