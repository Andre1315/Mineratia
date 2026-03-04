#include "animal.h"
#include <windows.h>

static void goto_xy(int x, int y)
{
	std::cout << "\033[" << y << ";" << x << "H";
}

void Animal::up_animation(std::string texture_animation)
{
	goto_xy(x, y - 1);
	std::cout << texture_animation;
	Sleep(500);
	goto_xy(x, y - 1);
	std::cout << " ";
}

Animal::Animal(int x_, int y_, std::string texture_) { x = x_; y = y_; texture = texture_; srand(time(NULL)); };

void Animal::rendering_animal()
{
	goto_xy(x, y);
	std::cout << texture;
}

void Animal::rendering_animal_last()
{
	goto_xy(x, y);
	std::cout << " ";
}

void Animal::physic()
{
	while (Generation::get_exits_block_on_xy(x, y + 1) == 0)
	{
		rendering_animal_last();
		y++;
		rendering_animal();
		Sleep(90);
	}
}

void Animal::move(std::string direction, int step, std::string speed)
{
	int time = 0;
	if (speed == "run") time = 125;
	if (speed == "normal") time = 250;

	if (direction == "left")
	{
		for (int i = 0; i < step; i++)
		{ 
			rendering_animal_last();
			int block_left = Generation::get_exits_block_on_xy(x - 1, y);
			int block_down = Generation::get_exits_block_on_xy(x, y + 1);
			int block_up = Generation::get_exits_block_on_xy(x, y - 1);
			int block_up_left = Generation::get_exits_block_on_xy(x - 1, y - 1);

			if (block_left != 0 && block_up == 0 && block_down != 0 && block_up_left == 0)
			{
				y--; //вверх
				x--;
			}

			else if (block_left == 0 && block_down != 0)
			{
				x--;
			}

			else if (block_up_left != 0)
			{
				i = step;
			}

			if (block_down == 0)
			{
				physic();
			}
			rendering_animal();
			block_left = 0;
			block_down = 0;
			block_up = 0;
			block_up_left = 0;
			Sleep(time);
			if (time < 250) time += 2;
		}
	}
	if (direction == "right")
	{
		for (int i = 0; i < step; i++)
		{
			rendering_animal_last();
			int block_right = Generation::get_exits_block_on_xy(x + 1, y);
			int block_down = Generation::get_exits_block_on_xy(x, y + 1);
			int block_up = Generation::get_exits_block_on_xy(x, y - 1);
			int block_up_right = Generation::get_exits_block_on_xy(x + 1, y - 1);

			if (block_right != 0 && block_up == 0 && block_down != 0 && block_up_right == 0)
			{
				y--; //вверх
				x++;
			}

			else if (block_right == 0 && block_down != 0)
			{
				x++;
			}

			else if (block_up_right != 0)
			{
				i = step;
			}

			if (block_down == 0)
			{
				physic();
			}
			rendering_animal();
			block_right = 0;
			block_down = 0;
			block_up = 0;
			block_up_right = 0;
			Sleep(time);
			if (time < 250) time += 2;
		}
	}
}

int Animal::get_pos(std::string arg)
{
	if (arg == "x") return x;
	else if (arg == "y") return y;
	else return 0;
}

void Animal::eat() {}

void Animal::action() {
	if (rand() % 10 > 5)
	{
		if (rand() % 10 > 3)
		{
			if (rand() % 10 > 5)
			{
				int step = rand() % 100;
				move("left", step, "normal");
			}
			else
			{
				int step = rand() % 100;
				move("right", step, "normal");
			}
		}
		else
		{
			eat();
		}
	}
}

void Animal::death()
{
	texture = " ";
	rendering_animal();
	x = 0;
	y = 0;
}