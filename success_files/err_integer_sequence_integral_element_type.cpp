
template <class T, T... I>
struct Seq {
  static constexpr T PackSize = sizeof...(I);
};

template <typename T, T N>
using ErrorSeq = __make_integer_seq<Seq, T, N>; // expected-error{{must have non-negative sequence length}} expected-error{{must have integral element type}}

enum Color : int { Red, Green, Blue };
using illformed1 = ErrorSeq<Color, Blue>; // expected-note{{in instantiation}}
using illformed2 = ErrorSeq<int, -5>; // expected-note{{in instantiation}}
