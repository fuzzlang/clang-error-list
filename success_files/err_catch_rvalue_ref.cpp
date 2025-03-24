
void foo() {
    try {
        throw 42;
    } catch (int&& e) { // expected-error {{cannot catch exceptions by rvalue reference}}
    }
}
