#include "generation.h"

Generation::Generation(int y_start_, int max_size_) { y_start = y_start_; max_size = max_size_; };

void fill_down(int x, int y_start)
{
	for (int i = y_start; i < y_start + 10; i++)
	{
		Earth earth(x, i);
		earth.rendering();
	}
};

void Generation::generation_and_rendering_level()
{
	std::vector<std::vector<int>> level_();
	srand(0);
	int y = y_start;
	for (int i = 1; i < max_size; i++)
	{
		if (rand() % 10 > 5)
		{
			if (rand() % 10 > 5)
			{
				y++;
			}
			else
			{
				y--;
			}
		}
		Grass grass(i, y);
		grass.rendering();
		fill_down(i, y+1);
	}
};

std::vector<std::vector<int>> Generation::get_level()
{

};