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

enum class State{	READY,
					NEW_LINE,
					FILE_FORMAT,
					HEADER,
					SESSION_TYPE,
					DATE,
					SESSION_CODE,
					DOY,
					TIME,
					DUR,
					STATIONS,
					SKED,
					CORR,
					STATUS,
					DBC_CODE,
					SUBM,
					DEL,
					HORIZONTAL_DIVIDER,
					FOOTER,
					CHECK_NEW_LINE
};


////////////////////////////////////////////////////////////////////////////////
//
// Parsing the input buffer
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::parser(void)
{
	State		state = State::READY;
	const char*	ptr		= fo_inputBuffer.c_str();

	fo_inputBufferIndex	= 0;

	clearAllBuffers();

	while(*ptr){
		switch(state){
		case State::READY:			switch(*ptr){
										case '#':	state = State::FILE_FORMAT;
													break;
										case '|':	state = State::SESSION_TYPE;
													_sessionType.append(1, *ptr);
													*ptr++;
													fo_inputBufferIndex++;
													break;
										case '\r':	*ptr++;
													break;
										case '\n':	*ptr++;
													break;
										case ' ':	state = State::NEW_LINE;
													break;
										case '-':	*ptr++;
													fo_inputBufferIndex++;
													//state = State::HORIZONTAL_DIVIDER;
													break;
										default:	break;
									}
									break;
		case State::NEW_LINE:		if(*ptr == '\r'){
										buffer.append(1, '\0');
										state = State::READY;
										*ptr++;
										fo_inputBufferIndex++;
										state = State::CHECK_NEW_LINE;
										break;
									}
									buffer.append(1, *ptr);
									*ptr++;
									fo_inputBufferIndex++;
									break;
		case State::CHECK_NEW_LINE: if(buffer.find("MULTI-AGENCY SCHEDULE") != std::string::npos){
										intensiveFlag = false;
									}
									else if(buffer.find("MULTI-AGENCY INTENSIVE SCHEDULE") != std::string::npos){
										intensiveFlag = true;
									}
									else if(buffer.find("SESSION") != std::string::npos){
										header1 = buffer;
									}
									else if(buffer.find("TYPE") != std::string::npos){
										header2 = buffer;
									}
									buffer.clear();
									state = State::READY;
									break;
		case State::FILE_FORMAT:	if(*ptr == '\r'){
										fileFormat.append(1, '\0');
										state = State::READY;
										*ptr++;
										fo_inputBufferIndex++;
										break;
									}
									fileFormat.append(1, *ptr);
									*ptr++;
									fo_inputBufferIndex++;
									break;
		case State::SESSION_TYPE:	if(*ptr == '|'){
										_sessionType.append(1, '\0');
										state = State::SESSION_CODE;
										*ptr++;
										fo_inputBufferIndex++;
										break;
									}
									_sessionType.append(1, *ptr);
									*ptr++;
									fo_inputBufferIndex++;
									break;
		case State::SESSION_CODE:
									break;
			default:				break;
		}
	}

	std::cout << std::endl;
}

