
template <int N>
struct D {
  ~D() requires(N != 0) = delete; // expected-note {{explicitly marked deleted}}
  ~D() requires(N == 1) = delete;  // expected-note {{explicitly marked deleted}}
};

template struct D<0>; // expected-error {{no viable destructor found for class 'D<0>'}} expected-note {{in instantiation of template}}
