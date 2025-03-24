
namespace cwg313 { // cwg313: dup 299 c++11
  struct A { operator int() const; };
  
  int *p = new int[A()]; // expected-error@-4 {{expected ';' after top level declarator}}
}
