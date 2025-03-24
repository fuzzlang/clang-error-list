
namespace cwg1443 { // cwg1443: yes
struct A {
  int i;
  A() { void foo(int=i); } // expected-error@-1 {{use of undeclared identifier 'var5'}}
};

void bar() {
  A a;
}
}

namespace cwg1423 { // cwg1423: 11
#if __cplusplus >= 201103L
  bool b1 = nullptr; // since-cxx11-error@-1 {{cannot initialize a variable of type 'bool' with an rvalue of type 'std::nullptr_t'}}
  bool b2(nullptr); // since-cxx11-error@-2 {{cannot initialize a variable of type 'bool' with an rvalue of type 'std::nullptr_t'}}
  bool b3 = {nullptr}; // since-cxx11-error@-3 {{cannot initialize a variable of type 'bool' with an rvalue of type 'std::nullptr_t'}}
  bool b4{nullptr}; // since-cxx11-error@-4 {{cannot initialize a variable of type 'bool' with an rvalue of type 'std::nullptr_t'}}
#endif
}
