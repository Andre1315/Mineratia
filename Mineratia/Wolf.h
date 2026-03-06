#pragma once

#include "animal.h"
#include "generation.h"
#include "sheep.h"

class Wolf : public Animal
{
public:
	Wolf(int x, int y);

	void eat_sheep(Sheep sheep);
};