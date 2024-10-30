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
// What do I want form this function?
//		- I want it to print the session list to the visible screen, starting
// 			from _startItem.
//		- I only want printed those items that are set to .visible.
//		- I want the top-most item displayed to be highlighted, initially. Later
//			I want to be able to use the keyboard to select other items in the
//			list to be highlighted.
//
// What do I need to make this happen?
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::printSessionList(unsigned long _startItem)
{
	int x, y;

	x	= 1;
	y	= listStartRow;

	for(unsigned long i = _startItem; i < sessionList.size(); i++){
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
			if(y >= listEndRow)
				break;
		}
	}
}
