//***********************************************************
//
//  File:        TxtFileLogger.cpp
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


#include <iostream>
#include "TxtFileLogger.h" 


void TxtFileLogger::log(std::string msg) {
	std::cout << " Writing " << msg << " to a text file\n";
};
