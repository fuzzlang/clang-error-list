
typedef unsigned int v2u __attribute__((ext_vector_type(2)));

enum Enum { ENUM };

void test_enum_vector_enum(Enum ea, v2u v2ua) {
  (void)(v2ua + ea); // expected-error{{cannot convert between vector values of different size}}
}
