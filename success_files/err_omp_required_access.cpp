
void foo() {}

void exampleFunction() {
    float fl;

    #pragma omp parallel private(fl) // expected-note {{defined as private}}
    {
        #pragma omp for reduction(+ : fl) // expected-error {{reduction variable must be shared}}
        for (int i = 0; i < 10; ++i) {
            fl += i;
        }
    }
}
