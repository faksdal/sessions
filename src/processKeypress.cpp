/*
 * processKeypress.cpp
 *
 *  Created on: 2 Nov 2024
 *      Author: jole
 */

#include <iostream>

#include "keyboard.h"
#include "vlbi-sessions.h"



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
		case UP_ARROW:		break;
		case DOWN_ARROW:	break;

		case ESC:			//std::cout << "ESC pressed\r\n" << std::flush;
							_quit = true;
							break;
	}
}
