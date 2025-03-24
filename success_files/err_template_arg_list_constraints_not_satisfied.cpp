
namespace cwg2512 {
  struct A; // Forward declaration
  void test() {
    // expected-error@-1 {{'typeid' of incomplete type 'A'}}
    typeid(A);
  }
} // namespace cwg2512

namespace cwg2516 {
#if __cplusplus >= 201103L
  template <typename T> struct S {
    typedef char I;
  };
  enum E2 : S<E2>::I { e }; // since-cxx11-error@-1 {{use of undeclared identifier 'E2'}}
#endif
} // namespace cwg2516

namespace cwg2518 {
#if __cplusplus >= 201103L
  template <class T>
  void f(T t) {
    if constexpr (sizeof(T) != sizeof(int)) {
      // cxx11-14-error@-1 {{constexpr if is a C++17 extension}}
      static_assert(false, "must be int-sized");
      // since-cxx11-error@-1 {{static assertion failed: must be int-sized}}
    }
  }

  void g(char c) {
    f(0);
    f(c); // #cwg2518-f-c
  }

  template <typename Ty>
  struct S {
    static_assert(false); // cxx11-14-error@-1 {{'static_assert' with no message is a C++17 extension}}
  };

  template <>
  struct S<int> {};

  template <>
  struct S<float> {};

  int test_specialization() {
    S<int> s1;
    S<float> s2;
    S<double> s3; // #cwg2518-S-double
  }
#endif
}

namespace cwg2521 {
#if __cplusplus >= 201103L
  long double operator"" _\u03C0___(long double); // since-cxx11-warning@-2 {{user-defined literal suffixes containing '__' are reserved}}

  template <char... Chars> decltype(sizeof 0) operator"" _div(); // since-cxx11-warning@-1 {{identifier '_div' preceded by whitespace in a literal operator declaration is deprecated}}
#endif
} // namespace cwg2521

#if __cplusplus >= 202302L
namespace cwg2553 {
struct B {
  virtual void f(this B&); 
  // since-cxx23-error@-1 {{an explicit object parameter cannot appear in a virtual function}}
};
} 
#endif

#if __cplusplus >= 202302L
namespace cwg2554 {
struct B {
  virtual void f(); // #cwg2554-g
};

struct D : B {
  void f(this D&);
  // since-cxx23-error@-1 {{an explicit object parameter cannot appear in a virtual function}}
};
} 
#endif

#if __cplusplus >= 202302L
namespace cwg2561 {
struct C {
    constexpr C(auto) { }
};

void foo() {
    constexpr auto b = [](this C) { return 1; };
    constexpr int (*fp)(C) = b; // constexpr int (*fp)(C) = b; // static_assert failed
}
}
#endif

namespace cwg2565 {
#if __cplusplus >= 202002L
  template<typename T>
    concept C = requires (typename T::type x) {
      x + 1;
    };
  static_assert(!C<int>);

  template<typename T, typename U>
    concept TwoParams = requires (T *a, U b) { true; }; // #cwg2565-TPC

  template<typename T, typename U>
    requires TwoParams<T, U> // #cwg2565-TPSREQ
  struct TwoParamsStruct {};

  using TPSU = TwoParamsStruct<void, void>; // This will trigger an error
#endif
}
