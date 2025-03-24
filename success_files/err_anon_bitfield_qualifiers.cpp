
#if __cplusplus >= 201103L
namespace test_anon_bitfield {
struct AnonBitfieldQualifiers {
  const unsigned : 1; // expected-error {{anonymous bit-field cannot have qualifiers}}
};
}
#endif
