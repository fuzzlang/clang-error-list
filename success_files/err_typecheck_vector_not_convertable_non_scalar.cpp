
typedef unsigned int v2u __attribute__((ext_vector_type(2)));
enum class EnumClass { ENUM };

void test_scoped_enum_vector(EnumClass ea, v2u v2ua) {
  (void)(v2ua + ea); // expected-error{{cannot convert between vector and non-scalar values}}
}
