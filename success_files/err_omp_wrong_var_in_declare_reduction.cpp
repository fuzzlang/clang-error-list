
int main() {
    int temp = 0;
    double omp_in = 0.0;

#pragma omp declare reduction(|| : int, double : temp += omp_in) // expected-error 2 {{only 'omp_in' or 'omp_out' variables are allowed in combiner expression}}
    
    return 0;
}
