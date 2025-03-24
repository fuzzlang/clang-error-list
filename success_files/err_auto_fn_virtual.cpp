
class Base {
public:
    virtual auto f() { return 0; } // expected-error {{function with deduced return type cannot be virtual}} expected-note {{here}}
};

class Derived : public Base {
public:
    auto f() override { return 1; }
};
