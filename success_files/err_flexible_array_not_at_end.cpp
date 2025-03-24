
class C {
  char c[]; // expected-error {{flexible array member 'c' with type 'char[]' is not at the end of class}}
  int s; // expected-note {{next field declaration is here}}
};
