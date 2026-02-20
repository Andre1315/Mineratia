#include <iostream>
#include "generation.h"

int main()
{
	int y_start = 20;
	int max_size = 100;
	Generation gen(y_start, max_size);
	gen.generation_and_rendering_level();
}