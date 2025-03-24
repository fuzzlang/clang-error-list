
void func() {
    void& ref; // expected-error{{cannot form a reference to 'void'}}
}
