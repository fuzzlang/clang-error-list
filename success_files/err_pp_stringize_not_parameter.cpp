
//expected-error@+1{{not followed by}}
#define V1(...) __VA_OPT__  (#)

int main() {
    V1(); // This will produce the expected error
    return 0;
}
