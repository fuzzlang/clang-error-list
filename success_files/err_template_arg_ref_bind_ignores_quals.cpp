
// Expected error name is: err_template_arg_ref_bind_ignores_quals
namespace reference_parameters {
  template <int& N> struct S0 { }; // expected-note 0-3{{template parameter is declared here}}
  extern const int ci;
  
  void test() {
    S0<ci> s0c; // expected-error{{type 'const int'}}
  }
}
