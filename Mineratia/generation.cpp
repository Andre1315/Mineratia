#include "generation.h"

Generation::Generation(int y_start, int max_size) {};

void fill_down(int x, int y_start)
{
	for (int i = y_start; i < y_start + 10; i++)
	{

	}
};

void Generation::generation_and_rendering_level()
{
	srand(0);
	int y = y_start;
	for (int i = y_start+1; i < max_size; i++)
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
		fill_down(i, y);
	}
};