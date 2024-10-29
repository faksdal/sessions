/*
 * parser.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */


// disable warning for unused value
#pragma GCC diagnostic ignored "-Wunused-value" *ptr

#include <iostream>

#include "vlbi-sessions.h"




////////////////////////////////////////////////////////////////////////////////
//
// Process the input buffer, making a dynamic <vector> list of all sessions
// The list is defined in vlbi_sessions.h; std::vector<SessionList>	sessionList
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::parser(void)
{
	std::cout << "Parser\r\n";
	std::cout << fo_outputBuffer;
}


