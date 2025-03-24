
// expected-error@-1 {{use of typeid requires -frtti}}
namespace std {
  class type_info;
}

void f() {
  (void)typeid(int); // expected-error {{use of typeid requires -frtti}}
}
