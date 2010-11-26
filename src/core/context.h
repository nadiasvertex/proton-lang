#ifndef __PROTON_CONTEXT_H__
#define __PROTON_CONTEXT_H__

#include "core-internal.h"

namespace proton {

class context: public gc {

	/// The jit context for this interpreter context.
	jit_context_t jit;

public:
	context() :
		jit(jit_context_create()) {
	}

	~context() {
		jit_context_destroy(jit);
	}

	jit_context_t jit_ctx() {
		return jit;
	}

	void build_start() {
		::jit_context_build_start(jit);
	}

	void build_end() {
		::jit_context_build_end(jit);
	}

	// Handles automatic locking and unlocking of the context,
	// which is needed in some situations - like building a
	// new function.
	class lock {
		context *ctx;
	public:
		lock(context *_ctx) :
			ctx(_ctx) {
			ctx->build_start();
		}

		~lock() {
			ctx->build_end();
		}
	};

};

}

#endif
