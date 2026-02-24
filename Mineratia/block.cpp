#include "block.h"

Block::Block(std::string texture_) { texture = texture_; }

static void goto_xy(int x, int y) {
	std::cout << "\033[" << y << ";" << x << "H";
}

void Block::rendering_block(int x, int y)
{
	goto_xy(x, y);
	std::cout << texture;
}