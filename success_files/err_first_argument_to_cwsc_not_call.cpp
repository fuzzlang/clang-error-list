
struct A {
    void f() {}
};

void f() {}

int main() {
    __builtin_call_with_static_chain(A().f(), f); // expected-error {{first argument to __builtin_call_with_static_chain must be a non-member call expression}}
    return 0;
}
