#pragma once
#include "..\Block.h"

class Sort : public Block
{
public:
	BlockType getType() override;

	Text execute(Text& output, std::vector<std::string>& args) override;
};
