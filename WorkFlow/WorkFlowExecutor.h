#pragma once
#include <istream>
#include <iostream>
#include "WorkFlowParser.h"
#include "Block.h"
#include "BlockFactory.h"
#include "Exceptions/CompatibilityExceptoins.h"

class WorkFlowExecutor
{
	std::vector<std::string> str_type{ "IN", "INOUT", "OUT", "FIRST" };
public:
	bool CheckCompatibility(BlockType prev, BlockType now)
	{
		if (prev == FIRST)
		{
			return now == IN;
		}
		if (prev == OUT)
		{
			return now == IN;
		}
		if (prev == IN)
		{
			return now == INOUT || now == OUT;
		}
		return true;
	}

	void execute(std::string file_name)
	{
		Text text;
		BlockType prev_block = FIRST;
		WorkFlowParser parser;
		auto blocks = parser.getBlocks(file_name);
		for (auto block : blocks)
		{
			Block* block_object = BlockFactory::getInstance().getBlock(block.first);
			BlockType block_type = block_object->getType();
			if (!CheckCompatibility(prev_block, block_type))
			{
				throw CompatibilityExceptions("After " + str_type[prev_block] + " there cannot be " + str_type[block_type] + "!");
			}
			text = block_object->execute(text, block.second);
			prev_block = block_type;
		}
	}
};

