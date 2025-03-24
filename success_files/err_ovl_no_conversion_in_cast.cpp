
struct A {};

void foo(A t) {
    (void)((int)t); // expected-error{{cannot convert 'A' to 'int' without a conversion operator}}
}
