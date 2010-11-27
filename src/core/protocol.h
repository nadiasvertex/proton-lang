#ifndef PROTON_PROTOCOL_H_
#define PROTON_PROTOCOL_H_

/*
 * The protocol is the external representation of the Python system that can
 * be used by other programs or languages to interact with the runtime.  This
 * is *also* the API that the JIT uses to interact with the runtime, so it
 * is very complete.
 *
 */

extern "C" {

//===---------------------------------------------------------------------====//
// Unary protocol operations


/// Returns the length of the object, if the object
/// implements the sequence protocol.  Otherwise,
/// returns 0.
proton::object* proto_len(proton::object* o) {
	if (o->is_sequence()) {

		auto seq = (proton::sequence*) o;

		return new proton::integer(seq->len());
	}

	return proton::integer::zero;
}

//===---------------------------------------------------------------------====//
// Conversion protocol operations

proton::object* proto_new_int(proton::object *o, proton::int32 v) {
	return new proton::integer(v);
}

proton::name_space* proto_bind_namespace(proton::closure *c, proton::function *f) {
	return f->bind_closure_to_namespace(c);
}


//===---------------------------------------------------------------------====//
// Query protocol operations

bool proto_is_sequence_type(proton::object *o) {
	if (!o->is_sequence())
	{
		jit_exception_throw(new proton::exception());
		return false;
	}

	return true;
}

bool proto_is_number_type(proton::object *o) {
	return o->is_number();
}

}

#endif /* PROTOCOL_H_ */
