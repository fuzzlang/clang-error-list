
void foo() {
}

#pragma omp threadprivate(foo) // expected-error {{'foo' is not a global variable, static local variable or static data member}}
