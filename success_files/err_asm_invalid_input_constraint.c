
int main() {
    int test_W;
    __asm__("" : : "Wd"(test_W)); // expected-error{{invalid input constraint 'Wd' in asm}}
    return 0;
}
