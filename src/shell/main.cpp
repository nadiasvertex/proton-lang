#include "proton.h"

#include <iostream>


int main(int argc, char **argv)
{
	std::cout << "proton python alpha 0.1" << std::endl;

	proton::Bootstrapper->init();

	auto ctx = new proton::context();



	return 0;
}
