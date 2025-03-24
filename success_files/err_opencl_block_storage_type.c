
void test() {
    __block int a = 10; // expected-error {{the __block storage type is not permitted}}
}
