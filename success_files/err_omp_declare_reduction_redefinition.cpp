
#pragma omp declare reduction(fun23 : long : omp_out += omp_in) // expected-note {{previous definition is here}}
#pragma omp declare reduction(fun23 : long, int, long : omp_out += omp_in) // expected-error {{redefinition of user-defined reduction for type 'long'}}

int main() {
    return 0;
}
