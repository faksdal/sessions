/******************************************************************************
 *
 * vlbi-automation.cpp; Created by Jon Leithe based on https://www.geeksforgeeks.org/html-parser-in-c-cpp/
 * Date: 3/5-2024
 *
 * 
******************************************************************************/
  

#include <getopt.h>
#include <iostream>

//#include <stdio.h> 
//#include <string.h>
//#include <stdbool.h>


#include "inc/fileoperations.h"

using namespace std;



// Driver code
int main(int argc, char **argv)
{
	//string			searchString;
	//unsigned long	filePointer = 0L;
	string	inputFilename, outputFilename, searchStringArray[8];
	bool	inputFilenameSet, outputFilenameSet, searchStringSet;


	inputFilenameSet =  outputFilenameSet = searchStringSet = false;



	//	getopt variables
	int		c, optionIndex, searchArrayIndex;

	char	*shortOptions = (char*)"I:i:o:h";
	struct option	longOptions[] = {
		{"include",		required_argument,	NULL,	'I'},
		{"input-file",	required_argument,	NULL,	'i'},
		{"output-file",	required_argument,	NULL,	'o'},
		/*{"lat",		required_argument,	NULL,	4},
		{"lon",		required_argument,	NULL,	5},
		{"dst",		required_argument,	NULL,	6},
		{"verbose",	no_argument,		NULL,	'v'},*/
		{"help",	no_argument,		NULL,	'h'},
		{0, 0, 0, 0}
	};	//End of getopt()-variables

	searchArrayIndex = 0;

	//	getopt() switch statement
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 'I':	{
							//cout << "Include " << optarg << endl;
							searchStringSet = true;
							searchStringArray[searchArrayIndex] = optarg;
							cout << "Search string added: " << searchStringArray[searchArrayIndex++] << endl;
							//searchArrayIndex++;
							break;
						}
			case 'i':	{
							//cout << "Inputfile " << optarg << endl;
							inputFilename = optarg;
							inputFilenameSet = true;
							break;
						}
			case 'o':	{
							//cout << "Outputfile " << optarg << endl;
							outputFilename = optarg;
							outputFilenameSet = true;
							break;
						}
			case 'h':	{
							cout << "Provide some useful help to the user!" << endl;
							exit(1);
						}
			default:	{
							cout << "Switch default\n" << endl;
							break;
						}
		}	//end of getopt() switch statement
	}	// end of while-loop

	if(inputFilenameSet)
		cout << "Input file name set to: " << inputFilename << endl;
	if(outputFilenameSet)
			cout << "Output file name set to: " << outputFilename << endl;


	/*
	//	create an object of type fileoperations, calling the constructor
	//	of the class
	if(inputFilenameSet && outputFilenameSet){
		cout << "Creating class object..." << endl;
		fileoperations fo(inputFilename.c_str(), outputFilename.c_str());
	}

	else{
		cout << "Missing parameters..." << endl;
	}
	*/

	//	if we make it here, we know the user has provided us with
	//	good info to proceed
	if(inputFilenameSet && outputFilenameSet && searchStringSet){
		cout << "Number of included search terms: " << searchArrayIndex << endl;
		cout << "Creating class object..." << endl;
		fileoperations fo(inputFilename.c_str(), outputFilename.c_str());

		//cout << "Input file, output file and search strings are set!" << endl;
		//cout << "We are good to proceed." << endl;

		unsigned long	searchPoint = 0L;

		for(short i = 0; i < searchArrayIndex; i++){
			while(!fo.eof){
				cout << "searchPoint: " << searchPoint << endl;
				cout	<< "Search term " << searchStringArray[i] << " is found at position "
						<< (searchPoint = fo.find(searchPoint, searchStringArray[i])) << " in " << fo.getInputFileName(false) << endl;
				cout << "searchPoint: " << searchPoint << endl;
				searchPoint += searchStringArray[i].length();
				cout << "searchPoint: " << searchPoint << endl;
			}
		}
	}
	else{
		cout << "Missing parameters..." << endl;
	}

    return(0);
}

