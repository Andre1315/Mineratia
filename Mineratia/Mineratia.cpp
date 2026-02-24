#include <iostream>
#include "generation.h"

int main()
{
	int y_start = 20;
	int max_sizeX = 100;
	int max_sizeY = 100;
	Generation gen(y_start, max_sizeX, max_sizeY);
	gen.generation_and_rendering_level();
	//std::cout << "\n"<< "Number in x:50 y:30 : " << gen.get_exits_block_on_xy(50, 30);
	gen.clear_memory();
}