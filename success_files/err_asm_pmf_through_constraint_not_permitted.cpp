
// RUN: %clang_cc1 -triple x86_64-unknown-windows-msvc -std=c++23 -fsyntax-only %s -verify
// RUN: %clang_cc1 -triple x86_64-unknown-windows-itanium -std=c++23 -fsyntax-only %s -verify

struct S {
  void operator()();
};

struct T {
  virtual void operator()();
};

struct U {
  static void operator()();
};

struct V : virtual T {
  virtual void f();
};

struct W : virtual V {
  int i;
};

struct X {
  __UINTPTR_TYPE__ ptr;
  __UINTPTR_TYPE__ adj;
};

auto L = []() {};

void f() {
  auto pmf = &S::operator();

  __asm__ __volatile__ ("" : : "r"(&decltype(L)::operator()));  // Error: iserr_asm_pmf_through_constraint_not_permitted
}
