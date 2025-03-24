
void function() {
    (void)new int[1.1]; // expected-error {{array size must be an integral type}}
}
