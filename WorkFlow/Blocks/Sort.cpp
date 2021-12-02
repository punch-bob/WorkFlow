#include "..\Exceptions\ArgsExceptions.h"
#include "Sort.h"
#include "..\BlockMaker.h"

BlockType Sort::getType()
{
	return INOUT;
}

Text Sort::execute(Text& output, std::vector<std::string>& args)
{
	if (args.size() != 0)
	{
		throw ArgsExceptions(" sort, should be : 0");
	}
	output.sort();
	return output;
}

static BlockMaker<Sort> maker("sort");