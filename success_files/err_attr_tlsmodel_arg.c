
static __thread int y __attribute__((tls_model("foobar"))); // expected-error {{tls_model must be "global-dynamic", "local-dynamic", "initial-exec" or "local-exec"}}
