
// expected-error@-1 {{redefinition of 'f'}}
//   expected-note@#cwg140-f-first {{previous definition is here}}
void g(const int);
void g(int n) { n = 2; }

namespace cwg141 { // cwg141: 3.1
  template<typename T> void f();
  template<typename T> struct S { int n; }; // #cwg141-S
  struct A : S<int> {
    template<typename T> void f();
    template<typename T> struct S {}; // #cwg141-A-S
  } a;
  struct B : S<int> {} b;
  void g() {
    a.f<int>();
    (void)a.S<int>::n; // #cwg141-a
  }
}
