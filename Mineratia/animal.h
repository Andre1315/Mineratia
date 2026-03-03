#pragma once

#include <iostream>
#include "generation.h"

class Animal
{
public:
	Animal(int x, int y, std::string texture);

	void rendering_animal();

	void rendering_animal_last();

	void action();

	void move(std::string direction, int step);

	void move_run(std::string direction, int step);

	int get_pos(std::string arg);

	virtual void eat();

	void death();

	void up_animation(std::string texture_animation);

	void physic();

private:
	int x, y;
	std::string texture;
};