#ifndef __PROTON_FUNCTION_H__
#define __PROTON_FUNCTION_H__

#include "core-internal.h"
#include "namespace.h"
#include "type.h"
#include "list.h"
#include "exception.h"

#include <string>
#include <vector>

#include <stdio.h>
#include <jit/jit-dump.h>

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

/// The parameter signature for a binary message
jit_type_t binary_fn_sig_parms[2] = { jit_type_void_ptr, jit_type_void_ptr };

/// The function signature for a Python function
jit_type_t binary_fn_sig = jit_type_create_signature(jit_abi_cdecl, jit_type_void_ptr,
		binary_fn_sig_parms, 2, 1);


class function: public object {
	friend class jitter;

	/// The proton context for this function
	context *ctx;

	/// The jit function information
	jit_function_t jit;

	/// The names of the positional parameters for this function.
	std::vector<std::wstring, gc_allocator<std::wstring>> arguments;

	/// A method is a member of a class
	bool is_method;

	/// Non-empty if this function accepts varargs.
	std::wstring vararg_name;

	/// Non-empty if this function accepts keyword arguments.
	std::wstring kwarg_name;

public:
	function(context *_ctx) : object(type::function),
		ctx(_ctx) {

		context::lock lck();

		jit = jit_function_create(ctx->jit_ctx(), python_fn_sig);
	}

	jit_function_t jit_fn() {
		return jit;
	}

	/// Adds an argument name to the function.
	void add_arg_name(std::wstring name) {
		arguments.push_back(name);
	}

	void add_arg_names(std::initializer_list<std::wstring> names) {
		arguments.insert(arguments.begin(), names.begin(), names.end());
	}

	void set_vararg_name(std::wstring _vararg_name) {
		vararg_name = _vararg_name;
	}

	void set_kwarg_name(std::wstring _kwarg_name) {
		kwarg_name = _kwarg_name;
	}

	/// Compiles the function - must be run before executing it.
	void compile() {
		context::lock lck();

		jit_function_compile(jit);
	}

	/// Allows you to "manually" execute the function.
	closure* apply(closure* c) {

		void * args[1] = {&c};
		closure *result;

		jit_function_apply(jit, args, &result);

		return result;
	}

	/// Takes a closure that has been passed to a function
	/// and binds the closure's data to a namespace created
	/// specifically for this function call.
	name_space* bind_closure_to_namespace(closure *c) {
		auto ns = new name_space();

		if (vararg_name.size()==0 && c->positional.size() > arguments.size()){
			throw new argument_error(this, arguments.size(), c->positional.size());
		}

		auto pos = c->positional.begin();
		for(auto idx=0; idx<c->positional.size(); ++idx, ++pos) {
			if (idx<arguments.size()) {
				ns->set(arguments[idx], *pos);
			}
			else {
				// Add elements to the varargs name.
				auto va = new list();
				va->extend(pos, c->positional.end());

				// Set the vararg name into the namespace.
				ns->set(vararg_name, va);
				break;
			}
		}

		if (kwarg_name.size()) {
			auto kwargs = new name_space();
			kwargs->insert(c->keyword.begin(), c->keyword.end());

			ns->set(kwarg_name, kwargs);
		}

		return ns;
	}

	void dump() {
		jit_dump_function(stdout, jit, "python_func");
	}


};

}

#endif

