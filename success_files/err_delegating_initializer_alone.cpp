
struct foo {
    int i;
    foo();
    foo(int);
    foo(int, int);
    foo(bool);
    foo(char);
    foo(const float*);
    foo(const float&);
    foo(void*);
};

// Good
foo::foo (int i) : i(i) {}

// Good
foo::foo () : foo(-1) {}

// Good
foo::foo (int, int) : foo() {}

// Good
foo::foo (const float* f) : foo(*f) {}

// expected-error{{creates a delegation cycle}}
foo::foo (bool) : foo(true) {}

//expected-error{{creates a delegation cycle}}
foo::foo (const float &f) : foo(&f) {}

// Good
foo::foo (void*) : foo(4.0f) {}

foo::foo (char) : 
    i(3),
    foo(3) { // expected-error{{must appear alone}}
}
