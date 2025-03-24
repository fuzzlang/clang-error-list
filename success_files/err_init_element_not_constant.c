
__declspec(dllimport) int GlobalDecl;

int *VarForInit = &GlobalDecl; // expected-error{{initializer element is not a compile-time constant}}
