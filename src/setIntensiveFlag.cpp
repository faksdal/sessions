/*
 * intensiveSession.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include <string>
#include <cstring>
#include <iostream>

#include "vlbi-sessions.h"


////////////////////////////////////////////////////////////////////////////////
//
// Process the input buffer, checking in the heading to see if the session is
// intensive, or regular. Setting the private variable <intensiveFlag> accordingly.
//
////////////////////////////////////////////////////////////////////////////////
bool ivsSessions::setIntensiveFlag(void)
{
	// Location we start look from
	int			inputBufferIndex	= 63;

	// Hold the text to find
	// Search for this text, it will be included in the intensive sessions file at the beginning.
	const char*	s = "MULTI-AGENCY INTENSIVES SCHEDULE\0";

	////////////////////////////////////////////////////////////////////////////////
	//
	// Documentation for string::find();
	//
	// https://cplusplus.com/reference/string/string/find/
	// size_t find (const char* s, size_t pos, size_t n) const;
	//
	// s; Pointer to an array of characters.
	// If argument n is specified (3), the sequence to match are the first n characters in the array.
	// Otherwise (2), a null-terminated sequence is expected: the length of the sequence to match is determined by the first occurrence of a null character.
	//
	// n; Length of sequence of characters to match.
	//
	////////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////////
	//
	// To find out if the session is INTENSIVE or not, we read the header of the
	// session file.
	//
	////////////////////////////////////////////////////////////////////////////////

	// Do the search, and set flag accordingly
	if((fo_inputBuffer.find(s, inputBufferIndex, strlen(s))) != std::string::npos)
		intensiveFlag = true;
	else
		intensiveFlag = false;

	// return true or false depending on whether it's a regular or intensive schedule file
	return intensiveFlag;
}
