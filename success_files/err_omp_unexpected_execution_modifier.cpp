
#pragma omp error at(execution) // expected-error {{unexpected 'execution' modifier in non-executable context}}

int main() {
    return 0;
}
