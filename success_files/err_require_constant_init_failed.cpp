
namespace ParenInit {
  struct A {
    int a;
  };

  struct B : A {
    int b;
  };

  constexpr B b(A(1), 2);

  struct O {
    int &&j;
  };

  /// Not constexpr!
  O o1(0);
  constinit O o2(0); // both-error {{variable does not have a constant initializer}} \
                      // both-note {{required by 'constinit' specifier}} \
                      // both-note {{reference to temporary is not a constant expression}} \
                      // both-note {{temporary created here}}
}
