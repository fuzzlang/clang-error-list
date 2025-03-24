
void test() {
    float *pf;
    int *pi;
    (void)(pi - pf);  // expected-error {{not pointers to compatible types}}
}
