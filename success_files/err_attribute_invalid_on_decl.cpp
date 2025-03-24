
void exampleFunction() {
    [[assume(true)]] int x; // expected-error {{'assume' attribute cannot be applied to a declaration}}
}
