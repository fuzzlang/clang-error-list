
namespace std {
  template <class Ret, typename... T>
  struct coroutine_traits { using promise_type = typename Ret::promise_type; };
  
  template <class Promise = void>
  struct coroutine_handle {
    static coroutine_handle from_address(void *);
    void *address() const noexcept;
  };
  
  template <>
  struct coroutine_handle<void> {
    template <class PromiseType>
    coroutine_handle(coroutine_handle<PromiseType>);
    void *address() const noexcept;
  };
  
  struct suspend_always {
    bool await_ready() { return false; }      // expected-note 2 {{must be declared with 'noexcept'}}
    void await_suspend(coroutine_handle<>) {} // expected-note 2 {{must be declared with 'noexcept'}}
    void await_resume() {}                    // expected-note 2 {{must be declared with 'noexcept'}}
    ~suspend_always() noexcept(false);        // expected-note 2 {{must be declared with 'noexcept'}}
  };
}

using namespace std;

struct A {
  bool await_ready();
  void await_resume();
  template <typename F>
  void await_suspend(F);
};

struct coro_t {
  struct promise_type {
    coro_t get_return_object();
    suspend_always initial_suspend();
    suspend_always final_suspend(); // expected-note 2 {{must be declared with 'noexcept'}}
    void return_void();
    static void unhandled_exception();
  };
};

coro_t f(int n) { // expected-error {{the expression 'co_await __promise.final_suspend()' is required to be non-throwing}}
  A a{};
  co_await a;
}
