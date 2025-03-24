
// expected-error@+1 {{total number of threads cannot exceed 1024}}
[numthreads(1024, 1024, 1024)]
void kernel_function() {
}
