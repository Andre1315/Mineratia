#include "grass.h"
#include "earth.h"

class Generation
{
public:
	Generation(int y_start, int max_size);

	void generation_and_rendering_level();

	int y_start;
	int max_size;
};