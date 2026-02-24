#include "generation.h"

Generation::Generation(int y_start_, int max_sizeX_, int max_sizeY_) {
	y_start = y_start_;
	max_sizeX = max_sizeX_;
	max_sizeY = max_sizeY_;

	level = new int* [max_sizeY];

	// Для каждой строки создаём массив из m элементов
	for (int i = 0; i < max_sizeY; ++i) {
		level[i] = new int[max_sizeX];
	}
};

static void goto_xy(int x, int y) {
	std::cout << "\033[" << y << ";" << x << "H";
}

void Generation::delete_block(int x, int y)
{
	goto_xy(x, y);
	std::cout << " ";
}

void Generation::fill_down(int x, int y_start)
{
	for (int i = y_start; i < y_start + 10; i++)
	{
		Block earth("|");
		earth.rendering_block(x, i);
		level[x][i] = 2;
	}
};

void Generation::generation_and_rendering_level()
{
	srand(0);

	int y = y_start;
	for (int i = 1; i < max_sizeX; i++)
	{
		if (rand() % 10 > 5)
		{
			if (rand() % 10 > 5)
			{
				if (y < max_sizeY) {
					y++;  //ниже
				}
			}
			else
			{
				y--; //выше
			}
		}
		Block grass("#");
		grass.rendering_block(i, y);
		level[i][y] = 1;
		fill_down(i, y+1);
	}
};

int Generation::get_exits_block_on_xy(int x, int y)
{
	if (level[x][y] < 0)
	{
		return 0;
	}
	else
	{
		return level[x][y];
	}
}

void Generation::clear_memory()
{
	for (int i = 0; i < max_sizeY; ++i) {
		delete[] level[i];
	}
	delete[] level;
}