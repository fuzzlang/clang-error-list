
[[carries_dependency]]; // expected-error {{'carries_dependency' attribute only applies to parameters, Objective-C methods, and functions}}

class B {
  B([[gnu::unused]] int b);
};
B::B([[gnu::unused]] int b) {}

namespace TestConst {
  [[gnu::const]] int *func1();
  [[gnu::__const]] int *func2();
  [[gnu::__const__]] int *func3();
  void func(const int *);
  void test() { func(func1()); func(func2()); }
  void test2() { func(func3()); }
}

namespace TestASan {
  __attribute__((no_address_safety_analysis)) void func1();
  __attribute__((no_sanitize_address)) void func2();
  [[gnu::no_address_safety_analysis]] void func3();
  [[gnu::no_sanitize_address]] void func4();
}

namespace {
  [[deprecated]] void example();
  // expected-warning@-1 {{use of the 'deprecated' attribute is a C++14 extension}}
  [[deprecated("warning")]] void example2();
  // expected-warning@-1 {{use of the 'deprecated' attribute is a C++14 extension}}
  [[deprecated()]] void example3();
}
