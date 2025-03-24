
void example() {
    int m;
    float fl;
    int j;

    #pragma omp parallel for reduction(inscan, + : m, fl, j) // expected-error 2 {{the inscan reduction list item must appear as a list item in an 'inclusive' or 'exclusive' clause on an inner 'omp scan' directive}}
    for (int i = 0; i < 10; ++i) {
        m += i;
        fl += static_cast<float>(i);
        j += i;
    }
}
