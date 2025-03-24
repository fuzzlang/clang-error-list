
struct Base {};
struct Derived : Base {};

void test() {
    Base b;
    const Derived d;

    int i1 = 1; // Necessary initialization for conditional expression
    (void)(i1 ? b : d); // expected-error {{incompatible operand types ('Base' and 'const Derived')}}
}
