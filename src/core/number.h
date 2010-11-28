#ifndef NUMBER_H_
#define NUMBER_H_

#include "core-internal.h"
#include "type.h"

namespace proton {

class number: public object {
public:
	number(type* t) :
		object(t) {
	}
	virtual bool is_number() {
		return true;
	}
};

}

#endif /* NUMBER_H_ */
