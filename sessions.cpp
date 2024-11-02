/*******************************************************************************
 *
 * main.cpp; Created by Jon Leithe
 * Date: 21/8-2024
 *
 *
 *
*******************************************************************************/
//#pragma GCC diagnostic ignored "-Wunused-variable" ivs
//#pragma GCC diagnostic ignored "-Wunused-but-set-variable" inputFileNameSet


#include <string>
#include <iostream>

#include <getopt.h>

#include "fileexists.h"
#include "vlbi-sessions.h"



// main program
int main(int argc, char **argv)
{
	////////////////////////////////////////////////////////////////////////////
	//
	// getopt()-variables
	//
	int		c, optionIndex;

	char	*shortOptions = (char*)"i:h";
	struct option	longOptions[] = {
		{"input-file",	required_argument,	NULL,	'i'},
		{"help",		no_argument,		NULL,	'h'},
		{0, 0, 0, 0}
	}; //end of getopt()-variables
	////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////
	//
	// filename variables
	//
	std::string	inputFileName;
	bool		inputFileNameSet;
	////////////////////////////////////////////////////////////////////////////


	// getopt() switch statement
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 'i':	{
							// if file don't exists, give a message and exit
							if(!fileexists(optarg)){
								std::cerr << "[ERROR] main(): Input file " << optarg << " does not exist!" << std::endl;
								std::cerr << "[ERROR] main(): Exiting..." << std::endl;

								exit(1);
							}

							// otherwise, store filename for later use
							inputFileName		= optarg;
							inputFileNameSet	= true;
							break;
						}

			case 'h':	{
							std::cout << "main(): Provide something useful to the user!" << std::endl;
							exit(1);
						}
			default:	{
							std::cout << "main: Switch default\n" << std::endl;
							break;
						}
				} //end of getopt() switch statement
	} // end of while-loop


	if(inputFileNameSet){
		//ivsSessions *s = new ivsSessions(inputFileName);
		ivsSessions s(inputFileName);

		/*
		if(!s){
			std::cerr << "Memory allocation failed! " << std::endl;
			std::cerr << "[ERROR] main(): failed to create object: ivsSessions(), exiting..." << std::endl;
			exit(-1);
		}
		*/

		s.run();
		//delete s;

	}
	else{
		std::cout << "No input filename given, nothing to do..." << std::endl;
	}


	//*************************************************************************

    return(0);
}

