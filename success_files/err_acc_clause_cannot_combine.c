
void func() {
  // expected-error@+3{{OpenACC clause 'gang' may not appear on the same construct as a 'seq' clause on a 'loop' construct}}
  // expected-note@+2{{previous clause is here}}
  // expected-warning@+1{{OpenACC clause 'gang' not yet implemented}}
  #pragma acc loop seq gang
  for (int i = 0; i < 10; i++) {
    // Loop body
  }
}
