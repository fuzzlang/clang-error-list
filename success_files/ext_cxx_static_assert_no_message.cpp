
namespace cwg2512 {
// expected-error@-1 {{'typeid' of incomplete type 'A'}}
//   expected-note@#cwg2512-A {{forward declaration of 'cwg2512::A'}}
struct A; // Incomplete type
}

namespace cwg2516 { 
#if __cplusplus >= 201103L
template <typename T> struct S {
  typedef char I;
};
enum E2 : S<E2>::I { e }; // since-cxx11-error@-1 {{use of undeclared identifier 'E2'}}
#endif
}

namespace cwg2518 { 

#if __cplusplus >= 201103L
template <class T>
void f(T t) {
  if constexpr (sizeof(T) != sizeof(int)) {
    // cxx11-14-error@-1 {{constexpr if is a C++17 extension}}
    static_assert(false, "must be int-sized");
    // since-cxx11-error@-1 {{static assertion failed: must be int-sized}}
    //   since-cxx11-note@#cwg2518-f-c {{in instantiation of function template specialization 'cwg2518::f<char>' requested here}}
  }
}

void g(char c) {
  f(0);
  f(c); // #cwg2518-f-c
}

template <typename Ty>
struct S {
  static_assert(false); // static assertion failure
};
#endif

}
