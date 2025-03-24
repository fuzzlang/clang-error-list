
namespace PR8033 {
  template <typename T1, typename T2> int f(T1 *, const T2 *); // expected-note {{candidate function [with T1 = const int, T2 = int]}}
  template <typename T1, typename T2> int f(const T1 *, T2 *); // expected-note {{candidate function [with T1 = int, T2 = const int]}}

  int (*p)(const int *, const int *) = f; // expected-error{{address of overloaded function 'f' is ambiguous}}
}
