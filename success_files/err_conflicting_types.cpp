
namespace cwg4 { // cwg4: 2.8
  extern "C" {
    static void cwg4_f(int) {}
    static void cwg4_f(float) {}
    void cwg4_g(int) {} // #cwg4-g-int
    void cwg4_g(float) {} // expected-error@-1 {{conflicting types for 'cwg4_g'}}
    //   expected-note@#cwg4-g-int {{previous definition is here}}
  }
}
