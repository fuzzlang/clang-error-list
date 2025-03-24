
namespace foo1::foo2::foo3 {
#if __cplusplus <= 201400L
// expected-warning@-2 {{nested namespace definition is a C++17 extension; define each namespace separately}}
#else
// expected-warning@-4 {{nested namespace definition is incompatible with C++ standards before C++17}}
#endif
  int foo(int x) { return x; }
}

#ifndef FIXIT
inline namespace goo::bar { // expected-error {{nested namespace definition cannot be 'inline'}} expected-warning 0-1{{C++11 feature}}
  int n;
}
#endif

int m = goo::bar::n;
