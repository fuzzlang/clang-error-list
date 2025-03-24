
struct A {
    operator int&();
    operator long*&();
};

struct B {
    operator long&();
    operator int*&();
};

struct C : B, A { };

void test(C c) {
    ++c; // expected-error {{use of overloaded operator '++' is ambiguous}}
}
