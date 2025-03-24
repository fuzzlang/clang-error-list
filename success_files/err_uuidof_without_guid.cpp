
namespace FailUuidof {
  struct number {};
  
  constexpr void test() {
    __uuidof(number); // both-error {{cannot call operator __uuidof on a type with no GUID}}
  }
}
