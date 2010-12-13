#ifndef __PROTON_AST_H_
#define __PROTON_AST_H_

#include "core-internal.h"
#include "integer.h"

#include <vector>

namespace proton {

class jitter;

namespace ast {

/// The base ast type - provides pieces for all ast objects.
class base: public gc {
	int32_t line_num;
	int32_t col_num;
	int32_t the_start_index, the_end_index;

protected:
	/// The parent ast, if one exists.
	base* parent;

	/// The next alternative ast tree, if one exists.
	base* alt;
public:

	base() :
		parent(0) {
	}
	base(base* _parent) :
		parent(_parent) {
	}

	/// Set the position in the input stream where this
	/// ast was matched.
	void set_pos(int _line, int _col, int _index) {
		line_num = _line;
		col_num = _col;
		the_start_index = _index;
	}

	/// Set the last read position in the input stream
	/// for this ast.
	void set_end_pos(int _end_index) {
		the_end_index = _end_index;
	}

	/// Provides the line number where this ast was matched.
	inline int line() const {
		return line_num;
	}

	/// Provides the column number where this ast was matched.
	inline int col() const {
		return col_num;
	}

	/// Provides the input index where this ast was matched.
	inline int start_index() const {
		return the_start_index;
	}

	/// Provides the input index where the match for this ast stopped.
	inline int end_index() const {
		return the_end_index;
	}

	/// Set the ast which is a parent to this ast.
	void set_parent(base* _parent) {
		parent = _parent;
	}

	/// Compile this node into the jit.
	virtual jit_value_t compile(jitter* j)=0;
};

typedef std::vector<base*, gc_allocator<base*>> ast_list;

class ident: public base {
	string name;
public:
	ident(string _name) : name(_name) {
	}

	/// Compile this node into the jit.
	virtual jit_value_t compile(jitter* j);
};

class integer: public base {
	proton::integer the_value;
public:
	integer(proton::integer _value) : the_value(_value) {
	}

	proton::integer value() { return the_value; }

	/// Compile this node into the jit.
	virtual jit_value_t compile(jitter* j);
};

class binop: public base {
	wchar op;
	base* left;
	base* right;

	static std::map<wchar, int> prec_map;
	static bool initialized;

	void initialize() {
		if (!initialized) {
			initialized = true;

			prec_map['p'] = 70; // power

			prec_map['*'] = 60;
			prec_map['/'] = 60;
			prec_map['%'] = 60;

			prec_map['+'] = 50;
			prec_map['-'] = 50;

			prec_map['l'] = 40; // left shift
			prec_map['r'] = 40; // right shift

			prec_map['|'] = 30;
			prec_map['&'] = 30;
			prec_map['^'] = 30;
		}
	}

	/// To properly solve order of operations, we have to adjust the
	/// parse tree.  This operation makes higher precedence operations
	/// deeper in the tree (so they happen first.)
	void rotate(binop* r) {
		/* Consider 5*6+2.  The parser will generate a tree that looks like
		 * this:
		 *
		 *                 *
		 *                / \
		 *               5   +
		 *                  / \
		 *                 6   2
		 *
		 *  That's clearly wrong, since the addition will be performed first.  What we want to see is:
		 *
		 *                 +
		 *                / \
		 *               *   2
		 *              / \
		 *             5   6
		 *
		 *  This will result in the correct behavior in a depth-first translation system.  So we rotate
		 *  the '+' and '*' nodes with respect to each other.
		 */

		auto tmp_r = r->right;
		auto tmp_op = r->op;

		r->op=op;
		r->right=r->left;
		r->left = left;

		op = tmp_op;
		left = r;
		right = tmp_r;
	}

public:
	binop() {initialize();}

	binop(wchar _op, base* l, base* r) : op(_op) {
		initialize();
		set_left(l);
		set_right(r);
	}

	void set_left(base* l) {
		left = l;
		if (l) l->set_parent(this);
	}

	void set_right(base *r) {
		right = r;
		r->set_parent(this);
	}

	void check_precedence() {
		auto rb = dynamic_cast<binop*>(right);

		if (right && rb)  {
			// Figure out if we need to adjust the association depending on the
			// operation.
			if (prec_map[op] > prec_map[rb->op]) {
				rotate(rb);
			}
		}

	}

	/// Compile this node into the jit.
	virtual jit_value_t compile(jitter* j);
};

}
}

#endif /* __PROTON_AST_H_ */
