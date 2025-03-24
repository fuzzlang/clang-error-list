
namespace arity {
  template<typename v, typename>
  concept C1 = true;

  auto f() -> C1 auto {} // expected-error{{'C1' requires more than 1 template argument; provide the remaining arguments explicitly to use it here}}
}
