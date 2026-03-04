#include "sheep.h"

Sheep::Sheep(int x, int y) : Animal(x, y, "o") { age = 1; };

void Sheep::eat()
{
	srand(time(NULL));
	if (Generation::get_exits_block_on_xy(get_pos("x"), get_pos("y") + 1) == 1)
	{
		up_animation("+");
		age++;
		Generation::delete_block(get_pos("x"), get_pos("y") + 1);
		Generation::add_block(get_pos("x"), get_pos("y") + 1, 5);
	}
	else
	{
		up_animation("!");
		if (rand() % 10 > 5)
		{
			move("left", rand() % 100, "normal");
		}
		else
		{
			move("right", rand() % 100, "normal");
		}
	}
}

int Sheep::get_age()
{
	return age;
}