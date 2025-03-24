
namespace reference_to_function {
  template<int (&)(int)> struct X0 { }; // expected-note 0-4{{template parameter is declared here}}
  int f(int);
  int f(float);
  int g(float);
  
  void x0c(X0<g>); // expected-error{{non-type template parameter of reference type 'int (&)(int)' cannot bind to template argument of type 'int (float)'}}
}
