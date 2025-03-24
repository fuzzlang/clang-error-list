
class Base {
public:
    void foo() {}
};

class Derived : public Base {};

void test() {
    using __super::foo; // expected-error {{'__super' cannot be used with a using declaration}}
}
