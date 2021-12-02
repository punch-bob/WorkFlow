#pragma once
#include "Exceptions.h"

class ParserExceptions : public Exceptions
{
public:
	ParserExceptions(const std::string& error_message) : Exceptions(error_message + " wasn't found") {}
};