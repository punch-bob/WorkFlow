#pragma once
#include "Exceptions.h"

class RegExceptions : public Exceptions
{
public:
	RegExceptions(const std::string& error_message) : Exceptions(error_message) {}
};