
template <typename T>
struct X {
  static constinit int n; // expected-error {{constinit is missing an initializer}}
};

template <typename T>
int X<T>::n = 123; 
