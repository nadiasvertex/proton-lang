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

proton::object* proto_len(proton::object* o);

//===---------------------------------------------------------------------====//
// Conversion protocol operations

proton::object* proto_new_int(proton::object *o, proton::int32 v);

proton::name_space* proto_bind_namespace(proton::closure *c, proton::function *f);
proton::object* proto_load(proton::wstring* name, proton::name_space* ns);
void proto_store(proton::wstring* name, proton::object* o, proton::name_space* ns);

//===---------------------------------------------------------------------====//
// Binary protocol operations

#include "proto-binops.h"

//===---------------------------------------------------------------------====//
// Query protocol operations

bool proto_is_sequence_type(proton::object *o);
bool proto_is_number_type(proton::object *o);

} // end extern

#endif /* PROTOCOL_H_ */
