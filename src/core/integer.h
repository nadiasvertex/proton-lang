#ifndef PROTO_INTEGER_H_
#define PROTO_INTEGER_H_

#include <gmp.h>

#include "core-internal.h"
#include "number.h"

namespace proton {

class integer: public number {
	mpz_t value;
public:

	/// Should be used when a zero integer is desired.
	static integer *zero;

	integer() :
		number(type::py_int) {
		mpz_init(value);
	}

	integer(proton::int32 v) :
		number(type::py_int) {
		mpz_init_set_si(value, v);
	}

	integer(proton::int64 v) :
		number(type::py_int) {
		mpz_init_set_si(value, v);
	}

	integer(proton::uint32 v) :
		number(type::py_int) {
		mpz_init_set_ui(value, v);
	}

	integer(proton::uint64 v) :
		number(type::py_int) {
		mpz_init_set_ui(value, v);
	}

	~integer() {
		mpz_clear(value);

	}

	int64 get_int64() {
		return mpz_get_si(value);
	}

	uint64 get_uint64() {
		return mpz_get_ui(value);
	}

	//==-------------------------------------------------------------------==/
	// Numeric Methods

	virtual integer* add(integer* r) {
		auto result = new integer();

		mpz_add(result->value, this->value, r->value);

		return result;
	}

	virtual object* add(object* r) {
		if (r->is_type(type::py_int)) {
			return add(static_cast<integer*>(r));
		}

		throw new type_error();

	}




};

/// Assign this to its one and only value.
integer* integer::zero = new integer();

}

#endif /* INTEGER_H_ */
