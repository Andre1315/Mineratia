#include "wolf.h"

Wolf::Wolf(int x, int y) : Animal(x, y, "w") {}

void Wolf::eat_sheep(Sheep sheep)
{
	sheep.death();
	rendering_animal();
	up_animation("-");
}