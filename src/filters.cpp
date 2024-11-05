/*
 * filters.cpp
 *
 *  Created on: Nov 4, 2024
 *      Author: leijon
 */
#include <iostream>

#include "vlbi-sessions.h"

	/*class Filter{
	public:
		int			filterColumn, filterRow;
		bool		active;
		std::string	filterName, filterText, filterColor;
	};*/



void ivsSessions::addFilter(int _key)
{
	unsigned long i = 0;

	while(!filter[i++].active);
	i--;

	print(1, 33, "         ");
	print(1, 33, i);

	filter[i].filterText.append(1, _key);

	print(1, 34, "         ");
	print(1, 34, filter[i].filterName);
	print(1, 35, "         ");
	print(1, 35, filter[i].filterText);

	kb.moveCursor(kb.cursorColumn, kb.cursorRow);
}



void ivsSessions::nextFilter(void)
{
	unsigned long i;

	for(i = 0; i < filter.size(); i++){
		if(filter[i].active){
			filter[i].active = false;
			if(i+1 == filter.size()){
				i = 0;
				filter[i].active = true;
				break;
			}
			else{
				i++;
				filter[i].active = true;
				break;
			}
		}
	}

	kb.cursorColumn	=  filter[i].filterColumn;
	kb.cursorRow	=  filter[i].filterRow;
	kb.moveCursor(kb.cursorColumn, kb.cursorRow);
}



void ivsSessions::printFilters(void)
{
	for(unsigned long i = 0; i < filter.size(); i++){
		print(filter[i].filterColumn, filter[i].filterRow, filter[i].filterColor + filter[i].filterText);
	}

}



void ivsSessions::setupFilters(void)
{
	int			_filterColumn, _filterRow;
	bool		_active;
	std::string	_filterName, _filterText, _filterColor;

	//highlighted	= "\033[30;102m";
	//regular		= "\033[40;00m";	// white text, default background

	_filterColumn	= 2;
	_filterRow		= 4;
	_active			= false;
	_filterName		= "SESSION_TYPE";
	_filterText		= "";
	_filterColor	= "\033[40;00m";

	filter.push_back({	_filterColumn,
						_filterRow,
						_active,
						_filterName,
						_filterText,
						_filterColor });

	_filterColumn += sessionList[0].sessionType.length() - 1;
	_filterRow		= 4;
	_active			= false;
	_filterName		= "DATE";
	_filterText		= "";
	_filterColor	= "\033[40;00m";
	filter.push_back({	_filterColumn,
						_filterRow,
						_active,
						_filterName,
						_filterText,
						_filterColor });

	_filterColumn += sessionList[0].date.length() - 1;
	_filterColumn += sessionList[0].sessionCode.length() - 1;
	_filterColumn += sessionList[0].doy.length() - 1;
	_filterColumn += sessionList[0].time.length() - 1;
	_filterColumn += sessionList[0].dur.length() - 1;
	_filterRow		= 4;
	_active			= true;
	_filterName		= "STATIONS";
	_filterText		= "";
	_filterColor	= "\033[40;00m";
	filter.push_back({	_filterColumn,
						_filterRow,
						_active,
						_filterName,
						_filterText,
						_filterColor });
}
