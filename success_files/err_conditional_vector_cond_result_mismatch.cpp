
using FourShorts = short __attribute__((ext_vector_type(4)));
using FourShortsVS = short __attribute__((__vector_size__(8)));

FourShorts four_shorts;

void mix_vector_types() {
  FourShortsVS vs;
  (vs == 1 ? four_shorts : four_shorts); // expected-error {{cannot mix vectors and extended vectors in a vector conditional}}
}
