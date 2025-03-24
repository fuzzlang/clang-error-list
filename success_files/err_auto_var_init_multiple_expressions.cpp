
namespace cwg1330 {
  template<typename T>
  struct C {};
  
  struct D : C<void> {}; // #cwg1330-C-void
  void f(D &d) { d = d; } // ok
  
  struct E : C<int> {}; // #cwg1330-C-int
  E e; // #cwg1330-e
}

namespace cwg1340 {
  struct A;
  struct B;

  void f(B* a, A B::* p) {
    (*a).*p;
    a->*p;
  }
}

namespace cwg1341 {
#if __cplusplus >= 202002L
  int a;
  const int b = 0; // #cwg1341-b
  struct S {
    int x1 : 8 = 42;
    int x2 : 8 { 42 };
    int y1 : true ? 8 : a = 42;
    int y2 : true ? 8 : b = 42; // since-cxx20-error@-1 {{cannot assign to variable 'b' with const-qualified type 'const int'}}
    int y3 : (true ? 8 : b) = 42;
    int z : 1 || new int { 0 };
  };
#endif
}

namespace cwg1346 {
  auto a(1); // cxx98-error@-1 {{'auto' type specifier is a C++11 extension}}
  auto b(1, 2);
}
