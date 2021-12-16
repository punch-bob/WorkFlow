#include "Replace.h"
#include "..\BlockMaker.h"
#include "..\Exceptions\ArgsExceptions.h"

BlockType Replace::getType()
{
	return BlockType::INOUT;
}

Text Replace::execute(Text& input, std::vector<std::string>& args)
{
	if (args.size() != 2)
	{
		throw ArgsExceptions(" replace, should be : 2");
	}
	for (auto& iter : input)
	{
		size_t index = 0;
		while ((index = iter.find(args[0], index)) != std::string::npos)
		{
			iter.replace(index, args[0].length(), args[1]);
			index += args[1].length();
		}
	}
	return input;
}

static BlockMaker<Replace> maker("replace");