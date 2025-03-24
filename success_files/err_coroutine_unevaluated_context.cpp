
struct Awaitable {
    friend void operator co_await(Awaitable);
};

void example() {
    Awaitable a;
    decltype(co_await a); // expected-error {{'co_await' cannot be used in an unevaluated context}}
}
