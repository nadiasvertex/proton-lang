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

class jitter {
	function *f;
public:
	jitter(function *_f) :
		f(_f) {
	}

	/// Sends an "is_sequence" message.  The message is sent to the
	/// object represented by the jit value type in o. Throws an
	/// exception if the object is _not_ a sequence type.
	jit_value_t is_sequence(jit_value_t o) {
		context::lock lck(f->ctx);

		jit_value_t args[1] = { o };

		auto result = jit_insn_call_native(f->jit, "proto_is_sequence",
				(void*)proto_is_sequence_type, query_fn_sig, args, 1, 0);

	}

};

}

#endif /* JITTER_H_ */
