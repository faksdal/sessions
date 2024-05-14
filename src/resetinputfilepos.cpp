/*
 * resetinputfilepos.cpp
 *
 *  Created on: 14 May 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include "../inc/fileoperations.h"



unsigned long fileoperations::resetInputFilePos(void)
{
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	eof = false;
	return(inputFile.tellg());
}
