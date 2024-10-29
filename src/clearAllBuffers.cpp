/*
 * clearAllBuffers.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include "vlbi-sessions.h"


////////////////////////////////////////////////////////////////////////////////
//
// Clear all working buffer strings
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::clearAllBuffers(void)
{
	buffer.clear();
	_sessionType.clear();
	_date.clear();
	_sessionCode.clear();
	_doy.clear();
	_time.clear();
	_dur.clear();
	_stations.clear();
	//_includedStations.clear();
	//_excludedStations.clear();
	_sked.clear();
	_corr.clear();
	_status.clear();
	_dbcCode.clear();
	_subm.clear();
	_del.clear();
}
