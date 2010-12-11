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

	Spec(IntegerRuleCanMatch) {
			proton::parser::integer r;
			proton::string input("12334567");
			auto ctx = proton::parser::context(*input.iterator());

			Assert::That(r.match(ctx));
	}

	Spec(IntegerRuleCanMatchHex) {
			proton::parser::integer r;
			proton::string input("0x10");
			auto ctx = proton::parser::context(*input.iterator());

			auto n = (proton::ast::integer*)r.match(ctx);
			Assert::That(n);

			auto v = n->value().get_int64();
			Assert::That(v==0x10);
	}

	Spec(IntegerRuleCanMatchOct) {
			proton::parser::integer r;
			proton::string input("010");
			auto ctx = proton::parser::context(*input.iterator());

			auto n = (proton::ast::integer*)r.match(ctx);
			Assert::That(n);

			auto v = n->value().get_int64();
			Assert::That(v==010);
	}

	Spec(IntegerRuleCanMatchBin) {
			proton::parser::integer r;
			proton::string input("0b10");
			auto ctx = proton::parser::context(*input.iterator());

			auto n = (proton::ast::integer*)r.match(ctx);
			Assert::That(n);

			auto v = n->value().get_int64();
			Assert::That(v==2);
	}

	Spec(IntegerRuleCanMatchDec) {
			proton::parser::integer r;
			proton::string input("10");
			auto ctx = proton::parser::context(*input.iterator());

			auto n = (proton::ast::integer*)r.match(ctx);
			Assert::That(n);

			auto v = n->value().get_int64();
			Assert::That(v==10);
	}

	Spec(IntegerRuleGetsMemoized) {
		proton::parser::integer r;
		proton::string input("1234567 + 45345");
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
