#ifndef __PARSER_RULE_TEST_H_
#define __PARSER_RULE_TEST_H_

#include <iostream>

using namespace igloo;

Context(BasicRules)
{
	Spec(IdentifierRuleCanMatch) {
		proton::parser::identifier r;
		proton::string input("abcDEF123_654GHIjkl");
		auto ctx = proton::parser::context(*input.iterator());

		Assert::That(r.match(ctx));
	}


};


#endif /* __PARSER_RULE_TEST_H_ */
