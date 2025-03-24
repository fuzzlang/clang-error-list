
// expected-error@+1{{nested}}
#define V5(...) __VA_OPT__(__VA_OPT__())

int main() {
    V5(1, 2); // This should trigger the expected error
    return 0;
}
