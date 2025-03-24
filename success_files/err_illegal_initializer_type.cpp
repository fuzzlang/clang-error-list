
template <typename T> struct E {
  // expected-note@+1 {{candidate constructor}}
  explicit((T{}, false)) // expected-error {{illegal initializer type 'void'}}
  E(int);
};

E<void> e(1); // expected-note {{in instantiation of template class 'E<void>' requested here}}
