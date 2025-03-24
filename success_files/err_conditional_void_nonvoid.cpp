
void test() {}

int main() {
    int i1 = 1;
    int result = i1 ? 0 : test(); // expected-error {{right operand to ? is void, but left operand is of type 'int'}}
    return 0;
}
