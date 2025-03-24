
int funcptr3(long);

int main() {
    int sz8 = sizeof(^int (*[5])(long) {return funcptr3;}); // expected-error {{block cannot return array type}} expected-error {{incompatible pointer to integer conversion}}
    return 0;
}
