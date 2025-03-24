
template <bool... vals>
void f() __attribute__((diagnose_if(vals..., "message", "error"))) {
    [] () __attribute__((diagnose_if(vals..., "message", "error"))) {}(); // expected-error {{attribute 'diagnose_if' does not support argument pack expansion}}
}
