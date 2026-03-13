#pragma once

#include <iostream>
#include "generation.h"
#include <tuple>
#include "tags.h"

class Animal
{
public:
	Animal(int x, int y, std::string texture);

	void rendering_animal();

	void rendering_animal_last();

	void expertise();

	int move(std::string direction);

	int get_pos(std::string arg);

	virtual int eat();

	void death();

	void up_animation(std::string texture_animation);

	int physic();

private:
	int x, y;
	std::string texture;
	tags internal;
	tags external;
	tags constants;
};