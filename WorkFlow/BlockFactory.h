#pragma once
#include "Block.h"
#include "IBlockMaker.h"
#include "Exceptions/RegExceptions.h"
#include <map>

class BlockFactory
{
public:
	void RegisterMaker(const std::string& block_name, IBlockMaker* maker)
	{
		if(makers.find(block_name) != makers.end()) {
			throw RegExceptions("The" + block_name + "has already been registred!");
		}
		makers[block_name] = maker;
	}

	static BlockFactory& getInstance()
	{
		static BlockFactory factory;
		return factory;
	}

	Block* getBlock(const std::string& block_name)
	{
		auto iter = makers.find(block_name);
		if (iter == makers.end()) {
			throw RegExceptions(block_name + " wasn't found!");
		}
		IBlockMaker* maker = iter->second;
		return maker->Create();
	}
private:
	BlockFactory() = default;

	BlockFactory(const BlockFactory&) = delete;

	std::map<std::string, IBlockMaker*> makers;
};