
struct A { };

A::A() { } // expected-error {{definition of implicitly declared default constructor}}
