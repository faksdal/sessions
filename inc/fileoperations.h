/*
 * FileOperations.h
 *
 *  Created on: May 7, 2024
 *      Author: leijon
 */

#ifndef INC_FILEOPERATIONS_H_
#define INC_FILEOPERATIONS_H_

#include <string>
#include <fstream>
#include <iostream>

#include <sys/stat.h>
#include <unistd.h>

using namespace std;



class fileoperations {

private:
	unsigned long	inputFileSize			= 0L;
	unsigned long	currentInputFilePos		= 0L;
	unsigned long	currentOutputFilePos	= 0L;

	string		inputFileName, outputFileName;

	ifstream	inputFile;
	ofstream	outputFile;


	string	readHmtlTag(string _tag);
	string	skipInitialWhitespace(string _stringToSkip);
	void	updateFilepointerPositions(void);

	inline bool exists(const std::string& name) {	struct stat buffer;
													return (stat (name.c_str(), &buffer) == 0);
												}

protected:

public:
	bool			eof;

	fileoperations(string _inputFileName, string _outputFileName);
	virtual ~fileoperations();

	inline unsigned long	getInputFileSize(void)			{ return inputFileSize;			}
	inline unsigned long	getCurrentInputFilePos(void)	{ return currentInputFilePos;	}
	inline unsigned long	getCurrentOutputFilePos(void)	{ return currentOutputFilePos;	}

	string getOutputFileName(bool _printToScreen);
	string getInputFileName(bool _printToScreen);

	void			readFile(void);
	unsigned long	find(unsigned long _startPosition, string _searchString);
	string			fread(unsigned long _startPosition, unsigned long _nbytes);

};



#endif /* INC_FILEOPERATIONS_H_ */
