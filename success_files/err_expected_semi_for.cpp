
void test() {
  int arr[3];
  { for (const n
  // expected-error@-1 {{expected a type}}
         : arr) ; {} }
}
