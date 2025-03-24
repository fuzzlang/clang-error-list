
void example() {
    __c11_atomic_store(0, 0, 0); // expected-error {{address argument to atomic builtin must be a pointer}}
}
