
kernel void test_exceptions() {
  int x;
  try {
    // expected-error@-1 {{cannot use 'try' with exceptions disabled}}
    throw 0;
    // expected-error@-1 {{cannot use 'throw' with exceptions disabled}}
  } catch (int i) {
    x = 41;
  }
}

// Test that 'private' can be parsed as an access qualifier and an address space too.
class A {
  private:
  private int i; // expected-error{{field may not be qualified with an address space}}
};

private ::A i; // expected-error{{program scope variable must reside in global or constant address space}}

void foo(private int i);

private int bar(); // expected-error{{return type cannot be qualified with address space}}
