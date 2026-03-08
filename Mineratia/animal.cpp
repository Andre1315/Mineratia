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

int Animal::physic()
{
	if (Generation::get_exits_block_on_xy(x, y + 1) == 0)
	{
		y++;
		return 1;
	}
	else return 0;
}

int Animal::move(std::string direction)
{
	int block = 0;
	if (direction == "left" || direction == "move_left")
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
			block = 1;
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
	}
	if (direction == "right" || direction == "move_right")
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
			block = 1;
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
	}
	return block;
}

int Animal::get_pos(std::string arg)
{
	if (arg == "x") return x;
	else if (arg == "y") return y;
	else return 0;
}

int Animal::eat() { return 0; }

std::tuple<std::string, int> Animal::action() {
	if (rand() % 10 > 3)
	{
		if (rand() % 10 > 2)
		{
			if (rand() % 10 > 5)
			{
				int step = rand() % 100;
				return { "move_left", step };
			}
			else
			{
				int step = rand() % 100;
				return { "move_right", step };
			}
		}
		else
		{
			return { "eat", 0 };
		}
	}
	else return { "none", 0 };
}

void Animal::death()
{
	texture = " ";
	rendering_animal();
	x = 0;
	y = 0;
}