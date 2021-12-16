#include "Grep.h"
#include "..\BlockMaker.h"
#include "..\Exceptions\ArgsExceptions.h"

BlockType Grep::getType()
{
	return BlockType::INOUT;
}

Text Grep::execute(Text& input, std::vector<std::string>& args)
{
	if (args.size() != 1)
	{
		throw ArgsExceptions(" grep, should be : 1");
	}
	Text grep_text;
	for (const auto& iter : input)
	{
		if (iter.find(args[0]) != std::string::npos) 
		{
			grep_text.push_back(iter);
		}
	}
	return grep_text;
}

static BlockMaker<Grep> maker("grep");