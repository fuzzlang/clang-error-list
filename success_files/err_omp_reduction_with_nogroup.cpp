
int main() {
    int m = 0;

    #pragma omp taskloop nogroup reduction(+ : m) // expected-error {{'reduction' clause cannot be used with 'nogroup' clause}}
    for (int i = 0; i < 10; i++) {
        m += i;
    }

    return 0;
}
