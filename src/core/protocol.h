#ifndef PROTON_PROTOCOL_H_
#define PROTON_PROTOCOL_H_

#include <typeinfo>

/*
 * The protocol is the external representation of the Python system that can
 * be used by other programs or languages to interact with the runtime.  This
 * is *also* the API that the JIT uses to interact with the runtime, so it
 * is very complete.
 *
 */


extern "C" {

proton::object* proto_len(proton::object *o) {
	if (typeid(*o) == typeid(proton::sequence)) {

		auto seq = (proton::sequence*)o;
		auto value = seq->len();

	}

	return 0;
}

}

#endif /* PROTOCOL_H_ */
