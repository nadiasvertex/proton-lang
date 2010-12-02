#ifndef __PROTON_RULE_H_
#define __PROTON_RULE_H_

#include "core-internal.h"
#include "string.h"

#include <vector>
#include <ostream>

namespace proton {
namespace parser {

enum rule_suffix_type {
	ONE_OR_NONE, ONE_OR_MORE, ZERO_OR_MORE
};

/// A single matching rule
class rule: public gc {
	rule_suffix_type suffix;

protected:
	std::string name;

public:
	rule() {
	}

	rule(const std::string& _name) :
		name(_name) {
	}

	rule(rule_suffix_type _suffix) :
		suffix(_suffix) {
	}

	virtual void dump(std::ostream& s) const {
		s << name;
	}

	virtual uint64_t size() {
		return 0;
	}

	virtual bool match(wstring_iterator& it) {
		return false;
	}

};

class literal_rule: public rule {
	string to_match;
	wstring_iterator at;
public:
	literal_rule(const string& _to_match) :
		to_match(_to_match), at(to_match.iterator()) {
	}

	literal_rule(const char* literal) :
		to_match(literal), at(to_match.iterator()) {
	}

	virtual void dump(std::ostream& s) const {
		s << "'" << to_match.to_escaped_local_str() << "'";
	}

	void set_literal(string s) {
		to_match = s;
	}

	virtual uint64_t size() {
		return to_match.get_length();
	}

	virtual bool match(wstring_iterator& it) {
		for(; at.getIndex()!=at.endIndex(); at.next(), it.next())
		{
			if (at.current()!=it.current()) {
				return false;
			}
		}

		return true;
	}
};

} // end parser namespace
} // end proton namespace

#endif /* __PROTON_RULE_H_ */
