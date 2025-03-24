
// RUN:  %clang_cc1 -std=c++2a -verify %s

template<typename T>
class A {
  virtual void f1() requires (sizeof(T) == 0); // expected-error {{constraint 'sizeof(T) == 0' is not satisfied}}
};
