
struct A {
  char i;
  double j;
};

struct B {
  A a;
  int b[20];
  int &&c;
};

struct C {
  A a;
  int b[20];
};

struct D : public C, public A {
  int a;
};

struct E {
  struct F {
    F(int, int);
  };
  int a;
  F f;
};

struct N {
private:
    N(int);
};

struct M {
    int i;
    N n; // expected-error@-1 {{field of type 'N' has private constructor}}
};

int main() {
    M m(1, 1); // expected-error@-1 {{field of type 'N' has private constructor}}
    return 0;
}
