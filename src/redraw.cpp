/*
 * redraw.cpp
 *
 *  Created on: 3 Nov 2024
 *      Author: jole
 */

#include <iostream>

#include "vlbi-sessions.h"



void ivsSessions::printSession(short _row, unsigned long _sessionId, std::string _sessionColor)
{
	kb.hideCursor();
	print(1, _row,	_sessionColor
				+	sessionList[_sessionId].sessionType
				+	sessionList[_sessionId].date
				+	sessionList[_sessionId].sessionCode
				+	sessionList[_sessionId].doy
				+	sessionList[_sessionId].time
				+	sessionList[_sessionId].dur
				+	sessionList[_sessionId].stations
				+	sessionList[_sessionId].sked
				+	sessionList[_sessionId].corr
				+	sessionList[_sessionId].status
				+	sessionList[_sessionId].dbcCode
				+	sessionList[_sessionId].subm
				+	sessionList[_sessionId].del);
	kb.showCursor();
	kb.moveCursor(kb.cursorColumn, kb.cursorRow);
}



////////////////////////////////////////////////////////////////////////////////
//
// highlighted	itemListColor = "\033[30;102m"
// regular		itemListColor = "\033[40;00m";	// white text, default background
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::redraw(short _offset)
{
	std::string	regular, highlighted;

	//db.terminal_current_topmost_session
	//db.terminal_current_highlighted_row
	//db.terminal_current_highlighted_session

	sessionList[db.terminal_current_highlighted_session + _offset].highlighted = false;
	sessionList[db.terminal_current_highlighted_session].highlighted = true;

	highlighted	= "\033[30;102m";
	regular		= "\033[40;00m";	// white text, default background


	printSession(	(db.terminal_current_highlighted_row + _offset),
					(db.terminal_current_highlighted_session + _offset),
					regular);

	printSession(	db.terminal_current_highlighted_row,
					db.terminal_current_highlighted_session,
					highlighted);

}
