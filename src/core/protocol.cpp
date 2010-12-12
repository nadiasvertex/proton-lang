#include "proton.h"

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
	try {
		return f->bind_closure_to_namespace(c);
	} catch (proton::exception *e) {
		jit_exception_throw(e);
	}

}

/// Loads an object from a namespace.
proton::object* proto_load(proton::wstring* name, proton::name_space* ns) {
	auto o = ns->get(*name);

	if (o==proton::object::none) {
		jit_exception_throw(new proton::name_error());
	}

	return o;
}

/// Stores an object into a namespace.
void proto_store(proton::wstring* name, proton::object* o, proton::name_space* ns) {
	ns->set(*name, o);
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
