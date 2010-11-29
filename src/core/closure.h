#ifndef __PROTON_CLOSURE_H_
#define __PROTON_CLOSURE_H_

#include "core-internal.h"
#include "object.h"

#include <vector>

namespace proton {

/// This is the object that we pass to functions, and that functions pass back to us. It
/// contains all of the input and output values, as well as a value that indicates where
/// we should go next.
class closure: public gc {
public:
	/// The positional input parameters
	object_vector positional;

	/// The keyword parameters.
	object_map keyword;

	/// If this is a call to a member function, we need to bind self.
	/// The parent field contains the value that would be bound to self.
	object* parent;

	closure() {}

	closure(object_vector _positional_parameters) {
		positional.clear();
		positional.insert(positional.begin(),  _positional_parameters.begin(), _positional_parameters.end());
	}
};

}

#endif /* CLOSURE_H_ */
