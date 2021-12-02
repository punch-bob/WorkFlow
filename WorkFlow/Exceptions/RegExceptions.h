#pragma once
#include "Exceptions.h"

class RegExceptions : public Exceptions
{
public:
	//ArgsExceptions() : Exceptions("Bad number of arguments, sh") {}

	RegExceptions(const std::string& error_message) : Exceptions(error_message) {}
};