
void no_coroutine_traits_bad_arg_await() {
    co_await a; // expected-error {{include <coroutine>}}
}
