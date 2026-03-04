#include "generation.h"

int Generation::y_start;
int Generation::max_sizeX;
int Generation::max_sizeY;
int** Generation::level;

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
	level[y][x] = 0;
}

void Generation::fill_down(int x, int y_start)
{
	Block earth("|");
	for (int i = y_start; get_exits_block_on_xy(x, i) != 3 ; i++)
	{
		earth.rendering_block(x, i);
		level[i][x] = 2;
	}
};

void Generation::set_border()
{
	Block border("$");

	int x1 = 1;
	int x2 = max_sizeX;
	for (int i = 1; i < max_sizeY; i++)
	{
		if (get_exits_block_on_xy(x1, i) == 0)
		{
			border.rendering_block(x1, i);
			level[i][x1] = 4;
		}

		if (get_exits_block_on_xy(x2, i) == 0)
		{
			border.rendering_block(x2, i);
			level[i][x2] = 4;
		}
	}
}

void Generation::set_bedrock(int y, int max_size_x)
{
	Block bedrock("-");
	for (int i = 1; i < max_size_x; i++)
	{
		bedrock.rendering_block(i, y);
		level[y][i] = 3;
	}
}

void Generation::generation_and_rendering_level()
{
	srand(0);

	Block grass("#");

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
		grass.rendering_block(i, y);
		level[y][i] = 1;
		fill_down(i, y+1);
	}
};

int Generation::get_exits_block_on_xy(int x, int y)
{
	int block = level[y][x];
	if (block < 0)
	{
		return 0;
	}
	else
	{
		return block;
	}
}

void Generation::clear_memory()
{
	for (int i = 0; i < max_sizeY; i++) {
		delete[] level[i];
	}
	delete[] level;
}

void Generation::add_block(int x, int y, int type)
{
	if (type == 1)
	{
		Block grass("#");
		grass.rendering_block(x, y);
		level[y][x] = type;
	}
	if (type == 2)
	{
		Block stone("|");
		stone.rendering_block(x, y);
		level[y][x] = type;
	}
	if (type == 5)
	{
		Block earth("&");
		earth.rendering_block(x, y);
		level[y][x] = type;
	}
}

void Generation::rendering_memory()
{
	for (int j = 1; j < max_sizeY + 1; j++)
	{
		for (int i = 1; i < max_sizeX + 1; i++)
		{
			goto_xy(i, j);
			std::cout << level[j][i];
		}
	}
}

Generation::~Generation()
{
	clear_memory();
	std::cout << "\033[" << 1 << ";" << 1 << "H";
}