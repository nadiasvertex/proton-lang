#ifndef __PARSER_RULE_TEST_H_
#define __PARSER_RULE_TEST_H_

#include <iostream>

using namespace igloo;

Context(BasicRules)
{
	Spec(RulesCanBeJoined) {
		auto test = new proton::parser::production("test_production");

		test->r("\n")
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
		proton::parser::literal_rule r("my");
		proton::string input("my wife is awesome.");
		auto it = input.iterator();

		Assert::That(r.match(it));
	}
};


#endif /* __PARSER_RULE_TEST_H_ */
