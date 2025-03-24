
void fun(int a) {}

void (*ptr2)(int, int);

int main() {
    ptr2 = &fun;  // expected-error {{incompatible function pointer types assigning to 'void (*)(int, int)' from 'void (*)(int)'}}
    return 0;
}
