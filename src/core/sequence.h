#ifndef PROTO_SEQUENCE_H_
#define PROTO_SEQUENCE_H_

#include "core-internal.h"

namespace proton {

class sequence : public object {
public:
	virtual bool is_sequence() { return true; }

	virtual uint64 len() {
		return 0;
	}


};

}

#endif /* SEQUENCE_H_ */
