/*
 * sequence_protocol_test.h
 *
 *  Created on: Nov 26, 2010
 *      Author: cnelson
 */

#ifndef SEQUENCE_PROTOCOL_TEST_H_
#define SEQUENCE_PROTOCOL_TEST_H_

using namespace igloo;

Context(NormalSystemState)
{
	Spec(IntegerIsNotASequence)
	{
		auto n = new proton::integer(5);

		Assert::That(proto_is_sequence_type(n), Is().Not().EqualTo(true));
	}

};


#endif /* SEQUENCE_PROTOCOL_TEST_H_ */
