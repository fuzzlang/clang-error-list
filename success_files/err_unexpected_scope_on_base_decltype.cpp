
struct Base {
    void function() {}
};

struct Derived4 : ::decltype(Base()) { }; // expected-error {{unexpected namespace scope prior to decltype}}
