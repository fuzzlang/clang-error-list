
void f() {}

int main() {
    __builtin_call_with_static_chain(^{}(), f); // expected-error {{first argument to __builtin_call_with_static_chain must not be a block call}}
    return 0;
}
