
namespace cwg625 { // cwg625: yes
  template<typename T> struct A {};
  A<auto> x = A<int>(); // expected-error@-1 {{redefinition of 'f<int>'}}
  // expected-note@#cwg621-f {{previous definition is here}}
}
