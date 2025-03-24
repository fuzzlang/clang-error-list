
void my_function() {
  // expected-error@+2{{expected identifier or string literal}}
  // expected-warning@+1{{OpenACC construct 'routine' not yet implemented, pragma ignored}}
  #pragma acc routine(BCP1) bind()
}
