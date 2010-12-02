#include <igloo/igloo.h>
#include <proton.h>

#include "integer_test.h"
#include "sequence_protocol_test.h"
#include "number_protocol_test.h"
#include "context_test.h"

#include "parser_rule_test.h"

using namespace igloo;

int main()
{
	proton::Bootstrapper->init();

	return TestRunner::RunAllTests();
}
