
namespace class_with_ctor {
  struct A { // cxx20-note 6{{candidate}}
    A() = default; // cxx20-note 3{{candidate}}
    int x;
    int y;
  };
  A a = {1, 2}; // cxx20-error {{no matching constructor}}

  struct B {
    int x;
    int y;
  };
  B b1 = B(); // trigger declaration of implicit ctors
  B b2 = {1, 2}; // ok

  struct C : A {
    A a;
  };
  C c1 = {{}, {}}; // ok, call default ctor twice
  C c2 = {{1, 2}, {3, 4}}; // cxx20-error 2{{no matching constructor}}
}

namespace designator {
struct A { int x, y; };
struct B { A a; };

A a1 = {
  .y = 1, // reorder-note {{previous initialization for field 'y' is here}}
  .x = 2 // reorder-error {{ISO C++ requires field designators to be specified in declaration order; field 'y' will be initialized after field 'x'}}
};
int arr[3] = {[1] = 5}; // pedantic-error {{array designators are a C99 extension}}
B b = {.a.x = 0}; // pedantic-error {{nested designators are a C99 extension}}
A a2 = {
  .x = 1, // pedantic-error {{mixture of designated and non-designated initializers in the same initializer list is a C99 extension}}
  2 // pedantic-note {{first non-designated initializer is here}}
};
A a3 = {
  1, // pedantic-note {{first non-designated initializer is here}}
  .y = 2 // pedantic-error {{mixture of designated and non-designated initializers in the same initializer list is a C99 extension}}
};
A a4 = {
  .x = 1, // override-note {{previous}}
  .x = 1 // override-error {{overrides prior initialization}}
}; // wmissing-designated-warning {{missing field 'y' initializer}}
A a5 = {
  .y = 1, // override-note {{previous}}
  .y = 1 // override-error {{overrides prior initialization}}
}; // wmissing-designated-warning {{missing field 'x' initializer}}
B b2 = {.a = 1}; // pedantic-error {{brace elision for designated initializer is a C99 extension}}
}
