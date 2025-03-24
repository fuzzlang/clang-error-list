
namespace cwg712 {
#if __cplusplus >= 201103L
  void g() {
    struct A { int n; };
    constexpr A a = {0};  // #cwg712-g-a
    struct X {
      void g(bool cond) {
        use(a.n);
        use(a.*&A::n);

        (void)a.n;
        // since-cxx11-error@-1 {{reference to local variable 'a' declared in enclosing function 'cwg712::g'}} FIXME
        //   since-cxx11-note@#cwg712-g-a {{'a' declared here}}
        (void)(a.*&A::n);
        // since-cxx11-error@-1 {{reference to local variable 'a' declared in enclosing function 'cwg712::g'}} FIXME
        //   since-cxx11-note@#cwg712-g-a {{'a' declared here}}
      }
    };
  }
#endif
}

namespace cwg727 {
  struct A {
    template<typename T> struct C; // #cwg727-C
    template<typename T> void f(); // #cwg727-f
    template<typename T> static int N; // #cwg727-N
    // cxx98-11-error@-1 {{variable templates are a C++14 extension}}

    template<> struct C<int>;
    template<> void f<int>();
    template<> int N<int>;

    template<typename T> struct C<T*>;
    template<typename T> static int N<T*>;

    struct B {
      template<> struct C<float>; // expected-error@-1 {{template specialization for 'C<float>' redeclared out of scope}}
    };
  };
}
