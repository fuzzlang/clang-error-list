
namespace cwg407 {
  namespace A {
    struct S {};
  }
  
  namespace B {
    struct S {};
  }

  namespace D {
    using A::S; // expected-error@-1 {{ambiguous}}
    typedef struct S S;
    struct S s;
  }

  namespace E {
    typedef A::S S; 
    using A::S; 
    struct S s;
  }
  
  namespace F {
    typedef A::S S;
  }
  
  namespace G {
    using namespace A;
    using namespace F;
    struct S s;
  }
  
  namespace H {
    using namespace F;
    using namespace A;
    struct S s;
  }
}

namespace cwg408 { 
  template<int N> void g() { static_assert(N != 1, ""); }
  template<> void g<2>() { }

  template<typename T> struct S {
    static int i[];
    void f();
  };
  
  template<typename T> int S<T>::i[] = { 1 };

  template<typename T> void S<T>::f() {
    g<sizeof (i) / sizeof (int)>();
  }
  
  template<> int S<int>::i[] = { 1, 2 };
  template void S<int>::f(); 

  template<typename T> struct R {
    static int arr[];
    void f();
  };
  
  template<typename T> int R<T>::arr[1];
  
  template<typename T> void R<T>::f() {
    static_assert(sizeof(arr) != sizeof(int), "");
  }
  
  template<> int R<int>::arr[2];
  template void R<int>::f();
}

namespace cwg409 {
  template<typename T> struct A {
    typedef int B;
    B b1;
    A::B b2; // expected-error@-1 {{ambiguous}}
    A<T>::B b3;
    A<T*>::B b4;
  };
}
