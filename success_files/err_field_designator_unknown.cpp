
struct Point {
    int a;
    int b;
};

int main() {
    Point d = {.x = 1, .y = 2}; // expected-error {{'x' does not refer to any field}}
    return 0;
}
