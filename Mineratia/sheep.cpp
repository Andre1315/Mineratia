#include "sheep.h"

Sheep::Sheep(int x, int y) : Animal(x, y, "o") { age = 1; };

int Sheep::eat()
{
	srand(time(NULL));
	if (Generation::get_exits_block_on_xy(get_pos("x"), get_pos("y") + 1) == 1)
	{
		up_animation("+");
		age++;
		Generation::delete_block(get_pos("x"), get_pos("y") + 1);
		Generation::add_block(get_pos("x"), get_pos("y") + 1, 5);
		return 1;
	}
	else
	{
		up_animation("!");
		return 0;
	}
}

int Sheep::get_age()
{
	return age;
}