
void test() {
  int i; // Integer i is not an array or pointer, leading to the expected error
  #pragma acc parallel private(i[0:1]) // The error occurs here
  {
    // Code block required by OpenACC directive
  }
}
