#include "rule.h"

namespace proton {
namespace parser {

bool identifier::initialized = false;
UnicodeSet identifier::start_pattern;
UnicodeSet identifier::end_pattern;

bool integer::initialized = false;
UnicodeSet integer::start_pattern;
UnicodeSet integer::end_pattern;

/// Match identifier
ast::base* identifier::do_match(context& ctx) {
	/// See if the match works.
	if (!start_pattern.contains(ctx.current())) {
		return NULL;
	}

	do {
		value.append(ctx.current());
		ctx.next();
	} while(end_pattern.contains(ctx.current()));

	return new ast::ident(value);
}

/// Match integer
ast::base* integer::do_match(context& ctx) {
	int base = 10;

	// Must be a base-specific value.
	if (ctx.current() == '0') {
		switch(ctx.next())
		{
		case 'b': base=2; ctx.next(); break;
		case 'x': base=16; ctx.next(); break;
		default: base=8; break;
		}
	}

	// Parse out the integer digits
	while(end_pattern.contains(ctx.current())) {
		value.append(ctx.current());
		ctx.next();
	}

	return new ast::integer(proton::integer(proton::string(value), base));
}



}
}
