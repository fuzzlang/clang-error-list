
int main() {
    float *i;
    __atomic_fetch_and(i, 3, __ATOMIC_SEQ_CST); // expected-error {{pointer to integer}}
    return 0;
}
