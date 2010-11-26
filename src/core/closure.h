#ifndef __PROTON_CLOSURE_H_
#define __PROTON_CLOSURE_H_

#include "core-internal.h"

namespace proton {

/// This is the object that we pass to functions, and that functions pass back to us. It
/// contains all of the input and output values, as well as a value that indicates where
/// we should go next.
class closure : public gc {
public:

	uint64 id(){
		return reinterpret_cast<uint64>(this);
	}

};

}

#endif /* CLOSURE_H_ */
