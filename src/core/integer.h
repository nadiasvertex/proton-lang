#ifndef PROTO_INTEGER_H_
#define PROTO_INTEGER_H_

#include <gmp.h>

#include "core-internal.h"
#include "number.h"
#include "string.h"

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

	integer(const integer& o) : number(type::py_int) {
		mpz_init_set(value, o.value);
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

	integer(const string& s, int base=10) :
		number(type::py_int) {
		auto str = s.to_local_str().c_str();
		auto result = mpz_init_set_str(value, str, base);
		if (result==0) return;
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
	// Basic Methods

	/// Return the "official" string representation of this object.  This
	/// should look like a valid Python expression if at all possible.
	/// Must return a string object.
	virtual object* repr() {
		return new string(UNICODE_STRING_SIMPLE(mpz_get_str(NULL, 10, value)));
	}

	//==-------------------------------------------------------------------==/
	// Numeric Methods

	integer* add(integer* r) {
		auto result = new integer();

		mpz_add(result->value, this->value, r->value);

		return result;
	}

	virtual object* add(object* r) {
		if (r->is_type(type::py_int)) {
			return add(static_cast<integer*> (r));
		}

		throw new type_error();
	}

	integer* sub(integer* r) {
		auto result = new integer();

		mpz_sub(result->value, this->value, r->value);

		return result;
	}

	virtual object* sub(object* r) {
		if (r->is_type(type::py_int)) {
			return sub(static_cast<integer*> (r));
		}

		throw new type_error();
	}

	integer* mul(integer* r) {
		auto result = new integer();

		mpz_mul(result->value, this->value, r->value);

		return result;
	}

	virtual object* mul(object* r) {
		if (r->is_type(type::py_int)) {
			return mul(static_cast<integer*> (r));
		}

		throw new type_error();
	}

	integer* truediv(integer* r) {
		auto result = new integer();

		mpz_fdiv_q(result->value, this->value, r->value);

		return result;
	}

	virtual object* truediv(object* r) {
		if (r->is_type(type::py_int)) {
			return truediv(static_cast<integer*> (r));
		}

		throw new type_error();
	}

	integer* floordiv(integer* r) {
		auto result = new integer();

		mpz_fdiv_q(result->value, this->value, r->value);

		return result;
	}

	virtual object* floordiv(object* r) {
		if (r->is_type(type::py_int)) {
			return floordiv(static_cast<integer*> (r));
		}

		throw new type_error();
	}

	integer* mod(integer* r) {
		auto result = new integer();

		mpz_mod(result->value, this->value, r->value);

		return result;
	}

	virtual object* mod(object* r) {
		if (r->is_type(type::py_int)) {
			return mod(static_cast<integer*> (r));
		}

		throw new type_error();
	}

	integer* rshift(integer* r) {
		auto result = new integer();

		mpz_tdiv_q_2exp(result->value, this->value, r->get_uint64());

		return result;
	}

	virtual object* rshift(object* r) {
		if (r->is_type(type::py_int)) {
			return rshift(static_cast<integer*> (r));
		}

		throw new type_error();
	}

	integer* lshift(integer* r) {
		auto result = new integer();

		mpz_mul_2exp(result->value, this->value, r->get_uint64());

		return result;
	}

	virtual object* lshift(object* r) {
		if (r->is_type(type::py_int)) {
			return lshift(static_cast<integer*> (r));
		}

		throw new type_error();
	}

	integer* bitwise_and(integer* r) {
		auto result = new integer();

		mpz_and(result->value, this->value, r->value);

		return result;
	}

	virtual object* bitwise_and(object* r) {
		if (r->is_type(type::py_int)) {
			return bitwise_and(static_cast<integer*> (r));
		}

		throw new type_error();
	}

	integer* bitwise_or(integer* r) {
		auto result = new integer();

		mpz_ior(result->value, this->value, r->value);

		return result;
	}

	virtual object* bitwise_or(object* r) {
		if (r->is_type(type::py_int)) {
			return bitwise_or(static_cast<integer*> (r));
		}

		throw new type_error();
	}

	integer* bitwise_xor(integer* r) {
		auto result = new integer();

		mpz_xor(result->value, this->value, r->value);

		return result;
	}

	virtual object* bitwise_xor(object* r) {
		if (r->is_type(type::py_int)) {
			return bitwise_xor(static_cast<integer*> (r));
		}

		throw new type_error();
	}
};

}

#endif /* INTEGER_H_ */
