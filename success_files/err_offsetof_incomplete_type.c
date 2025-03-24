
struct dr040; // Forward declaration of struct dr040

int i[__builtin_offsetof(struct dr040, s)]; /* expected-error {{offsetof of incomplete type 'struct dr040'}} */
