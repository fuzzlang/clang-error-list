
void example() {
#pragma clang loop pipeline(disable)
#pragma clang loop pipeline_initiation_interval(4) // expected-error {{incompatible directives 'pipeline(disable)' and 'pipeline_initiation_interval(4)'}}
  for (int i = 0; i < 10; ++i) {
    // Loop body
  }
}
