#pragma once
#include "Block.h"

class IBlockMaker
{
public:
	virtual Block* Create() const = 0;
	virtual ~IBlockMaker() = default;
};

