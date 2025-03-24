
template<typename T> struct x0 { }; // expected-note {{explicitly specialized declaration is here}}

namespace exp_spec {
  template<> struct x0<int> { }; // expected-error {{class template specialization of 'x0' must occur at global scope}}
}
