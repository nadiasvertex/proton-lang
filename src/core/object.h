#ifndef PROTON_OBJECT_H_
#define PROTON_OBJECT_H_

#include <functional>
#include <string>
#include <map>

#include "core-internal.h"

namespace proton {

class type;

/// The object class is the root object for the Python hierarchy. All
/// objects provide a minimal subset of functionality.
class object {
	type* otype;
public:
	object(type* t) :
		otype(t) {
	}

	uint64 id() {
		return reinterpret_cast<uint64> (this);
	}

	/// Returns true if this object is the same as the other type.
	bool is_type(type* other) {
		return otype == other;
	}

	/// Returns true if the object is a sequence.
	virtual bool is_sequence() {
		return false;
	}

	/// Returns true if the object is a number.
	virtual bool is_number() {
		return false;
	}

	static object *none;
};

#include "type.h"

/// The one and only None object.
object* object::none = new object(type::none);

/// The garbage collecting allocator for objects, used
/// with the STL allocator classes.
typedef gc_allocator<object *> object_allocator;

typedef gc_allocator<std::pair<std::wstring, object*>> named_object_allocator;

typedef std::map<std::wstring, object *, std::less<std::wstring>,named_object_allocator> object_map;

typedef std::vector<object*, object_allocator> object_vector;
}

#endif /* OBJECT_H_ */
