
int main() {
  (void) R"\t()\t";
  // expected-error@-1 {{invalid character '\\' in raw string delimiter}}
  // expected-error@-2 {{expected expression}}
}
