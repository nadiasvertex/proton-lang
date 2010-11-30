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

		Assert::That(i->is_type(proton::type::py_int));
	}

};

Context(IntegerJitOperations)
{
	proton::context *ctx;
	proton::function *f;

	void SetUp()
	{
		ctx = new proton::context();
		f = new proton::function(ctx);

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
	}

	Spec(AddingTwoIntsDoesntThrow) {
		auto l = new proton::integer(5);
		auto r = new proton::integer(7);

		// Create closure to call the function.
		auto c = new proton::closure({l, r});

		//f->dump();

		// Call the function and see what happens!
		auto call_result = f->apply(c);

		Assert::That(!ctx->has_exception());
	}

	Spec(AddingTwoIntsYieldsInt) {
		auto l = new proton::integer(5);
		auto r = new proton::integer(7);

		// Create closure to call the function.
		auto c = new proton::closure({l, r});

		// Call the function and see what happens!
		auto call_result = f->apply(c);

		auto result_as_object = (proton::object*)call_result;

		Assert::That(result_as_object->is_type(proton::type::py_int));
	}

	Spec(AddingTwoIntsYieldsCorrectValue) {
		auto l = new proton::integer(5);
		auto r = new proton::integer(7);

		// Create closure to call the function.
		auto c = new proton::closure({l, r});

		// Call the function and see what happens!
		auto call_result = f->apply(c);

		auto result_as_integer = (proton::integer*)call_result;

		Assert::That(result_as_integer->get_int64(), Is().EqualTo(12));

	}



};

#endif /* INTEGER_TEST_H_ */
