#ifndef __PROTON_RULE_H_
#define __PROTON_RULE_H_

#include "core-internal.h"
#include "string.h"
#include "ast.h"

#include "unicode/uniset.h"

#include <vector>
#include <map>
#include <ostream>

namespace proton {
namespace parser {

enum rule_type {
	IDENTIFIER, ADD
};

/// The key for memos.
typedef std::pair<rule_type, int32_t> memo_key;

/// The actual map for memos
typedef std::map<memo_key, ast::base*, std::less<memo_key>, gc_allocator<std::pair<memo_key, ast::base*>>> memo;

/// The parser context, keeps a reference to where we are in the
/// input stream, as well as the parser memo.
class context : public gc {
	int line_num;
	int col_num;

	wstring_iterator* it;

	memo *m;
public:
	context(wstring_iterator* _it):line_num(1), col_num(1), it(_it) {}

	context clone() {
		context n(*this);
		n.it = (wstring_iterator*)it->clone();

		return n;
	}

	inline int line() { return line_num; }
	inline int col()  { return col_num; }
	inline int index() { return it->getIndex(); }

	/// Advance the iterator
	inline wchar next() {
		++col_num;

		return it->next();
	}

	/// Get the current character
	inline wchar current() {
		return it->current();
	}

	/// Bump the row indicator.
	void newline() {
		++line_num;
	}
};

enum rule_suffix_type {
	ONE_OR_NONE, ONE_OR_MORE, ZERO_OR_MORE
};

/// A single matching rule
class rule: public gc {
	rule_suffix_type suffix;

protected:
	int match_start_line;
	int match_end_line;

	int match_start_col;
	int match_end_col;

	int match_start_index;
	int match_end_index;

protected:
	std::string name;

public:
	rule() {
	}

	rule(const std::string& _name) :
		name(_name) {
	}

	rule(rule_suffix_type _suffix) :
		suffix(_suffix) {
	}

	void set_name(const std::string& _name) {
		name = _name;
	}

	void set_match_start(context& ctx) {
		match_start_line = ctx.line();
		match_start_col = ctx.col();
		match_start_index = ctx.index();
	}

	void set_match_end(context& ctx) {
		match_end_line = ctx.line();
		match_end_col = ctx.col();
		match_end_index = ctx.index();
	}

	virtual void dump(std::ostream& s) const {
		s << name;
	}

	virtual ast::base* to_ast() {
		return 0;
	}

	virtual uint64_t size() {
		return 0;
	}

	virtual bool match(context& ctx) {
		return false;
	}

};

class literal_rule: public rule {
	string to_match;
public:
	literal_rule(const string& _to_match) :
		to_match(_to_match) {
	}

	literal_rule(const char* literal) :
		to_match(literal) {
	}

	virtual void dump(std::ostream& s) const {
		s << "'" << to_match.to_escaped_local_str() << "'";
	}

	void set_literal(string s) {
		to_match = s;
	}

	virtual uint64_t size() {
		return to_match.get_length();
	}

	virtual bool match(context& ctx) {
		auto at = to_match.iterator();

		set_match_start(ctx);

		for (; at->getIndex() != at->endIndex(); at->next(), ctx.next()) {
			if (at->current() != ctx.current()) {
				return false;
			}
		}

		set_match_end(ctx);

		return true;
	}
};

class identifier : public rule {
	wstring value;

	UnicodeSet start_pattern, end_pattern;
public:
	identifier() : rule("identifier") {
		UErrorCode err = U_ZERO_ERROR;

		start_pattern.applyPattern("[a-zA-Z_]", err);
		end_pattern.applyPattern("[a-zA-Z0-9_]", err);
	}

	virtual uint64_t size() {
		return value.length();
	}

	virtual ast::base* to_ast() {
		return new ast::ident(value, match_start_line, match_start_col);
	}

	virtual bool match(context& ctx) {
		if (!start_pattern.contains(ctx.current())) {
			return false;
		}

		set_match_start(ctx);

		do {
			value.append(ctx.current());
			ctx.next();
		} while (end_pattern.contains(ctx.current()));

		set_match_end(ctx);

		return true;
	}
};

class binop : public rule {
	UnicodeSet pattern;

	wchar op;
public:
	binop() : rule("binop") {
		UErrorCode err = U_ZERO_ERROR;

		pattern.applyPattern("[+-*/^&|]", err);
	}

	virtual uint64_t size() {
		return 1;
	}

	virtual ast::base* to_ast() {
		switch(op) {
		case '+' :
			return new ast::add();
		}
	}

	virtual bool match(context& ctx) {

		set_match_start(ctx);


		if (!pattern.contains(ctx.current())) {
			return false;
		}

		op = ctx.current();
		ctx.next();

		set_match_end(ctx);

		return true;
	}
};


class newline: public literal_rule {
public:
	newline() :
		literal_rule("\n") {
	}

	virtual bool match(context& ctx) {
		if (literal_rule::match(ctx)) {
			ctx.newline();
			return true;
		}

		return false;
	}
};

class plus: public literal_rule {
public:
	plus() :
		literal_rule("+") {
	}
};

class expr: public rule {
public:
	virtual bool match(context &ctx);
};


} // end parser namespace
} // end proton namespace

#endif /* __PROTON_RULE_H_ */
