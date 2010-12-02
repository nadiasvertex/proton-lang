#ifndef __PROTON_PRODUCTION_H_
#define __PROTON_PRODUCTION_H_

#include "core-internal.h"
#include "memo.h"

namespace proton {
namespace parser {

class production : public rule {
	rule_list rules;
public:

	production(const std::string& n):rule(n) {}

	production* r(const rule& _r) {
		rules.push_back(new rule(_r));
		return this;
	}

	production* r(const string& literal) {
		rules.push_back(new literal_rule(literal));
		return this;
	}

	production* r(const char* literal) {
		rules.push_back(new literal_rule(literal));
		return this;
	}

	virtual void dump(std::ostream& s) const {
		s << name << " : ";
		for(auto it=rules.begin(); it!=rules.end(); ++it)
		{
			(*it)->dump(s);
		}
	}
};


} // end parser namespace
} // end proton namespace

#endif /* __PROTON_PRODUCTION_H_ */
