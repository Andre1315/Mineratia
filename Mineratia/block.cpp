#include "block.h"

void goto_xy(int x, int y) {
	std::cout << "\033[" << x << ";" << y << "H";
}

Block::Block(int x, int y, std::string texture) {}

void Block::rendering()
{
	goto_xy(x, y);
	std::cout << texture;
}

