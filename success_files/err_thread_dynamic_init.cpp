
int f() {
    return 42;
}

int __declspec(thread) x = f(); // expected-error {{initializer for thread-local variable must be a constant expression}}
