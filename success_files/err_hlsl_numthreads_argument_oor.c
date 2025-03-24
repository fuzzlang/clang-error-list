
// expected-error@+1 {{argument 'X' to numthreads attribute cannot exceed 1024}}
[numthreads(-1, 2, 3)]
void example_function() {}
