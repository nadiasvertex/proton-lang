#include "object.h"
#include "string.h"

namespace proton {

object* object::repr() {
	internal_stringstream o;

	o << "<object at " << this << ">";

	auto s = o.str();

	return new string(UNICODE_STRING(s.c_str(), s.size()));
}


}
