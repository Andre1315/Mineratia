#pragma once

#include <iostream>
#include "block.h"
#include <windows.h>

class Generation
{
public:
	Generation(int y_start, int max_sizeX, int max_sizeY);

	static void generation_and_rendering_level();

	static void delete_block(int x, int y);

	static void fill_down(int x, int y_start);

	static int get_exits_block_on_xy(int x, int y);

	static void clear_memory();

	static void add_block(int x, int y, int type);

	static void set_bedrock(int y, int max_size_x);

	static void rendering_memory();

	~Generation();
private:
	static int y_start;
	static int max_sizeX;
	static int max_sizeY;
	static int** level;
};