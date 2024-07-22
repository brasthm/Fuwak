#include <iostream>
#include<sstream>

#include "../src/Screen/ScreenManager.h"
#include "../src/System/Utils.h"

int main(int argc, char* argv[]) {

	std::cout << "Max Texture Size " << sf::Texture::getMaximumSize() << std::endl;
	unsigned int x;
	std::stringstream ss;
	ss << std::hex << "0xff0000ff";
	ss >> x;
	std::cout << "Test Color " << x << " " << Utils::stui("0xff0000ff") << " " << 0xff0000ff << std::endl;

	ScreenManager screenManager;

	screenManager.display();

	return 0;
}