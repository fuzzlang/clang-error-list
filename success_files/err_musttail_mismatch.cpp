
void NoParams(); // expected-note {{target function has different number of parameters (expected 1 but has 0)}}

void TestParamArityMismatch(int x) {
  [[clang::musttail]] // expected-note {{tail call required by 'musttail' attribute here}}
  return NoParams();  // expected-error {{cannot perform a tail call to function 'NoParams' because its signature is incompatible with the calling function}}
}
