
template<typename T>
struct X : public T {
    using T::iterator; // expected-note{{add 'typename' to treat this using declaration as a type}} 
    // expected-error{{dependent using declaration resolved to type without 'typename'}}

    void f() {
        typename X<T>::iterator i; // expected-error{{typename specifier refers to a dependent using declaration for a value 'iterator' in 'X<T>'}}
    }
};

struct HasIterator {
    typedef int* iterator; // expected-note{{target of using declaration}}
};

void test_X(X<HasIterator> xi) { // expected-note{{in instantiation of template class}}
    xi.f();
}
