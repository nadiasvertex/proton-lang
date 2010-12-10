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
	IDENTIFIER, BINOP
};

/*****************************************************************************
 * Control flow for the Parser
 *
 * There are two pieces: a rule and an ast node.  A rule knows how to match
 * a grammar element, and how to generate an ast.  It also knows how to
 * store the ast into the memo map.
 *
 * A parse occurs by matching a rule.  If the rule matches, it generates an
 * ast.  If the rule requires additional rules to match to those rules are
 * matched as well.  Once the rule matches completely the ast is memoized
 * at the root.  The rule returns this root.
 *
 * When a match occurs, the matching rule generates an ast and locks it to
 * the line, column, and index where the match started.
 */

/// The key that the parser uses to find an ast from
/// some input that may have already been matched.
typedef std::pair<rule_type, int32_t> memo_key;

/// The map type for the parse context's memo.
typedef std::map<memo_key, base::ast*, std::less<memo_key>, gc_allocator<
		memo_key>> memo_map;

class context : public gc {
	/// The current line
	int cur_line;

	/// The current column
	int cur_col;

	/// The input iterator to use.
	wstring_iterator& it;

	/// The memo
	memo_map memo;
public:
	context(wstring_iterator& _it) : cur_line(1), cur_col(1), it(_it) {}

	/// Get the current line number
	int line() { return cur_line; }

	/// Get the current column.
	int col()  { return cur_col; }

	/// Get the current glyph index.
	int index() { return it.getIndex(); }

	/// Store a node into the memo
	void store(rule_type rule_id, base::ast* node) {
		memo[std::make_pair(rule_id, node->index())] = node;
	}

	/// Load a node from the memo
	base::ast* load(rule_type rule_id, int32_t index) {
		auto it = memo.find(std::make_pair(rule_id, index));

		if (it==memo.end()) {
			return NULL;
		}

		return it->second;
	}

	/// Get the next glyph.
	wchar next() {
		auto v = it.next();
		switch(v) {
			case '\n':
			++cur_line;
			cur_col=1;
			break;

			default:
			++cur_col;
			break;
		}

		return v;
	}

	/// Return the current glyph.
	wchar current() {
		return it.current();
	}

};

class rule : public gc {
	int start_match_line;
	int start_match_col;
	int start_match_index;
	int end_match_index;

	rule_type rt;

protected:
	rule(rule_type _rt) : rt(_rt) {}

	void set_ast_pos(base::ast* node) {
		node->set_pos(start_match_line, start_match_col, start_match_index);
		node->set_end_pos(end_match_index);
	}

	void start(context& ctx) {
		start_match_line = ctx.line();
		start_match_col = ctx.col();
		start_match_index = ctx.index();
	}

	void end(context& ctx) {
		end_match_index = ctx.index();
	}

protected:
	virtual base::ast* do_match(context& ctx)=0;

public:
	base::ast* match(context& ctx) {
		/// See if we already have a memoized match.
		auto node = ctx.load(rt, ctx.index());

		/// Early out: match was already done in the past.
		if (node) {
			return node;
		}

		start(ctx);

		/// Try to match
		node = do_match();

		end(ctx);

		if (node) {
			set_ast_pos(node);
			ctx.store(rt, node);
		}

		return node;
	}
};

class identifier : public rule {
	static UnicodeSet start_pattern;
	static UnicodeSet end_pattern;
	static bool initialized;
public:
	identifier() : rule(IDENTIFIER) {
		if (!initialized) {
			initialized = true;
			UErrorCode status = U_ZERO_ERROR;

			start_pattern.applyPattern("[a-zA-Z_]", status);
			end_pattern.applyPattern("[a-zA-Z0-9_]", status);
		}
	}

	virtual base::ast* do_match(context& ctx) {



		return new
	}
};


} // end parser namespace
} // end proton namespace

#endif /* __PROTON_RULE_H_ */
