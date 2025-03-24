
namespace cwg69 {
  template<typename T> static void f() {} // #cwg69-f
  inline void g() { f<int>(); }
  extern template void f<char>(); // expected-error@-1 {{explicit instantiation declaration of 'f' with internal linkage}}
}
