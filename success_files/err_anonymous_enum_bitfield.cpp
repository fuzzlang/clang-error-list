
namespace cwg2157 { // cwg2157: 11
#if __cplusplus >= 201103L
  enum E : int; // expected-error@-1 {{'E' cannot be defined in a type specifier}}
  struct X {
    enum E : int(); // expected-error@-1 {{'E' cannot be defined in a type specifier}}
  };
#endif
}
