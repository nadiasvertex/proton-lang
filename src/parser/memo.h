#ifndef __PROTON_MEMO_H_
#define __PROTON_MEMO_H_

#include "core-internal.h"
#include "rule.h"

#include <map>
#include <vector>

namespace proton {
namespace parser {

typedef std::vector<rule*, gc_allocator<rule*>> rule_list;

typedef gc_allocator<std::pair<int32_t, rule_list*>> memo_allocator;

typedef std::map<int32_t, rule_list*, std::less<int32_t>, memo_allocator> memo_map;

}
}

#endif /* __PROTON_MEMO_H_ */
