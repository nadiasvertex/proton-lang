#ifndef PROTON_OBJECT_H_
#define PROTON_OBJECT_H_

#include "core-internal.h"

namespace proton {

/// The object class is the root object for the Python hierarchy. All
/// objects provide a minimal subset of functionality.
class object {

public:
	uint64 id() {
		return reinterpret_cast<uint64> (this);
	}

	/// Returns true if the object is a sequence.
	virtual bool is_sequence() {
		return false;
	}

	/// Returns true if the object is a number.
	virtual bool is_number() {
		return false;
	}

};

// The garbage collecting allocator for objects, used
// with the STL allocator classes.
typedef gc_allocator<object *> object_allocator;

}

#endif /* OBJECT_H_ */
