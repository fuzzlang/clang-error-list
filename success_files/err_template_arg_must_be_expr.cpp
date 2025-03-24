
template <int N>
struct A { };

void test() {
    A<int> *a2; // expected-error{{template argument for non-type template parameter must be an expression}}
}
