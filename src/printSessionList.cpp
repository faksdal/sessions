/*
 * printSessionList.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include <iostream>

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// Prints the sessions to terminal once, as the program launches. Sub-sequent
// draws are done by redraw().
//
// TODO: Look into how I can make it all with njust the redraw()-function
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::printSessionList(void)
{
	int x, y;

	x	= 1;
	y	= db.terminal_list_start_row;



	for(unsigned long i = 0; i < sessionList.size(); i++){
		if(sessionList[i].visible){
			sessionList[i].highlighted	? itemListColor = "\033[30;102m"
										: itemListColor = "\033[40;00m";	// white text, default background

			print(x, y,		itemListColor
						+	sessionList[i].sessionType
						+	sessionList[i].date
						+	sessionList[i].sessionCode
						+	sessionList[i].doy
						+	sessionList[i].time
						+	sessionList[i].dur
						+	sessionList[i].stations
						+	sessionList[i].sked
						+	sessionList[i].corr
						+	sessionList[i].status
						+	sessionList[i].dbcCode
						+	sessionList[i].subm
						+	sessionList[i].del);
			y++;
			if(y >= db.terminal_list_end_row)
				break;
		}
	}
	db.terminal_current_topmost_session		= 0;
	db.terminal_current_highlighted_session	= 0;
	db.terminal_current_highlighted_row		= db.terminal_list_start_row;


}
