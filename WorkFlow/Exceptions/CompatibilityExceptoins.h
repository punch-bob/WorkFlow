#pragma once
#include "Exceptions.h"

class CompatibilityExceptions : public Exceptions
{
public:
	CompatibilityExceptions(const std::string& error_message) : Exceptions(error_message) {}
};