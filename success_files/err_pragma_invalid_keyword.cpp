
int main() {
    #pragma clang loop vectorize(badidentifier) // expected-error {{invalid argument; expected 'enable', 'assume_safety' or 'disable'}}
    for (int i = 0; i < 10; ++i) {
        // Some operation
    }
    return 0;
}
