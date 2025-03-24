
struct B {
  int y;
};

struct A : B {
  int z;
};

auto &&[r] = A{B{1}, 2}; // expected-error-re {{cannot decompose class type 'A': both it and its base class 'B' have non-static data members}}
