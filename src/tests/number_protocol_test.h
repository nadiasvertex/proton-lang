/*
 * sequence_protocol_test.h
 *
 *  Created on: Nov 26, 2010
 *      Author: cnelson
 */

#ifndef NUMBER_PROTOCOL_TEST_H_
#define NUMBER_PROTOCOL_TEST_H_

using namespace igloo;

Context(NormalNumbers)
{
	Spec(IntegerIsANumber)
	{
		auto n = new proton::integer(5);

		Assert::That(proto_is_number_type(n), Is().EqualTo(true));
	}

};


#endif /* NUMBER_PROTOCOL_TEST_H_ */
