
template<typename T>
struct A {};

typedef A(int(&)[21]) -> A<int>; // expected-error {{deduction guide cannot be declared 'typedef'}}
