/*
 * setupDisplay.cpp
 *
 *  Created on: 30 Oct 2024
 *      Author: jole
 */

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::setupDisplay(void)
{
	terminalSize();	// loads terminal size into memory, rows and columns
	clearScreen();

	db.terminal_header_1_row	= 2;
	db.terminal_header_2_row	= 3;
	db.terminal_list_start_row	= db.terminal_header_2_row + 2;
	db.terminal_list_end_row	= db.terminal_rows - 3;

	print(1, 3, "Filter:");
}
