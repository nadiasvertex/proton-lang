#ifndef __PROTON_JITTER_H_
#define __PROTON_JITTER_H_

#include <string>

#include "core-internal.h"
#include "function.h"

#include "protocol.h"

namespace proton {

struct debuginfo {
	int line;
	int col;
	std::wstring filename;
};

class jitter : public gc {
	function *f;
public:
	jitter(function *_f) :
		f(_f) {
	}

	/// Provides locking routines that avoid corruption of the jit context.
	/// Also disables garbage collection so that finalization routines are
	/// not run until the build is finished.
	void start() {
		GC_disable();
		f->ctx->build_start();
	}

	/// Unlocks the jit context and re-enables garbage collection.
	void end() {
		f->ctx->build_end();
		GC_enable();
	}

	/// Generates a constant value that holds a pointer.   This can be used as
	/// input to other instructions.
	jit_value_t ld_constant_pointer(void *p) {
		return jit_value_create_nint_constant(f->jit, jit_type_void_ptr, (jit_nint)p);
	}

	/// Sends an "is_sequence" message.  The message is sent to the
	/// object represented by the jit value type in o. Throws an
	/// exception if the object is _not_ a sequence type.
	jit_value_t is_sequence(jit_value_t o) {
		jit_value_t args[1] = { o };

		auto result = jit_insn_call_native(f->jit, "proto_is_sequence",
				(void*)proto_is_sequence_type, query_fn_sig, args, 1, 0);

	}

};

}

#endif /* JITTER_H_ */
