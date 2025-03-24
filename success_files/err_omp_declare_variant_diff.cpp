
static void fn_sc_base() {}

void fn_sc_variant() {}

#pragma omp declare variant(fn_sc_variant) match(xxx = {}) // expected-error {{function with '#pragma omp declare variant' has a different storage class}} expected-warning {{'xxx' is not a valid context set in a `declare variant`; set ignored}} expected-note {{context set options are: 'construct' 'device' 'implementation' 'user'}} expected-note {{the ignored set spans until here}}
void fn_sc_base();
