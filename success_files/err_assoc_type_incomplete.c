
struct A: 0; // expected-error {{type 'struct A' in generic association incomplete}}

void foo(int n) {
    (void) _Generic(0,
        struct A: 0, // expected-error {{type 'struct A' in generic association incomplete}}
        int: 0
    );
}
