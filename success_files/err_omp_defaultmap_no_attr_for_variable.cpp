
int *g;

void foo() {
    #pragma omp target parallel defaultmap(none:pointer)
    {
        g++; // expected-error {{variable 'g' must have explicitly specified data sharing attributes, data mapping attributes, or in an is_device_ptr clause}}
    }
}

int main() {
    return 0;
}
