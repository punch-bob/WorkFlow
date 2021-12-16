#pragma once
#include "IBlockMaker.h"
#include "BlockFactory.h"

template<typename T>
class BlockMaker : public IBlockMaker
{
public:
	Block* Create() const override
	{
		return new T();
	}

	BlockMaker(const std::string& block_name)
	{
		BlockFactory::getInstance().RegisterMaker(block_name, this);
	}
};