#ifndef __PROTON_FUNCTION_H__
#define __PROTON_FUNCTION_H__

#include "core-internal.h"

namespace proton {

/// The parameter signature for a Python function
jit_type_t python_fn_sig_parms[1] = { jit_type_void_ptr };

/// The function signature for a Python function
jit_type_t python_fn_sig = jit_type_create_signature(jit_abi_cdecl, jit_type_void_ptr,
		python_fn_sig_parms, 1, 1);

/// The parameter signature for a query message
jit_type_t query_fn_sig_parms[1] = { jit_type_void_ptr };

/// The function signature for a Python function
jit_type_t query_fn_sig = jit_type_create_signature(jit_abi_cdecl, jit_type_sys_bool,
		query_fn_sig_parms, 1, 1);

class function: public gc {
	friend class jitter;

	/// The proton context for this function
	context *ctx;

	/// The jit function information
	jit_function_t jit;

public:
	function(context *_ctx) :
		ctx(_ctx) {

		context::lock lck();

		jit_function_create(ctx->jit_ctx(), python_fn_sig);
	}

	jit_function_t jit_fn() {
		return jit;
	}

	/// Compiles the function - must be run before executing it.
	void compile() {
		context::lock lck();

		jit_function_compile(jit);
	}

	/// Allows you to "manually" execute the function.
	closure* apply(closure* c) {

		void * args[1] = {c};
		closure *result;

		jit_function_apply(jit, args, &result);

		return result;
	}

};

}

#endif

