
alignas(8) extern int n6; // expected-note {{declared with 'alignas' attribute here}}
int n6; // expected-error {{'alignas' must be specified on definition if it is specified on any declaration}}
