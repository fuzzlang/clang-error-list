
namespace cwg585 { // cwg585: 3.0
  template<typename> struct T; // #cwg585-struct-T
  struct A {
    friend T; // expected-error@-1 {{a type specifier is required for all declarations}}
    // expected-error@-2 {{friends can only be classes or functions}}
    // since-cxx17-error@-3 {{use of class template 'T' requires template arguments; argument deduction not allowed in friend declaration}}
    template<typename U> friend T<U>; // expected-error@-3
  };
}
