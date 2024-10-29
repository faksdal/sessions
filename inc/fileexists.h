/*
 * fileexists.h
 *
 *  Created on: May 21, 2024
 *      Author: leijon
 */

#ifndef INC_FILEEXISTS_H_
#define INC_FILEEXISTS_H_

#include <string>

#include <unistd.h>
#include <sys/stat.h>

bool fileexists(const std::string& name);

bool fileexists(const std::string& name)
{
	struct stat buffer;
	return(stat(name.c_str(), &buffer) == 0);
}


#endif /* INC_FILEEXISTS_H_ */
