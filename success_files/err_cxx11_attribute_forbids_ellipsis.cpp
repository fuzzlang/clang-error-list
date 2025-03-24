
struct T {
    int a;
};

[[gnu::aligned(alignof(T))...]] int x; // expected-error {{cannot be used as an attribute pack}} expected-error {{unexpanded}}
