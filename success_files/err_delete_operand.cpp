
namespace cwg599 { // cwg599: partial
  typedef int Fn();
  struct S { operator void*(); };
  struct T { operator Fn*(); };
  struct U { operator int*(); operator void*(); }; // #cwg599-U
  struct V { operator int*(); operator Fn*(); };

  void f(void *p, void (*q)()) {
    delete p;
    // cxx98-23-error@-1 {{cannot delete expression with pointer-to-'void' type 'void *'}}
    // since-cxx26-error@-2 {{cannot delete pointer to incomplete type 'void'}}
    delete q;
  }

  int &t = h(N::i); // expected-error@-1 {{use of undeclared identifier 'h'}}
}
