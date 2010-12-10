#ifndef __PROTON_AST_H_
#define __PROTON_AST_H_

#include "core-internal.h"
#include <vector>

namespace proton {
namespace ast {

/// The base ast type - provides pieces for all ast objects.
class base: public gc {
	int32_t line_num;
	int32_t col_num;
	int32_t start_index, end_index;

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
		start_index = _index;
	}

	/// Set the last read position in the input stream
	/// for this ast.
	void set_end_pos(int _end_index) {
		end_index = _end_index;
	}

	/// Provides the line number where this ast was matched.
	inline int line() {
		return line_num;
	}

	/// Provides the column number where this ast was matched.
	inline int col() {
		return col_num;
	}

	/// Provides the input index where this ast was matched.
	inline int index() {
		return start_index;
	}

	/// Provides the input index where the match for this ast stopped.
	inline int end_index() {
		return end_index;
	}

	/// Set the ast which is a parent to this ast.
	void set_parent(base* _parent) {
		parent = _parent;
	}
};

typedef std::vector<base*, gc_allocator<base*>> ast_list;

class ident: public base {
	string name;
public:
	ident(string _name, int _line, int _col) :
	base(_line, _col), name(_name) {
	}
};

class add: public base {
	base* left;
	base* right;
public:
	add() {}

	add(base* l, base* r) :
	left(l), right(r) {
		l->set_parent(this);
		r->set_parent(this);
	}
};

}
}

#endif /* __PROTON_AST_H_ */
