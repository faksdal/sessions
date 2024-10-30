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
// Parsing the input buffer with the help of a state machine.
// Learning and inspiration from:
//		https://www.youtube.com/watch?v=rauO5qespFc&t=1077s
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::parser(void)
{
	state	= State::READY;
	ptr		= fo_inputBuffer.c_str();

	clearAllBuffers();

	while(*ptr){
		switch(state){
		case State::READY:			switch(*ptr){
										case '#':	state = State::FILE_FORMAT;
													break;
										case '|':	state = State::SESSION_TYPE;
													_sessionType.append(1, *ptr);
													*ptr++;
													//fo_inputBufferIndex++;
													break;
										case '\r':	*ptr++;
													break;
										case '\n':	*ptr++;
													break;
										case ' ':	state = State::NEW_LINE;
													break;
										case '-':	*ptr++;
													//fo_inputBufferIndex++;
													//state = State::HORIZONTAL_DIVIDER;
													break;
										default:	break;
									}
									break;
		case State::NEW_LINE:		if(*ptr == '\r'){
										buffer.append(1, '\0');
										*ptr++;
										//fo_inputBufferIndex++;
										state = State::CHECK_NEW_LINE;
										break;
									}
									buffer.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
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
										//fo_inputBufferIndex++;
										break;
									}
									fileFormat.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::SESSION_TYPE:	if(*ptr == '|'){
										_sessionType.append(1, '\0');
										state = State::DATE;
										break;
									}
									_sessionType.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::DATE:			if(*ptr == '|'){
										if(_date.size() < 1){
											_date.append(1, *ptr);
											*ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										_date.append(1, '\0');
										state = State::SESSION_CODE;
										break;
									}
									_date.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::SESSION_CODE:	if(*ptr == '|'){
										if(_sessionCode.size() < 1){
											_sessionCode.append(1, *ptr);
											*ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										_sessionCode.append(1, '\0');
										state = State::DOY;
										break;
									}
									_sessionCode.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::DOY:			if(*ptr == '|'){
										if(_doy.size() < 1){
											_doy.append(1, *ptr);
											*ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										_doy.append(1, '\0');
										state = State::TIME;
										break;
									}
									_doy.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::TIME:			if(*ptr == '|'){
										if(_time.size() < 1){
											_time.append(1, *ptr);
											*ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										_time.append(1, '\0');
										state = State::DUR;
										break;
									}
									_time.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::DUR:			if(*ptr == '|'){
										if(_dur.size() < 1){
											_dur.append(1, *ptr);
											*ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										_dur.append(1, '\0');
										state = State::STATIONS;
										break;
									}
									_dur.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::STATIONS:		if(*ptr == '|'){
										if(_stations.size() < 1){
											_stations.append(1, *ptr);
											*ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										_stations.append(1, '\0');
										state = State::SKED;
										break;
									}
									_stations.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::SKED:			if(*ptr == '|'){
										if(_sked.size() < 1){
											_sked.append(1, *ptr);
											*ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										_sked.append(1, '\0');
										state = State::CORR;
										break;
									}
									_sked.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::CORR:			if(*ptr == '|'){
										if(_corr.size() < 1){
											_corr.append(1, *ptr);
											*ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										_corr.append(1, '\0');
										state = State::STATUS;
										break;
									}
									_corr.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::STATUS:			if(*ptr == '|'){
										if(_status.size() < 1){
											_status.append(1, *ptr);
											*ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										_status.append(1, '\0');
										state = State::DBC_CODE;
										break;
									}
									_status.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::DBC_CODE:		if(*ptr == '|'){
										if(_dbcCode.size() < 1){
											_dbcCode.append(1, *ptr);
											*ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										_dbcCode.append(1, '\0');
										state = State::SUBM;
										break;
									}
									_dbcCode.append(1, *ptr);
									*ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::SUBM:		if(*ptr == '|'){
									if(_subm.size() < 1){
										_subm.append(1, *ptr);
										*ptr++;
										//fo_inputBufferIndex++;
										break;
									}
									_subm.append(1, '\0');
									state = State::DEL;
									break;
								}
								_subm.append(1, *ptr);
								*ptr++;
								//fo_inputBufferIndex++;
								break;
		case State::DEL:		if(*ptr == '|'){
									if(_del.size() < 1){
										_del.append(1, *ptr);
										*ptr++;
										//fo_inputBufferIndex++;
										break;
									}
									_del.append(1, *ptr);
									_del.append(1, '\0');
									state = State::ADD_LIST_ITEM;
									*ptr++;
									//fo_inputBufferIndex++;
									break;
								}
								_del.append(1, *ptr);
								*ptr++;
								//fo_inputBufferIndex++;
								break;

		case State::ADD_LIST_ITEM:	addListItem();
									clearAllBuffers();
									state = State::READY;
									break;
			default:			break;
		}
	}

	//std::cout << std::endl;
}

