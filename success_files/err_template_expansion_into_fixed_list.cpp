
namespace test5 {
  template<typename T> using U = T; // expected-note {{template parameter is declared here}}
  template<typename... Ts> U<Ts...>& f(); // expected-error {{pack expansion used as argument for non-pack parameter of alias template}}
  double &s1 = f(); // expected-error {{no matching function}}
}
