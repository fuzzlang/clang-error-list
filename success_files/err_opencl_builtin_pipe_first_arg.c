
void test() {
    int tmp; // variable needs initialization
    int *p;  // pointer variable declaration

    read_pipe(tmp, p); // expected-error {{first argument to 'read_pipe' must be a pipe type}}
}
