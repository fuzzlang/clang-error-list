
namespace cwg136 {
  extern "C" void k(int, int, int, int); // #cwg136-k
  namespace NSA {
    struct A {
      friend void cwg136::k(int, int, int = 0, int); // #cwg136-friend-k
      // expected-error@#cwg136-friend-k {{friend declaration specifying a default argument must be the only declaration}}
      //   expected-note@#cwg136-k {{previous declaration is here}}
    };
  }
}
