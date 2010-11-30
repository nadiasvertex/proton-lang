#ifndef SINGLETONS_H_
#define SINGLETONS_H_

#include "object.h"
#include "type.h"

namespace proton {

type* type::none = new type(L"NoneType");
type* type::not_implemented = new type(L"NotImplementedType");

type* type::list = new type(L"list");
type* type::dict = new type(L"dict");
type* type::set = new type(L"set");
type* type::tuple = new type(L"tuple");

type* type::function = new type(L"function");

type* type::py_int = new type(L"int");
type* type::py_bool = new type(L"bool");
type* type::py_float = new type(L"float");
type* type::py_complex = new type(L"complex");
type* type::py_str = new type(L"str");

type* type::py_type = new type(L"type");
type* type::py_namespace = new type(L"namespace");

/// The one and only None object.
object* object::none = new object(type::none);

/// The one and only NotImplemented object.
object* object::not_implemented = new object(type::not_implemented);

}

#endif /* SINGLETONS_H_ */
