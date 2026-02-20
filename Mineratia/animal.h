#pragma once

#include <iostream>

class Animal
{
public:
	Animal(int x, int y, std::string texture);

	void rendering_animal();

	void action(bool state);

	void move(std::string direction);

private:
	int x, y;
	std::string texture;
};