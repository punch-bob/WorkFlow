#include "ReadFile.h"
#include "..\BlockMaker.h"
#include "..\Exceptions\ArgsExceptions.h"
#include <fstream>

BlockType ReadFile::getType()
{
	return IN;
}

Text ReadFile::execute(Text& input, std::vector<std::string>& args)
{
	if (args.size() != 1)
	{
		throw ArgsExceptions(" readfile, should be : 1");
	}
	std::ifstream in(args[0]);
	std::string str;
	while (getline(in, str, '\n'))
	{
		input.push_back(str);
	}
	in.close();
	return input;
}

static BlockMaker<ReadFile> maker("readfile");