
global pipe int gp; // expected-error {{type '__global read_only pipe int' can only be used as a function parameter in OpenCL}}

void exampleFunction() {
    int localVar = 0;
}
