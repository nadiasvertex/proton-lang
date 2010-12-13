#include "proton.h"

namespace proton {

object* python_parser::eval(context* ctx, char* line) {
	// Unicode-ify the line
	string uline(line);

	// Create a parser context.
	proton::parser::context pctx(*uline.iterator());

	// Try to parse out the line.
	proton::parser::expr r;
	auto n = r.match(pctx);

	if (!n) {
		return NULL;
	}

	auto f = new proton::function(ctx);
	auto j = new proton::jitter(f);

	j->start();
	j->prologue();
	auto result = n->compile(j);
	j->ret(result);
	f->compile();
	j->end();

	 // Create closure to call the function.
	auto c = new proton::closure();

	// Call the function and see what happens!
	return f->apply(c);
}


}
