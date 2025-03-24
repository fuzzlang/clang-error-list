
// expected-error@-1 {{missing 'typename' prior to dependent type name 'Y::type'}}
struct X { static const int type = 0; };
struct Y { typedef int type; };
int a = f<X>();
int b = f<Y>(); // #cwg666-f-Y

#if __cplusplus >= 201103L
namespace cwg667 { // cwg667: 8
  struct A {
    A() = default; // #cwg667-A-ctor
    int &r; // #cwg667-r
  };
  static_assert(!__is_trivially_constructible(A), "");

  struct B { ~B() = delete; };
  union C { B b; };
  static_assert(!__is_trivially_destructible(C), "");

  struct D { D(const D&) = delete; };
  struct E : D {};
  static_assert(!__is_trivially_constructible(E, const E&), "");

  struct F { F &operator=(F&&) = delete; };
  struct G : F {};
  static_assert(!__is_trivially_assignable(G, G&&), "");
}
#endif

#if __cplusplus >= 201103L
namespace cwg669 { // cwg669: yes
  void f() {
    int n;
    using T = decltype(n);
    using T = int;
    using U = decltype((n));
    using U = int &;

    [=] {
      using V = decltype(n);
      using V = int;
      using W = decltype((n));
      using W = const int&;
    } ();

    struct X {
      int n;
      void f() const {
        using X = decltype(n);
        using X = int;
        using Y = decltype((n));
        using Y = const int&;
      }
    };
  }
}
#endif

namespace cwg671 { // cwg671: 2.9
  enum class E { e };
}
