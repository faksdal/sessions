/*
 * print.cpp
 *
 *  Created on: 30 Oct 2024
 *      Author: jole
 */

#include <iostream>

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::print(int _x, int _y, std::string _text)
{
	std::cout << "\033[" << _y << ";" << _x << "H" << _text << std::flush;
}
