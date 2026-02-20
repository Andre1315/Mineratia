#include "grass.h"
#include "earth.h"
#include <vector>

class Generation
{
public:
	Generation(int y_start, int max_size);

	void generation_and_rendering_level();

	std::vector<std::vector<int>> get_level();
private:
	int y_start;
	int max_size;
	std::vector<std::vector<int>> level;
};