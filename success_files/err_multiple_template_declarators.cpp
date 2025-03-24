
template<typename T> struct S {
  static int a, b;
};

template<typename T> int S<T>::a, S<T>::b; // expected-error {{can only declare a single entity}}
