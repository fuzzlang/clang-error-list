
// expected-error@-2 {{specialization of member 'cwg531::bad::A<char>::C' does not specialize an instantiated member}}
// expected-note@#cwg531-C {{attempt to specialize declaration here}}
template<typename T>
struct A;

template<>
struct A<char> {
    template<typename U>
    struct C; // Declaration of C
};

template<> template<typename U> struct A<char>::C {}; // Incorrect specialization
