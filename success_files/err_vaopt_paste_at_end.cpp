
#define V1(...) y __VA_OPT__(X ##) // expected-error{{cannot appear at end}}

int main() {
    V1(); // This will generate the expected error
    return 0;
}
