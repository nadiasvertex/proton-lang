#ifndef __PROTON_EXCEPTION_H_
#define __PROTON_EXCEPTION_H_

#include "core-internal.h"

namespace proton {

class function;

class exception: public gc {

};

class argument_error: public exception {
public:
	function *func;
	uint32 accepted_count;
	uint32 actual_count;

	argument_error(function* _func, uint32 accepted, uint32 actual) :
		func(_func), accepted_count(accepted), actual_count(actual) {
	}

};

class range_error: public exception {
public:

};


}

#endif /* EXCEPTION_H_ */
