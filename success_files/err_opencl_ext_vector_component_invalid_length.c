
typedef float float8 __attribute__((ext_vector_type(8)));

void foo(void) {
    float8 f2 = (float8)(0, 0, 0, 0, 0, 0, 0, 0);
    f2.s01234; // expected-error {{vector component access has invalid length 5; supported lengths are: 1,2,3,4,8,16}}
}
