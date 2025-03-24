
int main(int argc, char **argv) {
    #pragma omp task default(none) // expected-note {{explicit data sharing attribute requested here}}
    {
        ++argc; // expected-error {{variable 'argc' must have explicitly specified data sharing attributes}}
    }
    return 0;
}
