
template<typename T>
class A {
public:
    void g(int);
};

template<> void A<int>::g(int) {
    // expected-error@-1 {{template specialization requires 'template<>'}}
}

template<typename U> void A<int>::g(int, U) {
    // expected-error@-1 {{template specialization requires 'template<>'}}
}
