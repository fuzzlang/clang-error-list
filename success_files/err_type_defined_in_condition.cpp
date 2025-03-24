
// expected-error@-1 {{'I' cannot be defined in a type specifier}}
void test() {
    if (struct J *p = 0) {}
    if (struct J {} *p = 0) {}
}
