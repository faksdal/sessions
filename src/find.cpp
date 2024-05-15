/*
 *	find.cpp
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 *
 */

//
// TODO - add functionality to sum up all occurences of a search term, with fp to where they are in the file
//

#include <string>
//include <sstream>

#include "../inc/fileoperations.h"



//	find() searches for _searchString, starting at _startPosition, returning
//	the position in the file where the string starts.
//	find() also updates the file pointer positions
unsigned long fileoperations::find(unsigned long _startPosition, string _searchString)
{
	string			inputString, searchString;

	unsigned long	filePosition	= 0L;		// This starts with a 0
	unsigned long	position		= 0L;
	unsigned long	stringPosition	= 0L;		// This starts with a 0



	// If inputfile is not open, we exit with an error
	if(!inputFile.is_open()){
		cout << "Error: inputfile not open, exiting with exit(-1)!" << endl;
		exit(-1);
	}



	// search to _startPosition from the beginning of the file
	inputFile.seekg(_startPosition, ios::beg);


	searchString = _searchString;


	// As long as we have input from the file, we keep reading line by line
	while(getline(inputFile, inputString)){

		filePosition = inputFile.tellg();
		position = filePosition - inputString.length() - 1;

		// Updates file pointer positions,and the eof flag,
		// the eof flag is used by the caller
		updateFilepointerPositions();


		// Compare searchString with what we've just read from file.
		// If there's a match, we break out of the while-loop,
		// and return to caller with the position in the file where the string starts.
		if((stringPosition = inputString.find(searchString)) != string::npos){
			cout << "find(): Search match found: " << searchString << ", at position: " << position << endl;
			break;
		}


	} // while(getline(inputFile, inputString))



	// Return current input file pointer position to the caller
	return(position);
}
