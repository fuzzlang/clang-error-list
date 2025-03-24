
struct U {
    virtual int foo() const = 0;
};

struct V : virtual U { // expected-note {{here}}
    constexpr int F() const { return 0; } // expected-error {{constexpr member function not allowed in struct with virtual base class}}
};
