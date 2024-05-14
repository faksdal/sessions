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
	string			inputString, s;
	unsigned long	filePosition	= 0L;		// This starts with a 0
	unsigned long	position		= 0L;
	unsigned long	stringPosition	= 0L;		// This starts with a 0


	// if inputfile is not open, we exit with an error
	if(!inputFile.is_open()){
		cout << "Error: inputfile not open, exiting with exit(-1)!" << endl;
		exit(-1);
	}



	// search to _startPosition from the beginning of the file
	inputFile.seekg(_startPosition, ios::beg);

	/*
	cout << "_startPosition: " << _startPosition << endl;
	string s;
	cin >> s;
	*/


	//	As long as we have input from the file, we keep reading line by line
	while(getline(inputFile, inputString)){

		filePosition = inputFile.tellg();
		position = filePosition - inputString.length() - 1;


		cout << "  filePosition: " << filePosition << endl;
		cout << " inputFileSize: " << inputFileSize << endl;
		cout << "Line from file: " << inputString << endl;
		cout << " _searchString: " << _searchString << endl;
		cin >> s;


		if((stringPosition = inputString.find(_searchString)) != string::npos){
			cout << "Something!" << endl;
		}


		updateFilepointerPositions();


		/*
		// Then we do a string comparison to see if we have a match.
		// find() returns the position of the first character of the first match.
		// If no matches were found, the function returns string::npos.
		if((stringPosition = inputString.find(_searchString)) != string::npos){
			//	If we have a match, calculate file position for the
			// start of the _searchString variable, and break out of the while-loop
			position = filePosition - inputString.length() - 1;
			break;
		} // if((stringPosition = inputString.find(_searchString)) != string::npos)
		*/



	} // while(getline(inputFile, inputString))



	//	Return current input file pointer position to the caller
	return(position);
}
