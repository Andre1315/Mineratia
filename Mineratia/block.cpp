#include "block.h"

void goto_xy(int x, int y) {
	std::cout << "\033[" << y << ";" << x << "H";
}

Block::Block(int x_, int y_, std::string texture_) { x = x_; y = y_; texture = texture_; }

void Block::rendering()
{
	goto_xy(x, y);
	std::cout << texture;
}

