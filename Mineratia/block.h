#pragma once

#include <vector>
#include <string>
#include <iostream>

class Block
{
public:
	Block(int x, int y, std::string texture);

	void rendering();

private:
	int x;
	int y;
	std::string texture;
};