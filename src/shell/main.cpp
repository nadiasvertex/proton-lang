#include <proton.h>
#include <iostream>
#include <readline/readline.h>

void eval(proton::context* ctx, char* line) {
	proton::python_parser p;

	auto result = p.eval(ctx, line);
	if (result==NULL) {
		std::cout << "I was unable to parse your input (and my parse-error detection is really poor right now, sorry.)" << std::endl;
	} else {
		auto s = (proton::string*)result->repr();
		std::cout << s->to_local_str() << std::endl;
	}
}


int main(int argc, char **argv)
{
	std::cout << "proton python alpha 0.1" << std::endl;

	proton::Bootstrapper->init();

	auto ctx = new proton::context();

	while(true) {
		// Go into the interactive loop.
		auto line = readline(">>> ");
		eval(ctx, line);
	}

	return 0;
}
