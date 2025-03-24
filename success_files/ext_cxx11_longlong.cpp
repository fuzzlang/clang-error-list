
// expected-error@-1 {{declaration of 'cwg171b' with C language linkage conflicts with declaration in global scope}}
//   expected-note@#cwg171b-int {{declared in global scope here}}

extern "C" {
    int cwg171b; // Conflicting declaration
}

namespace cwg172 { // cwg172: yes
  enum { zero };
  static_assert(-1 < zero, "");

  enum { x = -1, y = (unsigned int)-1 };
  static_assert(sizeof(x) > sizeof(int), "");

  enum { a = (unsigned int)-1 / 2 };
  static_assert(sizeof(a) == sizeof(int), "");
  static_assert(-a < 0, "");

  enum { b = (unsigned int)-1 / 2 + 1 };
  static_assert(sizeof(b) == sizeof(unsigned int), "");
  static_assert(-b > 0, "");

  enum { c = (unsigned long)-1 / 2 };
  static_assert(sizeof(c) == sizeof(long), "");
  static_assert(-c < 0, "");

  enum { d = (unsigned long)-1 / 2 + 1 };
  static_assert(sizeof(d) == sizeof(unsigned long), "");
  static_assert(-d > 0, "");

  enum { e = (unsigned long long)-1 / 2 };
  static_assert(sizeof(e) == sizeof(unsigned long long), "");
  static_assert(-e < 0, "");
}
