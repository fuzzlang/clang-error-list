
void foo(); // Declaration of foo function

int main() {
    int i = 0;
    int j = 0;

    #pragma omp ordered depend(sink : i+foo(), j/4) // expected-error {{integral constant expression}} expected-error {{expected '+' or '-' operation}}
    {
        // Some code here
    }

    return 0;
}
