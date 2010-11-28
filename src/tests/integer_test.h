#ifndef INTEGER_TEST_H_
#define INTEGER_TEST_H_

using namespace igloo;

Context(AFreshInteger)
{
	Spec(ShouldHaveAZeroInt)
	{
		Assert::That(proton::integer::zero, Is().Not().EqualTo((proton::integer*)0));
	}

	Spec(ShouldBeIntType)
	{
		auto i = new proton::integer();

		Assert::That(i->is_type(proton::type::py_int), Is().EqualTo(true));
	}

	Spec(TwoIntsAreAddable) {
		auto l = new proton::integer(5);
		auto r = new proton::integer(7);

		auto ctx = new proton::context();
		auto f = new proton::function(ctx);
		auto j = new proton::jitter(f);

		f->add_arg_names({L"x", L"y"});

		j->start();
		j->prologue();

		auto lv = j->load(L"x");
		auto rv = j->load(L"y");

		auto result = j->add(lv, rv);

		j->ret(result);

		f->compile();

		j->end();

		// Create closure to call the function.
		auto c = new proton::closure({l, r});

		f->dump();

		// Call the function and see what happens!
		auto call_result = f->apply(c);

	}

};

#endif /* INTEGER_TEST_H_ */
