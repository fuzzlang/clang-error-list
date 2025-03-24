
namespace reference_to_function {
  template<int (&)(int)> struct X0 { }; // expected-note 0-4{{template parameter is declared here}}
  int f(int);
  int f(float);
  int g(float);
  void x0b(X0<&f>); // expected-error{{address taken in non-type template argument for template parameter of reference type 'int (&)(int)'}}
}
