
static void operator delete(void *, int, int); // expected-error {{'operator delete' cannot be declared static in global scope}}

int main() {
    return 0;
}
