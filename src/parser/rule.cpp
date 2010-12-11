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
	primary_expr lrule();

	// Try to match a primary expression
	auto l = lrule.match(ctx);

	// If that fails, then we must not have a binop here.
	if (!l) {
		return NULL;
	}

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
		break;

		// Not a binop
	default:
		return NULL;
	}

	// Finally, we need a right side.
	ctx.skip_ws();

	expr rexpr_rule();
	auto r = rexpr_rule.match(ctx);

	if (!r) {
		return NULL;
	}

	return new ast::binop(op_type, l, r);
}

ast::base* primary_expr::do_match(context& ctx) {
	identifier ident_rule();
	integer int_rule();

	// First try to match an identifer
	auto l = ident_rule.match(ctx);

	// If that fails, try a number
	if (!l) {
		l = int_rule.match(ctx);
	}

	// If that fails, then we must not have a primary_expr
	if (!l) {
		return NULL;
	}

	return l;
}

ast::base* expr::do_match(context& ctx) {
	binop binop_rule();

	// First try a binary op.
	auto n = binop_rule.match(ctx);
	if (n!=NULL) {
		return n;
	}

	// If that didn't work, try a primary expr
	primary_expr pe_rule();
	n = pe_rule.match(ctx);
	if (n!=NULL) {
		return n;
	}

	// Not an expression.
	return NULL;
}

}
}
