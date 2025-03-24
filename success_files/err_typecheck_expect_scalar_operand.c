
void func() {
    int s1 = 0;
    int s2 = 1;
    (int)__atomic_exchange(&s1, &s2, &s2, __ATOMIC_SEQ_CST); // expected-error {{operand of type 'void'}}
}
