
void example() {
  // expected-error@+1{{invalid OpenACC directive 'invalid'}}
  #pragma acc invalid
  {
    int a = 5;
  }
}
