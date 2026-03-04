#include "wolf.h"

Wolf::Wolf(int x, int y) : Animal(x, y, "w") { eat_state = 0; }

void Wolf::eat_sheep(Sheep sheep)
{
	while (get_pos("x") != sheep.get_pos("x"))
	{
		int step = get_pos("x") - sheep.get_pos("x");
		std::string dir = "";
		if (step > 0) dir = "left";
		else dir = "right";
		move(dir, step, "run");
	}
	sheep.death();
	rendering_animal();
	up_animation("-");
	eat_state = 0;
}

void Wolf::eat()
{
	eat_state = 1;
}

int Wolf::get_eat_state()
{
	return eat_state;
}

//void Wolf::search_food()
//{
//
//}