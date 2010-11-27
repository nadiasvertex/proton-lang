#ifndef __PROTON_NAMESPACE_H_
#define __PROTON_NAMESPACE_H_

#include "core-internal.h"
#include "object.h"

namespace proton {

class name_space : public object {

	object_map names;
public:

	/// Get the value bound to the key.
	object *get(std::wstring key, object* default_value = object::none) {
		auto it = names.find(key);

		if (it == names.end()) {
			return default_value;
		}

		return it->second;
	}

	void set(std::wstring key, object* value) {
		names[key] = value;
	}

	void insert(object_map::iterator begin, object_map::iterator end) {
		names.insert(begin, end);
	}
};


}

#endif /* NAMESPACE_H_ */
