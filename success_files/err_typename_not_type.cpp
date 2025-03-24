
using A = int;

template<typename T> using identity_t = T;

struct C {};

struct D { static int type; };

namespace ns {
  using B = int;
  int C = 0;

  static_assert(requires { typename A; typename B; typename ::A; });
  static_assert(!requires { typename ns::A; }); // expected-error{{no type named 'A' in namespace 'ns'}}
  static_assert(!requires { typename ::B; }); // expected-error{{no type named 'B' in the global namespace}}
  static_assert(requires { typename C; }); // expected-error{{typename specifier refers to non-type 'C'}}
}
