
double test15(void) {
    double ret;
    __asm("0.0" : "="(ret)); // expected-error {{invalid output constraint '=' in asm}}
    return ret;
}
