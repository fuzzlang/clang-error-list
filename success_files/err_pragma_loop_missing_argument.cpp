
// expected-error {{missing argument; expected an integer value}}
void exampleFunction() {
    #pragma unroll_and_jam()
    for (int i = 0; i < 10; i++) {
        // do something
    }
}
