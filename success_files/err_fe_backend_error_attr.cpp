
void __attribute__((error("oh no foo"))) foo();

int main() {
    foo(); // expected-error {{call to 'foo()' declared with 'error' attribute: oh no foo}}
    return 0;
}
