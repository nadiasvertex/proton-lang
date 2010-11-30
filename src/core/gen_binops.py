binops = ["add", "sub", "mul", "truediv", "floordiv", "mod", "divmod", "pow", "lshift", "rshift", "bitwise_and", "bitwise_or", "bitwise_xor" ]

inplace_ops = ["add", "sub", "mul", "truediv", "floordiv", "mod", "pow", "lshift", "rshift", "bitwise_and", "bitwise_or", "bitwise_xor", ]


for op in binops:
    if op!="pow":
        func = """proton::object* proto_{op}(proton::object *l, proton::object *r) {{
    try {{
        auto result = l->{op}(r);
        return (result == proton::object::not_implemented ? r->r{op}(l) : result)
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
    
    print "/// Performs %s on l, if l does not support the operation it tries the" % op
    print "/// reverse operation on r."
    print func.format(op=op)

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
    
    print "/// Performs inplace %s on l, if l does not support the operation it tries the" % op
    print "/// normal version of the operation.  If that fails, it tries the reverse operation on r."
    print func.format(op=op)
