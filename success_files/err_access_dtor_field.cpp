
namespace ArrayNewNeedsDtor {
  struct A { A(); private: ~A(); };
#if __cplusplus <= 199711L
  // expected-note@-2 {{declared private here}}
#endif
  struct B { B(); A a; }; // expected-error {{field of type 'A' has private destructor}}

  B *test() {
    return new B[5]; 
  }
}
