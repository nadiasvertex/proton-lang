
Context(IntegerJitAdd)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->add(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(AddTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(AddTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(AddTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(123));
    }
};

Context(IntegerJitSub)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->sub(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(SubTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(SubTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(SubTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(77));
    }
};

Context(IntegerJitMul)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->mul(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(MulTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(MulTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(MulTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(2300));
    }
};

Context(IntegerJitTruediv)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->truediv(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(TruedivTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(TruedivTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(TruedivTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(4.34782608696));
    }
};

Context(IntegerJitFloordiv)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->floordiv(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(FloordivTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(FloordivTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(FloordivTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(4));
    }
};

Context(IntegerJitMod)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->mod(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(ModTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(ModTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(ModTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(8));
    }
};

Context(IntegerJitDivmod)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->divmod(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(DivmodTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(DivmodTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(DivmodTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo((4, 8)));
    }
};

Context(IntegerJitPow)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->pow(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(PowTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(PowTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(PowTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(10000000000000000000000000000000000000000000000));
    }
};

Context(IntegerJitLshift)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->lshift(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(LshiftTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(LshiftTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(LshiftTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(838860800));
    }
};

Context(IntegerJitRshift)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->rshift(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(RshiftTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(RshiftTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(RshiftTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(0));
    }
};

Context(IntegerJitBitwise_and)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->bitwise_and(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(Bitwise_andTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(Bitwise_andTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(Bitwise_andTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(4));
    }
};

Context(IntegerJitBitwise_or)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->bitwise_or(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(Bitwise_orTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(Bitwise_orTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(Bitwise_orTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(119));
    }
};

Context(IntegerJitBitwise_xor)
{
    proton::context *ctx;
    proton::function *f;

    void SetUp()
    {
        ctx = new proton::context();
        f = new proton::function(ctx);

        auto j = new proton::jitter(f);

        f->add_arg_names({UNICODE_STRING_SIMPLE("x"), UNICODE_STRING_SIMPLE("y")});

        j->start();
        j->prologue();

        auto lv = j->load(UNICODE_STRING("x",1));
        auto rv = j->load(UNICODE_STRING("y",1));

        auto result = j->bitwise_xor(lv, rv);

        j->ret(result);

        f->compile();

        j->end();
    }

    Spec(Bitwise_xorTwoIntsDoesntThrow) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        //f->dump();

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        Assert::That(!ctx->has_exception());
    }

    Spec(Bitwise_xorTwoIntsYieldsInt) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_object = (proton::object*)call_result;

        Assert::That(result_as_object->is_type(proton::type::py_int));
    }

    Spec(Bitwise_xorTwoIntsYieldsCorrectValue) {
        auto l = new proton::integer(100);
        auto r = new proton::integer(23);

        // Create closure to call the function.
        auto c = new proton::closure({l, r});

        // Call the function and see what happens!
        auto call_result = f->apply(c);

        auto result_as_integer = (proton::integer*)call_result;

        Assert::That(result_as_integer->get_int64(), Is().EqualTo(115));
    }
};
