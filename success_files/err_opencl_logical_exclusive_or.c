
int main() {
    int n = 5;
    int logxor = n ^^ n; // expected-error {{^^ is a reserved operator in OpenCL}}
    return 0;
}
