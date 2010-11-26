#ifndef PROTO_INTEGER_H_
#define PROTO_INTEGER_H_

#include "core-internal.h"
#include <gmp.h>

namespace proto {

class integer: public gc {
	mpz_t value;
public:

	integer() {
		mpz_init(value);
	}

	integer(proton::int32 v) {
		mpz_init_set_si(value, v);
	}

	integer(proton::int64 v) {
		mpz_init_set_si(value, v);
	}

	integer(proton::uint32 v) {
		mpz_init_set_ui(value, v);
	}

	integer(proton::uint64 v) {
		mpz_init_set_ui(value, v);
	}

	~integer() {
		mpz_clear(value);

	}

};

}

#endif /* INTEGER_H_ */
