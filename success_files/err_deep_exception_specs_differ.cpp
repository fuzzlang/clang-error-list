
struct A {};
struct B1 : A {};
struct B2 : A {};
struct D : B1, B2 {};
void (*s8())() throw(B1); // s8 returns a pointer to function with spec

void fnptrs() {
    void (*(*t8)())() throw(A) = &s8;  // expected-error {{return types differ}}
}
