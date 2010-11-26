#ifndef __PROTON_CONTEXT_H__
#define __PROTON_CONTEXT_H__

#include <jit/jit.h>
#include <gc.h>

namespace proton {

class context {

	jit_context_t ctx;

public:
	context():ctx(jit_context_create()) {}

};

}

#endif
