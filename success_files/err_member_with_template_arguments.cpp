
template <typename T>
struct A {};

template <typename T>
struct B {
  T(A<T>){}; // expected-error{{member 'A' cannot have template arguments}}
};
