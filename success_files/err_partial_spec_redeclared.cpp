
template<typename T, typename U>
struct Outer {
  template<typename X, typename Y> struct Inner;
  template<typename Y> struct Inner<T, Y> {}; // expected-note{{previous declaration of class template partial specialization 'Inner<int, type-parameter-0-0>' is here}}
  template<typename Y> struct Inner<U, Y> {}; // expected-error{{cannot be redeclared}}
};

Outer<int, int> outer; // expected-note{{instantiation}}
