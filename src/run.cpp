/*
 * run.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include <iostream>
#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// The main part of the program, run() runs until the user exits the program.
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::run(void)
{
	readfile();
	parser();

	printHeaders();
	printSessionList(0);
}
