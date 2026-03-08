#include <iostream>
#include "generation.h"
#include "sheep.h"
#include "wolf.h"

static void physic_animal(Sheep& sheep1, Wolf& wolf1)
{
	int i_sheep = 1;
	int i_wolf = 1;

	while (i_sheep != 0 || i_wolf != 0)
	{
		if (i_sheep != 0)
		{
			sheep1.rendering_animal_last();
			i_sheep = sheep1.physic();
		}
		
		if (i_wolf != 0)
		{
			wolf1.rendering_animal_last();
		i_wolf = wolf1.physic();
		}
		
		sheep1.rendering_animal();
		wolf1.rendering_animal();
		Sleep(90);
	}
}

static void move_animal(std::string type ,std::string direction_sheep, int step_sheep, Sheep& sheep1, std::string direction_wolf, int step_wolf, Wolf& wolf1, int eat_state)
{
	int n_sheep = step_sheep;
	int n_wolf = step_wolf;
	int time = 0;

	if (type == "normal") time = 250;
	else if (type == "run") time = 125;

	while (n_sheep != 0 && n_wolf != 0)
	{
		if (n_sheep != 0) 
		{
			sheep1.move(direction_sheep);
			n_sheep--;
		}
		if (n_wolf != 0)
		{
			wolf1.move(direction_wolf);
			n_wolf--;
			if (eat_state == 1)
			{
				for (int i = -1; i < 1; i++)
				{
					for (int j = -1; j < 1; j++)
					{
						if (sheep1.get_pos("x") == wolf1.get_pos("x") + i && sheep1.get_pos("y") == wolf1.get_pos("y") + j)
						{
							wolf1.eat_sheep(sheep1);
							n_wolf = 0;
						}
					}
				}
			}
		}
		Sleep(time);
		if (type == "run") time += 5;
	}
}

static void eat_animal(std::string action_sheep, Sheep& sheep1, std::string action_wolf, Wolf& wolf1)
{
	if (action_sheep == "eat")
	{
		int eat_sheep = sheep1.eat();
		if (eat_sheep == 0)
		{
			int step_sheep = rand() % 10;

			std::string direction_sheep = "";
			if (rand() % 10 > 5) direction_sheep = "left";
			else direction_sheep = "right";

			int step_wolf = rand() % 100;

			std::string direction_wolf = "";
			if (rand() % 10 > 5) direction_wolf = "left";
			else direction_wolf = "right";

			move_animal("normal", direction_sheep, step_sheep, sheep1, direction_wolf, step_wolf, wolf1, 0);
		}
	}

	if (action_wolf == "eat")
	{
		int x_sheep = sheep1.get_pos("x");
		int x_wolf = wolf1.get_pos("x");
		std::string direction = "";
		if (x_sheep > x_wolf) direction = "right";
		else direction = "left";

		int step_wolf = 40;
		int step_sheep = 20;

		move_animal("run", direction, step_sheep, sheep1, direction, step_wolf, wolf1, 1);
	}
}

int main()
{
	srand(time(NULL));

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
		physic_animal(sheep_Olga, wolf_Oleg);



		std::tuple<std::string, int> result_sheep = sheep_Olga.action();

		std::string action_sheep = std::get<0>(result_sheep); // первый элемент
		int step_sheep = std::get<1>(result_sheep); // второй элемент



		std::tuple<std::string, int> result_wolf = wolf_Oleg.action();

		std::string action_wolf = std::get<0>(result_wolf); // первый элемент
		int step_wolf = std::get<1>(result_wolf); // второй элемент



		if (action_sheep == "move_left" || action_sheep == "move_right" || action_wolf == "move_left" || action_wolf == "move_right") move_animal("normal", action_sheep, step_sheep, sheep_Olga, action_wolf, step_wolf, wolf_Oleg, 0);
		if (action_sheep == "eat" || action_wolf == "eat") eat_animal(action_sheep, sheep_Olga, action_wolf, wolf_Oleg);



		age_sheep = sheep_Olga.get_age();
		pos_sheep = sheep_Olga.get_pos("x") + sheep_Olga.get_pos("y");
		Sleep(4000);
	}

	gen.clear_memory();

	std::cout << "\033[" << 1 << ";" << 1 << "H";
}