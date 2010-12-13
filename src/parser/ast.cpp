#include "proton.h"

namespace proton {
namespace ast {

std::map<wchar, int> binop::prec_map;
bool binop::initialized = false;

jit_value_t ident::compile(jitter* j) {
	return j->load(name.raw_value());
}

jit_value_t integer::compile(jitter* j) {
	return j->ld_constant_pointer(new proton::integer(the_value));
}

jit_value_t binop::compile(jitter* j) {
	switch(op) {
	case '+': return j->add(left->compile(j), right->compile(j));
	case '-': return j->sub(left->compile(j), right->compile(j));
	case '/': return j->truediv(left->compile(j), right->compile(j));
	case '*': return j->mul(left->compile(j), right->compile(j));
	case '&': return j->bitwise_and(left->compile(j), right->compile(j));
	case '|': return j->bitwise_or(left->compile(j), right->compile(j));
	case '^': return j->bitwise_xor(left->compile(j), right->compile(j));
	}
}

}
}

