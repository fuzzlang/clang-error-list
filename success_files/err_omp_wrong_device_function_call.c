
void bazz() {}

#pragma omp declare target to(bazz) device_type(nohost)

void any() {
    bazz(); // expected-error {{function with 'device_type(nohost)' is not available on host}}
}
