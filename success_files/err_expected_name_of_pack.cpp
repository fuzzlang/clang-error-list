
class PR47176 {
  friend void f(PR47176, int = 0) noexcept(true) {}
};
static_assert(noexcept(f(PR47176())), "");

struct Base { virtual void f() = 0; virtual void g() = 0; virtual void h() = 0; };
struct MemberComponentOrder : Base {
  void f() override __asm__("foobar") __attribute__(( )) {}
  void g() __attribute__(( )) override;
  void h() __attribute__(( )) override {}
};

void NoMissingSemicolonHere(struct S
                            [3]); // expected-error@-1 {{expected ';' after alias declaration}}
template<int ...N> void NoMissingSemicolonHereEither(struct S... [N]); // expected-error@-1 {{expected ';' after alias declaration}}
