
void f() {}

int main() {
    __builtin_call_with_static_chain(__builtin_unreachable(), f); // expected-error {{first argument to __builtin_call_with_static_chain must not be a builtin call}}
    return 0;
}
