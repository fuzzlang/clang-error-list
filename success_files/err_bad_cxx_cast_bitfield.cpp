
struct S {
    int a : 1;
};

void foo() {
    S x;
    int *y = &reinterpret_cast<int&>(x.a); // expected-error {{reinterpret_cast from bit-field lvalue to reference type 'int &'}}
}
