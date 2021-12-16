#pragma once
#include "Block.h"
#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
#include <functional>
#include "Exceptions/ParserExceptoins.h"
#include "Exceptions/RegExceptions.h"

typedef std::pair<std::string, std::vector<std::string>> Blocks;
class WorkFlowParser
{
public:
	std::list<std::pair<std::string, std::vector<std::string>>> getBlocks(std::string file_name)
	{
		std::list<Blocks> list_of_blocks;
		std::map<std::string, Blocks> number_of_block;
		std::string str;
		std::ifstream in(file_name);
		std::getline(in, str, '\n');
		if (str != "desc")
		{
			throw ParserExceptions("desc");
		}
		while (std::getline(in, str, '\n') && str != "csed")
		{
			std::istringstream ist(str);
			std::string argument;
			std::string number;
			std::vector<std::string> list_of_args;
			ist >> number;
			ist >> argument;
			std::string block_name;
			ist >> block_name;
			while (ist >> argument)
			{
				list_of_args.push_back(argument);
			}
			number_of_block[number] = make_pair(block_name, list_of_args);
		}
		if (str != "csed")
		{
			throw ParserExceptions("csed");
		}
		std::getline(in, str, '\n');
		std::istringstream ist(str);
		std::string number;
		std::string arrow;
		while (ist >> number)
		{
			ist >> arrow;
			if (number_of_block.count(number) == 0)
			{
				throw RegExceptions("The block with the number " + number + " was not found!");
			}
			list_of_blocks.push_back(number_of_block[number]);
		}
		return list_of_blocks;
	}
};