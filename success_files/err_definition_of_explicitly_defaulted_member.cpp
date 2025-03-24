
#ifndef PASS1
#define PASS1

struct foo {
    foo() = default;
    void bar() = delete;
};

#else

foo::foo() { } // expected-error{{definition of explicitly defaulted default constructor}}

#endif
