
int main() {
  int n = 0;
  extern auto &[c] = n; // expected-error {{cannot be declared 'extern'}} expected-error {{declaration of block scope identifier with linkage cannot have an initializer}}
}
