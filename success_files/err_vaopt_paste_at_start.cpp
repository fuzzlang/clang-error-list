
#define V1(...) __VA_OPT__(##)

int main() {
    int x = 0;
    V1(x); // expected-error@+1{{cannot appear at start}}
}
