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

#include "jit_int_test.h"

#endif /* INTEGER_TEST_H_ */
