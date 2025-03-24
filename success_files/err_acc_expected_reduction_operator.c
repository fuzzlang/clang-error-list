
void test() {
    #pragma acc serial reduction() {
        int x = 0;
        x += 1;
    }
}
