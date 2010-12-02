#ifndef PROTON_OBJECT_H_
#define PROTON_OBJECT_H_

#include <functional>
#include <string>
#include <sstream>
#include <map>
#include <vector>

#include "core-internal.h"
#include "exception.h"

namespace proton {

/// Unicode string type
typedef UnicodeString wstring;

// Unicode string iterator type;
typedef StringCharacterIterator wstring_iterator;

/// Garbage collected, 8-bit string for creating string literals in some internal APIs
typedef std::basic_string<char, std::char_traits<char>, gc_allocator<char>> internal_string;

/// Garbage collected, 8-bit string stream for createing string literals in some internal APIs
typedef std::basic_stringstream<char, std::char_traits<char>, gc_allocator<char>> internal_stringstream;


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

	//==-------------------------------------------------------------------==/
	// Basic Methods

	/// Return the "official" string representation of this object.  This
	/// should look like a valid Python expression if at all possible.
	/// Must return a string object.
	virtual object* repr();

	/// Computes an "informal" string representation.  Does not have to be
	/// valid Python, can be a more convenient or concise representation.
	/// Must return a string object.
	virtual object* str() {
		return repr();
	}

	//==-------------------------------------------------------------------==/
	// Numeric Methods

	virtual object* add(object* other) {
		return not_implemented;
	}

	virtual object* sub(object* other) {
		return not_implemented;
	}

	virtual object* mul(object* other) {
		return not_implemented;
	}

	virtual object* truediv(object* other) {
		return not_implemented;
	}

	virtual object* floordiv(object* other) {
		return not_implemented;
	}

	virtual object* mod(object* other) {
		return not_implemented;
	}

	virtual object* divmod(object* other) {
		return not_implemented;
	}

	virtual object* pow(object* other) {
		return not_implemented;
	}

	virtual object* lshift(object* other) {
		return not_implemented;
	}

	virtual object* rshift(object* other) {
		return not_implemented;
	}

	virtual object* bitwise_and(object* other) {
		return not_implemented;
	}

	virtual object* bitwise_or(object* other) {
		return not_implemented;
	}

	virtual object* bitwise_xor(object* other) {
		return not_implemented;
	}

	virtual object* radd(object* other) {
		return not_implemented;
	}

	virtual object* rsub(object* other) {
		return not_implemented;
	}

	virtual object* rmul(object* other) {
		return not_implemented;
	}

	virtual object* rtruediv(object* other) {
		return not_implemented;
	}

	virtual object* rfloordiv(object* other) {
		return not_implemented;
	}

	virtual object* rmod(object* other) {
		return not_implemented;
	}

	virtual object* rdivmod(object* other) {
		return not_implemented;
	}

	virtual object* rpow(object* other) {
		return not_implemented;
	}

	virtual object* rlshift(object* other) {
		return not_implemented;
	}

	virtual object* rrshift(object* other) {
		return not_implemented;
	}

	virtual object* rbitwise_and(object* other) {
		return not_implemented;
	}

	virtual object* rbitwise_or(object* other) {
		return not_implemented;
	}

	virtual object* rbitwise_xor(object* other) {
		return not_implemented;
	}

	virtual object* iadd(object* other) {
		return not_implemented;
	}

	virtual object* isub(object* other) {
		return not_implemented;
	}

	virtual object* imul(object* other) {
		return not_implemented;
	}

	virtual object* itruediv(object* other) {
		return not_implemented;
	}

	virtual object* ifloordiv(object* other) {
		return not_implemented;
	}

	virtual object* imod(object* other) {
		return not_implemented;
	}

	virtual object* ipow(object* other) {
		return not_implemented;
	}

	virtual object* ilshift(object* other) {
		return not_implemented;
	}

	virtual object* irshift(object* other) {
		return not_implemented;
	}

	virtual object* ibitwise_and(object* other) {
		return not_implemented;
	}

	virtual object* ibitwise_or(object* other) {
		return not_implemented;
	}

	virtual object* ibitwise_xor(object* other) {
		return not_implemented;
	}

	virtual object* neg() {
		return not_implemented;
	}

	virtual object* pos() {
		return not_implemented;
	}

	virtual object* abs() {
		return not_implemented;
	}

	virtual object* invert() {
		return not_implemented;
	}

	virtual object* to_complex() {
		return not_implemented;
	}

	virtual object* to_int() {
		return not_implemented;
	}

	virtual object* to_float() {
		return not_implemented;
	}

	virtual object* to_rounded_int() {
		return not_implemented;
	}

	static object *none;

	static object *not_implemented;
};

/// The garbage collecting allocator for objects, used
/// with the STL allocator classes.
typedef gc_allocator<object *> object_allocator;

/// Garbage collecting allocator for object maps, designed for the
/// STL map container.
typedef gc_allocator<std::pair<wstring, object*>> named_object_allocator;

/// Garbage collected map container.
typedef std::map<wstring, object *, std::less<wstring>,named_object_allocator> object_map;

/// Garbage collected vector container.
typedef std::vector<object*, object_allocator> object_vector;

}

#endif /* OBJECT_H_ */
