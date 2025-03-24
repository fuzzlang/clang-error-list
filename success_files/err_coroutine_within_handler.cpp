
void await_in_catch_coroutine() {
    try {
    } catch (...) { 
        co_await a; // expected-error {{'co_await' cannot be used in the handler of a try block}} 
    }
}
