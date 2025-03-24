
void overload_fn(int);
void overload_fn(double);

void test() {
    auto bad_init_6 = [a{overload_fn}] {}; // expected-error {{cannot deduce type for lambda capture 'a' from initializer list}}
}
