
void test() {
    (void)new int __attribute__((address_space(1))); // expected-error{{'new' cannot allocate objects of type 'int' in address space '1'}}
}
