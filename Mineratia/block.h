#pragma once

#include <iostream>

class Block
{
public:
	Block(std::string texture);

	void rendering_block(int x, int y);

private:
	std::string texture;
};