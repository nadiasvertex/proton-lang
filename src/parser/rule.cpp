#include "rule.h"

namespace proton {
namespace parser {

bool expr::match(context& ctx) {
	auto matches = new ast_list();

	// Try an identifier
	identifier id();
	if (id.match(ctx)) {
		matches.push_back(id.to_ast());
	}


}


}
}
