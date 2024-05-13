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
	string			inputString;
	unsigned long	filePosition	= 0L;		// This starts with a 0
	unsigned long	position		= 0L;
	unsigned long	stringPosition	= 0L;		// This starts with a 0


	if(!inputFile.is_open()){
		cout << "Error: inputfile not open, exiting with exit(-1)!" << endl;
		exit(-1);
	}

	// search to _startPosition from the beginning of the file
	inputFile.seekg(_startPosition, ios::beg);

	//	As long as we have input from the file, we keep reading line by line
	while(getline(inputFile, inputString)){
		// break out of the while-loop if eof
		if(inputFile.eof())
			break;

		// Reset file pointer and break out of while-loop if we've read past eof
		if((filePosition = inputFile.tellg()) >= inputFileSize){
			//	we've reached end-of-file and should act accordingly
			//eof = true;
			//	Update current file pointers
			updateFilepointerPositions();

			//	Reset file pointer to beginning of file
			inputFile.seekg(0, ios::beg);
			filePosition = inputFile.tellg();
			//updateFilepointerPositions();
			break;
		}

		//	Delete any initial whitespace in the string
		inputString = skipInitialWhitespace(inputString);


		//	If this is true, we've got a match between _searchString and a
		//	substring in the line stored in inputString, which we've just
		//	from file.
		//	Then break out of the while-loop
		if((stringPosition = inputString.find(_searchString)) != string::npos){
			//	Calculate file position for the start of the _searchString...
			position = filePosition - inputString.length() - 1;
			break;
		}
		//	Update current file pointers
		//updateFilepointerPositions();

	}
	//	Return current input file pointer position
	return(position);
}
