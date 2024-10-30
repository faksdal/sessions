/*
 * addListItem.cpp
 *
 *  Created on: 29 Oct 2024
 *      Author: jole
 */

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::addListItem(void)
{
	////////////////////////////////////////////////////////////////////////////
	//
	// Add the current line to the list
	//
	sessionList.push_back({	_sessionType, // @suppress("Invalid arguments")
							_date,
							_sessionCode,
							_doy,
							_time,
							_dur,
							_stations,
							_sked,
							_corr,
							_status,
							_dbcCode,
							_subm,
							_del,
							true,
							false });
}
