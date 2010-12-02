#ifndef __PROTON_RULE_H_
#define __PROTON_RULE_H_

#include "core-internal.h"
#include "string.h"

#include "unicode/uniset.h"

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

	void set_name(const std::string& _name) {
		name = _name;
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
		for (; at.getIndex() != at.endIndex(); at.next(), it.next()) {
			if (at.current() != it.current()) {
				return false;
			}
		}

		return true;
	}
};

class identifier : public rule {
	wstring value;

	UnicodeSet start_pattern, end_pattern;
public:
	identifier() : rule("identifier") {
		UErrorCode err;

		start_pattern.applyPattern("[a-zA-Z_]", err);
		end_pattern.applyPattern("[a-zA-Z0-9_]", err);
	}

	virtual uint64_t size() {
		return value.length();
	}

	virtual bool match(wstring_iterator& it) {
		if (!start_pattern.contains(it.current())) {
			return false;
		}

		do {
			value.append(it.current());
			it.next();
		} while (end_pattern.contains(it.current()));

		return true;
	}

};

class newline: public literal_rule {
public:
	newline() :
		literal_rule("\n") {
	}
};

} // end parser namespace
} // end proton namespace

#endif /* __PROTON_RULE_H_ */
