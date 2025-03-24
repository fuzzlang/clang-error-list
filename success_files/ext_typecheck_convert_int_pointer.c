
int main() {
    int I = 42;
    _Bool cmpexch_7 = __atomic_compare_exchange(&I, &I, 5, 1, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST); // expected-error {{passing 'int' to parameter of type 'int *'}}
    return 0;
}
