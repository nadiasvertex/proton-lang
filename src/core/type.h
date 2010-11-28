#ifndef __PROTON_TYPE_H_
#define __PROTON_TYPE_H_

#include "core-internal.h"
#include "object.h"

#include <string>

namespace proton {

class type: public object {
	std::wstring name;
public:
	type(std::wstring _name) :
		object(type::py_type), name(_name) {
	}

	static type* none;
	static type* not_implemented;
	static type* ellipsis;

	static type* list;
	static type* dict;
	static type* set;
	static type* tuple;
	static type* bytes;

	static type* frozenset;

	static type* function;
	static type* method;
	static type* generator;
	static type* builtin_function_or_method;

	static type* py_int;
	static type* py_bool;
	static type* py_float;
	static type* py_complex;
	static type* py_str;

	static type* py_namespace;
	static type* py_class;
	static type* py_type;

	static type* module;
};

type* type::none = new type(L"NoneType");

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

}

#endif /* TYPE_H_ */
