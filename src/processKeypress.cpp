/*
 * processKeypress.cpp
 *
 *  Created on: 2 Nov 2024
 *      Author: jole
 */
#pragma GCC diagnostic ignored "-Wsign-compare" (db.terminal_current_highlighted_row >= db.terminal_list_start_row + sessionList.size() - 1)

#include <iostream>

#include <unistd.h>

#include "keyboard.h"
#include "vlbi-sessions.h"

#define LIST_OFFSET_UP_ARROW	1
#define LIST_OFFSET_DOWN_ARROW	-1


////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::processKeypress(bool& _quit)
{
	int key = kb.readkey(STDIN_FILENO);
	/*
	switch(c){
		case UP_ARROW:		std::cout << "UP_ARROW\r\n" << std::flush;
							break;
		case DOWN_ARROW:	std::cout << "DOWN_ARROW\r\n" << std::flush;
							break;
		case LEFT_ARROW:	break;
		case RIGHT_ARROW:	//editorMoveCursor(c);
							break;
		case ESC:			_quit = true;
							break;
		default:			//editorInsertChar(c);
							break;
	} // switch(c)
	*/



	switch(key){
		case TAB:			nextFilter();
							break;
		case UP_ARROW:		if(db.terminal_current_highlighted_row == db.terminal_list_start_row)
								break;
							db.terminal_current_highlighted_row--;
							db.terminal_current_highlighted_session--;
							redraw(LIST_OFFSET_UP_ARROW);
							break;
		case DOWN_ARROW:	if(	db.terminal_current_highlighted_row == db.terminal_list_end_row ||
								db.terminal_current_highlighted_row >= db.terminal_list_start_row + sessionList.size() - 1)	// See #pragma... at top
								break;

							db.terminal_current_highlighted_row++;
							db.terminal_current_highlighted_session++;
							redraw(LIST_OFFSET_DOWN_ARROW);
							break;
		case ESC:			// ESC quits the program
							kb.disableRawMode();
							_quit = true;
							break;
		default:			kb.cursorColumn++;
							itemListColor = "\033[40;00m";	// regular
							std::cout << itemListColor << (char)key << std::flush;
							addFilter(key);
							break;
	}
}
