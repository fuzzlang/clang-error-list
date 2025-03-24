
struct I {
    ~I() {}
};

void f() {}

int main() {
    __builtin_call_with_static_chain((42).~I(), f); // expected-error {{first argument to __builtin_call_with_static_chain must not be a pseudo-destructor call}}
    return 0;
}
