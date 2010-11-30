#ifndef __PROTON_STRING_H_
#define __PROTON_STRING_H_

#include "core-internal.h"
#include "object.h"
#include "type.h"

namespace proton {

class string: public object {
	wstring value;
public:
	string() :
		object(type::py_str) {
	}
	string(const wstring &s) :
		object(type::py_str), value(s) {
	}




};

}

#endif /* STRING_H_ */
