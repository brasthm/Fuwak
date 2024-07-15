#include <iostream>
#include <SFML/Graphics.hpp>
#include "../src/Network/Server.h"
#include "../src/main.h"


int main(int argc, char* argv[]) {

	std::cout << "Synchrone 1.0" << std::endl;
	std::cout << "This is the test project for the Synchrone Engine." << std::endl;
	std::cout << "Synchrone Engine handles TCP/UDP connections from a client and server." << std::endl;
	std::cout << "Synchrone Engine also comes with a built in lobby manager." << std::endl;

	std::cout << "Server started at " << sf::IpAddress::getLocalAddress() << "/" << sf::IpAddress::getPublicAddress() << std::endl;

	Server s;
	s.run();

	return 0;
}