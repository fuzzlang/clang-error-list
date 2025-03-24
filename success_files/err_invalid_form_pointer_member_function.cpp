
struct S {
    template<typename T> static int f(T);
    template<typename T> static int g(T);
    template<typename T> static int g(T, int);
} s;

int k4 = f(&s.f); // expected-error@-1 {{reference to overloaded function could not be resolved; did you mean to call it?}}
//   expected-note@#cwg115-g-int {{possible target for call}}
//   expected-note@#cwg115-g {{possible target for call}}
