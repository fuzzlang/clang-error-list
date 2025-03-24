
void test() {
    _BitInt(129) x = 1; // 129-bit variable
    _BitInt(129) y = 2; // 129-bit variable
    _BitInt(129) result;

    _Bool status = __builtin_mul_overflow(x, y, &result); // expected-error {{__builtin_mul_overflow does not support 'signed _BitInt' operands of more than 128 bits}}
}
