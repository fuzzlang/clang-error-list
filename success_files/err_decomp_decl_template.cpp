
namespace Template {
  int n[3];
  template<typename T> auto [a, b, c] = n; // expected-error {{decomposition declaration template not supported}}
}
