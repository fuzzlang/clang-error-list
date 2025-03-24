
int main() {
    int ii = 0;

#pragma omp target parallel for simd
    for (int &ref = ii; ref < 10; ref++) { // expected-error {{initialization clause of OpenMP for loop is not in canonical form ('var = init' or 'T var = init')}}
        // loop body
    }

    return 0;
}
