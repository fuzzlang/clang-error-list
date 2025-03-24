
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++14 %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++98 %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++11 %s

char *const_cast_test(const char *var)
{
  return const_cast<char*>(var);
}

struct A {
  virtual ~A() {}
};

struct B : public A {
};

struct B *dynamic_cast_test(struct A *a)
{
  return dynamic_cast<struct B*>(a);
}

char *reinterpret_cast_test()
{
  return reinterpret_cast<char*>(0xdeadbeef);
}

double static_cast_test(int i)
{
  return static_cast<double>(i);
}

char postfix_expr_test()
{
  return reinterpret_cast<char*>(0xdeadbeef)[0];
}

// This was being incorrectly tentatively parsed.
namespace test1 {
  template <class T> class A {}; // expected-note 2{{here}}
  void foo() { A<int>(*(A<int>*)0); } // expected-warning {{binding dereferenced null pointer to reference has undefined behavior}}
}

typedef char* c;
typedef A* a;

void test2(char x, struct B * b) {
  (void)const_cast<::c>(&x); /* expected-error {{missing whitespace after '<<'}} */
}
