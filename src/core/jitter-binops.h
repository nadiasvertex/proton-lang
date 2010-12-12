
    /// add two objects.
    jit_value_t add(jit_value_t l, jit_value_t r);

    /// sub two objects.
    jit_value_t sub(jit_value_t l, jit_value_t r);

    /// mul two objects.
    jit_value_t mul(jit_value_t l, jit_value_t r);

    /// truediv two objects.
    jit_value_t truediv(jit_value_t l, jit_value_t r);

    /// floordiv two objects.
    jit_value_t floordiv(jit_value_t l, jit_value_t r);

    /// mod two objects.
    jit_value_t mod(jit_value_t l, jit_value_t r);

    /// divmod two objects.
    jit_value_t divmod(jit_value_t l, jit_value_t r);

    /// pow two objects.
    jit_value_t pow(jit_value_t l, jit_value_t r);

    /// lshift two objects.
    jit_value_t lshift(jit_value_t l, jit_value_t r);

    /// rshift two objects.
    jit_value_t rshift(jit_value_t l, jit_value_t r);

    /// bitwise_and two objects.
    jit_value_t bitwise_and(jit_value_t l, jit_value_t r);

    /// bitwise_or two objects.
    jit_value_t bitwise_or(jit_value_t l, jit_value_t r);

    /// bitwise_xor two objects.
    jit_value_t bitwise_xor(jit_value_t l, jit_value_t r);

    /// in-place add two objects.
    jit_value_t iadd(wstring lname, jit_value_t r);
    /// in-place sub two objects.
    jit_value_t isub(wstring lname, jit_value_t r);
    /// in-place mul two objects.
    jit_value_t imul(wstring lname, jit_value_t r);
    /// in-place truediv two objects.
    jit_value_t itruediv(wstring lname, jit_value_t r);
    /// in-place floordiv two objects.
    jit_value_t ifloordiv(wstring lname, jit_value_t r);
    /// in-place mod two objects.
    jit_value_t imod(wstring lname, jit_value_t r);
    /// in-place pow two objects.
    jit_value_t ipow(wstring lname, jit_value_t r);
    /// in-place lshift two objects.
    jit_value_t ilshift(wstring lname, jit_value_t r);
    /// in-place rshift two objects.
    jit_value_t irshift(wstring lname, jit_value_t r);
    /// in-place bitwise_and two objects.
    jit_value_t ibitwise_and(wstring lname, jit_value_t r);
    /// in-place bitwise_or two objects.
    jit_value_t ibitwise_or(wstring lname, jit_value_t r);
    /// in-place bitwise_xor two objects.
    jit_value_t ibitwise_xor(wstring lname, jit_value_t r);