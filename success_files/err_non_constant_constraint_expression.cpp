
template <typename T>
constexpr bool f4() {
  [[assume(!T{})]]; // expected-error {{invalid argument type 'T'}} // expected-warning 2 {{assumption is ignored because it contains (potential) side-effects}} ext-warning {{C++23 extension}}
  return sizeof(T) == sizeof(int);
}

template <typename T>
concept C = f4<T>(); // expected-note 3 {{in instantiation of}}

struct D {
  int x;
};

static_assert(C<D>); // expected-error@-1 {{resulted in a non-constant expression}} expected-note@-2 {{while substituting}}
