#pragma once
#include "..\Block.h"

class WriteFile : public Block
{
public:
	BlockType getType() override;

	Text execute(Text& output, std::vector<std::string>& args) override;
};