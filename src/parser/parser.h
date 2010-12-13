#ifndef __PROTON_PARSER_H_
#define __PROTON_PARSER_H_

#include "core-internal.h"
#include "rule.h"

namespace proton {

class python_parser: public gc {

public:

	object* eval(context* ctx, char* line);
};

}

#endif /* PARSER_H_ */
