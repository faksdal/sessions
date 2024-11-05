/*
 * run.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include <cstdlib>  // For system()
#include <iostream>

#include <unistd.h>	// STDIN_FILENO

#include "keyboard.h"
#include "vlbi-sessions.h"

bool keypressed(void)
{
	struct timeval tv = {0, 0}; // No timeout
	fd_set readfds;

	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);

	return select(STDIN_FILENO + 1, &readfds, nullptr, nullptr, &tv) == 1;

}



////////////////////////////////////////////////////////////////////////////////
//
// The main part of the program, run() runs until the user exits the program.
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::run(void)
{

	//int				key = 0;
	//int				fd		= STDIN_FILENO;
	bool			quit	= false;
	//keyboard		kb;

	db.terminal_current_highlighted_row = 5;


	// Read from inputfile and parse the content.
	// The parser populates the sessionList, making it available
	// for us to use.
	readfile();
	parser();

	//kb.hideCursor();

	// Sets up the static parts of the display
	setupDisplay();

	// Set up the input filters
	setupFilters();
	printFilters();

	// Print descriptive list headers previously read from input file
	printHeaders();

	// Prints the initial list to terminal
	// Updates as the user moves around will be done by redraw().
	printSessionList();

	kb.cursorColumn = 53;
	kb.cursorRow = 4;
	kb.moveCursor(kb.cursorColumn, kb.cursorRow);

	kb.updateCursorValues();

	// Draws up the sessions in terminal.
	// redraw() updates db.terminal_current_highlighted_row
	// startSession is updated by run()
	//redraw(db.terminal_current_highlighted_row, startSession);

	while(!quit){
		processKeypress(quit);

		/*
		if((key = kb.readkey(fd)) != -1){
				processKeypress(key, quit);
		} // if((key = kb.readkey(fd)) != -1)
		*/


		// here, I can do other stuff

	} // while(!quit)

	//kb.showCursor();
}
