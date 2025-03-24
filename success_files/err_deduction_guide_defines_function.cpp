
template<typename T>
struct A {
    A(T) {}
};

template<typename T>
A(T(&)[40]) -> A<T>; // deduced

A(int(&)[40]) -> A<int> {} // expected-error {{deduction guide cannot have a function definition}}
