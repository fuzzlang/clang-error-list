
void void_fn();
int overload_fn();
int overload_fn(int);

void test() {
    auto bad_init_5 = [a(overload_fn)] {}; // expected-error {{cannot deduce type for lambda capture 'a' from initializer of type '<overloaded function'}}
}
