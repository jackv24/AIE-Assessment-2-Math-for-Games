#include "unittest.h"
#include <iostream>

int main() {

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;

	//Custom testing
	Vector2 derp(13, 15);
	std::cout << derp.x << ", " << derp.y << std::endl;

	derp = derp * 2;
	std::cout << derp.x << ", " << derp.y << std::endl;

	derp = derp - derp;
	std::cout << derp.x << ", " << derp.y << std::endl;

	system("PAUSE");

	return 0;
}