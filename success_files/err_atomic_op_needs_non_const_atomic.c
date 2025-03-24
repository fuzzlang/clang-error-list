
void test() {
    const _Atomic int ci;
    __c11_atomic_init(&ci, 5); // expected-error {{address argument to atomic operation must be a pointer to non-const _Atomic type ('const _Atomic(int) *' invalid)}}
}
