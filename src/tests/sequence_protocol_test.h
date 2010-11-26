/*
 * sequence_protocol_test.h
 *
 *  Created on: Nov 26, 2010
 *      Author: cnelson
 */

#ifndef SEQUENCE_PROTOCOL_TEST_H_
#define SEQUENCE_PROTOCOL_TEST_H_

using namespace igloo;

Context(NormalSequences)
{
	Spec(IntegerIsNotASequence)
	{
		auto n = new proton::integer(5);

		Assert::That(proto_is_sequence_type(n), Is().EqualTo(false));
	}

	Spec(CanGenerateIfSequence)
	{
		auto ctx = new proton::context();
		auto f = new proton::function(ctx);

		auto j = new proton::jitter(f);


		//j->is_sequence(0);
	}

};


#endif /* SEQUENCE_PROTOCOL_TEST_H_ */
