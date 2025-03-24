
int main() {
    int argc;
    #pragma omp distribute parallel for reduction(foo : argc // expected-error {{expected ')'}} 
    {
        // some code
    }
    return 0;
}
