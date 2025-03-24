
double i = 0p+3; // expected-error {{invalid suffix 'p' on integer constant}}
#define PREFIX(x) foo ## x
double foo0p = 1, j = PREFIX(0p+3); // ok
double k = 0x42_amp+3; // expected-error {{invalid suffix 'amp' on integer constant}}
