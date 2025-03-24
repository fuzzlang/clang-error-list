
// expected-error@+1{{missing '('}}
#define V1(...) __VA_OPT__

int main() {
    int x = V1; // This will cause an error due to missing '('
    return 0;
}
