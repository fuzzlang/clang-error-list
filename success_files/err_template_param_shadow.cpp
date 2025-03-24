
namespace cwg281 { // cwg281: no
  void a();
  inline void b();

  void d();
  inline void e();

  struct S {
    friend inline void a(); // expected-error@-1 {{call to object of type 'struct S' is ambiguous}}
    friend inline void b(); // expected-note@#cwg281-B-f3 {{conversion candidate of type 'void (*)()'}}
    friend inline void c(); // expected-note@#cwg281-C-f3 {{conversion candidate of type 'void (*)()'}}
    friend inline void d() {}
    friend inline void e() {}
    friend inline void f() {}
  };
}

namespace cwg283 { // cwg283: yes
  template<typename T> // #cwg283-template
  struct S {
    friend class T; 
  };
}
