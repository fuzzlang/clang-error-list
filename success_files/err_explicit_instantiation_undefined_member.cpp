
template <typename T>
struct X0 {
    void f1();
};

// Explicit instantiation of undefined member function
template void X0<int>::f1(); // expected-error{{explicit instantiation of undefined member function}}
