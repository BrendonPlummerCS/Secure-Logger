//***********************************************************
//
//  File:        main.cpp
//  Description: source code file 
//  Rev:         1
//  Created:     10 Nov 2020
//  Author:      Janusz Kulon, University of South Wales
//  email:       j.kulon@southwales.ac.uk 
//  web:         http://staff.southwales.ac.uk/users/1032-jkulon
//  Tel:         +44 (0) 1443 654136
//
//
//***********************************************************

#include "TxtFileLogger.h" 
#include "ConsoleLogger.h" 
#include "BinLogger.h"
#include "LoggerDecorator.h"

#include <memory>
#include <iostream>

enum LoggerType { L_TEXT_FILE = 1, L_BIN_FILE, L_CONSOLE };
enum FormatType { F_NONE = 1, F_HTML, F_ENCRYPTED };


using namespace std;

int main(void)
{
	uint16_t loggerType;       // variable to store the input
	uint16_t userExited = 0;   // user has not chosen to exit
	uint16_t formatType;

	// loop while user has not chosen option to exit system
   while ( !userExited )
   {     
	   //============================================================================================================
		std::cout << "\n SELECT LOGGER [1: TXT FILE, 2: CONSOLE, 3: BINARY] : " ;
		std::cin >> loggerType; 
		std::cout << "\n SELECT FORMAT [1: NONE, 2: HTML, 3: ENCRYPTED] : ";
		std::cin >> formatType;

		unique_ptr< Logger> logger;

		switch(loggerType) {
			case L_TEXT_FILE:
				logger = make_unique<TxtFileLogger>();
				break;

			case L_CONSOLE:
				logger = make_unique<ConsoleLogger>();
				break;

			case L_BIN_FILE:
				logger = make_unique<BinLogger>();
				break;

			default:
				std::cout << "NO LOGGER" <<endl; 
				break;
		} //switch
		//============================================================================================================

		switch (formatType)
		{
			case F_NONE:
				logger = make_unique<LoggerDecorator>(std::move(logger), formatType);
				break;

			case F_HTML:
				logger = make_unique<LoggerDecorator>(std::move(logger), formatType);
				break;

			case F_ENCRYPTED:
				logger = make_unique<LoggerDecorator>(std::move(logger), formatType);
				break;

			default:
				std::cout << "NO FORMAT" << std::endl;
				break;

		}
		//============================================================================================================

		std::cout << " Logging: ";
		logger->log("A message to log");   // virtual dispatch
		std:: cout << "\n EXIT Yes = 1 , No  = 0 : ";
		std::cin >> userExited; 

		//============================================================================================================

   }//while

   return 0;
}

