
template<typename T>
struct C;

template<typename T>
auto C<T>::f() -> decltype(x) { } // expected-error {{use of undeclared identifier 'x'}}
