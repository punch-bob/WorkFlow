#include "WriteFile.h"
#include "..\BlockMaker.h"
#include "..\Exceptions\ArgsExceptions.h"
#include <fstream>

BlockType WriteFile::getType()
{
	return OUT;
}

Text WriteFile::execute(Text& output, std::vector<std::string>& args)
{
	if (args.size() != 1)
	{
		throw ArgsExceptions(" writefile, should be : 1");
	}
	std::ofstream out(args[0]);
	for (auto iter : output)
	{
		out << iter << "\n";
	}
	Text ret;
	out.close();
	return ret;
}

static BlockMaker<WriteFile> maker("writefile");