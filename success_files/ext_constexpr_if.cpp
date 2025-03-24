
namespace cwg2512 {
struct A; // Forward declaration of 'A'
  
void func() {
  typeid(A); // expected-error@-1 {{'typeid' of incomplete type 'A'}}
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
    // Some logic here
  }
}
#endif
} // namespace cwg2518
