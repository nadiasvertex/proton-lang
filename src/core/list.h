#ifndef __PROTON_LIST_H_
#define __PROTON_LIST_H_

#include "core-internal.h"
#include "object.h"
#include "type.h"
#include "exception.h"

#include <vector>

namespace proton {

class list : public object {
	object_vector items;
public:
	list():object(type::list) {}

	void append(object* x) {
		items.push_back(x);
	}

	void extend(list* x) {
		items.insert(items.end(), x->items.begin(), x->items.end());
	}

	void extend(object_vector::iterator begin, object_vector::iterator end)
	{
		items.insert(items.end(), begin, end);
	}

	object* get(uint32 idx) {
		if (idx>=items.size()) {
			throw new range_error();
		}

		return items[idx];
	}

};

}

#endif /* LIST_H_ */
