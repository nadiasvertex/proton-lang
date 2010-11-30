#ifndef SINGLETONS_H_
#define SINGLETONS_H_

#include "object.h"
#include "type.h"

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

}

#endif /* SINGLETONS_H_ */
