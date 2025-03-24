
namespace cwg1346 { // cwg1346: 3.5
  auto x(1); // expected-error@-1 {{'auto' type specifier is a C++11 extension}}
  void f() {
#if __cplusplus >= 201103L
    [b(1, 2)] {} (); // expected-error@-1 {{initialized lambda captures are a C++14 extension}}
                     // since-cxx11-error@-2 {{initializer for lambda capture 'b' contains multiple expressions}}
#endif
  }
  template void f(); // #cwg1346-f
}
