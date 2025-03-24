
template<typename T>
struct X0 {
    template<typename U, typename V>
    struct Inner;

    void f0(X0<T>::Inner<T*, T&>); // expected-note{{here}}
    void f0(typename X0<T>::Inner<T*, T&>); // expected-error{{redecl}}
};
