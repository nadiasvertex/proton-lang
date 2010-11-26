/*
 * integer_test.h
 *
 *  Created on: Nov 26, 2010
 *      Author: cnelson
 */

#ifndef INTEGER_TEST_H_
#define INTEGER_TEST_H_

using namespace igloo;

Context(AFreshInteger)
{
	Spec(ShouldHaveAZeroInt)
	{
		Assert::That(proton::integer::zero, Is().Not().EqualTo((proton::integer*)0));
	}

};

#endif /* INTEGER_TEST_H_ */
