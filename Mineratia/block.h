#include <vector>
#include <string>
#include <iostream>

class Block
{
public:
	Block(int x = 0, int y = 0, std::string texture);

	void rendering();

protected:
	int x, y;
	std::string texture;
};