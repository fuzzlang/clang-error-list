
template<typename T>
struct TPL {
    enum B { Value };
};

template<typename T>
void func() {
    using enum TPL<T>::B; // expected-error{{cannot name a dependent type}}
}
