
void TEST(void) {
  __try {
    // some code
  }
}  // expected-error{{expected '__except' or '__finally' block}}
