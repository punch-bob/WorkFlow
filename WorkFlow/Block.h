#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>


typedef std::list<std::string> Text;
enum BlockType
{
	IN, INOUT, OUT, FIRST
};

class Block
{
public:
	virtual Text execute(Text& input, std::vector<std::string>& args) = 0;
	virtual ~Block() = default;
	virtual BlockType getType() = 0;
};

