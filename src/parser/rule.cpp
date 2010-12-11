#include "rule.h"

namespace proton {
namespace parser {

bool identifier::initialized = false;
UnicodeSet identifier::start_pattern;
UnicodeSet identifier::end_pattern;

bool integer::initialized = false;
UnicodeSet integer::pattern;

/// Match identifier
ast::base* identifier::do_match(context& ctx) {
	/// See if the match works.
	if (!start_pattern.contains(ctx.current())) {
		return NULL;
	}

	do {
		value.append(ctx.current());
		ctx.next();
	} while (end_pattern.contains(ctx.current()));

	return new ast::ident(value);
}

/// Match integer
ast::base* integer::do_match(context& ctx) {
	int base = 10;

	// Must be a base-specific value.
	if (ctx.current() == '0') {
		switch (ctx.next()) {
		case 'B':
		case 'b':
			base = 2;
			ctx.next();
			break;

		case 'X':
		case 'x':
			base = 16;
			ctx.next();
			break;

		default:
			base = 8;
			break;
		}
	}

	// Parse out the integer digits
	while (pattern.contains(ctx.current())) {
		value.append(ctx.current());
		ctx.next();
	}

	return new ast::integer(proton::integer(proton::string(value), base));
}

/// Match a binary operation
ast::base* binop::do_match(context& ctx) {
	// So far we have a left side.  Now we need something to do.
	wchar op_type;

	ctx.skip_ws();
	switch (ctx.current()) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '|':
	case '&':
		op_type = ctx.current();
		ctx.next();
		break;

		// Not a binop
	default:
		return NULL;
	}

	// Finally, we need a right side.
	ctx.skip_ws();

	expr rrule;
	auto r = rrule.match(ctx);

	if (!r) {
		return NULL;
	}

	return new ast::binop(op_type, NULL, r);
}

ast::base* primary_expr::do_match(context& ctx) {
	identifier ident_rule;
	integer int_rule;

	// First try to match an identifer
	auto n = ident_rule.match(ctx);

	// If that fails, try a number
	if (!n) {
		n = int_rule.match(ctx);
	}

	// If that fails, then we must not have a primary_expr
	if (!n) {
		return NULL;
	}

	return n;
}

ast::base* expr::do_match(context& ctx) {

	// If that didn't work, try a primary expr
	primary_expr pe_rule;
	auto l = pe_rule.match(ctx);
	if (l==NULL) {
		return NULL;
	}

	// Now try a binop
	binop binop_rule;
	auto n = binop_rule.match(ctx);
	if (n!=NULL) {
		((ast::binop*)n)->set_left(l);
		return n;
	}

	// Only matched a primary expression.
	if (l) {
		return l;
	}

	// Not an expression.
	return NULL;
}

}
}
