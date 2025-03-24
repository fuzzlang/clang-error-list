
struct S {};
template <class T> using remove_const_t = __remove_const(T);

void check_make_signed() {
  static_assert(__is_same(remove_const_t<void>, void));
  static_assert(__is_same(remove_const_t<const void>, void));
  
  // Here the following line will trigger the expected-error
  { using ExpectedError = __make_signed(int&); } // expected-error {{not an unqualified class type}}
}
