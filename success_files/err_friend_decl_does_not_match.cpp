
namespace PR12585 {
  struct A { };

  template<typename> struct B {
    template<typename> friend struct A::does_not_exist; // expected-error {{redefinition of 'does_not_exist' as different kind of symbol}}
  };

  B<int> b;
}
