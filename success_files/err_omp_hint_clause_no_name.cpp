
int main() {
    #pragma omp critical hint(N) // expected-error {{the name of the construct must be specified in presence of 'hint' clause}}
    {
        // Critical section code
    }
    return 0;
}
