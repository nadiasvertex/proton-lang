// Automatically generated - do not edit.
#include "proton.h"
namespace proton {

    /// add two objects.
    jit_value_t jitter::add(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_add",
                (void*) proto_add, binary_fn_sig, args, 2, 0);
    }

    /// sub two objects.
    jit_value_t jitter::sub(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_sub",
                (void*) proto_sub, binary_fn_sig, args, 2, 0);
    }

    /// mul two objects.
    jit_value_t jitter::mul(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_mul",
                (void*) proto_mul, binary_fn_sig, args, 2, 0);
    }

    /// truediv two objects.
    jit_value_t jitter::truediv(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_truediv",
                (void*) proto_truediv, binary_fn_sig, args, 2, 0);
    }

    /// floordiv two objects.
    jit_value_t jitter::floordiv(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_floordiv",
                (void*) proto_floordiv, binary_fn_sig, args, 2, 0);
    }

    /// mod two objects.
    jit_value_t jitter::mod(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_mod",
                (void*) proto_mod, binary_fn_sig, args, 2, 0);
    }

    /// divmod two objects.
    jit_value_t jitter::divmod(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_divmod",
                (void*) proto_divmod, binary_fn_sig, args, 2, 0);
    }

    /// pow two objects.
    jit_value_t jitter::pow(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_pow",
                (void*) proto_pow, binary_fn_sig, args, 2, 0);
    }

    /// lshift two objects.
    jit_value_t jitter::lshift(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_lshift",
                (void*) proto_lshift, binary_fn_sig, args, 2, 0);
    }

    /// rshift two objects.
    jit_value_t jitter::rshift(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_rshift",
                (void*) proto_rshift, binary_fn_sig, args, 2, 0);
    }

    /// bitwise_and two objects.
    jit_value_t jitter::bitwise_and(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_bitwise_and",
                (void*) proto_bitwise_and, binary_fn_sig, args, 2, 0);
    }

    /// bitwise_or two objects.
    jit_value_t jitter::bitwise_or(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_bitwise_or",
                (void*) proto_bitwise_or, binary_fn_sig, args, 2, 0);
    }

    /// bitwise_xor two objects.
    jit_value_t jitter::bitwise_xor(jit_value_t l, jit_value_t r) {
        jit_value_t args[2] = { l, r };
    
        return jit_insn_call_native(f->jit, "proto_bitwise_xor",
                (void*) proto_bitwise_xor, binary_fn_sig, args, 2, 0);
    }

    /// in-place add two objects.
    jit_value_t jitter::iadd(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_iadd",
                       (void*) proto_iadd, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place sub two objects.
    jit_value_t jitter::isub(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_isub",
                       (void*) proto_isub, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place mul two objects.
    jit_value_t jitter::imul(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_imul",
                       (void*) proto_imul, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place truediv two objects.
    jit_value_t jitter::itruediv(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_itruediv",
                       (void*) proto_itruediv, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place floordiv two objects.
    jit_value_t jitter::ifloordiv(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_ifloordiv",
                       (void*) proto_ifloordiv, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place mod two objects.
    jit_value_t jitter::imod(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_imod",
                       (void*) proto_imod, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place pow two objects.
    jit_value_t jitter::ipow(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_ipow",
                       (void*) proto_ipow, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place lshift two objects.
    jit_value_t jitter::ilshift(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_ilshift",
                       (void*) proto_ilshift, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place rshift two objects.
    jit_value_t jitter::irshift(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_irshift",
                       (void*) proto_irshift, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place bitwise_and two objects.
    jit_value_t jitter::ibitwise_and(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_ibitwise_and",
                       (void*) proto_ibitwise_and, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place bitwise_or two objects.
    jit_value_t jitter::ibitwise_or(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_ibitwise_or",
                       (void*) proto_ibitwise_or, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }

    /// in-place bitwise_xor two objects.
    jit_value_t jitter::ibitwise_xor(wstring lname, jit_value_t r) {
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = { l, r };
    
        auto result = jit_insn_call_native(f->jit, "proto_ibitwise_xor",
                       (void*) proto_ibitwise_xor, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }
} // end namespace proton
