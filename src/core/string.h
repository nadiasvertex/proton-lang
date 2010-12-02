#ifndef __PROTON_STRING_H_
#define __PROTON_STRING_H_

#include "core-internal.h"
#include "object.h"
#include "type.h"

namespace proton {

class string: public object {
	wstring value;
public:
	string() :
		object(type::py_str) {
	}

	string(const wstring &s) :
		object(type::py_str), value(s) {
	}

	//==-------------------------------------------------------------------==/
	// Basic Methods

	/// Return the "official" string representation of this object.  This
	/// should look like a valid Python expression if at all possible.
	/// Must return a string object.
	virtual object* repr() {
		wstring r;

		r.append(UNICODE_STRING("'", 1));
		r.append(value);
		r.append(UNICODE_STRING("'", 1));

		return new string(r);
	}

	/// Computes an "informal" string representation.  Does not have to be
	/// valid Python, can be a more convenient or concise representation.
	/// Must return a string object.
	virtual object* str() {
		return this;
	}

	inline int32_t get_length() {
		return value.length();
	}

	internal_string to_local_str() const;
	internal_string to_escaped_local_str() const;

};

}

#endif /* STRING_H_ */
