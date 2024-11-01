/*
 * keyboardInput.cpp
 *
 *  Created on: 30 Oct 2024
 *      Author: jole
 */

#include <unistd.h>	// STDIN_FILENO

#include "vlbi-sessions.h"

enum KEY_ACTION{
        KEY_NULL = 0,       /* NULL */
        CTRL_C = 3,         /* Ctrl-c */
        CTRL_D = 4,         /* Ctrl-d */
        CTRL_F = 6,         /* Ctrl-f */
        CTRL_H = 8,         /* Ctrl-h */
        TAB = 9,            /* Tab */
        CTRL_L = 12,        /* Ctrl+l */
        ENTER = 13,         /* Enter */
        CTRL_Q = 17,        /* Ctrl-q */
        CTRL_S = 19,        /* Ctrl-s */
        CTRL_U = 21,        /* Ctrl-u */
        ESC = 27,           /* Escape */
        BACKSPACE =  127,   /* Backspace */
        /* The following are just soft codes, not really reported by the
         * terminal directly. */
        ARROW_LEFT = 1000,
        ARROW_RIGHT,
        ARROW_UP,
        ARROW_DOWN,
        DEL_KEY,
        HOME_KEY,
        END_KEY,
        PAGE_UP,
        PAGE_DOWN
};



/* Read a key from the terminal put in raw mode, trying to handle
 * escape sequences. */
/*
int editorReadKey(int fd) {
    int nread;
    char c, seq[3];
    while ((nread = read(fd,&c,1)) == 0);
    if (nread == -1) exit(1);

    while(1) {
        switch(c) {
        case ESC:   // escape sequence
            // If this is just an ESC, we'll timeout here.
            if (read(fd,seq,1) == 0) return ESC;
            if (read(fd,seq+1,1) == 0) return ESC;

            // ESC [ sequences.
            if (seq[0] == '[') {
                if (seq[1] >= '0' && seq[1] <= '9') {
                    // Extended escape, read additional byte.
                    if (read(fd,seq+2,1) == 0) return ESC;
                    if (seq[2] == '~') {
                        switch(seq[1]) {
                        case '3': return DEL_KEY;
                        case '5': return PAGE_UP;
                        case '6': return PAGE_DOWN;
                        }
                    }
                } else {
                    switch(seq[1]) {
                    case 'A': return ARROW_UP;
                    case 'B': return ARROW_DOWN;
                    case 'C': return ARROW_RIGHT;
                    case 'D': return ARROW_LEFT;
                    case 'H': return HOME_KEY;
                    case 'F': return END_KEY;
                    }
                }
            }

            // ESC O sequences.
            else if (seq[0] == 'O') {
                switch(seq[1]) {
                case 'H': return HOME_KEY;
                case 'F': return END_KEY;
                }
            }
            break;
        default:
            return c;
        }
    }
}
// Process events arriving from the standard input, which is, the user
// is typing stuff on the terminal.
#define KILO_QUIT_TIMES 3
void editorProcessKeypress(int fd) {
    // When the file is modified, requires Ctrl-q to be pressed N times
     // before actually quitting.
    static int quit_times = KILO_QUIT_TIMES;

    int c = editorReadKey(fd);

    switch(c) {
    case ENTER:         // Enter
        editorInsertNewline();
        break;
    case CTRL_C:        // Ctrl-c
        // We ignore ctrl-c, it can't be so simple to lose the changes
        // to the edited file.
        break;
    case CTRL_Q:        // Ctrl-q
        // Quit if the file was already saved.
        if (E.dirty && quit_times) {
            editorSetStatusMessage("WARNING!!! File has unsaved changes. "
                "Press Ctrl-Q %d more times to quit.", quit_times);
            quit_times--;
            return;
        }
        exit(0);
        break;
    case CTRL_S:        // Ctrl-s
        editorSave();
        break;
    case CTRL_F:
        editorFind(fd);
        break;
    case BACKSPACE:     // Backspace
    case CTRL_H:        // Ctrl-h
    case DEL_KEY:
        editorDelChar();
        break;
    case PAGE_UP:
    case PAGE_DOWN:
        if (c == PAGE_UP && E.cy != 0)
            E.cy = 0;
        else if (c == PAGE_DOWN && E.cy != E.screenrows-1)
            E.cy = E.screenrows-1;
        {
        int times = E.screenrows;
        while(times--)
            editorMoveCursor(c == PAGE_UP ? ARROW_UP:
                                            ARROW_DOWN);
        }
        break;

    case ARROW_UP:
    case ARROW_DOWN:
    case ARROW_LEFT:
    case ARROW_RIGHT:
        editorMoveCursor(c);
        break;
    case CTRL_L: // ctrl+l, clear screen
        // Just refresht the line as side effect
        break;
    case ESC:
        // Nothing to do for ESC in this mode.
        break;
    default:
        editorInsertChar(c);
        break;
    }

    quit_times = KILO_QUIT_TIMES; // Reset it to the original value.
}
*/






////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
char ivsSessions::readKey(int _fd)
{
	int		nread;
	char	ch;

	while((nread = read(_fd, &ch, 1)) != 1){
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
void ivsSessions::processKeypress(int _fd)
{
	char c = readKey(_fd);

	switch (c){
		case 'q':		disableRawMode();
						system("tput rmcup");
						exit(0);
						break;
		default:		break;
	}
}



