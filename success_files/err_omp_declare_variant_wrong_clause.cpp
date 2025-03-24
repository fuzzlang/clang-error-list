
#pragma omp declare variant(x) // expected-error {{use of undeclared identifier 'x'}} omp50-error {{expected 'match' clause on 'omp declare variant' directive}} omp51-error {{expected 'match', 'adjust_args', or 'append_args' clause on 'omp declare variant' directive}}

int main() {
    return 0;
}
