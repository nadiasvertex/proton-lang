#ifndef __PROTON_AST_H_
#define __PROTON_AST_H_

#include "core-internal.h"
#include <vector>

namespace proton {
namespace ast {

/// The base ast type - provides pieces for all ast objects.
class base: public gc {
	int32_t line;
	int32_t col;

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
	base(int _line, int _col) :
		line(_line), col(_col) {
	}

	void set_pos(int _line, int _col) {
		line = _line;
		col = _col;
	}

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
