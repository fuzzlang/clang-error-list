
void default_argument(int arg = co_await 0) {} // expected-error {{'co_await' cannot be used outside a function}}
