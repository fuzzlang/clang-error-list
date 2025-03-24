
void test() {
    int m;
    float fl;
    bool j;

#pragma omp parallel for reduction(inscan, + : m) reduction(*: fl) reduction(default, &&: j)
    for (int i = 0; i < 10; ++i) {
        m += i;
        fl *= 1.5f;
        j = j && (i > 5);
    }
}
