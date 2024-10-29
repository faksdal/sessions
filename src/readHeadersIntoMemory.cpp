/*
 * readHeadersIntoMemory.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */
/*
// disable warning for unused value
#pragma GCC diagnostic ignored "-Wunused-value" *_ptr

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// Reads the headers from file, storing them in header1 and header2.
// Keeping track of how far we advance in the pointer, returning that value
//
////////////////////////////////////////////////////////////////////////////////
int ivsSessions::readHeadersIntoMemory(const char* _ptr)
{
	int	ptrAdvance = 0;
	////////////////////////////////////////////////////////////////////////////
	//
	// Copying the headers into memory
	//
	// Counter to keep track of which line we're at in the buffer (or input file
	// if you want)
	//
	// This is used when we copy the header text from the file into the variables
	// header1 and header2. They are later printed to the screen above the list
	int	lineCounter = 0;
	//
	// It seems lines seven and eight, are where the heading is printed.
	// I wanna copy those into header1 and header2, for later printing to
	// the screen.
	//
	// I'll advance the *ptr until I'm at the beginning of line seven
	while(lineCounter < 6){
		if(*_ptr == '\r')
			lineCounter++;
		*_ptr++;
		ptrAdvance++;
	}

	// Clear headers
	header1.clear();
	header2.clear();

	// Copy line seven into header1...
	while(*_ptr++ != '\r'){
		if(*_ptr == '\r'){
			header1.append(1, '\0');
			*_ptr++;
			*_ptr++;
			break;
		}
		header1.append(1, *_ptr);
		ptrAdvance++;
	}

	// ...and line eight into header2
	while(*_ptr++ != '\r'){
		if(*_ptr == '\r'){
			header1.append(1, '\0');
			*_ptr++;
			*_ptr++;
			break;
		}
		header2.append(1, *_ptr);
		ptrAdvance++;
	}

	return(ptrAdvance);
}
*/
