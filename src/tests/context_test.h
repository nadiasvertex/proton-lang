#ifndef CONTEXT_TEST_H_
#define CONTEXT_TEST_H_

using namespace igloo;

Context(InitializedSystem)
{
	Spec(ContextCanBeCreated) {
		auto ctx = new proton::context();
	}
};

#endif /* CONTEXT_TEST_H_ */
