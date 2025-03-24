
void f(void) {
    static int a __attribute__((weakref ("v2"))); // expected-error {{declaration of 'a' must be in a global context}}
}
