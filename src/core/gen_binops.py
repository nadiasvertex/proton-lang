import sys

binops = ["add", "sub", "mul", "truediv", "floordiv", "mod", "divmod", "pow", "lshift", "rshift", "bitwise_and", "bitwise_or", "bitwise_xor" ]
inplace_ops = ["add", "sub", "mul", "truediv", "floordiv", "mod", "pow", "lshift", "rshift", "bitwise_and", "bitwise_or", "bitwise_xor", ]

test_code="""
Context(IntegerJit{cap_op})
{{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {{
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({{UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")}});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->{op}(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }}

    Spec({cap_op}TwoIntsDoesntThrow) {{
        auto l = new proton::integer({lvalue});
        auto r = new proton::integer({rvalue});

        // Create closure to call the function.
        auto c = new proton::closure({{l, r}});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }}

    Spec({cap_op}TwoIntsYieldsInt) {{
        auto l = new proton::integer({lvalue});
        auto r = new proton::integer({rvalue});

        // Create closure to call the function.
        auto c = new proton::closure({{l, r}});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }}

    Spec({cap_op}TwoIntsYieldsCorrectValue) {{
        auto l = new proton::integer({lvalue});
        auto r = new proton::integer({rvalue});

        // Create closure to call the function.
        auto c = new proton::closure({{l, r}});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo({op_result}));
    }}
}};
"""

###======-----------------------------------------------------------------------------===========###
# Protocol code generation for binops

proto_h = sys.argv[1]+".h"
proto_c = sys.argv[1]+".cpp"

with open(proto_h, "w") as out:    
    for op in binops:
        if op!="pow":
            func = """proton::object* proto_{op}(proton::object *l, proton::object *r);\n"""
        else:
            func = """proton::object* proto_{op}(proton::object *l, proton::object *r);\n"""
        
        out.write("/// Performs %s on l, if l does not support the operation it tries the\n" % op)
        out.write("/// reverse operation on r.\n")
        out.write(func.format(op=op))
    
    for op in inplace_ops:
        if op!="pow":
            func = """proton::object* proto_i{op}(proton::object *l, proton::object *r);\n"""
        else:
            func = """proton::object* proto_i{op}(proton::object *l, proton::object *r);\n"""
        
        out.write("/// Performs inplace %s on l, if l does not support the operation it tries the\n" % op)
        out.write("/// normal version of the operation.  If that fails, it tries the reverse operation on r.\n")
        out.write(func.format(op=op))
        
with open(proto_c, "w") as out:
    out.write("// Automatically generated - do not edit.\n")
    out.write('#include "proton.h"\n\n')    
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


###======-----------------------------------------------------------------------------===========###
# Jitter code generation for binops

jitter_h = sys.argv[2]+".h"
jitter_c = sys.argv[2]+".cpp"

with open(jitter_h, "w") as out:
    for op in binops:
        func = """
    /// {op} two objects.
    jit_value_t {op}(jit_value_t l, jit_value_t r);\n"""
    
        out.write(func.format(op=op))

    for op in inplace_ops:
        func = """
    /// in-place {op} two objects.
    jit_value_t i{op}(wstring lname, jit_value_t r);"""
    
        out.write(func.format(op=op))

with open(jitter_c, "w") as out:
    out.write("// Automatically generated - do not edit.\n")
    out.write('#include "proton.h"\n')
    out.write('namespace proton {\n')
    for op in binops:
        func = """
    /// {op} two objects.
    jit_value_t jitter::{op}(jit_value_t l, jit_value_t r) {{
        jit_value_t args[2] = {{ l, r }};
    
        return jit_insn_call_native(f->jit, "proto_{op}",
                (void*) proto_{op}, binary_fn_sig, args, 2, 0);
    }}
"""
    
        out.write(func.format(op=op))

    for op in inplace_ops:
        func = """
    /// in-place {op} two objects.
    jit_value_t jitter::i{op}(wstring lname, jit_value_t r) {{
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
        
    out.write('} // end namespace proton\n')
 
with open(sys.argv[3], "w") as out:
    for op in binops:
        lvalue=100
        rvalue=23
        perf_op = op if "bitwise" not in op else op.replace("bitwise_", "")
        
        func = test_code.format(op=op, cap_op=op.capitalize(), lvalue=lvalue, rvalue=rvalue, op_result=eval("lvalue.__%s__(rvalue)" % perf_op))
        out.write(func)
        