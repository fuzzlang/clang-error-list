
double f1(void) {
    // expected-error {{SSE2 register return with SSE2 disabled}}
    return 1.0;
}
