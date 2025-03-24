
void example() {
    int i = 5;
    int c[][i] = { 0 }; // expected-error {{variable-sized object may not be initialized}}
}
