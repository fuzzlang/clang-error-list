
#pragma omp declare target
static int y; // static variable with internal linkage
#pragma omp end declare target

void update_variable() {
    #pragma omp target update to(y) // expected-error {{the host cannot update a declare target variable that is not externally visible}}
}
