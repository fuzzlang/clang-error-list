
namespace std {
struct type_info;
}

namespace cwg2100 { // cwg2100: 12
  template<const int *P, bool = true> struct X {};
  template<typename T> struct A {
    static const int n = 1;
    int f() {
      return X<&n>::n; // ok, value-dependent
    }
    int g() {
      static const int n = 2; // #cwg2100-n
      return X<&n>::n; // ok, value-dependent
    }
    // Expected error: no linkage for template argument
    static const int *p = &n; // cxx98-error@-1 {{initialization of 'p' requires linkage}}
  };
}
