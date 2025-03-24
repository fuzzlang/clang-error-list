
struct S { int a, b, c; };

namespace InvalidContext {
    class A {
        auto [a, b, c] = S(); // expected-error {{not permitted in this context}}
    };
}
