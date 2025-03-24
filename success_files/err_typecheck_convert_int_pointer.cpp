
void func() {
    void *ptr;
    ptr = 42; // expected-error {{incompatible integer to pointer conversion assigning to 'void *' from 'int'}}
}
