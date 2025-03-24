
void my_function() {
  // expected-error@+2{{OpenACC clause 'auto' on 'loop' construct conflicts with previous data dependence clause}}
  // expected-note@+1{{previous clause is here}}
  #pragma acc loop seq independent auto
  for (int i = 0; i < 10; i++) {
    // loop body
  }
}
