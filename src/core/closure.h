#ifndef __PROTON_CLOSURE_H_
#define __PROTON_CLOSURE_H_

#include "core-internal.h"
#include "object.h"

#include <list>
#include <map>
#include <string>

namespace proton {

/// This is the object that we pass to functions, and that functions pass back to us. It
/// contains all of the input and output values, as well as a value that indicates where
/// we should go next.
class closure: public gc {

	/// The positional input paramters
	std::list<object*, object_allocator> positional;

	/// The extra input parameters.
	std::list<object*, object_allocator> varargs;

	/// The keyword parameters.
	std::map<std::wstring, object *, object_allocator> keyword;

public:

};

}

#endif /* CLOSURE_H_ */
