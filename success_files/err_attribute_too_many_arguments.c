
void f4(int a, ...) __attribute__ ((sentinel(1, 2, 3))); // expected-error{{'sentinel' attribute takes no more than 2 arguments}}

int main() {
    return 0;
}
