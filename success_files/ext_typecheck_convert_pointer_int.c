
void atomic_init(int *n, int value); // Declaration of atomic_init

int main() {
    int *n; // Pointer variable declaration
    atomic_init(n, (void*)0); // expected-error {{passing 'void *' to parameter of type 'int'}}
    return 0;
}
