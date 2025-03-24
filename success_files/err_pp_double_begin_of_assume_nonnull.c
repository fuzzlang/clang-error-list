
void foo() {
  #pragma clang assume_nonnull begin // expected-error{{already inside '#pragma clang assume_nonnull'}}
  #pragma clang assume_nonnull begin
}
