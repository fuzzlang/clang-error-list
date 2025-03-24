
// expected-error@-1{{expected unqualified-id}}
// CHECK: {{^}}struct C {
// CHECK: {{^}}    int [][][];
// CHECK: {{^}}    ^

struct C {
  int [][]; // expected-error
};
