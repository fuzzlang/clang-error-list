
struct B {};

struct D : public B {
    D(B &) = delete; // expected-error@-1 {{deleted function definitions are a C++11 extension}}
};

extern D d1;
B &b = d1;
const D &d2 = static_cast<const D&>(b);

// The following lines generate the expected error regarding conversion
const D &d3 = (const D&)b;
const D &d4(b); // expected-error@-1 {{conversion function from 'B' to 'const D' invokes a deleted function}}
