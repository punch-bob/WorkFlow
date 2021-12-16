#pragma once
#include <istream>
#include <iostream>
#include "WorkFlowParser.h"
#include "Block.h"
#include "BlockFactory.h"
#include "Exceptions/CompatibilityExceptoins.h"

class WorkFlowExecutor
{
public:
	bool CheckCompatibility(BlockType prev, BlockType now)
	{
		if (prev == BlockType::FIRST)
		{
			return now == BlockType::IN;
		}
		if (prev == BlockType::OUT)
		{
			return now == BlockType::IN;
		}
		if (prev == BlockType::IN)
		{
			return now == BlockType::INOUT || now == BlockType::OUT;
		}
		return true;
	}

	void execute(std::string file_name)
	{
		Text text;
		BlockType prev_block = BlockType::FIRST;
		WorkFlowParser parser;
		auto blocks = parser.getBlocks(file_name);
		for (auto block : blocks)
		{
			std::unique_ptr<Block> block_object(BlockFactory::getInstance().getBlock(block.first));
			BlockType block_type = block_object->getType();
			if (!CheckCompatibility(prev_block, block_type))
			{
				throw CompatibilityExceptions("After " + str_type[(int)prev_block] + " there can't be " + str_type[(int)block_type] + "!");
			}
			text = block_object->execute(text, block.second);
			prev_block = block_type;
		}
	}
private:
	std::vector<std::string> str_type{ "IN", "INOUT", "OUT", "FIRST" };
};