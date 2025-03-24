
struct S {
  explicit operator bool() {
    return true;
  }
};

void example() {
  S b;
  explicit( && b ); // expected-error{{conversion from 'void *' to 'bool' is not allowed in a converted constant expression}}
}
