
float TEST_FUNC(bool p1);

float builtin_exp_int_to_float_promotion(int p1) {
  return TEST_FUNC(p1); // expected-error@-1 {{1st argument must be a vector, integer or floating point type (was 'bool')}}
}
