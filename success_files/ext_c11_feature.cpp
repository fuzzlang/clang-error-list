
enum E { A, B, C };

void test() {
    int e;
    static_assert(_Generic(e, enum E: int{}, int: 1) == 0); // expected-error {{C11 extension}}
}
