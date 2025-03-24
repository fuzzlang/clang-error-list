
struct foo {
    int y[]; // flexible array member
};

struct foo design_foo2 = { .y = 2 }; // expected-error{{flexible array requires brace-enclosed initializer}}
