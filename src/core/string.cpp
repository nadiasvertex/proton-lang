#include "string.h"
#include "unicode/ucnv.h"

#include <string>

namespace proton {

UConverter* default_converter = 0;

internal_string string::to_local_str() const {
	UErrorCode err = U_ZERO_ERROR;

	if (default_converter == 0) {
		default_converter = ucnv_open(NULL, &err);
	}

	// Figure out how much memory to allocate
	auto size = value.extract(NULL, 0, default_converter, err);

	// Make a buffer
	auto str = new char[size + 1];

	// Get the string as the default locale representation
	err = U_ZERO_ERROR;
	auto decoded = value.extract(str, size + 1, default_converter, err);

	if (decoded < size) {
		// throw an error?
	}

	return const_cast<const char*>(str);
}

internal_string string::to_escaped_local_str() const {
	auto src = to_local_str();
	auto s = new internal_string();

	for (auto it = src.begin(); it != src.end(); ++it) {
		switch (*it) {
		case '\n':
			s->append("\\n");
			break;
		case '\r':
			s->append("\\r");
			break;
		case '\t':
			s->append("\\t");
			break;
		default:
			s->append(1,*it);
		}
	}

	return *s;
}

} // end namespace
