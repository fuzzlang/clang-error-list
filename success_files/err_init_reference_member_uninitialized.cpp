
// RUN: %clang_cc1 -verify -std=c++20 %s -fsyntax-only

struct A { // expected-note 4{{candidate constructor}}
  char i;
  double j;
};

struct B {
  A a;
  int b[20];
  int &&c; // expected-note@-1 {{uninitialized reference member is here}}
};

struct C {
  A a;
  int b[20];
};

struct D : public C, public A {
  int a;
};

struct O {
  int i;
  int &&j; // expected-note@-1 {{uninitialized reference member is here}}
  int &&k = 1;
};

O o1(0, 0, 0); // no-error
O o2(0, 0); // no-error
O o3(0); // expected-error@-1 {{reference member of type 'int &&' uninitialized}}
