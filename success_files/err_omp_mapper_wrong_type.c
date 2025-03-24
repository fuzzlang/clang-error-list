
#pragma omp declare mapper(int v) map(v) // expected-error {{mapper type must be of struct, union or class type}}

int main() {
    return 0;
}
