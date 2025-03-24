
namespace cwg389 { // cwg389: no
  struct S {
    typedef struct {} A;
    typedef enum {} B;
    typedef struct {} const C; // #cwg389-C
    typedef enum {} const D; // #cwg389-D
  };
  template<typename> struct T {};

  struct WithLinkage1 {};
  enum WithLinkage2 {};
  typedef struct {} *WithLinkage3a, WithLinkage3b;
  typedef enum {} WithLinkage4a, *WithLinkage4b;
  typedef S::A WithLinkage5;
  typedef const S::B WithLinkage6;
  typedef int WithLinkage7;
  typedef void (*WithLinkage8)(WithLinkage2 WithLinkage1::*, WithLinkage5 *);
  typedef T<WithLinkage5> WithLinkage9;

  typedef struct {} *WithoutLinkage1; // #cwg389-no-link-1
  typedef enum {} const WithoutLinkage2; // #cwg389-no-link-2
  typedef S::C WithoutLinkage3;
  typedef S::D WithoutLinkage4;
  typedef void (*WithoutLinkage5)(int (WithoutLinkage3::*)(char));

  typedef T<WithoutLinkage1> BadArg1; // expected-error@-1 {{use of undeclared identifier 'gcd'}}
}
