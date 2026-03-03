#include "sheep.h"

Sheep::Sheep(int x, int y) : Animal(x, y, "o") { age = 1; };

void Sheep::eat()
{
	if (Generation::get_exits_block_on_xy(get_pos("x"), get_pos("y") + 1) == 1)
	{
		up_animation("+");
		age++;
	}
	else
	{
		up_animation("!");
	}
}

int Sheep::get_age()
{
	return age;
}