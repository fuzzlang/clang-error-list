
int main() {
    int total = 0;

#pragma omp loop bind(teams) reduction(+:total) // expected-error{{'reduction' clause not allowed with '#pragma omp loop bind(teams)'}}
    for (int i = 0; i < 10; ++i) {
        total += i;
    }

    return 0;
}
