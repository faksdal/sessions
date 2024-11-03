/*
 * processKeypress.cpp
 *
 *  Created on: 2 Nov 2024
 *      Author: jole
 */
#pragma GCC diagnostic ignored "-Wsign-compare" (db.terminal_current_highlighted_row >= db.terminal_list_start_row + sessionList.size() - 1)

#include <iostream>

#include "keyboard.h"
#include "vlbi-sessions.h"

#define LIST_OFFSET_UP		1
#define LIST_OFFSET_DOWN	-1


////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::processKeypress(int _key, bool& _quit)
{
	switch(_key){
		case TAB:			//std::cout << "TAB pressed\r\n" << std::flush;
							break;
		case UP_ARROW:		if(db.terminal_current_highlighted_row == db.terminal_list_start_row)
								break;
							db.terminal_current_highlighted_row--;
							db.terminal_current_highlighted_session--;
							redraw(LIST_OFFSET_UP);
							break;
		case DOWN_ARROW:	if(	db.terminal_current_highlighted_row == db.terminal_list_end_row ||
								db.terminal_current_highlighted_row >= db.terminal_list_start_row + sessionList.size() - 1)
								break;

							db.terminal_current_highlighted_row++;
							db.terminal_current_highlighted_session++;
							redraw(LIST_OFFSET_DOWN);
							break;
		case ESC:			// ESC quits the program
							_quit = true;
							break;
	}
}
