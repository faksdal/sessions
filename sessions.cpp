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
							searchStringSet = true;
							searchStringArray[searchArrayIndex] = optarg;
							cout << "...search string added: " << searchStringArray[searchArrayIndex++] << endl;
							//searchArrayIndex++;
							break;
						}
			case 'i':	{
							if(!exists(optarg)){
								cout << "Input file " << optarg << " does not exist!" << endl;
								cout << "Exiting..." << endl;
								break;
							}
							inputFilename = optarg;
							inputFilenameSet = true;
							cout << "Input file name set to " << inputFilename << endl;

							break;
						}
			case 'o':	{
							if(exists(optarg)){
								cout << optarg << " exists! Overwrite? y/n: ";
								char c;
								cin >> c;
								if(c == 'n')
									exit(-1);
							}
							outputFilename = optarg;
							outputFilenameSet = true;
							cout << "Output file name set to " << outputFilename << endl;
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





	//	create an object of type fileoperations, calling the constructor
	//	of the class
	if(inputFilenameSet && outputFilenameSet && searchStringSet){
		cout << "Creating class object..." << endl;
		//fileoperations fo(inputFilename.c_str(), outputFilename.c_str());
	}

	else{
		cout << "Missing parameters..." << endl;
	}



    return(0);
}

