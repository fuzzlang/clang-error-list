
namespace cwg1295 { // cwg1295: 4
  struct X {
    unsigned bitfield : 4;
  };

  X x = {1};

  unsigned const &r1 = static_cast<X &&>(x).bitfield; // expected-error {{rvalue references are a C++11 extension}}
  unsigned const &r2 = static_cast<unsigned &&>(x.bitfield); // expected-error {{rvalue references are a C++11 extension}}

  template<unsigned &r> struct Y {}; // #cwg1295-Y
  Y<x.bitfield> y; // #cwg1295-y
}
