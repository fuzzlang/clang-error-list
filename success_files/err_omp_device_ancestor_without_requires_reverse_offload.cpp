
int main() {
    #pragma omp target device(ancestor : 1) // expected-error {{device clause with ancestor device-modifier used without specifying 'requires reverse_offload'}}
    {
        // block should not be empty
    }
    return 0;
}
