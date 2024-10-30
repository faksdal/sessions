/*
 * saveTerminalState.cpp
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
void ivsSessions::saveTerminalState(termios &_originalTermios)
{
	// Save the current terminal settings
	if (tcgetattr(STDIN_FILENO, &_originalTermios) == -1){
		perror("Failed to get terminal attributes");
		exit(EXIT_FAILURE);
	}
}



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::restoreTerminalState(const termios &_originalTermios)
{
	// Restore the saved terminal settings
	if (tcsetattr(STDIN_FILENO, TCSANOW, &_originalTermios) == -1){
		perror("Failed to restore terminal attributes");
		exit(EXIT_FAILURE);
	}
}



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::enableRawMode(void)
{
	//tcgetattr(STDIN_FILENO, &orig_termios);
	if(tcgetattr(STDIN_FILENO, &orig_termios) == -1)
		die("tcgetattr");

	// diable rawmode upon exit, as a courtesy to the user
	//atexit(disableRawMode);

	struct termios raw = orig_termios;

	raw.c_iflag		&= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag		&= ~(OPOST);
	raw.c_cflag		|= (CS8);
	raw.c_lflag		&= ~(ECHO | ICANON | IEXTEN | ISIG);
	//raw.c_cc[VMIN]	= 0;
	//raw.c_cc[VTIME]	= 1;

	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		die("tcsetattr");
}



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::disableRawMode(void)
{
	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
		die("tcsetattr");
}



