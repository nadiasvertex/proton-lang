#ifndef __PROTON_PARSER_H_
#define __PROTON_PARSER_H_

#include "core-internal.h"
#include "production.h"

namespace proton {

class python_parser: public gc {

	/// Tracks memoized parser state.
	parser::memo_map memo;

	/// List of rules that are currently active.
	parser::rule_list* current_rules;

	/// Save the current parser state
	void save(wstring_iterator& it) {
		//memo[it.getIndex()] = new rule_list(current_rules);
	}

	/// Load the parser state from a previous step into the current
	/// parser state.
	void load(int32_t index, wstring_iterator& it) {
		//current_rules = memo[index];
		//it.setIndex(index);
	}

public:

	python_parser() :
		current_rules(new parser::rule_list()) {
	}



};

}

#endif /* PARSER_H_ */
