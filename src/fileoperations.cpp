/*
 * FileOperations.cpp
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 */
#include <string.h>
#include "../inc/fileoperations.h"



//	The constructor is in charge of opening both input- and output-files,
//	getting the filesize and position the file pointer at the beginning
//	of the input file.
//
//	It also gives an error if opening the files don't work out
fileoperations::fileoperations(string _inputFileName, string _outputFileName, string _searchTermsArray[MAXSEARCHTERMS])
{

	// assign filenames to object variables
	inputFileName	= _inputFileName;
	outputFileName	= _outputFileName;

	// open input file, position the fp at the end
	inputFile.open(inputFileName, ios::ate);
	//	if file is not open, flag an error and exit
	if(!inputFile.is_open()){
		cout << "fileoperations constructor: Error opening input file: " << inputFileName << ". Exiting..." << endl;
		exit(-1);
	}
	else{
		// get filesize and store it in object variable
		inputFileSize = inputFile.tellg();
		// After getting the filesize, set file pointer at beginning of file
		inputFile.seekg(0, ios::beg);
	}


	// open the output file
	outputFile.open(outputFileName);
	//	if file is not open, flag an error and exit
	if(!outputFile.is_open()){
		cout << "fileoperations(): Error opening output file: " << outputFileName << ". Exiting..." << endl;
		exit(-1);
	}

	//	update current file pointer positions
	updateFilepointerPositions();


	for(int i = 0; i < MAXSEARCHTERMS; i++){
		if(_searchTermsArray[i].length() > 0)
			cout << "fileoperations(): Search term " << i+1 << ": " << _searchTermsArray[i] << endl;
	}
}




//	The destructor is in charge of closing the files upon exit
fileoperations::~fileoperations()
{
	// Close files upon exiting
	inputFile.close();
	outputFile.close();

}
