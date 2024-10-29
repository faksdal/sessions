/*
 * processInput.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

/*
// disable warning for unused value
#pragma GCC diagnostic ignored "-Wunused-value" *ptr

#include <iostream>

#include "vlbi-sessions.h"
*/


/*
////////////////////////////////////////////////////////////////////////////////
//
// Process the input buffer, making a dynamic <vector> list of all sessions
// The list is defined in vlbi_sessions.h; std::vector<SessionList>	sessionList
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::processInput(void)
{
	int		itemCounter = 0;
	bool	quit = false;

	// Keep track of what to copy from the input buffer
	unsigned long	startX, length;

	// Declare a pointer the the fo_inputBuffer, this makes it easier to search
	// the buffer. (I think - might be revised)
	const char*	ptr = fo_inputBuffer.c_str();

	clearAllBuffers();
	setIntensiveFlag();

	// Read the headers into memory, and advance *ptr accordingly
	// Update the value of fo_inputBufferIndex, to keep track of where we are
	// in the buffer
	fo_inputBufferIndex = readHeadersIntoMemory(ptr);
	for(int i = 0; i < fo_inputBufferIndex; i++)
		*ptr ++;

	// Advance the index and pointer to the next point of interest
	// in the buffer. This will be after the divider (-------), just
	// at the beginning of all the sessions
	// Scan forward to the first occurence of '|', to put us at the start of the actual sessions
	while(*ptr != '|'){
		*ptr++;
		fo_inputBufferIndex++;
	}


	// TODO: Print for debug purpose
	int i = 0;
	while(fo_inputBuffer[fo_inputBufferIndex + i] != '\r'){
		std::cout << fo_inputBuffer[fo_inputBufferIndex + i];
		i++;
	}
	std::cout << std::endl;

	//

	// Set startX to match first character after vertical divider '|'
	startX = fo_inputBufferIndex;


	while(!quit){
		////////////////////////////////////////////////////////////////////////////
		//
		// Now that we know where to start, we traverse the buffer until its end.
		// Adding to the sessionlist for every linefeed we encounter
		//
		// Set length equal to the number of characters until next vertical divider '|'
		length = 0;
		//processLine(startX, length);
		////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////
		//
		// Add the current line to the list
		//
		sessionList.push_back({	_sessionType,
								_date,
								_sessionCode,
								_doy,
								_time,
								_dur,
								_includedStations,
								_excludedStations,
								_sked,
								_corr,
								_status,
								_dbcCode,
								_subm,
								_del,
								true,
								false });
		itemCounter++;

		////////////////////////////////////////////////////////////////////////////

		// Coming here, the value of _startX should put us on the first character on the next line

		// Clear all working buffers, making them readyu to process an new line
		clearAllBuffers();

		if(fo_inputBuffer[startX] == '#')
			quit = true;

	} // while(!quit)

}
*/


