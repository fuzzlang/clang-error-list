
namespace typename_specifier {
  struct X { template<typename T> struct A { A(T); }; };

  template<typename T> void f() {
    {(void)(typename T::A)(0);} // expected-error{{refers to class template member}}
  }
  template void f<X>();
}
