#ifndef SINGLETONS_H_
#define SINGLETONS_H_

#include "object.h"
#include "type.h"
#include "integer.h"

namespace proton {

type* type::none = new type(UNICODE_STRING_SIMPLE("NoneType"));
type* type::not_implemented = new type(UNICODE_STRING_SIMPLE("NotImplementedType"));

type* type::list = new type(UNICODE_STRING_SIMPLE("list"));
type* type::dict = new type(UNICODE_STRING_SIMPLE("dict"));
type* type::set = new type(UNICODE_STRING_SIMPLE("set"));
type* type::tuple = new type(UNICODE_STRING_SIMPLE("tuple"));

type* type::function = new type(UNICODE_STRING_SIMPLE("function"));

type* type::py_int = new type(UNICODE_STRING_SIMPLE("int"));
type* type::py_bool = new type(UNICODE_STRING_SIMPLE("bool"));
type* type::py_float = new type(UNICODE_STRING_SIMPLE("float"));
type* type::py_complex = new type(UNICODE_STRING_SIMPLE("complex"));
type* type::py_str = new type(UNICODE_STRING_SIMPLE("str"));

type* type::py_type = new type(UNICODE_STRING_SIMPLE("type"));
type* type::py_namespace = new type(UNICODE_STRING_SIMPLE("namespace"));

/// The one and only None object.
object* object::none = new object(type::none);

/// The one and only NotImplemented object.
object* object::not_implemented = new object(type::not_implemented);

/// Assign this to its one and only value.
integer* integer::zero = new integer();

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

/// The function signature for a binary operation
jit_type_t binary_fn_sig = jit_type_create_signature(jit_abi_cdecl, jit_type_void_ptr,
		binary_fn_sig_parms, 2, 1);

/// The parameter signature for a store message
jit_type_t store_fn_sig_parms[3] = { jit_type_void_ptr, jit_type_void_ptr, jit_type_void_ptr };

/// The function signature for a store message
jit_type_t store_fn_sig = jit_type_create_signature(jit_abi_cdecl, jit_type_void,
		store_fn_sig_parms, 3, 1);

}

#endif /* SINGLETONS_H_ */
