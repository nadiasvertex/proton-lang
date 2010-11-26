#ifndef NUMBER_H_
#define NUMBER_H_

#include "core-internal.h"

namespace proton {

class number : public object {
public:
	virtual bool is_number() { return true; }
};

}

#endif /* NUMBER_H_ */
