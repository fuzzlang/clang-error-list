
void test() {
    delete [] { return new int; } (); // expected-error {{'[]' after delete interpreted as 'delete[]'}}
}
