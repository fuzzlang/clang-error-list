
// expected-error@-1 {{constexpr variable 'V2' must be initialized by a constant expression}}

struct S6 {
  unsigned char a;
};

struct S7 {
  union {
    float a;
  };
  unsigned int b;
};

struct S8 {
  unsigned char a[3];
  unsigned int b[3];
};

constexpr struct S8 V2 = {.b = {299, 7, 8}, .a = {-1, 7, 8}};
