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
		auto v = jit_value_create_nint_constant(f->jit_fn(), jit_type_void_ptr, n);

		j->is_sequence(v);
	}

};


#endif /* SEQUENCE_PROTOCOL_TEST_H_ */
