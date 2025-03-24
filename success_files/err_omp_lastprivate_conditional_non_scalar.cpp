
void test_function(int argc) {
    struct S6 {
        S6() {}
        S6(const S6&) = delete; // Private constructor
    };

    S6 s;

    #pragma omp parallel
    {
        #pragma omp for simd lastprivate(conditional: argc, s)
        for (int i = 0; i < 10; ++i) {
            //some code
        }
    }
}
