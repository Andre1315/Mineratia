#include <iostream>
#include "generation.h"
#include "sheep.h"
#include "wolf.h"

int main()
{
	int x = 50;
	//int y = 70;

	int y_start = 20;
	int y_min = 28;
	int max_sizeX = 100;
	int max_sizeY = 30;
	Generation gen(y_start, max_sizeX, max_sizeY);
	gen.set_bedrock(y_min, max_sizeX);
	gen.generation_and_rendering_level();
	gen.set_border();

	Sheep sheep_Olga(5, 15);
	sheep_Olga.rendering_animal();

	Wolf wolf_Oleg(15, 15);
	wolf_Oleg.rendering_animal();

	int age_sheep = sheep_Olga.get_age();
	int pos_sheep = sheep_Olga.get_pos("x") + sheep_Olga.get_pos("y");
	while (age_sheep < 6 && pos_sheep != 0)
	{
		sheep_Olga.physic();
		wolf_Oleg.physic();

		sheep_Olga.action();
		sheep_Olga.rendering_animal();
		wolf_Oleg.action();
		wolf_Oleg.rendering_animal();

		if (wolf_Oleg.get_eat_state() == 1)
		{
			wolf_Oleg.eat_sheep(sheep_Olga);
		}

		age_sheep = sheep_Olga.get_age();
		int pos_sheep = sheep_Olga.get_pos("x") + sheep_Olga.get_pos("y");
		Sleep(4000);
	}


	gen.clear_memory();

	std::cout << "\033[" << 1 << ";" << 1 << "H";
}