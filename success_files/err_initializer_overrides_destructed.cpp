
struct NonTrivial {
  NonTrivial() {}
  ~NonTrivial() {}
};

struct S {
  int a;
  NonTrivial b;
};

struct T {
  S s;
};

S f();

void test() {
  T t1 = {
    .s = f()
  };

  T t2 = {
    .s = f(), // expected-note {{previous}}
    .s.b = NonTrivial() // expected-error {{initializer would partially override prior initialization of object of type 'S' with non-trivial destruction}}
  };
}
