#pragma once

#include <iostream>
#include "block.h"

class Generation
{
public:
	Generation(int y_start, int max_sizeX, int max_sizeY);

	void generation_and_rendering_level();

	void delete_block(int x, int y);

	void fill_down(int x, int y_start);

	int get_exits_block_on_xy(int x, int y);

	void clear_memory();
private:
	int y_start;
	int max_sizeX;
	int** level;
	int max_sizeY;
};