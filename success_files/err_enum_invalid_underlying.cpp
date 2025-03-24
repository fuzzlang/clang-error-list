
namespace cwg_test {
  struct A {
    enum E : int { 1 };
    // since-cxx11-error@-1 {{expected identifier}} (not bit-field)
  };

  auto *p1 = new enum E : int;
  // since-cxx11-error@-1 {{non-defining declaration of enumeration with a fixed underlying type is only permitted as a standalone declaration}}

  auto *p2 = new enum F : int {};
  // since-cxx11-error@-1 {{non-defining declaration of enumeration with a fixed underlying type is only permitted as a standalone declaration}}

  auto *p3 = true ? new enum G : int {} : nullptr;
  // since-cxx11-error@-1 {{ISO C++ forbids forward references to 'enum' types}}
  // since-cxx11-error@-2 {{allocation of incomplete type 'enum G'}}
  //   since-cxx11-note@-3 {{forward declaration of 'cwg_test::G'}}

  auto h() -> enum E : int {};
  // since-cxx11-error@-1 {{non-defining declaration of enumeration with a fixed underlying type is only permitted as a standalone declaration}}

  enum X : enum Y : int {} {};
  // since-cxx11-error@-1 {{'cwg_test::Y' cannot be defined in a type specifier}}

  struct Q {
    enum X : enum Y : int {} {};  
    // expected-error@-1 {{'cwg_test::Y' cannot be defined in a type specifier}}
  };
}
