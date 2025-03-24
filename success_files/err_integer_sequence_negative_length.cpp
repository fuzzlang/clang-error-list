
// Reproducing the error iserr_integer_sequence_negative_length.
template <template <class T, T...> class Seq, typename T, T N>
using ErrorSeq = __make_integer_seq<Seq, T, N>; // expected-error{{must have non-negative sequence length}}

template <typename T, T... Ints>
struct MySeq {};

void foo() {
  ErrorSeq<MySeq, int, -5> seq; // Attempting to create a sequence with a negative length.
}
