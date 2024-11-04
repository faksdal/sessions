/*
 * keyboard.cpp
 *
 *  Created on: 2 Nov 2024
 *      Author: jole
 */

// Resources:
//		- Step 8 - https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
//		- ASCII-table https://www.asciitable.com/
//		- https://www.man7.org/linux/man-pages/man2/read.2.html

#pragma GCC diagnostic ignored "-Wsign-compare" (i < sizeof(buf) - 1)

#include <iostream>

#include <unistd.h>
//#include <termios.h>

#include "keyboard.h"



keyboard::keyboard()
{
	enableRawMode();
}



keyboard::~keyboard()
{
	disableRawMode();
}



void keyboard::hideCursor(void)
{
	// ANSI escape code to hide the cursor
	std::cout << "\033[?25l" << std::flush;
}



void keyboard::showCursor(void)
{
	// ANSI escape code to show the cursor
	std::cout << "\033[?25h" << std::flush;
}



void keyboard::moveCursor(int _x, int _y)
{
	std::cout << "\033[" << _y << ";" << _x << "H" << std::flush;
}


void keyboard::updateCursorValues(void)
{

	// Send the ANSI escape sequence to request the cursor position
	std::cout << "\033[6n" << std::flush;

	// Capture the response
	char buf[32];
	int i = 0;

	while (i < sizeof(buf) - 1) {
		char c;

		if (read(STDIN_FILENO, &c, 1) != 1)
			break;
		if (c == 'R')
			break; // End of the response

		buf[i++] = c;
	}
	buf[i] = '\0';

	// Parse the response, which should be in the format `\033[row;colR`
	if (sscanf(buf, "\033[%d;%dR", &cursorRow, &cursorColumn) != 2) {
		cursorRow		= -1;
		cursorColumn	= -1; // Indicate an error
	}
}

/*

void getCursorPosition(int &row, int &col) {
    // Send the ANSI escape sequence to request the cursor position
    std::cout << "\033[6n" << std::flush;

    // Capture the response
    setRawMode(true); // Enable raw mode to read input directly
	char buf[32];
	int i = 0;
	while (i < sizeof(buf) - 1) {
		char c;
		if (read(STDIN_FILENO, &c, 1) != 1) break;
		if (c == 'R') break; // End of the response
		buf[i++] = c;
	}
	buf[i] = '\0';
	setRawMode(false); // Restore original terminal settings

	// Parse the response, which should be in the format `\033[row;colR`
	if (sscanf(buf, "\033[%d;%dR", &row, &col) != 2) {
		row = -1;
		col = -1; // Indicate an error
	}
}

*/
