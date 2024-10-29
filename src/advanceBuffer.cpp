/*
 * advanceBuffer.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// Advances the inputBufferIndex and length-of-field to the next vertical divider, '|'
// Updates the length at the caller
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::advanceBuffer(unsigned long &_start, unsigned long &_len)
{
	_start += _len;
	_len = 1;
	while(fo_inputBuffer[_start + _len] != '|'){
		_len++;
	}
}
