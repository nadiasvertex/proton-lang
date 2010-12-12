/// Performs add on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_add(proton::object *l, proton::object *r);
/// Performs sub on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_sub(proton::object *l, proton::object *r);
/// Performs mul on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_mul(proton::object *l, proton::object *r);
/// Performs truediv on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_truediv(proton::object *l, proton::object *r);
/// Performs floordiv on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_floordiv(proton::object *l, proton::object *r);
/// Performs mod on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_mod(proton::object *l, proton::object *r);
/// Performs divmod on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_divmod(proton::object *l, proton::object *r);
/// Performs pow on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_pow(proton::object *l, proton::object *r);
/// Performs lshift on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_lshift(proton::object *l, proton::object *r);
/// Performs rshift on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_rshift(proton::object *l, proton::object *r);
/// Performs bitwise_and on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_bitwise_and(proton::object *l, proton::object *r);
/// Performs bitwise_or on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_bitwise_or(proton::object *l, proton::object *r);
/// Performs bitwise_xor on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_bitwise_xor(proton::object *l, proton::object *r);
/// Performs inplace add on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_iadd(proton::object *l, proton::object *r);
/// Performs inplace sub on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_isub(proton::object *l, proton::object *r);
/// Performs inplace mul on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_imul(proton::object *l, proton::object *r);
/// Performs inplace truediv on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_itruediv(proton::object *l, proton::object *r);
/// Performs inplace floordiv on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ifloordiv(proton::object *l, proton::object *r);
/// Performs inplace mod on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_imod(proton::object *l, proton::object *r);
/// Performs inplace pow on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ipow(proton::object *l, proton::object *r);
/// Performs inplace lshift on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ilshift(proton::object *l, proton::object *r);
/// Performs inplace rshift on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_irshift(proton::object *l, proton::object *r);
/// Performs inplace bitwise_and on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ibitwise_and(proton::object *l, proton::object *r);
/// Performs inplace bitwise_or on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ibitwise_or(proton::object *l, proton::object *r);
/// Performs inplace bitwise_xor on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ibitwise_xor(proton::object *l, proton::object *r);
