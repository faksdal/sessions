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
	enableRawMode();
	clearScreen();


	header1Row		= 2;
	header2Row		= 3;
	listStartRow	= header2Row + 2;
	listEndRow		= rows - 3;
}
