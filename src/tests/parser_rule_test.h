#ifndef __PARSER_RULE_TEST_H_
#define __PARSER_RULE_TEST_H_

#include <iostream>

using namespace igloo;

Context(BasicRules)
{
	Spec(RulesCanBeJoined) {
		auto test = new proton::parser::production("test_production");

		test->r(proton::parser::newline())
			->r("test_rule");

		/*std::cout << std::endl;
		test->dump(std::cout);*/
	}

	Spec(NonterminalsCanBeCreated) {
			proton::parser::rule test(std::string("test"));

			/*std::cout << std::endl;
			test.dump(std::cout);*/
	}

	Spec(LiteralRuleCanMatch) {
		proton::parser::literal_rule r("my wife");
		proton::string input("my wife is awesome.");
		auto ctx = proton::parser::context(input.iterator());

		Assert::That(r.match(ctx));
	}

	Spec(IdentifierRuleCanMatch) {
		proton::parser::identifier r;
		proton::string input("abcDEF123_654GHIjkl");
		auto ctx = proton::parser::context(input.iterator());

		Assert::That(r.match(ctx));
	}

	Spec(ProductionCanMatch) {
		proton::parser::literal_rule r("my wife");
		proton::string input("my wife is awesome.");
		auto ctx = proton::parser::context(input.iterator());

		Assert::That(r.match(ctx));
	}



};


#endif /* __PARSER_RULE_TEST_H_ */
