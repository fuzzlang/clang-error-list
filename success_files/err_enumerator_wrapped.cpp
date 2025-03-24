
enum class E5 {
    e1 = 2147483647, // ok
    e2 // expected-error{{2147483648 is not representable in the underlying type 'int'}}
};
