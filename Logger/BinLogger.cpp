#include <iostream>
#include "BinLogger.h"

void BinLogger::log(std::string msg) {
	std::cout << "Writing " << msg << " to a Bin file\n";
}