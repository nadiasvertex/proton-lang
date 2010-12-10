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

	Spec(IdentifierRuleGetsMemoized) {
		proton::parser::identifier r;
		proton::string input("abcDEF123_654GHIjkl and stuff");
		auto ctx = proton::parser::context(*input.iterator());

		// Match out a rule
		auto n1 = r.match(ctx);

		// Reset and match out the rule again.
		ctx.seek(0);
		auto n2 = r.match(ctx);

		Assert::That(n1==n2);
	}




};


#endif /* __PARSER_RULE_TEST_H_ */
