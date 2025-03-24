
__regcall int RegCallReturnsInt(); // expected-note {{target function has calling convention regcall (expected cdecl)}}
int TestMismatchCallingConvention() {
    [[clang::musttail]]         // expected-note {{tail call required by 'musttail' attribute here}}
    return RegCallReturnsInt(); // expected-error {{cannot perform a tail call to function 'RegCallReturnsInt' because it uses an incompatible calling convention}}
}
