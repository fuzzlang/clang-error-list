
int foo();
#pragma omp declare variant(foo) match(xxx={}) // expected-error {{single declaration is expected after 'declare variant' directive}} \
                                                // expected-warning {{'xxx' is not a valid context set in a `declare variant`; set ignored}} \
                                                // expected-note {{context set options are: 'construct' 'device' 'implementation' 'user'}} \
                                                // expected-note {{the ignored set spans until here}}
int b, c;
