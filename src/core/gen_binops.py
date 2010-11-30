import sys

binops = ["add", "sub", "mul", "truediv", "floordiv", "mod", "divmod", "pow", "lshift", "rshift", "bitwise_and", "bitwise_or", "bitwise_xor" ]
inplace_ops = ["add", "sub", "mul", "truediv", "floordiv", "mod", "pow", "lshift", "rshift", "bitwise_and", "bitwise_or", "bitwise_xor", ]

with open(sys.argv[1], "w") as out:    
    for op in binops:
        if op!="pow":
            func = """proton::object* proto_{op}(proton::object *l, proton::object *r) {{
    try {{
        auto result = l->{op}(r);
        return (result == proton::object::not_implemented ? r->r{op}(l) : result);
    }} catch(proton::exception *e) {{
        jit_exception_throw(e);
    }}
}}
"""
        else:
            func = """proton::object* proto_{op}(proton::object *l, proton::object *r) {{
    try {{
        return l->{op}(r);                
    }} catch(proton::exception *e) {{
        jit_exception_throw(e);
    }}
}}
"""
        
        out.write("/// Performs %s on l, if l does not support the operation it tries the\n" % op)
        out.write("/// reverse operation on r.\n")
        out.write(func.format(op=op))
    
    for op in inplace_ops:
        if op!="pow":
            func = """proton::object* proto_i{op}(proton::object *l, proton::object *r) {{
    try {{
        auto result = l->i{op}(r);
        if (result != proton::object::not_implemented) return result;
        
        result = l->{op}(r);
        if (result != proton::object::not_implemented) return result;
        
        return r->r{op}(l);        
    }} catch(proton::exception *e) {{
        jit_exception_throw(e);
    }}
}}
"""
        else:
            func = """proton::object* proto_i{op}(proton::object *l, proton::object *r) {{
    try {{
        auto result = l->i{op}(r);
        if (result != proton::object::not_implemented) return result;
        
        return l->{op}(r);                
    }} catch(proton::exception *e) {{
        jit_exception_throw(e);
    }}
}}
"""
        
        out.write("/// Performs inplace %s on l, if l does not support the operation it tries the\n" % op)
        out.write("/// normal version of the operation.  If that fails, it tries the reverse operation on r.\n")
        out.write(func.format(op=op))

with open(sys.argv[2], "w") as out:
    for op in binops:
        func = """
    /// {op} two objects.
    jit_value_t {op}(jit_value_t l, jit_value_t r) {{
        jit_value_t args[2] = {{ l, r }};
    
        return jit_insn_call_native(f->jit, "proto_{op}",
                (void*) proto_{op}, binary_fn_sig, args, 2, 0);
    }}
"""
    
        out.write(func.format(op=op))

    for op in inplace_ops:
        func = """
    /// in-place {op} two objects.
    jit_value_t i{op}(std::wstring lname, jit_value_t r) {{
        // Get the object bound to the name.
        auto l = load(lname);
    
        jit_value_t args[2] = {{ l, r }};
    
        auto result = jit_insn_call_native(f->jit, "proto_i{op}",
                       (void*) proto_i{op}, binary_fn_sig, args, 2, 0);
                       
        inplace_store(lname, l, result);
        
        // Return the value generated
        return result;
    }}
"""
    
        out.write(func.format(op=op))
 