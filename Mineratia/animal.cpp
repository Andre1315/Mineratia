#include "animal.h"
#include <windows.h>

static void goto_xy(int x, int y) {
	std::cout << "\033[" << y << ";" << x << "H";
}

Animal::Animal(int x_, int y_, std::string texture_, std::string type_) { x = x_; y = y_; texture = texture_; };

void Animal::rendering_animal() {
	goto_xy(x, y);
	std::cout << texture;
}

void Animal::move(std::string direction, int step)
{
	if (direction == "left")
	{
		for (int i = step; i > 0; i--)
		{

		}
	}
	if (direction == "right")
	{
		for (int i = step; i > 0; i--)
		{

		}
	}
}

int Animal::get_pos()
{
	return x, y;
}

void Animal::eat()
{
	
}

void Animal::action(bool state) {
	srand(0);
	while (state) {
		Sleep(2000);
		if (rand() % 10 > 5)
		{
			if (rand() % 10 > 5)
			{
				if (rand() % 10 > 5)
				{
					move("left", rand() % 10);
				}
				else
				{
					move("right", rand() % 10);
				}
			}
			else
			{
				eat();
			}
		}
	}
}