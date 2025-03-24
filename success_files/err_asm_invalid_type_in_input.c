
void test_W(int x) {
}

int main() {
    __asm__("" : : "Ws"(test_W(0))); // expected-error{{invalid type 'void' in asm input for constraint 'Ws'}}
    return 0;
}
