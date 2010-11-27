#ifndef __PROTON_CLOSURE_H_
#define __PROTON_CLOSURE_H_

#include "core-internal.h"
#include "object.h"

#include <vector>
#include <map>
#include <string>

namespace proton {

/// This is the object that we pass to functions, and that functions pass back to us. It
/// contains all of the input and output values, as well as a value that indicates where
/// we should go next.
class closure: public gc {

	/// The positional input parameters
	std::vector<object*, object_allocator> positional;

	/// The keyword parameters.
	std::map<std::wstring, object *> keyword;

public:
	void append(object *o) {
		positional.push_back(o);
	}

	void assign(std::wstring n, object *o) {
		keyword[n] = o;
	}

	object*  at(uint32 idx) {
		return positional[idx];
	}


};

}

#endif /* CLOSURE_H_ */
