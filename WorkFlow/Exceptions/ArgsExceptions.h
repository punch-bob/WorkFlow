#pragma once
#include "Exceptions.h"

class ArgsExceptions : public Exceptions
{
public:
	ArgsExceptions(const std::string& error_message) : Exceptions("Bad number of arguments in the" + error_message) {}
};