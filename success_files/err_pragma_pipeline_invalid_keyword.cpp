
void exampleFunction() {
    #pragma clang loop pipeline(enable)  // expected-error {{invalid argument; expected 'disable'}}
    for (int i = 0; i < 10; ++i) {
        // loop body
    }
}
