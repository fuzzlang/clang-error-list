
struct __declspec(code_seg("my_one")) FooOne {
  int barC();
};

struct FooTwo {
  int __declspec(code_seg("my_three")) barD();
  int barE();
};

int __declspec(code_seg("my_four")) FooOne::barC() { return 10; }
// expected-warning@-1 {{codeseg does not match previous declaration}}
// expected-note@3{{previous attribute is here}}
int __declspec(code_seg("my_five")) FooTwo::barD() { return 20; }
// expected-warning@-1 {{codeseg does not match previous declaration}}
// expected-note@8 {{previous attribute is here}}
int __declspec(code_seg("my_six")) FooTwo::barE() { return 30; }
// expected-warning@-1 {{codeseg does not match previous declaration}}
// expected-note@9 {{previous declaration is here}}

// Microsoft docs say:
// If a base-class has a code_seg attribute, derived classes must have the
// same attribute.
struct __declspec(code_seg("my_base")) Base1 {};
struct Base2 {};

struct D1 : Base1 {};
struct D2 : Base2 {}; // expected-error {{incompatible code_seg attributes}} 
