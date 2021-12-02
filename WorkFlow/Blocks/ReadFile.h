#pragma once
#include "..\Block.h"

class ReadFile : public Block
{
public:
	BlockType getType() override;

	Text execute(Text& input, std::vector<std::string>& args) override;
};