/*
 *	readfile.cpp
 *
 *	Created on: 27 Oct 2024
 *	Author: jole
 *
 *
 *
 */

#include <iostream>

#include "vlbi-sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// readfile() reads the entire content of inputfile into memory.
// It is stored in fo_inputBuffer for later processing
//
// readfile() closes the filestream upon completion
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::readfile(void)
{
	char	c;

	// open input file, position the fp at the end
	fo_inputFileStream.open(fo_inputFileName, std::ios::ate);
	//	if file is not open, flag an error and exit
	if(!fo_inputFileStream.is_open()){
		std::cout << "fileoperations(): Error opening input file: " << fo_inputFileName << ". Exiting..." << std::endl;
		exit(-1);
	}
	else{
		// get filesize and store it in object variable
		//std::cout << "fileoperations(): inputFile.tellg(): " << fo_inputFileStream.tellg() << std::endl;
		fo_inputFileSize = fo_inputFileStream.tellg();
		// After getting the filesize, set file pointer at beginning of file
		fo_inputFileStream.seekg(0, std::ios::beg);
	}

	// seek to start of input file
	fo_inputFileStream.seekg(0, std::ios::beg);
	if(fo_inputFileStream.tellg() != 0){
		std::cerr << "[ERROR] fileoperations::readfile(): Search to start of file failed!" << std::endl;
		exit(-1);
	}

	// read the whole file to memory
	while(fo_inputFileStream.get(c).good()){
		fo_inputBuffer.append(1, c);
	}

	// TODO: Not really necessary, as we are closing the file in the next statement!
	// reset file pointer to beginning of file after read operation
	// and clear any failbit
	fo_inputFileStream.clear();
	fo_inputFileStream.seekg(0, std::ios::beg);
	if(fo_inputFileStream.tellg() != 0){
		std::cerr << "[ERROR] fileoperations::fo_readFromInputFile(): Search to start of file failed!" << std::endl;
		exit(-1);
	}

	// close the file stream as we are done reading!
	if(fo_inputFileStream.is_open())
		fo_inputFileStream.close();

	return;
}
