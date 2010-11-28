#ifndef SINGLETONS_H_
#define SINGLETONS_H_

#include "object.h"
#include "type.h"

namespace proton {

/// The one and only None object.
object* object::none = new object(type::none);

}

#endif /* SINGLETONS_H_ */
