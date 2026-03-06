#pragma once

#include "animal.h"
#include "generation.h"

class Sheep : public Animal
{
public:
	Sheep(int x, int y);

	int eat() override;

	int get_age();
private:
	int age;
};