#pragma once
#include "Logger.h"

class BinLogger : public Logger
{
public:
	void log(std::string msg);
};