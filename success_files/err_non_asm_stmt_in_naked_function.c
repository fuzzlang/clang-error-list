
void __attribute__((naked)) myNakedFunction() {
  return 42; // expected-error{{non-ASM statement in naked function is not supported}}
}
