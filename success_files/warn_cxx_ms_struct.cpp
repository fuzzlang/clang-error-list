
#ifndef NO_PRAGMA
#pragma ms_struct on
#endif

struct A {
  unsigned long a : 4;
  unsigned char b;
};

struct B : public A {
  unsigned long c : 8;
};

struct C {
  B b;
};
