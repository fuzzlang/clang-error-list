
template <class Promise>
struct coro {};

struct BadCoroMemberTag {};

namespace std {
    template <class T, class = void>
    struct coroutine_traits {};
}

struct CoroHandleMemberFunctionTest {
    struct TestType {};

    BadCoroMemberTag test_diagnostics() {
        // expected-error@-1 {{this function cannot be a coroutine: 'std::coroutine_traits<CoroHandleMemberFunctionTest::BadCoroMemberTag, CoroHandleMemberFunctionTest::TestType &>' has no member named 'promise_type'}}
        co_return;
    }
};
