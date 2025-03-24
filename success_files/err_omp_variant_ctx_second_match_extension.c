
int dummy(void) { return 1; }

#pragma omp declare variant(dummy) match(implementation={extension(match_any,match_all)}, device={kind(cpu, gpu)}) // expected-error {{only a single match extension allowed per OpenMP context selector}} expected-note {{the previous context property 'match_any' used here}} // expected-note {{the ignored property spans until here}}

int base1(void) { return 2; }

int base2(void) { return 3; }

int base3(void) { return 4; }

int test(void) {
  return base1() + base2() + base3();
}
