
template <typename T>
struct [[clang::coro_return_type]] Gen {
    struct promise_type {
        Gen<T> get_return_object() {
            return {};
        }
        static Gen<T> get_return_object_on_allocation_failure() {
            return {};
        }
        void return_value(T t);
    };
};

Gen<int> foo_coro(int b) {
    co_return b;
}

Gen<int> non_marked_wrapper(int b) { 
    // expected-error@+1 {{neither a coroutine nor a coroutine wrapper}} 
    return foo_coro(b); 
}
