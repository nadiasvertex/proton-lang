#include <proton.h>
#include <iostream>
#include <readline/readline.h>

void eval(char* line) {
	proton::python_parser p;


}


int main(int argc, char **argv)
{
	std::cout << "proton python alpha 0.1" << std::endl;

	proton::Bootstrapper->init();

	auto ctx = new proton::context();

	while(true) {
		// Go into the interactive loop.
		auto line = readline(">>> ");
		eval(line);
	}

	return 0;
}
