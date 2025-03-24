
void test() {
    __declspec(thread) int a; // expected-error {{must have global storage}}
}
