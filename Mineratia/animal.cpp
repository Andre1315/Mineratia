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

Animal::Animal(int x_, int y_, std::string texture_) {
	x = x_;
	y = y_;
	texture = texture_;
	srand(time(NULL));

	//intarnal

	tag hunger("hunger", "the desire to eat");
	tag sleep("sleep", "the desire to sleep", tag::ultraLow);

	//external

	tag see1("see eat", "food found");
	tag see2("see predator", "predator in sight");
	tag danger1("danger predator's", "danger predator's", tag::ultraHight);

	//constants

	tag fear1("fear of heights", "fear of stepping off a cliff");

	constants.AddTag(fear1);
};

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
		Generation::block block_left = Generation::get_exits_block_on_xy(x - 1, y);
		Generation::block block_down = Generation::get_exits_block_on_xy(x, y + 1);
		Generation::block block_up = Generation::get_exits_block_on_xy(x, y - 1);
		Generation::block block_up_left = Generation::get_exits_block_on_xy(x - 1, y - 1);

		if (block_left != Generation::block::air && block_up == Generation::block::air && block_down != Generation::block::air && block_up_left == Generation::block::air)
		{
			y--; //вверх
			x--;
		}

		else if (block_left == Generation::block::air && block_down != Generation::block::air)
		{
			x--;
		}

		else if (block_up_left != Generation::block::air)
		{
			block = 1;
		}

		if (block_down == Generation::block::air)
		{
			physic();
		}
		rendering_animal();
		block_left = Generation::block::air;
		block_down = Generation::block::air;
		block_up = Generation::block::air;
		block_up_left = Generation::block::air;
	}
	if (direction == "right" || direction == "move_right")
	{
		rendering_animal_last();
		Generation::block block_right = Generation::get_exits_block_on_xy(x + 1, y);
		Generation::block block_down = Generation::get_exits_block_on_xy(x, y + 1);
		Generation::block block_up = Generation::get_exits_block_on_xy(x, y - 1);
		Generation::block block_up_right = Generation::get_exits_block_on_xy(x + 1, y - 1);

		if (block_right != Generation::block::air && block_up == Generation::block::air && block_down != Generation::block::air && block_up_right == Generation::block::air)
		{
			y--; //вверх
			x++;
		}

		else if (block_right == Generation::block::air && block_down != Generation::block::air)
		{
			x++;
		}

		else if (block_up_right != Generation::block::air)
		{
			block = 1;
		}

		if (block_down == Generation::block::air)
		{
			physic();
		}
		rendering_animal();
		block_right = Generation::block::air;
		block_down = Generation::block::air;
		block_up = Generation::block::air;
		block_up_right = Generation::block::air;
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

void Animal::expertise()
{

}

void Animal::death()
{
	texture = " ";
	rendering_animal();
	x = 0;
	y = 0;
}