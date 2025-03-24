
int f() {
    return 0;
}

int main() {
    __builtin_call_with_static_chain(f(), 42); // expected-error {{second argument to __builtin_call_with_static_chain must be of pointer type}}
    return 0;
}
