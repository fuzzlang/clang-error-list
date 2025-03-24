
struct Window {
    int bounds;
};

int main() {
    struct Window win = {.bunds = 10}; // expected-error{{field designator 'bunds' does not refer to any field in type 'struct Window'; did you mean 'bounds'?}}
    return 0;
}
