
#pragma omp requires unified_address
#pragma omp requires unified_address // expected-error {{only one unified_address clause can appear on a requires directive in a single translation unit}}

int main() {
    return 0;
}
