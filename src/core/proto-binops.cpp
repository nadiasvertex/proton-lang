// Automatically generated - do not edit.
#include "proton.h"

/// Performs add on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_add(proton::object *l, proton::object *r) {
    try {
        auto result = l->add(r);
        return (result == proton::object::not_implemented ? r->radd(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs sub on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_sub(proton::object *l, proton::object *r) {
    try {
        auto result = l->sub(r);
        return (result == proton::object::not_implemented ? r->rsub(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs mul on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_mul(proton::object *l, proton::object *r) {
    try {
        auto result = l->mul(r);
        return (result == proton::object::not_implemented ? r->rmul(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs truediv on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_truediv(proton::object *l, proton::object *r) {
    try {
        auto result = l->truediv(r);
        return (result == proton::object::not_implemented ? r->rtruediv(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs floordiv on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_floordiv(proton::object *l, proton::object *r) {
    try {
        auto result = l->floordiv(r);
        return (result == proton::object::not_implemented ? r->rfloordiv(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs mod on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_mod(proton::object *l, proton::object *r) {
    try {
        auto result = l->mod(r);
        return (result == proton::object::not_implemented ? r->rmod(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs divmod on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_divmod(proton::object *l, proton::object *r) {
    try {
        auto result = l->divmod(r);
        return (result == proton::object::not_implemented ? r->rdivmod(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs pow on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_pow(proton::object *l, proton::object *r) {
    try {
        return l->pow(r);                
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs lshift on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_lshift(proton::object *l, proton::object *r) {
    try {
        auto result = l->lshift(r);
        return (result == proton::object::not_implemented ? r->rlshift(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs rshift on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_rshift(proton::object *l, proton::object *r) {
    try {
        auto result = l->rshift(r);
        return (result == proton::object::not_implemented ? r->rrshift(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs bitwise_and on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_bitwise_and(proton::object *l, proton::object *r) {
    try {
        auto result = l->bitwise_and(r);
        return (result == proton::object::not_implemented ? r->rbitwise_and(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs bitwise_or on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_bitwise_or(proton::object *l, proton::object *r) {
    try {
        auto result = l->bitwise_or(r);
        return (result == proton::object::not_implemented ? r->rbitwise_or(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs bitwise_xor on l, if l does not support the operation it tries the
/// reverse operation on r.
proton::object* proto_bitwise_xor(proton::object *l, proton::object *r) {
    try {
        auto result = l->bitwise_xor(r);
        return (result == proton::object::not_implemented ? r->rbitwise_xor(l) : result);
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace add on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_iadd(proton::object *l, proton::object *r) {
    try {
        auto result = l->iadd(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->add(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->radd(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace sub on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_isub(proton::object *l, proton::object *r) {
    try {
        auto result = l->isub(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->sub(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->rsub(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace mul on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_imul(proton::object *l, proton::object *r) {
    try {
        auto result = l->imul(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->mul(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->rmul(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace truediv on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_itruediv(proton::object *l, proton::object *r) {
    try {
        auto result = l->itruediv(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->truediv(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->rtruediv(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace floordiv on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ifloordiv(proton::object *l, proton::object *r) {
    try {
        auto result = l->ifloordiv(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->floordiv(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->rfloordiv(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace mod on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_imod(proton::object *l, proton::object *r) {
    try {
        auto result = l->imod(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->mod(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->rmod(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace pow on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ipow(proton::object *l, proton::object *r) {
    try {
        auto result = l->ipow(r);
        if (result != proton::object::not_implemented) return result;
        
        return l->pow(r);                
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace lshift on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ilshift(proton::object *l, proton::object *r) {
    try {
        auto result = l->ilshift(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->lshift(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->rlshift(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace rshift on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_irshift(proton::object *l, proton::object *r) {
    try {
        auto result = l->irshift(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->rshift(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->rrshift(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace bitwise_and on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ibitwise_and(proton::object *l, proton::object *r) {
    try {
        auto result = l->ibitwise_and(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->bitwise_and(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->rbitwise_and(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace bitwise_or on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ibitwise_or(proton::object *l, proton::object *r) {
    try {
        auto result = l->ibitwise_or(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->bitwise_or(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->rbitwise_or(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
/// Performs inplace bitwise_xor on l, if l does not support the operation it tries the
/// normal version of the operation.  If that fails, it tries the reverse operation on r.
proton::object* proto_ibitwise_xor(proton::object *l, proton::object *r) {
    try {
        auto result = l->ibitwise_xor(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->bitwise_xor(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->rbitwise_xor(l);        
    } catch(proton::exception *e) {
        jit_exception_throw(e);
    }
}
