
int main() {
  float x; // expected-error {{redefinition of 'x'}}
  int x;   // redefinition with a different type
  return 0;
}
