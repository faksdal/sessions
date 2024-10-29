/*
 * processLine.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */
/*
#include <iostream>


#include "vlbi-sessions.h"


////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
bool ivsSessions::processLine(unsigned long &_startX, unsigned long _length)
{
	/

	advanceBuffer(_startX, _length);
	_sessionType.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_date.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_sessionCode.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_doy.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_time.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_dur.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_stations.append(fo_inputBuffer, _startX, _length);

	//advanceBuffer(_startX, _length);
	//_includedStations.append(fo_inputBuffer, _startX, _length);

	//advanceBuffer(_startX, _length);
	//_excludedStations.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_sked.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_corr.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_status.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_dbcCode.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_subm.append(fo_inputBuffer, _startX, _length);

	advanceBuffer(_startX, _length);
	_del.append(fo_inputBuffer, _startX, _length+1);

	while((int)fo_inputBuffer[_startX] != 10)
		_startX++;

	return(true);
}
*/
