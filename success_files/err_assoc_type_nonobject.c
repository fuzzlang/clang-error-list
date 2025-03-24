
void foo(int n) {
  (void) _Generic(0,
      void(): 0); // expected-error {{type 'void ()' in generic association not an object type}}
}
