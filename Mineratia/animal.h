#pragma once

#include <iostream>
#include "generation.h"

class Animal
{
public:
	Animal(int x, int y, std::string texture, std::string type);

	void rendering_animal();

	void action(bool state);

	void move(std::string direction, int step);

	int get_pos();

	void eat();

private:
	int x, y;
	std::string texture;
};