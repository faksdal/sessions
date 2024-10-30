/*
 * printHeaders.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include <iostream>

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// Printing the headers to screen
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::printHeaders(void)
{
	print(1, 1, header1);
	print(1, 2, header2);
}
