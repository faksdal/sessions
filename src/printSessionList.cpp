/*
 * printSessionList.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include <iostream>

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::printSessionList(unsigned long _startItem)
{
	for(unsigned long i = _startItem; i < sessionList.size(); i++){
		std::cout	<< sessionList[i].sessionType
					<< sessionList[i].date
					<< sessionList[i].sessionCode
					<< sessionList[i].doy
					<< sessionList[i].time
					<< sessionList[i].dur
					<< sessionList[i].includedStations
					/*<< sessionList[i].excludedStations*/
					<< sessionList[i].sked
					<< sessionList[i].corr
					<< sessionList[i].status
					<< sessionList[i].dbcCode
					<< sessionList[i].subm
					<< sessionList[i].del << std::endl;
	}
}
