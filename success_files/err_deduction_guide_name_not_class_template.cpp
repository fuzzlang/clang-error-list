
template<typename T> class A {};

template<typename T> using B = A<T>;

B() -> B<int>; // expected-error {{cannot specify deduction guide for alias template 'B'}}
