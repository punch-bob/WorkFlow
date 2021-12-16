#include "Dump.h"
#include "..\BlockMaker.h"
#include "..\Exceptions\ArgsExceptions.h"
#include <fstream>

BlockType Dump::getType()
{
	return BlockType::INOUT;
}

Text Dump::execute(Text& output, std::vector<std::string>& args)
{
	if (args.size() != 1)
	{
		throw ArgsExceptions(" dump, should be : 1");
	}
	std::ofstream out(args[0]);
	for (const auto& iter : output)
	{
		out << iter << std::endl;
	}
	return output;
}

static BlockMaker<Dump> maker("dump");