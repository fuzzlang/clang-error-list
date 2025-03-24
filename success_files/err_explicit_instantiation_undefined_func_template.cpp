
struct X0 {
  template<typename T> operator T*() const; // expected-note{{explicit instantiation refers here}}
};

template X0::operator float*() const; // expected-error{{explicit instantiation of undefined function template 'operator type-parameter-0-0 *'}}
