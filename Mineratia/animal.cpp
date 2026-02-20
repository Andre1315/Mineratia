#include "animal.h"
#include <windows.h>

void goto_xy(int x, int y) {
	std::cout << "\033[" << y << ";" << x << "H";
}

Animal::Animal(int x_, int y_, std::string texture_) { x = x_; y = y_; texture = texture_; };

void Animal::rendering_animal() {
	goto_xy(x, y);
	std::cout << texture;
}

void Animal::move(std::string direction)
{

}

void Animal::action(bool state) {
	while (state) {
		Sleep(2000);
	}
}