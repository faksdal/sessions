/*
 * keyboardInput.cpp
 *
 *  Created on: 30 Oct 2024
 *      Author: jole
 */

#include <unistd.h>	// STDIN_FILENO

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
char ivsSessions::readKey(void)
{
	int		nread;
	char	ch;

	while((nread = read(STDIN_FILENO, &ch, 1)) != 1){
		if (nread == -1 && errno != EAGAIN)
			die("read");
	}
	return ch;
}



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::processKeypress(void)
{
	char c = readKey();

	switch (c){
		case 'q':		disableRawMode();
						system("tput rmcup");
						exit(0);
						break;
		default:		break;
	}
}



