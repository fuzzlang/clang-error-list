
int main();

using T = decltype(main); // expected-error@-1 {{referring to 'main' within an expression is a Clang extension}}
using T2 = decltype(&main);

namespace example {
#if __cpp_constexpr >= 202306L
  constexpr void* ptr = nullptr;
  constexpr int* intPtr = static_cast<int*>(ptr);
  static_assert(intPtr == nullptr);
#endif
}

namespace test_namespace { // cwg2847: 19 review 2024-03-01

#if __cplusplus >= 202002L

template<typename>
void func();

struct B {
  template<typename>
  void g() requires true;

  template<>
  void g<int>() requires true; // expected-error@-1 {{is a Clang extension}}
};
#endif
}
