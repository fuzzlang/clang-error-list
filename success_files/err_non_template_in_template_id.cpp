
struct Base {
    void foo(); // Non-template function
};

struct Derived : Base {
    // Inherits foo from Base
};

void testMember() {
    Derived().foo<int>(); // expected-error-re {{does not name a template but is followed by template arguments{{$}}}}
}
