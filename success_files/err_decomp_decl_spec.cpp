
extern auto &[c] = n; // expected-error {{cannot be declared 'extern'}}
int n; // Declaration of n, required for the initializer
// expected-error {{declaration of block scope identifier with linkage cannot have an initializer}}
