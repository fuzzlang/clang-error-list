
namespace cwg302 { // cwg302: 3.0
  struct A { A(); ~A(); };
#if __cplusplus < 201103L
  struct B {
    const int n; // #cwg302-B-n
    A a;
  } b = B(); // expected-error@-1 {{implicit default constructor for 'cwg302::B' must explicitly initialize the const member 'n'}}
#endif
}
