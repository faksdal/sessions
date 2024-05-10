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
fileoperations::fileoperations(string _inputFileName, string _outputFileName)
{

	// assign filenames to object variables
	inputFileName	= _inputFileName;
	outputFileName	= _outputFileName;

	// open input file, position the fp at the end
	inputFile.open(inputFileName, ios::ate);
	//	if file is not open, flag an error and exit
	if(!inputFile.is_open()){
		cout << "Error opening input file: " << inputFileName << ". Exiting..." << endl;
		exit(-1);
	}
	else{
		// get filesize and store it in object variable
		inputFileSize = inputFile.tellg();
		// After getting the filesize, set file pointer at beginning of file
		inputFile.seekg(0, ios::beg);
	}

	// if outputfile exists, present the user with a choice
	if(exists(outputFileName)){
		cout << outputFileName << " exists! Overwrite? y/n: ";
		char c;
		cin >> c;
		if(c == 'n')
			exit(-1);
	}

	// open the output file
	outputFile.open(outputFileName);
	//	if file is not open, flag an error and exit
	if(!outputFile.is_open()){
		cout << "Error opening output file: " << outputFileName << ". Exiting..." << endl;
		exit(-1);
	}

	//	update current file pointer positions
	updateFilepointerPositions();
}




//	The destructor is in charge of closing the files upon exit
fileoperations::~fileoperations()
{
	// Close files upon exiting
	inputFile.close();
	outputFile.close();

}
