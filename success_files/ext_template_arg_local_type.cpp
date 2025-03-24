
namespace cwg488 { // cwg488: yes c++11
  template <typename T> void f(T);
  void f(int);
  void g() {
    enum E { e };
    f(e); // expected-error@-1 {{expression is not an integral constant expression}}
    //   since-cxx11-note@-2 {{non-constexpr function 'operator+' cannot be used in a constant expression}}
    //   since-cxx11-note@#cwg487-operator-plus {{declared here}}
  }
}
