
namespace GH64923 {
using nullptr_t = decltype(nullptr);
struct MyTask{};
constexpr MyTask DoAnotherThing() {
    return {};
}

constexpr nullptr_t operator++(MyTask &&T); // expected-note {{declared here}}
void DoSomething() {
  if constexpr (++DoAnotherThing() != nullptr) {} // expected-error {{constexpr if condition is not a constant expression}}
}
}
