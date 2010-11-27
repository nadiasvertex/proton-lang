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
		auto n = new proton::integer(5);

		j->start();

		auto v = j->ld_constant_pointer(n);

		j->is_sequence(v);
		f->compile();

		j->end();
	}

};


#endif /* SEQUENCE_PROTOCOL_TEST_H_ */
