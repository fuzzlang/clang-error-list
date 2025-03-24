
struct S {};
struct U {};

void test() {
    (void)::new ((S*)0) U; // expected-error {{no matching 'operator new' function for non-allocating placement new expression; include <new>}}
}
