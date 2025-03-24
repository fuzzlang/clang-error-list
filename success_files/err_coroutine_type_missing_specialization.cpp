
namespace std {

template<typename ...T>
struct coroutine_traits {
  struct promise_type {};
};

template <> struct coroutine_traits<void>; // expected-note {{forward declaration of 'std::coroutine_traits<void>'}}

} // namespace std

void uses_forward_declaration() {
  co_return; // expected-error {{this function cannot be a coroutine: missing definition of specialization 'coroutine_traits<void>'}}
}
